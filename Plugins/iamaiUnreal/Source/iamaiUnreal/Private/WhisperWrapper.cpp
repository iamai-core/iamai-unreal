#include "WhisperWrapper.h"

#include "Misc/Paths.h"
#include <filesystem>

namespace fs = std::filesystem;

FWhisperWrapper::FWhisperWrapper() {

    if (!LoadWhisper("ggml-base.bin")) {
        UE_LOG(LogTemp, Error, TEXT("Failed to load Whisper"));

    }
}

FWhisperWrapper::~FWhisperWrapper() {

    if (WhisperContext && whisper_free) {
        whisper_free(WhisperContext);
        WhisperContext = nullptr;
    }

    if (DllHandle) {
        FreeLibrary(DllHandle);
        DllHandle = nullptr;
    }

}

template<typename T>

T FWhisperWrapper::GetFunction(const char* Name) {
    FARPROC Proc = GetProcAddress(DllHandle, Name);
    if (!Proc) {
        UE_LOG(LogTemp, Error, TEXT("Failed to bind function: %S"), Name);
        return nullptr;
    }
    return reinterpret_cast<T>(Proc);

}

bool FWhisperWrapper::LoadWhisper(const std::string& ModelName) {

    FString ProjectDir = FPaths::ProjectDir();
    FString PluginDir = FPaths::Combine(ProjectDir, TEXT("Plugins"), TEXT("iamaiUnreal"));
    FString DllDir = FPaths::Combine(PluginDir, TEXT("ThirdParty"));
    FString ModelDir = FPaths::Combine(PluginDir, TEXT("Models"), *FString(ModelName.c_str()));

    std::string DllDirStd = TCHAR_TO_UTF8(*DllDir);
    std::string ModelPathStd = TCHAR_TO_UTF8(*ModelDir);
    std::string DllPathStd = TCHAR_TO_UTF8(*FPaths::Combine(DllDir, TEXT("whisper.dll")));

    if (!fs::exists(DllDirStd)) return false;
    SetDllDirectoryA(DllDirStd.c_str());

    DllHandle = LoadLibraryA(DllPathStd.c_str());
    if (!DllHandle) {
        UE_LOG(LogTemp, Error, TEXT("Failed to load whisper.dll"));
        return false;
    }

    whisper_init_from_file = GetFunction<whisper_init_from_file_t>("whisper_init_from_file");
    whisper_full = GetFunction<whisper_full_t>("whisper_full");
    whisper_full_default_params = GetFunction<whisper_full_default_params_t>("whisper_full_default_params");
    whisper_pcm_to_mel = GetFunction<whisper_pcm_to_mel_t>("whisper_pcm_to_mel");
    whisper_full_n_segments = GetFunction<whisper_full_n_segments_t>("whisper_full_n_segments");
    whisper_full_get_segment_text = GetFunction<whisper_full_get_segment_text_t>("whisper_full_get_segment_text");
    whisper_free = GetFunction<whisper_free_t>("whisper_free");

    if (!whisper_init_from_file || !whisper_full || !whisper_full_default_params ||
        !whisper_pcm_to_mel || !whisper_full_n_segments || !whisper_full_get_segment_text || !whisper_free) {
        return false;
    }

    WhisperContext = whisper_init_from_file(ModelPathStd.c_str());
    return WhisperContext != nullptr;

}

bool FWhisperWrapper::Transcribe(float* PcmData, int32 NumSamples, FString& OutTranscript) {

    if (!WhisperContext) return false;

    void* Params = whisper_full_default_params();
    if (!Params) return false;

    if (whisper_pcm_to_mel(WhisperContext, PcmData, NumSamples, 0) != 0) return false;
    if (whisper_full(WhisperContext, Params) != 0) return false;

    int NumSegments = whisper_full_n_segments(WhisperContext);
    FString Transcript;

    for (int i = 0; i < NumSegments; ++i) {
        const char* Text = whisper_full_get_segment_text(WhisperContext, i);
        if (Text) Transcript += ANSI_TO_TCHAR(Text);
    }

    OutTranscript = Transcript;
    return true;

}

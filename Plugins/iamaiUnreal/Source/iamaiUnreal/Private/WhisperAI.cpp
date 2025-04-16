#include "WhisperAI.h"

WhisperAI::WhisperAI(const std::string& modelName, int threads) {

    FString ProjectDirFString = FPaths::ProjectDir();
    FString PluginDirFString = FPaths::Combine(ProjectDirFString, TEXT("Plugins"), TEXT("iamaiUnreal"));
    FString DllDirectoryFString = FPaths::Combine(PluginDirFString, TEXT("ThirdParty"));
    FString DllPathFString = FPaths::Combine(DllDirectoryFString, TEXT("whisper-interface.dll"));
    FString ModelPathFString = FPaths::Combine(PluginDirFString, TEXT("Models"), *FString(modelName.c_str()));

    // Convert to standard strings
    std::string dllDirectory = TCHAR_TO_UTF8(*DllDirectoryFString);
    std::string dllPath = TCHAR_TO_UTF8(*DllPathFString);
    std::string modelPath = TCHAR_TO_UTF8(*ModelPathFString);

    if (!std::filesystem::exists(dllDirectory)) {

        throw std::runtime_error("DLL directory not found: " + dllDirectory);

    }

    SetDllDirectoryA(dllDirectory.c_str());

    // Load the whisper-interface DLL
    DllHandle = LoadLibraryA(dllPath.c_str());
    if (!DllHandle) {
        int errorCode = GetLastError();
        throw std::runtime_error("Failed to load whisper-interface DLL. Error code: " + std::to_string(errorCode));
    }

    // Get Whisper function pointers
    _init = GetFunction<InitFunction>("Init");
    _free = GetFunction<FreeFunction>("Free");
    _setThreads = GetFunction<SetThreadsFunction>("setThreads");
    _setLanguage = GetFunction<SetLanguageFunction>("setLanguage");
    _setTranslate = GetFunction<SetTranslateFunction>("setTranslate");
    _transcribe = GetFunction<TranscribeFunction>("Transcrible");

    // Initialize the model
    ctx = _init(modelPath.c_str(), threads);
    if (!ctx) {
        throw std::runtime_error("Failed to initialize whisper model");
    }

}

void WhisperAI::SetThreads(int nThreads) {
    _setThreads(ctx, nThreads);
}

void WhisperAI::SetLanguage(const std::string& language) {
    _setLanguage(ctx, language.c_str());
}

void WhisperAI::SetTranslate(bool translate) {
    _setTranslate(ctx, translate);
}

std::string WhisperAI::Transcribe(float* data, int samples) {

    const char* result = _transcribe(ctx, data, samples);
    return result ? std::string(result) : "";

}

WhisperAI::~WhisperAI() {

    if (!disposed) {

        if (ctx) _free(ctx);
        if (DllHandle) FreeLibrary(DllHandle);

        ctx = nullptr;
        DllHandle = nullptr;
        disposed = true;

    }

}

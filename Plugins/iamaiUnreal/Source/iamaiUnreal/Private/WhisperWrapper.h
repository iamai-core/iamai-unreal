#pragma once

#include "CoreMinimal.h"
#include <Windows.h>

class FWhisperWrapper {

public:

    FWhisperWrapper();
    ~FWhisperWrapper();

    bool Transcribe(float* PcmData, int32 NumSamples, FString& OutTranscript);

private:

    void* WhisperContext = nullptr;
    HMODULE DllHandle = nullptr;

    using whisper_init_from_file_t = void* (*)(const char*);
    using whisper_full_t = int (*)(void*, const void*);
    using whisper_full_default_params_t = void* (*)();
    using whisper_pcm_to_mel_t = int (*)(void*, const float*, int, int);
    using whisper_full_n_segments_t = int (*)(void*);
    using whisper_full_get_segment_text_t = const char* (*)(void*, int);
    using whisper_free_t = void (*)(void*);

    whisper_init_from_file_t whisper_init_from_file = nullptr;
    whisper_full_t whisper_full = nullptr;
    whisper_full_default_params_t whisper_full_default_params = nullptr;
    whisper_pcm_to_mel_t whisper_pcm_to_mel = nullptr;
    whisper_full_n_segments_t whisper_full_n_segments = nullptr;
    whisper_full_get_segment_text_t whisper_full_get_segment_text = nullptr;
    whisper_free_t whisper_free = nullptr;

    bool LoadWhisper(const std::string& ModelName);
    template<typename T>
    T GetFunction(const char* Name);

};

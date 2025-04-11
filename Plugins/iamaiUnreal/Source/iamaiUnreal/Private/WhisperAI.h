#pragma once

#include "CoreMinimal.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <memory>
#include <windows.h>

#include "Misc/Paths.h"

class WhisperAI {

public:

    WhisperAI(const std::string& modelPath);
    ~WhisperAI();

    WhisperAI(const WhisperAI&) = delete;
    WhisperAI& operator=(const WhisperAI&) = delete;

    void SetThreads(int nThreads);
    void SetLanguage(const std::string& language);
    void SetTranslate(bool translate);
    std::string Transcribe(float* data, int samples);

private:

    HMODULE DllHandle = nullptr;
    void* ctx = nullptr;
    bool disposed = false;

    typedef void* (*InitFunction)(const char*);
    typedef void (*FreeFunction)(void*);
    typedef void (*SetThreadsFunction)(void*, int);
    typedef void (*SetLanguageFunction)(void*, const char*);
    typedef void (*SetTranslateFunction)(void*, bool);
    typedef const char* (*TranscribeFunction)(void*, float*, int);

    InitFunction _init;
    FreeFunction _free;
    SetThreadsFunction _setThreads;
    SetLanguageFunction _setLanguage;
    SetTranslateFunction _setTranslate;
    TranscribeFunction _transcribe;

    template<typename T>
    T GetFunction(const char* funcName) {

        void* funcPtr = GetProcAddress(DllHandle, funcName);
        if (!funcPtr) {

            int errorCode = GetLastError();
            throw std::runtime_error("Failed to get proc address for " + std::string(funcName) + ". Error code: " + std::to_string(errorCode));

        }

        return reinterpret_cast<T>(funcPtr);

    }

};

#pragma once

#include "CoreMinimal.h"

#include <windows.h>
#include <string>
#include <iostream>
#include <filesystem>
#include <memory>

#include "Misc/Paths.h"


class IAMAIUNREAL_API iamaiAI {

public:

    iamaiAI(const std::string& modelName);
    iamaiAI(const std::string& modelName, int size, int tokens = 512, int batch = 512, int threads = 1);
    ~iamaiAI();

    iamaiAI(const iamaiAI&) = delete;
    iamaiAI& operator=(const iamaiAI&) = delete;

    std::string Generate(const std::string& prompt, int maxLength = 4096);

    void SetMaxTokens(int maxTokens) {
        _setMaxTokens(ctx, maxTokens);
    }

private:

    HMODULE DllHandle;
    void* ctx = nullptr;

    bool disposed = false;

    typedef void* (*InitFunction)(const char* modelPath);
    typedef void* (*FullInitFunction)(const char* modelPath, int size, int tokens, int batch, int threads);
    typedef bool (*GenerateFunction)(void* context, const char* prompt, char* output, int maxLength);
    typedef void (*SetMaxTokensFunction)(void* context, int maxTokens);
    typedef void (*FreeFunction)(void* context);

    InitFunction _init;
    FullInitFunction _fullInit;
    GenerateFunction _generate;
    SetMaxTokensFunction _setMaxTokens;
    FreeFunction _free;

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

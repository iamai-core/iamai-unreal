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
    ~iamaiAI();

    iamaiAI(const iamaiAI&) = delete;
    iamaiAI& operator=(const iamaiAI&) = delete;

    std::string Generate(const std::string& prompt, int maxLength = 4096);

    void SetMaxTokens(int maxTokens) {
        _setMaxTokens(ctx, maxTokens);
    }

    void SetThreads(int nThreads) {
        _setThreads(ctx, nThreads);
    }

    void SetBatchSize(int batchSize) {
        _setBatchSize(ctx, batchSize);
    }

private:

    HMODULE DllHandle;
    void* ctx = nullptr;

    bool disposed = false;

    typedef void* (*InitFunction)(const char* modelPath);
    typedef bool (*GenerateFunction)(void* context, const char* prompt, char* output, int maxLength);
    typedef void (*SetMaxTokensFunction)(void* context, int maxTokens);
    typedef void (*SetThreadsFunction)(void* context, int nThreads);
    typedef void (*SetBatchSizeFunction)(void* context, int batchSize);
    typedef void (*FreeFunction)(void* context);

    InitFunction _init;
    GenerateFunction _generate;
    SetMaxTokensFunction _setMaxTokens;
    SetThreadsFunction _setThreads;
    SetBatchSizeFunction _setBatchSize;
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

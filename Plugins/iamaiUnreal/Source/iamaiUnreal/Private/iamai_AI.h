// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <memory>
#include <windows.h>
#include "Misc/Paths.h"

namespace fs = std::filesystem;

/**
 *
 */
class iamai_AI {

public:

	iamai_AI(const std::string& modelName);
	~iamai_AI();

	// Delete copy constructor and assignment operator
	iamai_AI(const iamai_AI&) = delete;
	iamai_AI& operator=(const iamai_AI&) = delete;

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

	FString Transcribe(float* AudioData, int SampleCount);

private:

	HMODULE iamaiDllHandle;
	void* ctx = nullptr;

	HMODULE whisperDllHandle;
	void* WhisperContext = nullptr;

	bool disposed = false;

	// iamai-core function types
	typedef void* (*InitFunction)(const char* modelPath);
	typedef bool (*GenerateFunction)(void* context, const char* prompt, char* output, int maxLength);
	typedef void (*SetMaxTokensFunction)(void* context, int maxTokens);
	typedef void (*SetThreadsFunction)(void* context, int nThreads);
	typedef void (*SetBatchSizeFunction)(void* context, int batchSize);
	typedef void (*FreeFunction)(void* context);

	// whisper.dll function types
	typedef void* (*whisper_init_from_file_fn)(const char*);
	typedef void (*whisper_free_fn)(void*);
	typedef int (*whisper_full_fn)(void*, void*, float*, int);
	typedef void* (*whisper_full_default_params_fn)();
	typedef const char* (*whisper_full_get_segment_text_fn)(void*, int);
	typedef int (*whisper_full_n_segments_fn)(void*);

	// iamai-core function pointers
	InitFunction _init;
	GenerateFunction _generate;
	SetMaxTokensFunction _setMaxTokens;
	SetThreadsFunction _setThreads;
	SetBatchSizeFunction _setBatchSize;
	FreeFunction _free;

	// whisper function pointers
	whisper_init_from_file_fn whisper_init_from_file = nullptr;
	whisper_free_fn whisper_free = nullptr;
	whisper_full_fn whisper_full = nullptr;
	whisper_full_default_params_fn whisper_full_default_params = nullptr;
	whisper_full_get_segment_text_fn whisper_full_get_segment_text = nullptr;
	whisper_full_n_segments_fn whisper_full_n_segments = nullptr;

	template<typename T>
	T GetFunction(const HMODULE& dll, const char* funcName) {

		void* funcPtr = GetProcAddress(dll, funcName);

		if (!funcPtr) {
			int errorCode = GetLastError();
			throw std::runtime_error("Failed to get proc address for " + std::string(funcName) + ". Error code: " + std::to_string(errorCode));
		}

		return reinterpret_cast<T>(funcPtr);

	}

};

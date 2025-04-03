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


private:

	HMODULE dllHandle;
	void* ctx = nullptr;
	bool disposed = false;
	const std::string DLL_PATH = "iamai-core.dll";

	// Function types
	typedef void* (*InitFunction)(const char* modelPath);
	typedef bool (*GenerateFunction)(void* context, const char* prompt, char* output, int maxLength);
	typedef void (*SetMaxTokensFunction)(void* context, int maxTokens);
	typedef void (*SetThreadsFunction)(void* context, int nThreads);
	typedef void (*SetBatchSizeFunction)(void* context, int batchSize);
	typedef void (*FreeFunction)(void* context);

	// Function pointers
	InitFunction _init;
	GenerateFunction _generate;
	SetMaxTokensFunction _setMaxTokens;
	SetThreadsFunction _setThreads;
	SetBatchSizeFunction _setBatchSize;
	FreeFunction _free;

	template<typename T>
	T GetFunction(const char* funcName) {
		void* funcPtr = GetProcAddress(dllHandle, funcName);
		if (!funcPtr) {
			int errorCode = GetLastError();
			throw std::runtime_error("Failed to get proc address for " + std::string(funcName) +
				". Error code: " + std::to_string(errorCode));
		}
		return reinterpret_cast<T>(funcPtr);
	}

};

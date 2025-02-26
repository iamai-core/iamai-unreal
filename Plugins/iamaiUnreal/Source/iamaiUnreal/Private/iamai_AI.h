// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <memory>
#include <windows.h>

namespace fs = std::filesystem;

/**
 * 
 */
class iamai_AI
{
private:
	HMODULE dllHandle;
	void* ctx;
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

public:

	iamai_AI(const std::string& modelName) : ctx(nullptr) {
		// Get the current directory and navigate to the DLL location
		auto currentPath = fs::current_path();
		auto projectRoot = currentPath.parent_path().parent_path().parent_path().parent_path();
		auto dllDirectory = projectRoot / "Plugins" / "iamaiUnreal" / "Binaries" / "Thirdparty";
		auto dllPath = dllDirectory / DLL_PATH;
		auto modelPath = projectRoot / "Plugins" / "iamaiUnreal" / "Models" / modelName;

		if (!fs::exists(dllDirectory)) {
			throw std::runtime_error("DLL directory not found: " + dllDirectory.string());
		}

		std::cout << "Loading DLL from: " << dllPath.string() << std::endl;
		SetDllDirectoryA(dllDirectory.string().c_str());

		// Load the DLL
		dllHandle = LoadLibraryA(dllPath.string().c_str());
		if (!dllHandle) {
			int errorCode = GetLastError();
			throw std::runtime_error("Failed to load DLL. Error code: " + std::to_string(errorCode));
		}

		// Get function pointers
		_init = GetFunction<InitFunction>("Init");
		_generate = GetFunction<GenerateFunction>("Generate");
		_setMaxTokens = GetFunction<SetMaxTokensFunction>("SetMaxTokens");
		_setThreads = GetFunction<SetThreadsFunction>("SetThreads");
		_setBatchSize = GetFunction<SetBatchSizeFunction>("SetBatchSize");
		_free = GetFunction<FreeFunction>("Free");

		// Initialize the model
		ctx = _init(modelPath.string().c_str());
		if (!ctx) {
			throw std::runtime_error("Failed to initialize model");
		}
	}

	std::string Generate(const std::string& prompt, int maxLength = 4096) {
		std::unique_ptr<char[]> output(new char[maxLength]);
		bool success = _generate(ctx, prompt.c_str(), output.get(), maxLength);

		if (!success) {
			throw std::runtime_error("Generation failed");
		}

		return std::string(output.get());
	}

	void SetMaxTokens(int maxTokens) {
		_setMaxTokens(ctx, maxTokens);
	}

	void SetThreads(int nThreads) {
		_setThreads(ctx, nThreads);
	}

	void SetBatchSize(int batchSize) {
		_setBatchSize(ctx, batchSize);
	}

	~iamai_AI() {
		if (!disposed) {
			if (ctx) {
				_free(ctx);
				ctx = nullptr;
			}
			if (dllHandle) {
				FreeLibrary(dllHandle);
				dllHandle = nullptr;
			}
			disposed = true;
		}
	}

	// Delete copy constructor and assignment operator
	iamai_AI(const iamai_AI&) = delete;
	iamai_AI& operator=(const iamai_AI&) = delete;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "AIWrapper.h"

UAIWrapper::UAIWrapper() : 
	iamaiInstance(nullptr),
	whisperInstance(nullptr)
{}

UAIWrapper::~UAIWrapper() {
	// The unique_ptr will handle cleanup automatically
}

bool UAIWrapper::InitializeIamai(const FString& ModelName) {

	try {

		iamaiInstance = std::make_unique<iamaiAI>(TCHAR_TO_UTF8(*ModelName));
		
		return true;

	} catch (const std::exception& e) {

		UE_LOG(LogTemp, Error, TEXT("AI initialization error: %s"), UTF8_TO_TCHAR(e.what()));
		return false;

	}

}

bool UAIWrapper::InitializeWhisper(const FString& ModelName) {

	try {

		whisperInstance = std::make_unique<WhisperAI>(TCHAR_TO_UTF8(*ModelName));

		return true;

	} catch (const std::exception& e) {

		UE_LOG(LogTemp, Error, TEXT("AI initialization error: %s"), UTF8_TO_TCHAR(e.what()));
		return false;

	}

}

FString UAIWrapper::Generate(const std::string& Prompt, int32 MaxLength) {
	if (!iamaiInstance) {
		UE_LOG(LogTemp, Error, TEXT("AI not initialized"));
		return TEXT("Error: AI not initialized");
	}

	try {
		std::string result = iamaiInstance->Generate(Prompt, MaxLength);
		return UTF8_TO_TCHAR(result.c_str());
	} catch (const std::exception& e) {
		UE_LOG(LogTemp, Error, TEXT("Generation error: %s"), UTF8_TO_TCHAR(e.what()));
		return FString::Printf(TEXT("Error: %s"), UTF8_TO_TCHAR(e.what()));
	}

}

void UAIWrapper::SetMaxTokens(int32 MaxTokens) {
	if (iamaiInstance) {
		iamaiInstance->SetMaxTokens(MaxTokens);
	}
}

void UAIWrapper::SetThreads(int32 NumThreads) {
	if (iamaiInstance) {
		iamaiInstance->SetThreads(NumThreads);
	}
}

void UAIWrapper::SetBatchSize(int32 BatchSize) {
	if (iamaiInstance) {
		iamaiInstance->SetBatchSize(BatchSize);
	}
}

std::vector<float> clean_pcm(const std::vector<float>& input) {

	std::vector<float> output;
	float average, sum;

	for (size_t i = 0; i + 2 < input.size(); i += 3) {

		sum = input[i] + input[i + 1] + input[i + 2];
		average = std::clamp(sum / 3.0f, -1.0f, 1.0f);

		if (average != 0.0f) output.push_back(average);

	}

	return output;

}

FString UAIWrapper::Transcribe(float* AudioData, int SampleCount) {

	if (!iamaiInstance) return "";

	std::vector<float> downsized = clean_pcm(std::vector<float>(AudioData, AudioData + SampleCount));
	std::string Transcript = whisperInstance->Transcribe(downsized.data(), downsized.size());

	return FString(UTF8_TO_TCHAR(Transcript.c_str()));

}

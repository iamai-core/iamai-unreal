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



#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>

void write_wav_from_float(const std::string& filename, const float* pcm_float, size_t num_samples, int sample_rate, int num_channels = 1) {
	std::ofstream file(filename, std::ios::binary);

	std::vector<int16_t> pcm_int(num_samples);
	for (size_t i = 0; i < num_samples; ++i)
		pcm_int[i] = std::clamp(pcm_float[i], -1.0f, 1.0f) * 32767;

	int byte_rate = sample_rate * num_channels * sizeof(int16_t);
	int block_align = num_channels * sizeof(int16_t);
	int data_chunk_size = pcm_int.size() * sizeof(int16_t);
	int riff_chunk_size = 36 + data_chunk_size;
	int16_t audio_format = 1; // PCM
	int16_t bits_per_sample = 16;

	file.write("RIFF", 4);
	file.write(reinterpret_cast<const char*>(&riff_chunk_size), 4);
	file.write("WAVE", 4);

	file.write("fmt ", 4);
	int fmt_chunk_size = 16;
	file.write(reinterpret_cast<const char*>(&fmt_chunk_size), 4);
	file.write(reinterpret_cast<const char*>(&audio_format), 2);
	file.write(reinterpret_cast<const char*>(&num_channels), 2);
	file.write(reinterpret_cast<const char*>(&sample_rate), 4);
	file.write(reinterpret_cast<const char*>(&byte_rate), 4);
	file.write(reinterpret_cast<const char*>(&block_align), 2);
	file.write(reinterpret_cast<const char*>(&bits_per_sample), 2);

	file.write("data", 4);
	file.write(reinterpret_cast<const char*>(&data_chunk_size), 4);
	file.write(reinterpret_cast<const char*>(pcm_int.data()), data_chunk_size);
}

FString UAIWrapper::Transcribe(float* AudioData, int SampleCount) {

	if (!iamaiInstance) return "";

	std::string temp = "std::vector<float> = {";

	for (int32 i = 0; i < SampleCount; ++i) {

		temp += std::to_string(AudioData[i]) + "f, ";
		
	}

	temp += "}";


	write_wav_from_float("C:/Users/Collin/Downloads/output.wav", AudioData, SampleCount, 48000, 2);

	UE_LOG(LogTemp, Warning, TEXT("%s"), UTF8_TO_TCHAR(temp.c_str()));
	std::string Transcript = whisperInstance->Transcribe(AudioData, SampleCount);

	return FString();

}

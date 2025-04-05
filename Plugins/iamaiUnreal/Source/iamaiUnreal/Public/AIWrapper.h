// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <memory>

#include "iamai_AI.h"

#include "AIWrapper.generated.h"

/**
 * Blueprint-friendly wrapper for the AI class
 */
UCLASS(BlueprintType, Blueprintable)
class IAMAIUNREAL_API UAIWrapper : public UObject {

	GENERATED_BODY()

private:

	std::unique_ptr<iamai_AI> AIInstance;

public:

	UAIWrapper();
	virtual ~UAIWrapper();

	/**
	 * Initialize the AI with a specific model
	 * @param ModelName - Name of the model directory to load
	 * @return Whether initialization was successful
	 */
	bool Initialize(const FString& ModelName);


	/**
	 * Generate text based on a prompt
	 * @param Prompt - The input prompt
	 * @param MaxLength - Maximum length of the generated output
	 * @return The generated text
	 */
	FString Generate(const std::string& Prompt, int32 MaxLength = 4096);

	/**
	 * Set the maximum number of tokens to generate
	 * @param MaxTokens - Maximum number of tokens
	 */
	UFUNCTION(BlueprintCallable, Category = "iamai AI")
	void SetMaxTokens(int32 MaxTokens);

	/**
	 * Set the number of threads to use
	 * @param NumThreads - Number of threads
	 */
	UFUNCTION(BlueprintCallable, Category = "iamai AI")
	void SetThreads(int32 NumThreads);

	/**
	 * Set the batch size for generation
	 * @param BatchSize - Batch size
	 */
	UFUNCTION(BlueprintCallable, Category = "iamai AI")
	void SetBatchSize(int32 BatchSize);


	/** 
	* Transcribe an audio file
	* @param FilePath - Path to the wav audio file
	*/
	FString Transcribe(const std::string& FilePath);

	/**
	* Transcribe audio to text from float array
	* @param AudioData - Pointer to the audio data
	* @param SampleCount - Number of samples in the audio data
	*/
	FString Transcribe(float* AudioData, int SampleCount);

};

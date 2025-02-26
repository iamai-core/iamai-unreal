// Fill out your copyright notice in the Description page of Project Settings.


#include "AIWrapper.h"
#include "iamai_AI.h"

UAIWrapper::UAIWrapper()
    : AIInstance(nullptr)
{
}

UAIWrapper::~UAIWrapper()
{
    // The unique_ptr will handle cleanup automatically
}

bool UAIWrapper::Initialize(const FString& ModelName)
{
    try
    {
        AIInstance = std::make_unique<iamai_AI>(TCHAR_TO_UTF8(*ModelName));
        return true;
    }
    catch (const std::exception& e)
    {
        UE_LOG(LogTemp, Error, TEXT("AI initialization error: %s"), UTF8_TO_TCHAR(e.what()));
        return false;
    }
}

FString UAIWrapper::Generate(const FString& Prompt, int32 MaxLength)
{
    if (!AIInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("AI not initialized"));
        return TEXT("Error: AI not initialized");
    }

    try
    {
        std::string result = AIInstance->Generate(TCHAR_TO_UTF8(*Prompt), MaxLength);
        return UTF8_TO_TCHAR(result.c_str());
    }
    catch (const std::exception& e)
    {
        UE_LOG(LogTemp, Error, TEXT("Generation error: %s"), UTF8_TO_TCHAR(e.what()));
        return FString::Printf(TEXT("Error: %s"), UTF8_TO_TCHAR(e.what()));
    }
}

void UAIWrapper::SetMaxTokens(int32 MaxTokens)
{
    if (AIInstance)
    {
        AIInstance->SetMaxTokens(MaxTokens);
    }
}

void UAIWrapper::SetThreads(int32 NumThreads)
{
    if (AIInstance)
    {
        AIInstance->SetThreads(NumThreads);
    }
}

void UAIWrapper::SetBatchSize(int32 BatchSize)
{
    if (AIInstance)
    {
        AIInstance->SetBatchSize(BatchSize);
    }
}
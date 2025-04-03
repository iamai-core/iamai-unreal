// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerateText.h"

UGenerateText* UGenerateText::Generate(UAIWrapper* aiWrapper, const FString& Prompt, int32 MaxLength) {

	UGenerateText* Node = NewObject<UGenerateText>();
	Node->AIInstance = aiWrapper;
	Node->Prompt = new std::string(TCHAR_TO_UTF8(*Prompt));
	Node->MaxLength = MaxLength;

    return Node;

}

void UGenerateText::Activate() {

    if (!AIInstance) {

        UE_LOG(LogTemp, Error, TEXT("AI not initialized"));
        OnCompleted.Broadcast(false, "");
        return;

    }

    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]() {

        FString Result;
        bool bSuccess = false;

        try {

            Result = AIInstance->Generate(*Prompt, MaxLength);
            bSuccess = !Result.IsEmpty();

        } catch (const std::exception& e) {

            UE_LOG(LogTemp, Error, TEXT("Generation error: %s"), UTF8_TO_TCHAR(e.what()));

        }

        AsyncTask(ENamedThreads::GameThread, [this, bSuccess, Result]() {

            OnCompleted.Broadcast(bSuccess, Result);

            });

        });

}
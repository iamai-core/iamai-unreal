// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AIWrapper.h"
#include "iamaiUnrealBPLibrary.generated.h"

UCLASS()
class UiamaiUnrealBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "iamaiUnreal sample test testing"), Category = "iamaiUnrealTesting")
	static float iamaiUnrealSampleFunction(float Param);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Test function", Keywords = "iamaiUnreal testing"), Category = "iamaiUnrealTesting")
	static bool TestFunction(float input1, float input2, FString& returnValue);

    /**
     * Initialize the AI model with the given model name
     * @param ModelName - Name of the model directory to load
     * @return A new AI wrapper object
     */
    UFUNCTION(BlueprintCallable, Category = "iamai AI")
    static UAIWrapper* InitializeAI(const FString& ModelName);
};

//UAIWrapper* UAIBlueprintLibrary::InitializeAI(const FString& ModelName)
//{
//    UAIWrapper* Wrapper = NewObject<UAIWrapper>();
//    if (Wrapper)
//    {
//        if (!Wrapper->Initialize(ModelName))
//        {
//            UE_LOG(LogTemp, Error, TEXT("Failed to initialize AI with model: %s"), *ModelName);
//        }
//    }
//    return Wrapper;
//}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "AIWrapper.h"

#include "InitializeAI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIWrapperCompleted, bool, bSuccess, UAIWrapper*, Wrapper);

/**
 * Initialize the AI model with the given model name
 * @param ModelName - Name of the model directory to load
 * @return A new AI wrapper object
 */
UCLASS()
class IAMAIUNREAL_API UInitializeAI : public UBlueprintAsyncActionBase {

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", DisplayName = "Initialize AI", Category = "Iamai Core"))
	static UInitializeAI* Initialize(const FString& ModelName);

	UPROPERTY(BlueprintAssignable)
	FOnAIWrapperCompleted OnCompleted;

protected:

	virtual void Activate() override;
	FString m_modelName;

};

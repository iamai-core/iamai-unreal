// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AudioCapture.h"
#include "InamaiAudioCapture.generated.h"

/**
 *
 */
UCLASS()
class UInamaiAudioCapture : public UAudioCapture {

	GENERATED_BODY()

public:

	TArray<float> GetAudioData();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AudioMixerSubmix.h"
#include "ISubmixBufferListener.h"

#include "iamaiSubmixListener.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSubmixEnvelopeBP, float, EnvelopeValue);

/**
 *
 */
UCLASS()
class UiamaiSubmixListener : public UObject, public ISubmixBufferListener {

	GENERATED_BODY()

public:

	const TArray<float>& GetLatestAudioBuffer() const { return LatestBuffer; }

	void OnEnvelopeUpdate(float EnvelopeValue);

private:

	FString ListenerName = TEXT("iamaiSubmixListener");
	TArray<float> LatestBuffer;

	void OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock) override;


};
// Fill out your copyright notice in the Description page of Project Settings.


#include "iamaiSubmixListener.h"

void UiamaiSubmixListener::OnNewSubmixBuffer(

	const USoundSubmix* OwningSubmix,
	float* AudioData,
	int32 NumSamples,
	int32 NumChannels,
	const int32 SampleRate,
	double AudioClock)

{

	if (NumSamples <= 0 || !AudioData) return;

	const float VolumeThreshold = 0.1f;
	float RMS = 0.0f;
	for (int32 i = 0; i < NumSamples * NumChannels; ++i) RMS += FMath::Square(AudioData[i]);
	RMS = FMath::Sqrt(RMS / (NumSamples * NumChannels));

	if (RMS < VolumeThreshold) return;

	LatestBuffer.Reset(NumSamples);
	LatestBuffer.Append(AudioData, NumSamples);

}

void UiamaiSubmixListener::OnEnvelopeUpdate(float EnvelopeValue) {

	UE_LOG(LogTemp, Log, TEXT("%s: Envelope Value: %f"), *ListenerName, EnvelopeValue);

}

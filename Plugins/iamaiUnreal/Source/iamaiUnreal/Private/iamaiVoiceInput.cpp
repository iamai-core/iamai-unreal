#include "iamaiVoiceInput.h"

#include "Engine/Engine.h"
#include "Sound/SoundSubmix.h"
#include <sstream>

void UiamaiVoiceInput::BeginPlay() {
	Super::BeginPlay();

	/*
	
	SoundSubmix = NewObject<USoundSubmix>(GetTransientPackage(), USoundSubmix::StaticClass(), NAME_None, RF_Transient);
	if (!SoundSubmix) {
		UE_LOG(LogTemp, Error, TEXT("SoundSubmix is null in UIAmaiVoiceInput"));
		return;
	}

	if (bRecordOnStartup) StartCapturingAudio();

	*/

}

void UiamaiVoiceInput::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	StopCapturingAudio();

}

int32 UiamaiVoiceInput::OnGenerateAudio(float* OutAudio, int32 NumSamples) {

	int32 SamplesGenerated = Super::OnGenerateAudio(OutAudio, NumSamples);

	for (int32 i = 0; i < SamplesGenerated; ++i) m_pcmData.push_back(OutAudio[i]);

	return SamplesGenerated;

}

void UiamaiVoiceInput::StartCapturingAudio() {

	if (bIsCapturing) return;
	
	bIsCapturing = true;
	
	Start();

}

void UiamaiVoiceInput::StopCapturingAudio() {

	if (!bIsCapturing) return;

	bIsCapturing = false;
	Stop();

}
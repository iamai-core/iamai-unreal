#include "iamaiVoiceInput.h"

void UiamaiVoiceInput::BeginPlay() {
	Super::BeginPlay();

}

void UiamaiVoiceInput::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	StopCapturingAudio();

}

int32 UiamaiVoiceInput::OnGenerateAudio(float* OutAudio, int32 NumSamples) {

	int32 SamplesGenerated = Super::OnGenerateAudio(OutAudio, NumSamples);

	for (int32 i = 0; i < SamplesGenerated; i += 2) m_pcmData.push_back((OutAudio[i] + OutAudio[i + 1]) / 2.0f);

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
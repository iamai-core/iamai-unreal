#include "iamaiVoiceInput.h"

#include "Engine/Engine.h"
#include "Sound/SoundSubmix.h"

void UiamaiVoiceInput::BeginPlay() {
	Super::BeginPlay();

	SoundSubmix = NewObject<USoundSubmix>(GetTransientPackage(), USoundSubmix::StaticClass(), NAME_None, RF_Transient);
	if (!SoundSubmix) {
		UE_LOG(LogTemp, Error, TEXT("SoundSubmix is null in UIAmaiVoiceInput"));
		return;
	}

	if (bRecordOnStartup) StartCapturingAudio();

}

void UiamaiVoiceInput::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	StopCapturingAudio();

}

int32 UiamaiVoiceInput::OnGenerateAudio(float* OutAudio, int32 NumSamples) {

	int32 SamplesGenerated = Super::OnGenerateAudio(OutAudio, NumSamples);

	if (bIsCapturing) {
		
		if (EnvelopeHistory == nullptr) {

			EnvelopeHistory = new float[SamplesGenerated];
			Samples = 0;

		}

		int32 NewSamplesCount = Samples + SamplesGenerated;
		if (NewSamplesCount > Samples) {

			float* NewEnvelopeHistory = new float[NewSamplesCount];

			FMemory::Memcpy(NewEnvelopeHistory, EnvelopeHistory, Samples * sizeof(float));

			delete[] EnvelopeHistory;
			EnvelopeHistory = NewEnvelopeHistory;

		}

		FMemory::Memcpy(&EnvelopeHistory[Samples], OutAudio, SamplesGenerated * sizeof(float));
		Samples = NewSamplesCount;

	}

	return SamplesGenerated;

}

void UiamaiVoiceInput::StartCapturingAudio() {

	if (bIsCapturing) return;
	
	bIsCapturing = true;
	
	//Start();

}

void UiamaiVoiceInput::StopCapturingAudio() {

	if (!bIsCapturing) return;

	bIsCapturing = false;
	//Stop();

}
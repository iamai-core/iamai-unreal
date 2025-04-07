#include "iamaiVoiceInput.h"

#include "Engine/Engine.h"
#include "Sound/SoundSubmix.h"
#include "AudioCaptureComponent.h"
#include "AudioMixerBlueprintLibrary.h"

UiamaiVoiceInput::UiamaiVoiceInput() {

    OwnerActor = GetOwner();
    if (!OwnerActor) {
        UE_LOG(LogTemp, Warning, TEXT("OwnerActor is invalid!"));
        return;
    }

	AudioCaptureComponent = NewObject<UAudioCaptureComponent>(OwnerActor);

}

void UiamaiVoiceInput::BeginPlay() {
	Super::BeginPlay();

	if (!AudioCaptureComponent) {
		UE_LOG(LogTemp, Error, TEXT("AudioCaptureComponent is null in UIAmaiVoiceInput"));
		return;
	}

	SoundSubmix = NewObject<USoundSubmix>(GetTransientPackage(), USoundSubmix::StaticClass(), NAME_None, RF_Transient);
	if (!SoundSubmix) {
		UE_LOG(LogTemp, Error, TEXT("SoundSubmix is null in UIAmaiVoiceInput"));
		return;
	}

	AudioCaptureComponent->SoundSubmix = SoundSubmix;

	AudioCaptureComponent->RegisterComponent();
	AudioCaptureComponent->AttachToComponent(OwnerActor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	AudioCaptureComponent->SetComponentTickEnabled(true);

	OwnerActor->AddInstanceComponent(AudioCaptureComponent);
	AudioCaptureComponent->Activate();

	FScriptDelegate EnvelopeDelegate;
	EnvelopeDelegate.BindUFunction(this, FName("OnEnvelopeValue"));
	AudioCaptureComponent->OnAudioEnvelopeValue.Add(EnvelopeDelegate);

	if (bRecordOnStartup) StartCapturingAudio();

}

void UiamaiVoiceInput::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

	StopCapturingAudio();

}

void UiamaiVoiceInput::OnEnvelopeValue(const float EnvelopeValue) {
	
	EnvelopeHistory.Add(EnvelopeValue);
	UE_LOG(LogTemp, Log, TEXT("Envelope Value: %f"), EnvelopeValue);

}

void UiamaiVoiceInput::StartCapturingAudio() {

	if (!AudioCaptureComponent) return;
	if (bIsCapturing) return;
	
	bIsCapturing = true;
	EnvelopeHistory.Empty();
	AudioCaptureComponent->Start();

}

void UiamaiVoiceInput::StopCapturingAudio() {

	if (!AudioCaptureComponent) return;
	if (!bIsCapturing) return;

	bIsCapturing = false;
	AudioCaptureComponent->Stop();

}
#include "iamaiVoiceInput.h"
#include "Engine/Engine.h"
#include "Sound/SoundSubmix.h"
#include "AudioCaptureComponent.h"
#include "iamaiSubmixListener.h"  // Your listener class

UiamaiVoiceInput::UiamaiVoiceInput() {
    AudioCaptureComponent = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("AudioCaptureComponent"));
}

void UiamaiVoiceInput::BeginPlay() {
    Super::BeginPlay();

    if (!AudioCaptureComponent) {
        UE_LOG(LogTemp, Error, TEXT("AudioCaptureComponent is null in UIAmaiVoiceInput"));
        return;
    }


    Listener = NewObject<UiamaiSubmixListener>(this, UiamaiSubmixListener::StaticClass());
    SoundSubmix = NewObject<USoundSubmix>(this, USoundSubmix::StaticClass(), TEXT("iamaiSubmix"));

    if (SoundSubmix && Listener) {
        
        SoundSubmix->AddEnvelopeFollowerDelegate(Listener, &(UiamaiSubmixListener::OnEnvelopeUpdate) );

    }

    if (!AudioCaptureComponent || !SoundSubmix) return;

    AudioCaptureComponent->SoundSubmix = SoundSubmix;

    if (bRecordOnStartup) StartCapturingAudio();

}

void UiamaiVoiceInput::EndPlay(const EEndPlayReason::Type EndPlayReason) {
    Super::EndPlay(EndPlayReason);

    StopCapturingAudio();

}

void UiamaiVoiceInput::StartCapturingAudio() {

    if (!AudioCaptureComponent) return;
    AudioCaptureComponent->Start();

}

void UiamaiVoiceInput::StopCapturingAudio() {

    if (!AudioCaptureComponent) return;
    AudioCaptureComponent->Stop();

}
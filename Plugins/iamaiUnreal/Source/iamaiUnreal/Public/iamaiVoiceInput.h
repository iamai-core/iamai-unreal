#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "ISubmixBufferListener.h"

#include "iamaiVoiceInput.generated.h"

// Forward declaration of the capture component
class UAudioCaptureComponent;
class UiamaiSubmixListener;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IAMAIUNREAL_API UiamaiVoiceInput : public UActorComponent {

    GENERATED_BODY()

public:

    UiamaiVoiceInput();


    UFUNCTION(BlueprintCallable, Category = "iamai core")
    void StartCapturingAudio();

    UFUNCTION(BlueprintCallable, Category = "iamai core")
    void StopCapturingAudio();


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voice Input")
    bool bRecordOnStartup = false;

protected:

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

    UAudioCaptureComponent* AudioCaptureComponent;
    USoundSubmix* SoundSubmix;
    UiamaiSubmixListener* Listener;

};

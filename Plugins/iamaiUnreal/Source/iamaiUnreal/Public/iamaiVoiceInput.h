#pragma once

#include "CoreMinimal.h"

#ifdef PlaySound
#undef PlaySound
#endif
#include "AudioCaptureComponent.h"

#include "iamaiVoiceInput.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class IAMAIUNREAL_API UiamaiVoiceInput : public UAudioCaptureComponent {

    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "iamai core")
    void StartCapturingAudio();

    UFUNCTION(BlueprintCallable, Category = "iamai core")
    void StopCapturingAudio();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voice Input")
    bool bRecordOnStartup = false;

    float* GetAudioData() {

        return EnvelopeHistory;

	}

    const int32 GetNumSamples() {

        return Samples;

    }

protected:

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual int32 OnGenerateAudio(float* OutAudio, int32 NumSamples) override;

private:

	AActor* OwnerActor;

    float* EnvelopeHistory;
    int32 Samples;

	bool bIsCapturing = false;

};

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "AIWrapper.h"

#include "TranscribeAudio.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTextTranscribed, bool, bSuccess, const FString&, Text);

class UAudioCaptureComponent;

UCLASS()
class IAMAIUNREAL_API UTranscribeAudio : public UBlueprintAsyncActionBase {

	GENERATED_BODY()

public:

	UTranscribeAudio();

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", DisplayName = "Transcribe Audio", Category = "Iamai Core"))
	static UTranscribeAudio* Transcribe(UAIWrapper* AIWrapper, USoundWave* soundWave);

	UPROPERTY(BlueprintAssignable)
	FOnTextTranscribed OnTextTranscribed;

protected:

	virtual void Activate() override;
	UAIWrapper* m_aiWrapper = nullptr;
	USoundWave* m_soundWave = nullptr;

	UAudioCaptureComponent* m_audioCaptureComponent = nullptr;

};

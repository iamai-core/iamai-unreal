#include "InitializeAI.h"

#include "Async/Async.h"

UInitializeAI* UInitializeAI::Initialize(const FString& IamaiModel, const FString& WhisperModel) {

	UInitializeAI* Node = NewObject<UInitializeAI>();
	Node->m_iamaiModel = IamaiModel;
	Node->m_whisperModel = WhisperModel;
	return Node;

}

void UInitializeAI::Activate() {

	Async(EAsyncExecution::ThreadPool, [this]() {

		UAIWrapper* Wrapper = NewObject<UAIWrapper>();
		bool bWrapper = false;
		bool bIamaiModel = true;
		bool bWhisperModel = true;

		if (Wrapper) {

			bWrapper = true;
			if (!m_iamaiModel.IsEmpty()) bIamaiModel = Wrapper->InitializeIamai(m_iamaiModel);
			if (!m_whisperModel.IsEmpty()) bWhisperModel = Wrapper->InitializeWhisper(m_whisperModel);

		}

		Async(EAsyncExecution::TaskGraphMainThread, [this, bWrapper, bIamaiModel, bWhisperModel, Wrapper]() {

			if (!bWrapper) UE_LOG(LogTemp, Error, TEXT("Failed to create wrapper!"));
			if (!bIamaiModel) UE_LOG(LogTemp, Error, TEXT("Failed to initialize Iamai AI with model: %s"), *m_iamaiModel);
			if (!bWhisperModel) UE_LOG(LogTemp, Error, TEXT("Failed to initialize Whisper AI with model: %s"), *m_whisperModel);

			OnCompleted.Broadcast( bWrapper && bIamaiModel && bWhisperModel, (bWrapper) ? Wrapper : nullptr );

			});

		});
}

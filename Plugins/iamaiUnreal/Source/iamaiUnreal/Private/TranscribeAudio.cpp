#include "TranscribeAudio.h"

#include "iamaiVoiceInput.h"
#include "AIWrapper.h"

#include "Async/Async.h"

UTranscribeAudio::UTranscribeAudio() {

}

UTranscribeAudio* UTranscribeAudio::Transcribe(UAIWrapper* AIWrapper, UiamaiVoiceInput* iamaiVoiceInput) {

	UTranscribeAudio* Node = NewObject<UTranscribeAudio>();
	Node->m_aiWrapper = AIWrapper;
	Node->m_iamaiVoiceInput = iamaiVoiceInput;
	return Node;

}

void UTranscribeAudio::Activate() {

	if (!m_aiWrapper || !m_iamaiVoiceInput) {

		OnTextTranscribed.Broadcast(false, TEXT("Invalid inputs"));
		return;

	}

	Async(EAsyncExecution::ThreadPool, [this]() {

		float* data = m_iamaiVoiceInput->GetAudioData();
		int32 size = m_iamaiVoiceInput->GetNumSamples();
		FString TranscribedText = m_aiWrapper->Transcribe(data, size);

		Async(EAsyncExecution::TaskGraphMainThread, [this, TranscribedText]() {

			OnTextTranscribed.Broadcast(!TranscribedText.IsEmpty(), TranscribedText);
			});

		});


}


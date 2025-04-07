#include "TranscribeAudio.h"

#include "AIWrapper.h"
#include "iamaiVoiceInput.h"

#include "AudioCapture.h"

UTranscribeAudio::UTranscribeAudio() {

	UAudioCapture* audioCapture = NewObject<UAudioCapture>();
	audioCapture->StartCapturingAudio();


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

		auto data = m_iamaiVoiceInput->GetAudioData();
		auto TranscribedText = m_aiWrapper->Transcribe(data.GetData(), data.Num());

		Async(EAsyncExecution::TaskGraphMainThread, [this, TranscribedText]() {

			OnTextTranscribed.Broadcast(!TranscribedText.IsEmpty(), TranscribedText);
			});

		});


}


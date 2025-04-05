#include "TranscribeAudio.h"

#include "AudioCapture.h"

UTranscribeAudio::UTranscribeAudio() {

	UAudioCapture* audioCapture = NewObject<UAudioCapture>();
	audioCapture->StartCapturingAudio();


}

UTranscribeAudio* UTranscribeAudio::Transcribe(UAIWrapper* AIWrapper, USoundWave* soundWave) {

	UTranscribeAudio* Node = NewObject<UTranscribeAudio>();
	Node->m_aiWrapper = AIWrapper;
	Node->m_soundWave = soundWave;
	return Node;

}

void UTranscribeAudio::Activate() {

	if (!m_aiWrapper || !m_soundWave) {

		OnTextTranscribed.Broadcast(false, TEXT("Invalid inputs"));
		return;

	}
	 


	Async(EAsyncExecution::ThreadPool, [this]() {

		uint8* FloatAudio = m_soundWave->RawPCMData;
		int32 Samples = m_soundWave->RawPCMDataSize / sizeof(uint8);

		FString TranscribedText = m_aiWrapper->Transcribe((float*) FloatAudio, Samples);


		Async(EAsyncExecution::TaskGraphMainThread, [this, TranscribedText]() {
			OnTextTranscribed.Broadcast(!TranscribedText.IsEmpty(), TranscribedText);
			});

		});


}


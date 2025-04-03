// Fill out your copyright notice in the Description page of Project Settings.


#include "InitializeAI.h"
#include "iamaiUnreal.h"

UInitializeAI* UInitializeAI::Initialize(const FString& ModelName) {

	UInitializeAI* Node = NewObject<UInitializeAI>();
	Node->m_modelName = ModelName;
	return Node;

}

void UInitializeAI::Activate() {

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]() {

		UAIWrapper* Wrapper = NewObject<UAIWrapper>();

		bool bSuccess = false;
		if (Wrapper) {

			bSuccess = Wrapper->Initialize(m_modelName);

		}

		AsyncTask(ENamedThreads::GameThread, [this, bSuccess, Wrapper]() {

			if (!bSuccess) {

				UE_LOG(LogTemp, Error, TEXT("Failed to initialize AI with model: %s"), *m_modelName);
				OnCompleted.Broadcast(false, nullptr);

			} else {

				OnCompleted.Broadcast(true, Wrapper);

			}

			});

		});

}

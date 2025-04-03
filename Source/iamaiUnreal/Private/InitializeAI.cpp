#include "InitializeAI.h"

#include "iamaiUnreal.h"
#include "Async/Async.h"

UInitializeAI* UInitializeAI::Initialize(const FString& ModelName) {

    UInitializeAI* Node = NewObject<UInitializeAI>();
    Node->m_modelName = ModelName;
    return Node;

}

void UInitializeAI::Activate() {

    Async(EAsyncExecution::ThreadPool, [this]() {

        UAIWrapper* Wrapper = NewObject<UAIWrapper>();
        bool bSuccess = false;

        if (Wrapper) {

            bSuccess = Wrapper->Initialize(m_modelName);

        }

        Async(EAsyncExecution::TaskGraphMainThread, [this, bSuccess, Wrapper]() {
            
            if (!bSuccess) {

                UE_LOG(LogTemp, Error, TEXT("Failed to initialize AI with model: %s"), *m_modelName);
                OnCompleted.Broadcast(false, nullptr);

            } else {

                OnCompleted.Broadcast(true, Wrapper);

            }

            });

        });
}

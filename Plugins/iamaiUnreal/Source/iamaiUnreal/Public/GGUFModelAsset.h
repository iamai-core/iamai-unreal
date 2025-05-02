#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GGUFModelAsset.generated.h"

UCLASS()

class IAMAIUNREAL_API UGGUFModelAsset : public UObject {

    GENERATED_BODY()

public:

	virtual void BeginDestroy() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GGUF Model")
	FString FilePath;

};

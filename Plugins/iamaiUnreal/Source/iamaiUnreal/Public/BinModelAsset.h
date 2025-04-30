#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BinModelAsset.generated.h"

UCLASS()

class IAMAIUNREAL_API UBinModelAsset : public UObject {

    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Model")
    TArray<uint8> FileData;

};

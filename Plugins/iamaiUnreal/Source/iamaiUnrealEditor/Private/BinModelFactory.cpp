// Fill out your copyright notice in the Description page of Project Settings.


#include "BinModelFactory.h"
#include "BinModelAsset.h"

UBinModelFactory::UBinModelFactory() {

    bCreateNew = false;
    bEditorImport = true;
    SupportedClass = UBinModelAsset::StaticClass();
    Formats.Add(TEXT("bin;Bin AI Model"));

}

UObject* UBinModelFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) {

    UBinModelAsset* NewAsset = NewObject<UBinModelAsset>(InParent, InClass, InName, Flags);

    TArray<uint8> FileData;
    if (FFileHelper::LoadFileToArray(FileData, *Filename)) {

        NewAsset->FileData = MoveTemp(FileData);

    } else {

        UE_LOG(LogTemp, Warning, TEXT("Failed to load file: %s"), *Filename);
        bOutOperationCanceled = true;
        return nullptr;

    }

    return NewAsset;

}

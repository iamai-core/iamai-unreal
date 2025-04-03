// Copyright Epic Games, Inc. All Rights Reserved.

#include "iamaiUnrealBPLibrary.h"
#include "iamaiUnreal.h"

UiamaiUnrealBPLibrary::UiamaiUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UiamaiUnrealBPLibrary::iamaiUnrealSampleFunction(float Param)
{
	return -1;
}

bool UiamaiUnrealBPLibrary::TestFunction(float input1, float input2, FString& returnValue)
{
	returnValue = "Hello";
	return true;
}
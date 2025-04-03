// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "iamaiUnreal/Public/AIWrapper.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIWrapper() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UAIWrapper();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UAIWrapper_NoRegister();
UPackage* Z_Construct_UPackage__Script_iamaiUnreal();
// End Cross Module References

// Begin Class UAIWrapper Function SetBatchSize
struct Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics
{
	struct AIWrapper_eventSetBatchSize_Parms
	{
		int32 BatchSize;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "iamai AI" },
		{ "Comment", "/**\n\x09 * Set the batch size for generation\n\x09 * @param BatchSize - Batch size\n\x09 */" },
		{ "ModuleRelativePath", "Public/AIWrapper.h" },
		{ "ToolTip", "Set the batch size for generation\n@param BatchSize - Batch size" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_BatchSize;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::NewProp_BatchSize = { "BatchSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIWrapper_eventSetBatchSize_Parms, BatchSize), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::NewProp_BatchSize,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAIWrapper, nullptr, "SetBatchSize", nullptr, nullptr, Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::AIWrapper_eventSetBatchSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::AIWrapper_eventSetBatchSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAIWrapper_SetBatchSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAIWrapper_SetBatchSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAIWrapper::execSetBatchSize)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_BatchSize);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBatchSize(Z_Param_BatchSize);
	P_NATIVE_END;
}
// End Class UAIWrapper Function SetBatchSize

// Begin Class UAIWrapper Function SetMaxTokens
struct Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics
{
	struct AIWrapper_eventSetMaxTokens_Parms
	{
		int32 MaxTokens;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "iamai AI" },
		{ "Comment", "/**\n\x09 * Set the maximum number of tokens to generate\n\x09 * @param MaxTokens - Maximum number of tokens\n\x09 */" },
		{ "ModuleRelativePath", "Public/AIWrapper.h" },
		{ "ToolTip", "Set the maximum number of tokens to generate\n@param MaxTokens - Maximum number of tokens" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxTokens;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::NewProp_MaxTokens = { "MaxTokens", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIWrapper_eventSetMaxTokens_Parms, MaxTokens), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::NewProp_MaxTokens,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAIWrapper, nullptr, "SetMaxTokens", nullptr, nullptr, Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::AIWrapper_eventSetMaxTokens_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::AIWrapper_eventSetMaxTokens_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAIWrapper_SetMaxTokens()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAIWrapper_SetMaxTokens_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAIWrapper::execSetMaxTokens)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxTokens);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxTokens(Z_Param_MaxTokens);
	P_NATIVE_END;
}
// End Class UAIWrapper Function SetMaxTokens

// Begin Class UAIWrapper Function SetThreads
struct Z_Construct_UFunction_UAIWrapper_SetThreads_Statics
{
	struct AIWrapper_eventSetThreads_Parms
	{
		int32 NumThreads;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "iamai AI" },
		{ "Comment", "/**\n\x09 * Set the number of threads to use\n\x09 * @param NumThreads - Number of threads\n\x09 */" },
		{ "ModuleRelativePath", "Public/AIWrapper.h" },
		{ "ToolTip", "Set the number of threads to use\n@param NumThreads - Number of threads" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumThreads;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::NewProp_NumThreads = { "NumThreads", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AIWrapper_eventSetThreads_Parms, NumThreads), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::NewProp_NumThreads,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAIWrapper, nullptr, "SetThreads", nullptr, nullptr, Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::AIWrapper_eventSetThreads_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::AIWrapper_eventSetThreads_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAIWrapper_SetThreads()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAIWrapper_SetThreads_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAIWrapper::execSetThreads)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumThreads);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetThreads(Z_Param_NumThreads);
	P_NATIVE_END;
}
// End Class UAIWrapper Function SetThreads

// Begin Class UAIWrapper
void UAIWrapper::StaticRegisterNativesUAIWrapper()
{
	UClass* Class = UAIWrapper::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetBatchSize", &UAIWrapper::execSetBatchSize },
		{ "SetMaxTokens", &UAIWrapper::execSetMaxTokens },
		{ "SetThreads", &UAIWrapper::execSetThreads },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAIWrapper);
UClass* Z_Construct_UClass_UAIWrapper_NoRegister()
{
	return UAIWrapper::StaticClass();
}
struct Z_Construct_UClass_UAIWrapper_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Blueprint-friendly wrapper for the AI class\n */" },
		{ "IncludePath", "AIWrapper.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/AIWrapper.h" },
		{ "ToolTip", "Blueprint-friendly wrapper for the AI class" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAIWrapper_SetBatchSize, "SetBatchSize" }, // 2007031066
		{ &Z_Construct_UFunction_UAIWrapper_SetMaxTokens, "SetMaxTokens" }, // 2015143022
		{ &Z_Construct_UFunction_UAIWrapper_SetThreads, "SetThreads" }, // 4289937744
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAIWrapper>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAIWrapper_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_iamaiUnreal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAIWrapper_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAIWrapper_Statics::ClassParams = {
	&UAIWrapper::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAIWrapper_Statics::Class_MetaDataParams), Z_Construct_UClass_UAIWrapper_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAIWrapper()
{
	if (!Z_Registration_Info_UClass_UAIWrapper.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAIWrapper.OuterSingleton, Z_Construct_UClass_UAIWrapper_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAIWrapper.OuterSingleton;
}
template<> IAMAIUNREAL_API UClass* StaticClass<UAIWrapper>()
{
	return UAIWrapper::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAIWrapper);
// End Class UAIWrapper

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_AIWrapper_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAIWrapper, UAIWrapper::StaticClass, TEXT("UAIWrapper"), &Z_Registration_Info_UClass_UAIWrapper, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAIWrapper), 3210240442U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_AIWrapper_h_3583414767(TEXT("/Script/iamaiUnreal"),
	Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_AIWrapper_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_AIWrapper_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

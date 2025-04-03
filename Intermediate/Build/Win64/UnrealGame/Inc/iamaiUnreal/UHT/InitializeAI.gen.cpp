// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "iamaiUnreal/Public/InitializeAI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInitializeAI() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UAIWrapper_NoRegister();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UInitializeAI();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UInitializeAI_NoRegister();
IAMAIUNREAL_API UFunction* Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_iamaiUnreal();
// End Cross Module References

// Begin Delegate FOnAIWrapperCompleted
struct Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics
{
	struct _Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms
	{
		bool bSuccess;
		UAIWrapper* Wrapper;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InitializeAI.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Wrapper;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms), &Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_Wrapper = { "Wrapper", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms, Wrapper), Z_Construct_UClass_UAIWrapper_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::NewProp_Wrapper,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_iamaiUnreal, nullptr, "OnAIWrapperCompleted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAIWrapperCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnAIWrapperCompleted, bool bSuccess, UAIWrapper* Wrapper)
{
	struct _Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms
	{
		bool bSuccess;
		UAIWrapper* Wrapper;
	};
	_Script_iamaiUnreal_eventOnAIWrapperCompleted_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Wrapper=Wrapper;
	OnAIWrapperCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnAIWrapperCompleted

// Begin Class UInitializeAI Function Initialize
struct Z_Construct_UFunction_UInitializeAI_Initialize_Statics
{
	struct InitializeAI_eventInitialize_Parms
	{
		FString ModelName;
		UInitializeAI* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Iamai Core" },
		{ "DisplayName", "Initialize AI" },
		{ "ModuleRelativePath", "Public/InitializeAI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModelName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ModelName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInitializeAI_Initialize_Statics::NewProp_ModelName = { "ModelName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitializeAI_eventInitialize_Parms, ModelName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModelName_MetaData), NewProp_ModelName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInitializeAI_Initialize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InitializeAI_eventInitialize_Parms, ReturnValue), Z_Construct_UClass_UInitializeAI_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInitializeAI_Initialize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitializeAI_Initialize_Statics::NewProp_ModelName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInitializeAI_Initialize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInitializeAI_Initialize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInitializeAI_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInitializeAI, nullptr, "Initialize", nullptr, nullptr, Z_Construct_UFunction_UInitializeAI_Initialize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInitializeAI_Initialize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UInitializeAI_Initialize_Statics::InitializeAI_eventInitialize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInitializeAI_Initialize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInitializeAI_Initialize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UInitializeAI_Initialize_Statics::InitializeAI_eventInitialize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInitializeAI_Initialize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInitializeAI_Initialize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInitializeAI::execInitialize)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ModelName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInitializeAI**)Z_Param__Result=UInitializeAI::Initialize(Z_Param_ModelName);
	P_NATIVE_END;
}
// End Class UInitializeAI Function Initialize

// Begin Class UInitializeAI
void UInitializeAI::StaticRegisterNativesUInitializeAI()
{
	UClass* Class = UInitializeAI::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Initialize", &UInitializeAI::execInitialize },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInitializeAI);
UClass* Z_Construct_UClass_UInitializeAI_NoRegister()
{
	return UInitializeAI::StaticClass();
}
struct Z_Construct_UClass_UInitializeAI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Initialize the AI model with the given model name\n * @param ModelName - Name of the model directory to load\n * @return A new AI wrapper object\n */" },
		{ "IncludePath", "InitializeAI.h" },
		{ "ModuleRelativePath", "Public/InitializeAI.h" },
		{ "ToolTip", "Initialize the AI model with the given model name\n@param ModelName - Name of the model directory to load\n@return A new AI wrapper object" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "ModuleRelativePath", "Public/InitializeAI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInitializeAI_Initialize, "Initialize" }, // 3251945970
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInitializeAI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInitializeAI_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInitializeAI, OnCompleted), Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 4235854277
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInitializeAI_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInitializeAI_Statics::NewProp_OnCompleted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInitializeAI_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInitializeAI_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_iamaiUnreal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInitializeAI_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInitializeAI_Statics::ClassParams = {
	&UInitializeAI::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInitializeAI_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInitializeAI_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInitializeAI_Statics::Class_MetaDataParams), Z_Construct_UClass_UInitializeAI_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInitializeAI()
{
	if (!Z_Registration_Info_UClass_UInitializeAI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInitializeAI.OuterSingleton, Z_Construct_UClass_UInitializeAI_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInitializeAI.OuterSingleton;
}
template<> IAMAIUNREAL_API UClass* StaticClass<UInitializeAI>()
{
	return UInitializeAI::StaticClass();
}
UInitializeAI::UInitializeAI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInitializeAI);
UInitializeAI::~UInitializeAI() {}
// End Class UInitializeAI

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInitializeAI, UInitializeAI::StaticClass, TEXT("UInitializeAI"), &Z_Registration_Info_UClass_UInitializeAI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInitializeAI), 3490024722U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_4163009053(TEXT("/Script/iamaiUnreal"),
	Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

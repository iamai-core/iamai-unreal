// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "iamaiUnreal/Public/iamaiUnrealBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeiamaiUnrealBPLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UiamaiUnrealBPLibrary();
IAMAIUNREAL_API UClass* Z_Construct_UClass_UiamaiUnrealBPLibrary_NoRegister();
UPackage* Z_Construct_UPackage__Script_iamaiUnreal();
// End Cross Module References

// Begin Class UiamaiUnrealBPLibrary Function iamaiUnrealSampleFunction
struct Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics
{
	struct iamaiUnrealBPLibrary_eventiamaiUnrealSampleFunction_Parms
	{
		float Param;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "iamaiUnrealTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "iamaiUnreal sample test testing" },
		{ "ModuleRelativePath", "Public/iamaiUnrealBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(iamaiUnrealBPLibrary_eventiamaiUnrealSampleFunction_Parms, Param), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(iamaiUnrealBPLibrary_eventiamaiUnrealSampleFunction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::NewProp_Param,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UiamaiUnrealBPLibrary, nullptr, "iamaiUnrealSampleFunction", nullptr, nullptr, Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::iamaiUnrealBPLibrary_eventiamaiUnrealSampleFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::iamaiUnrealBPLibrary_eventiamaiUnrealSampleFunction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UiamaiUnrealBPLibrary::execiamaiUnrealSampleFunction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UiamaiUnrealBPLibrary::iamaiUnrealSampleFunction(Z_Param_Param);
	P_NATIVE_END;
}
// End Class UiamaiUnrealBPLibrary Function iamaiUnrealSampleFunction

// Begin Class UiamaiUnrealBPLibrary Function TestFunction
struct Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics
{
	struct iamaiUnrealBPLibrary_eventTestFunction_Parms
	{
		float input1;
		float input2;
		FString returnValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "iamaiUnrealTesting" },
		{ "DisplayName", "Execute Test function" },
		{ "Keywords", "iamaiUnreal testing" },
		{ "ModuleRelativePath", "Public/iamaiUnrealBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_input1;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_input2;
	static const UECodeGen_Private::FStrPropertyParams NewProp_returnValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_input1 = { "input1", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(iamaiUnrealBPLibrary_eventTestFunction_Parms, input1), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_input2 = { "input2", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(iamaiUnrealBPLibrary_eventTestFunction_Parms, input2), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_returnValue = { "returnValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(iamaiUnrealBPLibrary_eventTestFunction_Parms, returnValue), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((iamaiUnrealBPLibrary_eventTestFunction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(iamaiUnrealBPLibrary_eventTestFunction_Parms), &Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_input1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_input2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_returnValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UiamaiUnrealBPLibrary, nullptr, "TestFunction", nullptr, nullptr, Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::iamaiUnrealBPLibrary_eventTestFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::iamaiUnrealBPLibrary_eventTestFunction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UiamaiUnrealBPLibrary::execTestFunction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_input1);
	P_GET_PROPERTY(FFloatProperty,Z_Param_input2);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_returnValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UiamaiUnrealBPLibrary::TestFunction(Z_Param_input1,Z_Param_input2,Z_Param_Out_returnValue);
	P_NATIVE_END;
}
// End Class UiamaiUnrealBPLibrary Function TestFunction

// Begin Class UiamaiUnrealBPLibrary
void UiamaiUnrealBPLibrary::StaticRegisterNativesUiamaiUnrealBPLibrary()
{
	UClass* Class = UiamaiUnrealBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "iamaiUnrealSampleFunction", &UiamaiUnrealBPLibrary::execiamaiUnrealSampleFunction },
		{ "TestFunction", &UiamaiUnrealBPLibrary::execTestFunction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UiamaiUnrealBPLibrary);
UClass* Z_Construct_UClass_UiamaiUnrealBPLibrary_NoRegister()
{
	return UiamaiUnrealBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "iamaiUnrealBPLibrary.h" },
		{ "ModuleRelativePath", "Public/iamaiUnrealBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UiamaiUnrealBPLibrary_iamaiUnrealSampleFunction, "iamaiUnrealSampleFunction" }, // 3863119278
		{ &Z_Construct_UFunction_UiamaiUnrealBPLibrary_TestFunction, "TestFunction" }, // 1365562221
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UiamaiUnrealBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_iamaiUnreal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::ClassParams = {
	&UiamaiUnrealBPLibrary::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UiamaiUnrealBPLibrary()
{
	if (!Z_Registration_Info_UClass_UiamaiUnrealBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UiamaiUnrealBPLibrary.OuterSingleton, Z_Construct_UClass_UiamaiUnrealBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UiamaiUnrealBPLibrary.OuterSingleton;
}
template<> IAMAIUNREAL_API UClass* StaticClass<UiamaiUnrealBPLibrary>()
{
	return UiamaiUnrealBPLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UiamaiUnrealBPLibrary);
UiamaiUnrealBPLibrary::~UiamaiUnrealBPLibrary() {}
// End Class UiamaiUnrealBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_iamaiUnrealBPLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UiamaiUnrealBPLibrary, UiamaiUnrealBPLibrary::StaticClass, TEXT("UiamaiUnrealBPLibrary"), &Z_Registration_Info_UClass_UiamaiUnrealBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UiamaiUnrealBPLibrary), 1608657624U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_iamaiUnrealBPLibrary_h_1308251000(TEXT("/Script/iamaiUnreal"),
	Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_iamaiUnrealBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_iamaiUnrealBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeiamaiUnreal_init() {}
	IAMAIUNREAL_API UFunction* Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature();
	IAMAIUNREAL_API UFunction* Z_Construct_UDelegateFunction_iamaiUnreal_OnTextGenCompleted__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_iamaiUnreal;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_iamaiUnreal()
	{
		if (!Z_Registration_Info_UPackage__Script_iamaiUnreal.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_iamaiUnreal_OnAIWrapperCompleted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_iamaiUnreal_OnTextGenCompleted__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/iamaiUnreal",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xE0BE75A5,
				0xCD4D8A98,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_iamaiUnreal.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_iamaiUnreal.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_iamaiUnreal(Z_Construct_UPackage__Script_iamaiUnreal, TEXT("/Script/iamaiUnreal"), Z_Registration_Info_UPackage__Script_iamaiUnreal, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE0BE75A5, 0xCD4D8A98));
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InitializeAI.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAIWrapper;
class UInitializeAI;
#ifdef IAMAIUNREAL_InitializeAI_generated_h
#error "InitializeAI.generated.h already included, missing '#pragma once' in InitializeAI.h"
#endif
#define IAMAIUNREAL_InitializeAI_generated_h

#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_12_DELEGATE \
IAMAIUNREAL_API void FOnAIWrapperCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnAIWrapperCompleted, bool bSuccess, UAIWrapper* Wrapper);


#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execInitialize);


#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInitializeAI(); \
	friend struct Z_Construct_UClass_UInitializeAI_Statics; \
public: \
	DECLARE_CLASS(UInitializeAI, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/iamaiUnreal"), NO_API) \
	DECLARE_SERIALIZER(UInitializeAI)


#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInitializeAI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UInitializeAI(UInitializeAI&&); \
	UInitializeAI(const UInitializeAI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInitializeAI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInitializeAI); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInitializeAI) \
	NO_API virtual ~UInitializeAI();


#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_19_PROLOG
#define FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_INCLASS_NO_PURE_DECLS \
	FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IAMAIUNREAL_API UClass* StaticClass<class UInitializeAI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Collin_Documents_Repos_iamai_unreal_plugin_iamaiUnreal_HostProject_Plugins_iamaiUnreal_Source_iamaiUnreal_Public_InitializeAI_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

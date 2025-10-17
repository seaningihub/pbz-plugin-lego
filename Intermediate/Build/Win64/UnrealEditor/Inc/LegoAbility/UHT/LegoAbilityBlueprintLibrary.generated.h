// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbilityBlueprintLibrary.h"

#ifdef LEGOABILITY_LegoAbilityBlueprintLibrary_generated_h
#error "LegoAbilityBlueprintLibrary.generated.h already included, missing '#pragma once' in LegoAbilityBlueprintLibrary.h"
#endif
#define LEGOABILITY_LegoAbilityBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class ULGATimeline;
struct FGameplayAbilityTargetDataHandle;
struct FGameplayEventData;
struct FHitResult;
struct FLGAActionExecutionContextHandle;

// ********** Begin Class ULegoAbilityBlueprintLibrary *********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSampleSocketTransformFromTimeline); \
	DECLARE_FUNCTION(execActionContextFromGameplayEvent); \
	DECLARE_FUNCTION(execActionContextFromTargetData); \
	DECLARE_FUNCTION(execActionContextFromActors); \
	DECLARE_FUNCTION(execActionContextFromActor); \
	DECLARE_FUNCTION(execActionContextFromHitResults); \
	DECLARE_FUNCTION(execActionContextFromHitResult); \
	DECLARE_FUNCTION(execGetGameplayEventDataFromActionContext); \
	DECLARE_FUNCTION(execGetTargetDataFromActionContext); \
	DECLARE_FUNCTION(execGetAllActorsFromActionContext);


LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULegoAbilityBlueprintLibrary(); \
	friend struct Z_Construct_UClass_ULegoAbilityBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbilityBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULegoAbilityBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbilityBlueprintLibrary)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULegoAbilityBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbilityBlueprintLibrary(ULegoAbilityBlueprintLibrary&&) = delete; \
	ULegoAbilityBlueprintLibrary(const ULegoAbilityBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULegoAbilityBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbilityBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULegoAbilityBlueprintLibrary) \
	NO_API virtual ~ULegoAbilityBlueprintLibrary();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_13_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbilityBlueprintLibrary;

// ********** End Class ULegoAbilityBlueprintLibrary ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LegoAbilityTypes.h"

#ifdef LEGOABILITY_LegoAbilityTypes_generated_h
#error "LegoAbilityTypes.generated.h already included, missing '#pragma once' in LegoAbilityTypes.h"
#endif
#define LEGOABILITY_LegoAbilityTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FGameplayEventTag *************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGameplayEventTag_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGameplayEventTag;
// ********** End ScriptStruct FGameplayEventTag ***************************************************

// ********** Begin Interface ULegoAbilityPreviewInterface *****************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void PostPreviewActorCreated_Implementation() {}; \
	DECLARE_FUNCTION(execPostPreviewActorCreated);


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_CALLBACK_WRAPPERS
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	LEGOABILITY_API ULegoAbilityPreviewInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULegoAbilityPreviewInterface(ULegoAbilityPreviewInterface&&) = delete; \
	ULegoAbilityPreviewInterface(const ULegoAbilityPreviewInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(LEGOABILITY_API, ULegoAbilityPreviewInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULegoAbilityPreviewInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULegoAbilityPreviewInterface) \
	virtual ~ULegoAbilityPreviewInterface() = default;


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesULegoAbilityPreviewInterface(); \
	friend struct Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(ULegoAbilityPreviewInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULegoAbilityPreviewInterface_NoRegister) \
	DECLARE_SERIALIZER(ULegoAbilityPreviewInterface)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_GENERATED_UINTERFACE_BODY() \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ILegoAbilityPreviewInterface() {} \
public: \
	typedef ULegoAbilityPreviewInterface UClassType; \
	typedef ILegoAbilityPreviewInterface ThisClass; \
	static void Execute_PostPreviewActorCreated(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_27_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_30_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULegoAbilityPreviewInterface;

// ********** End Interface ULegoAbilityPreviewInterface *******************************************

// ********** Begin ScriptStruct FLegoCameraShakePreviewerAddParams ********************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h_50_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics; \
	static class UScriptStruct* StaticStruct();


struct FLegoCameraShakePreviewerAddParams;
// ********** End ScriptStruct FLegoCameraShakePreviewerAddParams **********************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

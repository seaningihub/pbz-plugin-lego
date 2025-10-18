// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/LGAAction_PlayMontage_Base.h"

#ifdef LEGOABILITY_LGAAction_PlayMontage_Base_generated_h
#error "LGAAction_PlayMontage_Base.generated.h already included, missing '#pragma once' in LGAAction_PlayMontage_Base.h"
#endif
#define LEGOABILITY_LGAAction_PlayMontage_Base_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UAnimInstance;
class UAnimMontage;
class UGameplayAbility;

// ********** Begin Class ULGAAction_PlayMontage_Base **********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual UAnimInstance* GetAnimInstance_Implementation(AActor* PreviewActor); \
	DECLARE_FUNCTION(execOnAbilityEnded); \
	DECLARE_FUNCTION(execOnMontageCompleted); \
	DECLARE_FUNCTION(execOnMontageBlendOut); \
	DECLARE_FUNCTION(execGetAnimInstance);


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_CALLBACK_WRAPPERS
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGAAction_PlayMontage_Base(); \
	friend struct Z_Construct_UClass_ULGAAction_PlayMontage_Base_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_Base_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGAAction_PlayMontage_Base, ULGAAction, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGAAction_PlayMontage_Base_NoRegister) \
	DECLARE_SERIALIZER(ULGAAction_PlayMontage_Base)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGAAction_PlayMontage_Base(ULGAAction_PlayMontage_Base&&) = delete; \
	ULGAAction_PlayMontage_Base(const ULGAAction_PlayMontage_Base&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGAAction_PlayMontage_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGAAction_PlayMontage_Base); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ULGAAction_PlayMontage_Base) \
	NO_API virtual ~ULGAAction_PlayMontage_Base();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_13_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGAAction_PlayMontage_Base;

// ********** End Class ULGAAction_PlayMontage_Base ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_Base_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

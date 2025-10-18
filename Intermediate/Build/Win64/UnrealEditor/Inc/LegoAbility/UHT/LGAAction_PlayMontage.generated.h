// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/LGAAction_PlayMontage.h"

#ifdef LEGOABILITY_LGAAction_PlayMontage_generated_h
#error "LGAAction_PlayMontage.generated.h already included, missing '#pragma once' in LGAAction_PlayMontage.h"
#endif
#define LEGOABILITY_LGAAction_PlayMontage_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UAnimMontage;
class UGameplayAbility;

// ********** Begin Class ULGAAction_PlayMontage ***************************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAbilityEnded); \
	DECLARE_FUNCTION(execOnMontageCompleted); \
	DECLARE_FUNCTION(execOnMontageBlendOut);


LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGAAction_PlayMontage(); \
	friend struct Z_Construct_UClass_ULGAAction_PlayMontage_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_PlayMontage_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGAAction_PlayMontage, ULGAAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGAAction_PlayMontage_NoRegister) \
	DECLARE_SERIALIZER(ULGAAction_PlayMontage)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGAAction_PlayMontage(ULGAAction_PlayMontage&&) = delete; \
	ULGAAction_PlayMontage(const ULGAAction_PlayMontage&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGAAction_PlayMontage); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGAAction_PlayMontage); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULGAAction_PlayMontage) \
	NO_API virtual ~ULGAAction_PlayMontage();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_13_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGAAction_PlayMontage;

// ********** End Class ULGAAction_PlayMontage *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_PlayMontage_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

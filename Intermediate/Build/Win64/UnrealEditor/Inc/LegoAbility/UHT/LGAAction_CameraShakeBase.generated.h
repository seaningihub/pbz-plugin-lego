// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actions/LGAAction_CameraShakeBase.h"

#ifdef LEGOABILITY_LGAAction_CameraShakeBase_generated_h
#error "LGAAction_CameraShakeBase.generated.h already included, missing '#pragma once' in LGAAction_CameraShakeBase.h"
#endif
#define LEGOABILITY_LGAAction_CameraShakeBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UCameraShakeBase;
struct FLegoCameraShakePreviewerAddParams;

// ********** Begin Class ULGAAction_CameraShakeBase ***********************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCameraShakeDuration); \
	DECLARE_FUNCTION(execRemoveCameraShake); \
	DECLARE_FUNCTION(execAddCameraShake);


LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGAAction_CameraShakeBase(); \
	friend struct Z_Construct_UClass_ULGAAction_CameraShakeBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_CameraShakeBase_NoRegister(); \
public: \
	DECLARE_CLASS2(ULGAAction_CameraShakeBase, ULGAAction_Executable, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_ULGAAction_CameraShakeBase_NoRegister) \
	DECLARE_SERIALIZER(ULGAAction_CameraShakeBase)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULGAAction_CameraShakeBase(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ULGAAction_CameraShakeBase(ULGAAction_CameraShakeBase&&) = delete; \
	ULGAAction_CameraShakeBase(const ULGAAction_CameraShakeBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGAAction_CameraShakeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGAAction_CameraShakeBase); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ULGAAction_CameraShakeBase) \
	NO_API virtual ~ULGAAction_CameraShakeBase();


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_13_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ULGAAction_CameraShakeBase;

// ********** End Class ULGAAction_CameraShakeBase *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_CameraShakeBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

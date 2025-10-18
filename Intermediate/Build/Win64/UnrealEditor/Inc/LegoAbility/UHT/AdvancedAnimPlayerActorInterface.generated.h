// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interface/AdvancedAnimPlayerActorInterface.h"

#ifdef LEGOABILITY_AdvancedAnimPlayerActorInterface_generated_h
#error "AdvancedAnimPlayerActorInterface.generated.h already included, missing '#pragma once' in AdvancedAnimPlayerActorInterface.h"
#endif
#define LEGOABILITY_AdvancedAnimPlayerActorInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface UAdvancedAnimPlayerActorInterface ************************************
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void SetDisableSliding_Implementation(bool DisableSliding) {}; \
	DECLARE_FUNCTION(execSetDisableSliding);


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_CALLBACK_WRAPPERS
LEGOABILITY_API UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_NoRegister();

#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAdvancedAnimPlayerActorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAdvancedAnimPlayerActorInterface(UAdvancedAnimPlayerActorInterface&&) = delete; \
	UAdvancedAnimPlayerActorInterface(const UAdvancedAnimPlayerActorInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAdvancedAnimPlayerActorInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAdvancedAnimPlayerActorInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAdvancedAnimPlayerActorInterface) \
	virtual ~UAdvancedAnimPlayerActorInterface() = default;


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUAdvancedAnimPlayerActorInterface(); \
	friend struct Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend LEGOABILITY_API UClass* Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UAdvancedAnimPlayerActorInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/LegoAbility"), Z_Construct_UClass_UAdvancedAnimPlayerActorInterface_NoRegister) \
	DECLARE_SERIALIZER(UAdvancedAnimPlayerActorInterface)


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IAdvancedAnimPlayerActorInterface() {} \
public: \
	typedef UAdvancedAnimPlayerActorInterface UClassType; \
	typedef IAdvancedAnimPlayerActorInterface ThisClass; \
	static void Execute_SetDisableSliding(UObject* O, bool DisableSliding); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_8_PROLOG
#define FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAdvancedAnimPlayerActorInterface;

// ********** End Interface UAdvancedAnimPlayerActorInterface **************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Interface_AdvancedAnimPlayerActorInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

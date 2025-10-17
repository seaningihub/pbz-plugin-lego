// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction_MotionWarping_Base.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction_MotionWarping_Base() {}

// ********** Begin Cross Module References ********************************************************
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_MotionWarping_Base();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_MotionWarping_Base_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULGAAction_MotionWarping_Base ********************************************
void ULGAAction_MotionWarping_Base::StaticRegisterNativesULGAAction_MotionWarping_Base()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base;
UClass* ULGAAction_MotionWarping_Base::GetPrivateStaticClass()
{
	using TClass = ULGAAction_MotionWarping_Base;
	if (!Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction_MotionWarping_Base"),
			Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.InnerSingleton,
			StaticRegisterNativesULGAAction_MotionWarping_Base,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_MotionWarping_Base_NoRegister()
{
	return ULGAAction_MotionWarping_Base::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Motions Warping Base" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction_MotionWarping_Base.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction_MotionWarping_Base.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction_MotionWarping_Base>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULGAAction,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::ClassParams = {
	&ULGAAction_MotionWarping_Base::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001020A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction_MotionWarping_Base()
{
	if (!Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.OuterSingleton, Z_Construct_UClass_ULGAAction_MotionWarping_Base_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction_MotionWarping_Base);
ULGAAction_MotionWarping_Base::~ULGAAction_MotionWarping_Base() {}
// ********** End Class ULGAAction_MotionWarping_Base **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_MotionWarping_Base_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction_MotionWarping_Base, ULGAAction_MotionWarping_Base::StaticClass, TEXT("ULGAAction_MotionWarping_Base"), &Z_Registration_Info_UClass_ULGAAction_MotionWarping_Base, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction_MotionWarping_Base), 803394152U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_MotionWarping_Base_h__Script_LegoAbility_3077748117(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_MotionWarping_Base_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_MotionWarping_Base_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilitySystemComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilitySystemComponent() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilitySystemComponent();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULegoAbilitySystemComponent **********************************************
void ULegoAbilitySystemComponent::StaticRegisterNativesULegoAbilitySystemComponent()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilitySystemComponent;
UClass* ULegoAbilitySystemComponent::GetPrivateStaticClass()
{
	using TClass = ULegoAbilitySystemComponent;
	if (!Z_Registration_Info_UClass_ULegoAbilitySystemComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilitySystemComponent"),
			Z_Registration_Info_UClass_ULegoAbilitySystemComponent.InnerSingleton,
			StaticRegisterNativesULegoAbilitySystemComponent,
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
	return Z_Registration_Info_UClass_ULegoAbilitySystemComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilitySystemComponent_NoRegister()
{
	return ULegoAbilitySystemComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilitySystemComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object LOD Lighting Transform Sockets TextureStreaming Object LOD Lighting Transform Sockets TextureStreaming" },
		{ "IncludePath", "LegoAbilitySystemComponent.h" },
		{ "ModuleRelativePath", "Public/LegoAbilitySystemComponent.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilitySystemComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAbilitySystemComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::ClassParams = {
	&ULegoAbilitySystemComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilitySystemComponent()
{
	if (!Z_Registration_Info_UClass_ULegoAbilitySystemComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilitySystemComponent.OuterSingleton, Z_Construct_UClass_ULegoAbilitySystemComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilitySystemComponent.OuterSingleton;
}
ULegoAbilitySystemComponent::ULegoAbilitySystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilitySystemComponent);
ULegoAbilitySystemComponent::~ULegoAbilitySystemComponent() {}
// ********** End Class ULegoAbilitySystemComponent ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilitySystemComponent_h__Script_LegoAbility_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilitySystemComponent, ULegoAbilitySystemComponent::StaticClass, TEXT("ULegoAbilitySystemComponent"), &Z_Registration_Info_UClass_ULegoAbilitySystemComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilitySystemComponent), 671573171U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilitySystemComponent_h__Script_LegoAbility_3992453437(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilitySystemComponent_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilitySystemComponent_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

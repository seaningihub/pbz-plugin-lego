// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityBlueprintFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityBlueprintFactory() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_EBlueprintType();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintFactory();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityBlueprintFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_LegoAbilityEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULegoAbilityBlueprintFactory *********************************************
void ULegoAbilityBlueprintFactory::StaticRegisterNativesULegoAbilityBlueprintFactory()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory;
UClass* ULegoAbilityBlueprintFactory::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityBlueprintFactory;
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityBlueprintFactory"),
			Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.InnerSingleton,
			StaticRegisterNativesULegoAbilityBlueprintFactory,
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
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityBlueprintFactory_NoRegister()
{
	return ULegoAbilityBlueprintFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/* Factory for Ability Blueprints. */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "LegoAbilityBlueprintFactory.h" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Factory for Ability Blueprints." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlueprintType_MetaData[] = {
		{ "Category", "LegoAbilityBlueprintFactory" },
		{ "Comment", "// The type of blueprint that will be created\n" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintFactory.h" },
		{ "ToolTip", "The type of blueprint that will be created" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentClass_MetaData[] = {
		{ "Category", "LegoAbilityBlueprintFactory" },
		{ "Comment", "// The parent class of the created blueprint\n" },
		{ "ModuleRelativePath", "Public/LegoAbilityBlueprintFactory.h" },
		{ "ToolTip", "The parent class of the created blueprint" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BlueprintType;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ParentClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityBlueprintFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::NewProp_BlueprintType = { "BlueprintType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprintFactory, BlueprintType), Z_Construct_UEnum_Engine_EBlueprintType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlueprintType_MetaData), NewProp_BlueprintType_MetaData) }; // 3915063642
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::NewProp_ParentClass = { "ParentClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityBlueprintFactory, ParentClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULegoAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentClass_MetaData), NewProp_ParentClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::NewProp_BlueprintType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::NewProp_ParentClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::ClassParams = {
	&ULegoAbilityBlueprintFactory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityBlueprintFactory()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.OuterSingleton, Z_Construct_UClass_ULegoAbilityBlueprintFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityBlueprintFactory);
// ********** End Class ULegoAbilityBlueprintFactory ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprintFactory_h__Script_LegoAbilityEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityBlueprintFactory, ULegoAbilityBlueprintFactory::StaticClass, TEXT("ULegoAbilityBlueprintFactory"), &Z_Registration_Info_UClass_ULegoAbilityBlueprintFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityBlueprintFactory), 2547703706U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprintFactory_h__Script_LegoAbilityEditor_3042319155(TEXT("/Script/LegoAbilityEditor"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprintFactory_h__Script_LegoAbilityEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Public_LegoAbilityBlueprintFactory_h__Script_LegoAbilityEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

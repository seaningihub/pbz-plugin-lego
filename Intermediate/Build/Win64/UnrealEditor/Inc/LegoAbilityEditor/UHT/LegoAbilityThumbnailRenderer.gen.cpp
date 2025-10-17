// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityThumbnailRenderer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityThumbnailRenderer() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityThumbnailRenderer();
LEGOABILITYEDITOR_API UClass* Z_Construct_UClass_ULegoAbilityThumbnailRenderer_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UDefaultSizedThumbnailRenderer();
UPackage* Z_Construct_UPackage__Script_LegoAbilityEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ULegoAbilityThumbnailRenderer ********************************************
void ULegoAbilityThumbnailRenderer::StaticRegisterNativesULegoAbilityThumbnailRenderer()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer;
UClass* ULegoAbilityThumbnailRenderer::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityThumbnailRenderer;
	if (!Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityThumbnailRenderer"),
			Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.InnerSingleton,
			StaticRegisterNativesULegoAbilityThumbnailRenderer,
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
	return Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityThumbnailRenderer_NoRegister()
{
	return ULegoAbilityThumbnailRenderer::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/* Simple class that renders a user-captured thumbnail for our Abilities. */" },
		{ "IncludePath", "LegoAbilityThumbnailRenderer.h" },
		{ "ModuleRelativePath", "Private/LegoAbilityThumbnailRenderer.h" },
		{ "ToolTip", "Simple class that renders a user-captured thumbnail for our Abilities." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_m_NoImage_MetaData[] = {
		{ "ModuleRelativePath", "Private/LegoAbilityThumbnailRenderer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_m_NoImage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULegoAbilityThumbnailRenderer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::NewProp_m_NoImage = { "m_NoImage", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULegoAbilityThumbnailRenderer, m_NoImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_m_NoImage_MetaData), NewProp_m_NoImage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::NewProp_m_NoImage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDefaultSizedThumbnailRenderer,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbilityEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::ClassParams = {
	&ULegoAbilityThumbnailRenderer::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::PropPointers),
	0,
	0x000000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityThumbnailRenderer()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.OuterSingleton, Z_Construct_UClass_ULegoAbilityThumbnailRenderer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityThumbnailRenderer);
ULegoAbilityThumbnailRenderer::~ULegoAbilityThumbnailRenderer() {}
// ********** End Class ULegoAbilityThumbnailRenderer **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityThumbnailRenderer_h__Script_LegoAbilityEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityThumbnailRenderer, ULegoAbilityThumbnailRenderer::StaticClass, TEXT("ULegoAbilityThumbnailRenderer"), &Z_Registration_Info_UClass_ULegoAbilityThumbnailRenderer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityThumbnailRenderer), 2441362915U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityThumbnailRenderer_h__Script_LegoAbilityEditor_3791328249(TEXT("/Script/LegoAbilityEditor"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityThumbnailRenderer_h__Script_LegoAbilityEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbilityEditor_Private_LegoAbilityThumbnailRenderer_h__Script_LegoAbilityEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

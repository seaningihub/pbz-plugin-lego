// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LegoAbilityTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLegoAbilityTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeSourceComponent_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECameraShakePlaySpace();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface_NoRegister();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayEventTag();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGameplayEventTag *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameplayEventTag;
class UScriptStruct* FGameplayEventTag::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayEventTag.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameplayEventTag.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameplayEventTag, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("GameplayEventTag"));
	}
	return Z_Registration_Info_UScriptStruct_FGameplayEventTag.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FGameplayEventTag_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameplayEventTag_MetaData[] = {
		{ "Categories", "GameplayEvent" },
		{ "Category", "GameplayEvent" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GameplayEventTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameplayEventTag>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameplayEventTag_Statics::NewProp_GameplayEventTag = { "GameplayEventTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameplayEventTag, GameplayEventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameplayEventTag_MetaData), NewProp_GameplayEventTag_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameplayEventTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameplayEventTag_Statics::NewProp_GameplayEventTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayEventTag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameplayEventTag_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"GameplayEventTag",
	Z_Construct_UScriptStruct_FGameplayEventTag_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayEventTag_Statics::PropPointers),
	sizeof(FGameplayEventTag),
	alignof(FGameplayEventTag),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameplayEventTag_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameplayEventTag_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameplayEventTag()
{
	if (!Z_Registration_Info_UScriptStruct_FGameplayEventTag.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameplayEventTag.InnerSingleton, Z_Construct_UScriptStruct_FGameplayEventTag_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FGameplayEventTag.InnerSingleton;
}
// ********** End ScriptStruct FGameplayEventTag ***************************************************

// ********** Begin Interface ULegoAbilityPreviewInterface Function PostPreviewActorCreated ********
void ILegoAbilityPreviewInterface::PostPreviewActorCreated()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_PostPreviewActorCreated instead.");
}
static FName NAME_ULegoAbilityPreviewInterface_PostPreviewActorCreated = FName(TEXT("PostPreviewActorCreated"));
void ILegoAbilityPreviewInterface::Execute_PostPreviewActorCreated(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(ULegoAbilityPreviewInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_ULegoAbilityPreviewInterface_PostPreviewActorCreated);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (ILegoAbilityPreviewInterface*)(O->GetNativeInterfaceAddress(ULegoAbilityPreviewInterface::StaticClass())))
	{
		I->PostPreviewActorCreated_Implementation();
	}
}
struct Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULegoAbilityPreviewInterface, nullptr, "PostPreviewActorCreated", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ILegoAbilityPreviewInterface::execPostPreviewActorCreated)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PostPreviewActorCreated_Implementation();
	P_NATIVE_END;
}
// ********** End Interface ULegoAbilityPreviewInterface Function PostPreviewActorCreated **********

// ********** Begin Interface ULegoAbilityPreviewInterface *****************************************
void ULegoAbilityPreviewInterface::StaticRegisterNativesULegoAbilityPreviewInterface()
{
	UClass* Class = ULegoAbilityPreviewInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PostPreviewActorCreated", &ILegoAbilityPreviewInterface::execPostPreviewActorCreated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULegoAbilityPreviewInterface;
UClass* ULegoAbilityPreviewInterface::GetPrivateStaticClass()
{
	using TClass = ULegoAbilityPreviewInterface;
	if (!Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LegoAbilityPreviewInterface"),
			Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.InnerSingleton,
			StaticRegisterNativesULegoAbilityPreviewInterface,
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
	return Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface_NoRegister()
{
	return ULegoAbilityPreviewInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULegoAbilityPreviewInterface_PostPreviewActorCreated, "PostPreviewActorCreated" }, // 1466843442
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ILegoAbilityPreviewInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::ClassParams = {
	&ULegoAbilityPreviewInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULegoAbilityPreviewInterface()
{
	if (!Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.OuterSingleton, Z_Construct_UClass_ULegoAbilityPreviewInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULegoAbilityPreviewInterface.OuterSingleton;
}
ULegoAbilityPreviewInterface::ULegoAbilityPreviewInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULegoAbilityPreviewInterface);
// ********** End Interface ULegoAbilityPreviewInterface *******************************************

// ********** Begin ScriptStruct FLegoCameraShakePreviewerAddParams ********************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams;
class UScriptStruct* FLegoCameraShakePreviewerAddParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("LegoCameraShakePreviewerAddParams"));
	}
	return Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeClass_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "// The class of the shake.\n" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
		{ "ToolTip", "The class of the shake." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceComponent_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "// Optional shake source.\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
		{ "NativeConstTemplateArg", "" },
		{ "ToolTip", "Optional shake source." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalStartTime_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "// Start time of the shake, for scrubbing.\n" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
		{ "ToolTip", "Start time of the shake, for scrubbing." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "Comment", "// Parameters to be passed to the shake's start method.\n" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
		{ "ToolTip", "Parameters to be passed to the shake's start method." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaySpace_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserPlaySpaceRot_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DurationOverride_MetaData[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/LegoAbilityTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_ShakeClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlobalStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlaySpace_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlaySpace;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UserPlaySpaceRot;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DurationOverride_Inner;
	static const UECodeGen_Private::FGenericPropertyParams NewProp_DurationOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FLegoCameraShakePreviewerAddParams>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_ShakeClass = { "ShakeClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, ShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeClass_MetaData), NewProp_ShakeClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_SourceComponent = { "SourceComponent", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, SourceComponent), Z_Construct_UClass_UCameraShakeSourceComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceComponent_MetaData), NewProp_SourceComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_GlobalStartTime = { "GlobalStartTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, GlobalStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalStartTime_MetaData), NewProp_GlobalStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, Scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_PlaySpace_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_PlaySpace = { "PlaySpace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, PlaySpace), Z_Construct_UEnum_Engine_ECameraShakePlaySpace, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaySpace_MetaData), NewProp_PlaySpace_MetaData) }; // 2661961121
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_UserPlaySpaceRot = { "UserPlaySpaceRot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, UserPlaySpaceRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserPlaySpaceRot_MetaData), NewProp_UserPlaySpaceRot_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_DurationOverride_Inner = { "DurationOverride", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FGenericPropertyParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_DurationOverride = { "DurationOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Optional, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FLegoCameraShakePreviewerAddParams, DurationOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DurationOverride_MetaData), NewProp_DurationOverride_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_ShakeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_SourceComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_GlobalStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_PlaySpace_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_PlaySpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_UserPlaySpaceRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_DurationOverride_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewProp_DurationOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	&NewStructOps,
	"LegoCameraShakePreviewerAddParams",
	Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::PropPointers),
	sizeof(FLegoCameraShakePreviewerAddParams),
	alignof(FLegoCameraShakePreviewerAddParams),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams()
{
	if (!Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.InnerSingleton, Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams.InnerSingleton;
}
// ********** End ScriptStruct FLegoCameraShakePreviewerAddParams **********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGameplayEventTag::StaticStruct, Z_Construct_UScriptStruct_FGameplayEventTag_Statics::NewStructOps, TEXT("GameplayEventTag"), &Z_Registration_Info_UScriptStruct_FGameplayEventTag, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameplayEventTag), 3327804238U) },
		{ FLegoCameraShakePreviewerAddParams::StaticStruct, Z_Construct_UScriptStruct_FLegoCameraShakePreviewerAddParams_Statics::NewStructOps, TEXT("LegoCameraShakePreviewerAddParams"), &Z_Registration_Info_UScriptStruct_FLegoCameraShakePreviewerAddParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FLegoCameraShakePreviewerAddParams), 2361453237U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULegoAbilityPreviewInterface, ULegoAbilityPreviewInterface::StaticClass, TEXT("ULegoAbilityPreviewInterface"), &Z_Registration_Info_UClass_ULegoAbilityPreviewInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULegoAbilityPreviewInterface), 3960765582U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_3864459073(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_LegoAbilityTypes_h__Script_LegoAbility_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

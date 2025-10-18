// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actions/LGAAction.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "LGATimeline.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeLGAAction() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagRequirements();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
LEGOABILITY_API UClass* Z_Construct_UClass_ULegoAbility_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGAAction_NoRegister();
LEGOABILITY_API UClass* Z_Construct_UClass_ULGATimeline_NoRegister();
LEGOABILITY_API UEnum* Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy();
LEGOABILITY_API UScriptStruct* Z_Construct_UScriptStruct_FLGAActionEvent();
UPackage* Z_Construct_UPackage__Script_LegoAbility();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EGameplayActionNetExecutionPolicy *****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy;
static UEnum* EGameplayActionNetExecutionPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy, (UObject*)Z_Construct_UPackage__Script_LegoAbility(), TEXT("EGameplayActionNetExecutionPolicy"));
	}
	return Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.OuterSingleton;
}
template<> LEGOABILITY_API UEnum* StaticEnum<EGameplayActionNetExecutionPolicy>()
{
	return EGameplayActionNetExecutionPolicy_StaticEnum();
}
struct Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Always.Comment", "// This action will always be executed\n" },
		{ "Always.DisplayName", "Always" },
		{ "Always.Name", "EGameplayActionNetExecutionPolicy::Always" },
		{ "Always.ToolTip", "This action will always be executed" },
		{ "BlueprintType", "true" },
		{ "LocalOnly.Comment", "// This action will only run on the client or server that has local control\n" },
		{ "LocalOnly.DisplayName", "Local Only" },
		{ "LocalOnly.Name", "EGameplayActionNetExecutionPolicy::LocalOnly" },
		{ "LocalOnly.ToolTip", "This action will only run on the client or server that has local control" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ServerOnly.Comment", "// This action will only run on the server\n" },
		{ "ServerOnly.DisplayName", "Server Only" },
		{ "ServerOnly.Name", "EGameplayActionNetExecutionPolicy::ServerOnly" },
		{ "ServerOnly.ToolTip", "This action will only run on the server" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGameplayActionNetExecutionPolicy::Always", (int64)EGameplayActionNetExecutionPolicy::Always },
		{ "EGameplayActionNetExecutionPolicy::LocalOnly", (int64)EGameplayActionNetExecutionPolicy::LocalOnly },
		{ "EGameplayActionNetExecutionPolicy::ServerOnly", (int64)EGameplayActionNetExecutionPolicy::ServerOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_LegoAbility,
	nullptr,
	"EGameplayActionNetExecutionPolicy",
	"EGameplayActionNetExecutionPolicy",
	Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy()
{
	if (!Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.InnerSingleton, Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy.InnerSingleton;
}
// ********** End Enum EGameplayActionNetExecutionPolicy *******************************************

// ********** Begin Class ULGAAction Function GetAbility *******************************************
struct Z_Construct_UFunction_ULGAAction_GetAbility_Statics
{
	struct LGAAction_eventGetAbility_Parms
	{
		ULegoAbility* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_GetAbility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetAbility_Parms, ReturnValue), Z_Construct_UClass_ULegoAbility_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetAbility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetAbility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetAbility_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetAbility", Z_Construct_UFunction_ULGAAction_GetAbility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbility_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetAbility_Statics::LGAAction_eventGetAbility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbility_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetAbility_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetAbility_Statics::LGAAction_eventGetAbility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetAbility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetAbility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetAbility)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULegoAbility**)Z_Param__Result=P_THIS->GetAbility();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetAbility *********************************************

// ********** Begin Class ULGAAction Function GetAbilitySystemComponent ****************************
struct Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics
{
	struct LGAAction_eventGetAbilitySystemComponent_Parms
	{
		UAbilitySystemComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetAbilitySystemComponent_Parms, ReturnValue), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetAbilitySystemComponent", Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::LGAAction_eventGetAbilitySystemComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::LGAAction_eventGetAbilitySystemComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetAbilitySystemComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAbilitySystemComponent**)Z_Param__Result=P_THIS->GetAbilitySystemComponent();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetAbilitySystemComponent ******************************

// ********** Begin Class ULGAAction Function GetActionEvent ***************************************
struct Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics
{
	struct LGAAction_eventGetActionEvent_Parms
	{
		FLGAActionEvent Event;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Event;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetActionEvent_Parms, Event), Z_Construct_UScriptStruct_FLGAActionEvent, METADATA_PARAMS(0, nullptr) }; // 3071200278
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::NewProp_Event,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetActionEvent", Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::LGAAction_eventGetActionEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::LGAAction_eventGetActionEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetActionEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetActionEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetActionEvent)
{
	P_GET_STRUCT_REF(FLGAActionEvent,Z_Param_Out_Event);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetActionEvent(Z_Param_Out_Event);
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetActionEvent *****************************************

// ********** Begin Class ULGAAction Function GetActionName ****************************************
struct LGAAction_eventGetActionName_Parms
{
	FString ReturnValue;
};
static FName NAME_ULGAAction_GetActionName = FName(TEXT("GetActionName"));
FString ULGAAction::GetActionName() const
{
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_GetActionName);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		LGAAction_eventGetActionName_Parms Parms;
		const_cast<ULGAAction*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<ULGAAction*>(this)->GetActionName_Implementation();
	}
}
struct Z_Construct_UFunction_ULGAAction_GetActionName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "/** \n\x09 * Implementable event to get a custom name for the action\n\x09 */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "Implementable event to get a custom name for the action" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULGAAction_GetActionName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetActionName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetActionName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetActionName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetActionName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetActionName", Z_Construct_UFunction_ULGAAction_GetActionName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionName_Statics::PropPointers), sizeof(LGAAction_eventGetActionName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionName_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetActionName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventGetActionName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetActionName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetActionName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetActionName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetActionName_Implementation();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetActionName ******************************************

// ********** Begin Class ULGAAction Function GetActionTags ****************************************
struct Z_Construct_UFunction_ULGAAction_GetActionTags_Statics
{
	struct LGAAction_eventGetActionTags_Parms
	{
		FGameplayTagContainer ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetActionTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 2104890724
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetActionTags", Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::LGAAction_eventGetActionTags_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::LGAAction_eventGetActionTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetActionTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetActionTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetActionTags)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetActionTags();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetActionTags ******************************************

// ********** Begin Class ULGAAction Function GetAvatarActor ***************************************
struct Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics
{
	struct LGAAction_eventGetAvatarActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetAvatarActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetAvatarActor", Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::LGAAction_eventGetAvatarActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::LGAAction_eventGetAvatarActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetAvatarActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetAvatarActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetAvatarActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetAvatarActor();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetAvatarActor *****************************************

// ********** Begin Class ULGAAction Function GetTimeline ******************************************
struct Z_Construct_UFunction_ULGAAction_GetTimeline_Statics
{
	struct LGAAction_eventGetTimeline_Parms
	{
		ULGATimeline* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventGetTimeline_Parms, ReturnValue), Z_Construct_UClass_ULGATimeline_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "GetTimeline", Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::LGAAction_eventGetTimeline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::LGAAction_eventGetTimeline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_GetTimeline()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_GetTimeline_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execGetTimeline)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULGATimeline**)Z_Param__Result=P_THIS->GetTimeline();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function GetTimeline ********************************************

// ********** Begin Class ULGAAction Function HasAuthority *****************************************
struct Z_Construct_UFunction_ULGAAction_HasAuthority_Statics
{
	struct LGAAction_eventHasAuthority_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventHasAuthority_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventHasAuthority_Parms), &Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "HasAuthority", Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::LGAAction_eventHasAuthority_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::LGAAction_eventHasAuthority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_HasAuthority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_HasAuthority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execHasAuthority)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasAuthority();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function HasAuthority *******************************************

// ********** Begin Class ULGAAction Function IsLocallyControlled **********************************
struct Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics
{
	struct LGAAction_eventIsLocallyControlled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventIsLocallyControlled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventIsLocallyControlled_Parms), &Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "IsLocallyControlled", Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::LGAAction_eventIsLocallyControlled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::LGAAction_eventIsLocallyControlled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_IsLocallyControlled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_IsLocallyControlled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execIsLocallyControlled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLocallyControlled();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function IsLocallyControlled ************************************

// ********** Begin Class ULGAAction Function IsLoopAction *****************************************
struct Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics
{
	struct LGAAction_eventIsLoopAction_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventIsLoopAction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventIsLoopAction_Parms), &Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "IsLoopAction", Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::LGAAction_eventIsLoopAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::LGAAction_eventIsLoopAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_IsLoopAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_IsLoopAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execIsLoopAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLoopAction();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function IsLoopAction *******************************************

// ********** Begin Class ULGAAction Function IsSimulatedAction ************************************
struct Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics
{
	struct LGAAction_eventIsSimulatedAction_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "LegoAbility" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventIsSimulatedAction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventIsSimulatedAction_Parms), &Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "IsSimulatedAction", Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::LGAAction_eventIsSimulatedAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::LGAAction_eventIsSimulatedAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_IsSimulatedAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_IsSimulatedAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ULGAAction::execIsSimulatedAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSimulatedAction();
	P_NATIVE_END;
}
// ********** End Class ULGAAction Function IsSimulatedAction **************************************

// ********** Begin Class ULGAAction Function K2_CanActivateAction *********************************
struct LGAAction_eventK2_CanActivateAction_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_eventK2_CanActivateAction_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ULGAAction_K2_CanActivateAction = FName(TEXT("K2_CanActivateAction"));
bool ULGAAction::K2_CanActivateAction() const
{
	LGAAction_eventK2_CanActivateAction_Parms Parms;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_K2_CanActivateAction);
		const_cast<ULGAAction*>(this)->ProcessEvent(Func,&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Comment", "/** Returns true if this action can be activated */" },
		{ "DisplayName", "CanActivateAction" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "Returns true if this action can be activated" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventK2_CanActivateAction_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventK2_CanActivateAction_Parms), &Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "K2_CanActivateAction", Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::PropPointers), sizeof(LGAAction_eventK2_CanActivateAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventK2_CanActivateAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_K2_CanActivateAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_K2_CanActivateAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function K2_CanActivateAction ***********************************

// ********** Begin Class ULGAAction Function Received_ActionBegin *********************************
struct LGAAction_eventReceived_ActionBegin_Parms
{
	float ElapsedTime;
	float TotalDuration;
	float BeginTime;
};
static FName NAME_ULGAAction_Received_ActionBegin = FName(TEXT("Received_ActionBegin"));
void ULGAAction::Received_ActionBegin(float ElapsedTime, float TotalDuration, float BeginTime)
{
	LGAAction_eventReceived_ActionBegin_Parms Parms;
	Parms.ElapsedTime=ElapsedTime;
	Parms.TotalDuration=TotalDuration;
	Parms.BeginTime=BeginTime;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_ActionBegin);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "ActionBegin" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BeginTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionBegin_Parms, ElapsedTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionBegin_Parms, TotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_BeginTime = { "BeginTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionBegin_Parms, BeginTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_TotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::NewProp_BeginTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_ActionBegin", Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::PropPointers), sizeof(LGAAction_eventReceived_ActionBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_ActionBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_ActionBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_ActionBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_ActionBegin ***********************************

// ********** Begin Class ULGAAction Function Received_ActionEnd ***********************************
struct LGAAction_eventReceived_ActionEnd_Parms
{
	bool bAbilityFinished;
	bool bActionFinished;
};
static FName NAME_ULGAAction_Received_ActionEnd = FName(TEXT("Received_ActionEnd"));
void ULGAAction::Received_ActionEnd(bool bAbilityFinished, bool bActionFinished)
{
	LGAAction_eventReceived_ActionEnd_Parms Parms;
	Parms.bAbilityFinished=bAbilityFinished ? true : false;
	Parms.bActionFinished=bActionFinished ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_ActionEnd);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "ActionEnd" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bAbilityFinished_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAbilityFinished;
	static void NewProp_bActionFinished_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bActionFinished;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bAbilityFinished_SetBit(void* Obj)
{
	((LGAAction_eventReceived_ActionEnd_Parms*)Obj)->bAbilityFinished = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bAbilityFinished = { "bAbilityFinished", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventReceived_ActionEnd_Parms), &Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bAbilityFinished_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bActionFinished_SetBit(void* Obj)
{
	((LGAAction_eventReceived_ActionEnd_Parms*)Obj)->bActionFinished = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bActionFinished = { "bActionFinished", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventReceived_ActionEnd_Parms), &Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bActionFinished_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bAbilityFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::NewProp_bActionFinished,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_ActionEnd", Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::PropPointers), sizeof(LGAAction_eventReceived_ActionEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_ActionEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_ActionEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_ActionEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_ActionEnd *************************************

// ********** Begin Class ULGAAction Function Received_ActionSkip **********************************
struct LGAAction_eventReceived_ActionSkip_Parms
{
	float ElapsedTime;
	float TotalDuration;
};
static FName NAME_ULGAAction_Received_ActionSkip = FName(TEXT("Received_ActionSkip"));
void ULGAAction::Received_ActionSkip(float ElapsedTime, float TotalDuration)
{
	LGAAction_eventReceived_ActionSkip_Parms Parms;
	Parms.ElapsedTime=ElapsedTime;
	Parms.TotalDuration=TotalDuration;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_ActionSkip);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "ActionSkip" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionSkip_Parms, ElapsedTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionSkip_Parms, TotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::NewProp_TotalDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_ActionSkip", Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::PropPointers), sizeof(LGAAction_eventReceived_ActionSkip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_ActionSkip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_ActionSkip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_ActionSkip_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_ActionSkip ************************************

// ********** Begin Class ULGAAction Function Received_ActionTick **********************************
struct LGAAction_eventReceived_ActionTick_Parms
{
	float ElapsedTime;
	float TotalDuration;
	float DeltaTime;
};
static FName NAME_ULGAAction_Received_ActionTick = FName(TEXT("Received_ActionTick"));
void ULGAAction::Received_ActionTick(float ElapsedTime, float TotalDuration, float DeltaTime)
{
	LGAAction_eventReceived_ActionTick_Parms Parms;
	Parms.ElapsedTime=ElapsedTime;
	Parms.TotalDuration=TotalDuration;
	Parms.DeltaTime=DeltaTime;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_ActionTick);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "ActionTick" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionTick_Parms, ElapsedTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionTick_Parms, TotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_ActionTick_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_TotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::NewProp_DeltaTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_ActionTick", Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::PropPointers), sizeof(LGAAction_eventReceived_ActionTick_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_ActionTick_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_ActionTick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_ActionTick_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_ActionTick ************************************

// ********** Begin Class ULGAAction Function Received_GetWidgetLocation ***************************
struct LGAAction_eventReceived_GetWidgetLocation_Parms
{
	AActor* PreviewActor;
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_eventReceived_GetWidgetLocation_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_ULGAAction_Received_GetWidgetLocation = FName(TEXT("Received_GetWidgetLocation"));
FVector ULGAAction::Received_GetWidgetLocation(AActor* PreviewActor)
{
	LGAAction_eventReceived_GetWidgetLocation_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_GetWidgetLocation);
	ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "GetWidgetLocation" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_GetWidgetLocation_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_GetWidgetLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_GetWidgetLocation", Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::PropPointers), sizeof(LGAAction_eventReceived_GetWidgetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_GetWidgetLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_GetWidgetLocation *****************************

// ********** Begin Class ULGAAction Function Received_GetWidgetRotation ***************************
struct LGAAction_eventReceived_GetWidgetRotation_Parms
{
	AActor* PreviewActor;
	FRotator ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_eventReceived_GetWidgetRotation_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_ULGAAction_Received_GetWidgetRotation = FName(TEXT("Received_GetWidgetRotation"));
FRotator ULGAAction::Received_GetWidgetRotation(AActor* PreviewActor)
{
	LGAAction_eventReceived_GetWidgetRotation_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_GetWidgetRotation);
	ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "GetWidgetRotation" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_GetWidgetRotation_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_GetWidgetRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_GetWidgetRotation", Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::PropPointers), sizeof(LGAAction_eventReceived_GetWidgetRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_GetWidgetRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_GetWidgetRotation *****************************

// ********** Begin Class ULGAAction Function Received_InputWidgetDelta ****************************
struct LGAAction_eventReceived_InputWidgetDelta_Parms
{
	AActor* PreviewActor;
	FVector Drag;
	FRotator Rot;
	FVector Scale;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_eventReceived_InputWidgetDelta_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ULGAAction_Received_InputWidgetDelta = FName(TEXT("Received_InputWidgetDelta"));
bool ULGAAction::Received_InputWidgetDelta(AActor* PreviewActor, FVector const& Drag, FRotator const& Rot, FVector const& Scale)
{
	LGAAction_eventReceived_InputWidgetDelta_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	Parms.Drag=Drag;
	Parms.Rot=Rot;
	Parms.Scale=Scale;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_InputWidgetDelta);
	ProcessEvent(Func,&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "InputWidgetDelta" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Drag_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rot_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Drag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_InputWidgetDelta_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Drag = { "Drag", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_InputWidgetDelta_Parms, Drag), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Drag_MetaData), NewProp_Drag_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Rot = { "Rot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_InputWidgetDelta_Parms, Rot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rot_MetaData), NewProp_Rot_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_InputWidgetDelta_Parms, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
void Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventReceived_InputWidgetDelta_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventReceived_InputWidgetDelta_Parms), &Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Drag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Rot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_InputWidgetDelta", Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::PropPointers), sizeof(LGAAction_eventReceived_InputWidgetDelta_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_InputWidgetDelta_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_InputWidgetDelta ******************************

// ********** Begin Class ULGAAction Function Received_NeedShowTransformWidget *********************
struct LGAAction_eventReceived_NeedShowTransformWidget_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	LGAAction_eventReceived_NeedShowTransformWidget_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_ULGAAction_Received_NeedShowTransformWidget = FName(TEXT("Received_NeedShowTransformWidget"));
bool ULGAAction::Received_NeedShowTransformWidget()
{
	LGAAction_eventReceived_NeedShowTransformWidget_Parms Parms;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_NeedShowTransformWidget);
	ProcessEvent(Func,&Parms);
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "NeedShowTransformWidget" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((LGAAction_eventReceived_NeedShowTransformWidget_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventReceived_NeedShowTransformWidget_Parms), &Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_NeedShowTransformWidget", Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::PropPointers), sizeof(LGAAction_eventReceived_NeedShowTransformWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_NeedShowTransformWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_NeedShowTransformWidget ***********************

// ********** Begin Class ULGAAction Function Received_PreviewBegin ********************************
struct LGAAction_eventReceived_PreviewBegin_Parms
{
	AActor* PreviewActor;
	float TotalDuration;
};
static FName NAME_ULGAAction_Received_PreviewBegin = FName(TEXT("Received_PreviewBegin"));
void ULGAAction::Received_PreviewBegin(AActor* PreviewActor, float TotalDuration)
{
	LGAAction_eventReceived_PreviewBegin_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	Parms.TotalDuration=TotalDuration;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_PreviewBegin);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "PreviewBegin" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_PreviewBegin_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_PreviewBegin_Parms, TotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::NewProp_TotalDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_PreviewBegin", Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::PropPointers), sizeof(LGAAction_eventReceived_PreviewBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_PreviewBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_PreviewBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_PreviewBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_PreviewBegin **********************************

// ********** Begin Class ULGAAction Function Received_PreviewEnd **********************************
struct LGAAction_eventReceived_PreviewEnd_Parms
{
	AActor* PreviewActor;
};
static FName NAME_ULGAAction_Received_PreviewEnd = FName(TEXT("Received_PreviewEnd"));
void ULGAAction::Received_PreviewEnd(AActor* PreviewActor)
{
	LGAAction_eventReceived_PreviewEnd_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_PreviewEnd);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "PreviewEnd" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_PreviewEnd_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::NewProp_PreviewActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_PreviewEnd", Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::PropPointers), sizeof(LGAAction_eventReceived_PreviewEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_PreviewEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_PreviewEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_PreviewEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_PreviewEnd ************************************

// ********** Begin Class ULGAAction Function Received_SetPosition *********************************
struct LGAAction_eventReceived_SetPosition_Parms
{
	AActor* PreviewActor;
	float Position;
	float TotalDuration;
};
static FName NAME_ULGAAction_Received_SetPosition = FName(TEXT("Received_SetPosition"));
void ULGAAction::Received_SetPosition(AActor* PreviewActor, float Position, float TotalDuration)
{
	LGAAction_eventReceived_SetPosition_Parms Parms;
	Parms.PreviewActor=PreviewActor;
	Parms.Position=Position;
	Parms.TotalDuration=TotalDuration;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_SetPosition);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "SetPosition" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Position;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_PreviewActor = { "PreviewActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_SetPosition_Parms, PreviewActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_SetPosition_Parms, Position), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LGAAction_eventReceived_SetPosition_Parms, TotalDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_PreviewActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::NewProp_TotalDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_SetPosition", Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::PropPointers), sizeof(LGAAction_eventReceived_SetPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_SetPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_SetPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_SetPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_SetPosition ***********************************

// ********** Begin Class ULGAAction Function Received_TimelineBegin *******************************
static FName NAME_ULGAAction_Received_TimelineBegin = FName(TEXT("Received_TimelineBegin"));
void ULGAAction::Received_TimelineBegin()
{
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_TimelineBegin);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ULGAAction_Received_TimelineBegin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "TimelineBegin" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_TimelineBegin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_TimelineBegin", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_TimelineBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_TimelineBegin_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ULGAAction_Received_TimelineBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_TimelineBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_TimelineBegin *********************************

// ********** Begin Class ULGAAction Function Received_TimelineEnd *********************************
struct LGAAction_eventReceived_TimelineEnd_Parms
{
	bool bTimelineFinished;
};
static FName NAME_ULGAAction_Received_TimelineEnd = FName(TEXT("Received_TimelineEnd"));
void ULGAAction::Received_TimelineEnd(bool bTimelineFinished)
{
	LGAAction_eventReceived_TimelineEnd_Parms Parms;
	Parms.bTimelineFinished=bTimelineFinished ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ULGAAction_Received_TimelineEnd);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "DisplayName", "TimelineEnd" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bTimelineFinished_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTimelineFinished;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::NewProp_bTimelineFinished_SetBit(void* Obj)
{
	((LGAAction_eventReceived_TimelineEnd_Parms*)Obj)->bTimelineFinished = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::NewProp_bTimelineFinished = { "bTimelineFinished", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(LGAAction_eventReceived_TimelineEnd_Parms), &Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::NewProp_bTimelineFinished_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::NewProp_bTimelineFinished,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ULGAAction, nullptr, "Received_TimelineEnd", Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::PropPointers), sizeof(LGAAction_eventReceived_TimelineEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(LGAAction_eventReceived_TimelineEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ULGAAction_Received_TimelineEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULGAAction_Received_TimelineEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class ULGAAction Function Received_TimelineEnd ***********************************

// ********** Begin Class ULGAAction ***************************************************************
void ULGAAction::StaticRegisterNativesULGAAction()
{
	UClass* Class = ULGAAction::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAbility", &ULGAAction::execGetAbility },
		{ "GetAbilitySystemComponent", &ULGAAction::execGetAbilitySystemComponent },
		{ "GetActionEvent", &ULGAAction::execGetActionEvent },
		{ "GetActionName", &ULGAAction::execGetActionName },
		{ "GetActionTags", &ULGAAction::execGetActionTags },
		{ "GetAvatarActor", &ULGAAction::execGetAvatarActor },
		{ "GetTimeline", &ULGAAction::execGetTimeline },
		{ "HasAuthority", &ULGAAction::execHasAuthority },
		{ "IsLocallyControlled", &ULGAAction::execIsLocallyControlled },
		{ "IsLoopAction", &ULGAAction::execIsLoopAction },
		{ "IsSimulatedAction", &ULGAAction::execIsSimulatedAction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ULGAAction;
UClass* ULGAAction::GetPrivateStaticClass()
{
	using TClass = ULGAAction;
	if (!Z_Registration_Info_UClass_ULGAAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("LGAAction"),
			Z_Registration_Info_UClass_ULGAAction.InnerSingleton,
			StaticRegisterNativesULGAAction,
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
	return Z_Registration_Info_UClass_ULGAAction.InnerSingleton;
}
UClass* Z_Construct_UClass_ULGAAction_NoRegister()
{
	return ULGAAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ULGAAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "Actions/LGAAction.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanEditSingleFrame_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "Comment", "/* whether bIsSingleFrame property is editable */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "whether bIsSingleFrame property is editable" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSupportPreview_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "Comment", "/* whether this action is triggered on preview */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "whether this action is triggered on preview" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionColor_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "Comment", "/* Color of Action in editor */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "Color of Action in editor" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "Comment", "/** The tooltip when mouse hovered. */" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
		{ "ToolTip", "The tooltip when mouse hovered." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActualStartTime_MetaData[] = {
		{ "Category", "Action Event Time" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActualDuration_MetaData[] = {
		{ "Category", "Action Event Time" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActualEndTime_MetaData[] = {
		{ "Category", "Action Event Time" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSingleFrame_MetaData[] = {
		{ "Category", "Duration Type" },
		{ "EditCondition", "bCanEditSingleFrame" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionTags_MetaData[] = {
		{ "Category", "Action Tags" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationRequirements_MetaData[] = {
		{ "Category", "Condition" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGuaranteedToBeTriggered_MetaData[] = {
		{ "Category", "Trigger" },
		{ "EditCondition", "bIsSingleFrame" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreInitialSkip_MetaData[] = {
		{ "Category", "Trigger" },
		{ "EditCondition", "bIsSingleFrame" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetExecutionPolicy_MetaData[] = {
		{ "Category", "Network Replication" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReplicateToSimulation_MetaData[] = {
		{ "Category", "Network Replication" },
		{ "ModuleRelativePath", "Public/Actions/LGAAction.h" },
	};
#endif // WITH_METADATA
#if WITH_EDITORONLY_DATA
	static void NewProp_bCanEditSingleFrame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanEditSingleFrame;
	static void NewProp_bSupportPreview_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportPreview;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionColor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActualStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActualDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActualEndTime;
#endif // WITH_EDITORONLY_DATA
	static void NewProp_bIsSingleFrame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSingleFrame;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActionTags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActivationRequirements;
	static void NewProp_bGuaranteedToBeTriggered_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGuaranteedToBeTriggered;
	static void NewProp_bIgnoreInitialSkip_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreInitialSkip;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NetExecutionPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NetExecutionPolicy;
	static void NewProp_bReplicateToSimulation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReplicateToSimulation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ULGAAction_GetAbility, "GetAbility" }, // 3282547092
		{ &Z_Construct_UFunction_ULGAAction_GetAbilitySystemComponent, "GetAbilitySystemComponent" }, // 3081358932
		{ &Z_Construct_UFunction_ULGAAction_GetActionEvent, "GetActionEvent" }, // 2958167212
		{ &Z_Construct_UFunction_ULGAAction_GetActionName, "GetActionName" }, // 2130878213
		{ &Z_Construct_UFunction_ULGAAction_GetActionTags, "GetActionTags" }, // 1423890371
		{ &Z_Construct_UFunction_ULGAAction_GetAvatarActor, "GetAvatarActor" }, // 2004431045
		{ &Z_Construct_UFunction_ULGAAction_GetTimeline, "GetTimeline" }, // 1471064649
		{ &Z_Construct_UFunction_ULGAAction_HasAuthority, "HasAuthority" }, // 1738387936
		{ &Z_Construct_UFunction_ULGAAction_IsLocallyControlled, "IsLocallyControlled" }, // 239517962
		{ &Z_Construct_UFunction_ULGAAction_IsLoopAction, "IsLoopAction" }, // 3330891386
		{ &Z_Construct_UFunction_ULGAAction_IsSimulatedAction, "IsSimulatedAction" }, // 1037829656
		{ &Z_Construct_UFunction_ULGAAction_K2_CanActivateAction, "K2_CanActivateAction" }, // 2709676038
		{ &Z_Construct_UFunction_ULGAAction_Received_ActionBegin, "Received_ActionBegin" }, // 3444573264
		{ &Z_Construct_UFunction_ULGAAction_Received_ActionEnd, "Received_ActionEnd" }, // 1396503923
		{ &Z_Construct_UFunction_ULGAAction_Received_ActionSkip, "Received_ActionSkip" }, // 4081797856
		{ &Z_Construct_UFunction_ULGAAction_Received_ActionTick, "Received_ActionTick" }, // 1317857829
		{ &Z_Construct_UFunction_ULGAAction_Received_GetWidgetLocation, "Received_GetWidgetLocation" }, // 3796924295
		{ &Z_Construct_UFunction_ULGAAction_Received_GetWidgetRotation, "Received_GetWidgetRotation" }, // 2182593095
		{ &Z_Construct_UFunction_ULGAAction_Received_InputWidgetDelta, "Received_InputWidgetDelta" }, // 163403245
		{ &Z_Construct_UFunction_ULGAAction_Received_NeedShowTransformWidget, "Received_NeedShowTransformWidget" }, // 355539959
		{ &Z_Construct_UFunction_ULGAAction_Received_PreviewBegin, "Received_PreviewBegin" }, // 3371273190
		{ &Z_Construct_UFunction_ULGAAction_Received_PreviewEnd, "Received_PreviewEnd" }, // 4162665472
		{ &Z_Construct_UFunction_ULGAAction_Received_SetPosition, "Received_SetPosition" }, // 1656836039
		{ &Z_Construct_UFunction_ULGAAction_Received_TimelineBegin, "Received_TimelineBegin" }, // 274752965
		{ &Z_Construct_UFunction_ULGAAction_Received_TimelineEnd, "Received_TimelineEnd" }, // 3494715675
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULGAAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
#if WITH_EDITORONLY_DATA
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bCanEditSingleFrame_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bCanEditSingleFrame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bCanEditSingleFrame = { "bCanEditSingleFrame", nullptr, (EPropertyFlags)0x0010000800010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bCanEditSingleFrame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanEditSingleFrame_MetaData), NewProp_bCanEditSingleFrame_MetaData) };
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bSupportPreview_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bSupportPreview = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bSupportPreview = { "bSupportPreview", nullptr, (EPropertyFlags)0x0010000800010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bSupportPreview_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSupportPreview_MetaData), NewProp_bSupportPreview_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActionColor = { "ActionColor", nullptr, (EPropertyFlags)0x0010000800010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActionColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionColor_MetaData), NewProp_ActionColor_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000800010001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualStartTime = { "ActualStartTime", nullptr, (EPropertyFlags)0x0010000800022001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActualStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActualStartTime_MetaData), NewProp_ActualStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualDuration = { "ActualDuration", nullptr, (EPropertyFlags)0x0010000800022001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActualDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActualDuration_MetaData), NewProp_ActualDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualEndTime = { "ActualEndTime", nullptr, (EPropertyFlags)0x0010000800022001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActualEndTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActualEndTime_MetaData), NewProp_ActualEndTime_MetaData) };
#endif // WITH_EDITORONLY_DATA
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bIsSingleFrame_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bIsSingleFrame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bIsSingleFrame = { "bIsSingleFrame", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bIsSingleFrame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSingleFrame_MetaData), NewProp_bIsSingleFrame_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActionTags = { "ActionTags", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActionTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionTags_MetaData), NewProp_ActionTags_MetaData) }; // 2104890724
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_ActivationRequirements = { "ActivationRequirements", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, ActivationRequirements), Z_Construct_UScriptStruct_FGameplayTagRequirements, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationRequirements_MetaData), NewProp_ActivationRequirements_MetaData) }; // 1313721778
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bGuaranteedToBeTriggered_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bGuaranteedToBeTriggered = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bGuaranteedToBeTriggered = { "bGuaranteedToBeTriggered", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bGuaranteedToBeTriggered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGuaranteedToBeTriggered_MetaData), NewProp_bGuaranteedToBeTriggered_MetaData) };
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bIgnoreInitialSkip_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bIgnoreInitialSkip = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bIgnoreInitialSkip = { "bIgnoreInitialSkip", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bIgnoreInitialSkip_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIgnoreInitialSkip_MetaData), NewProp_bIgnoreInitialSkip_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_NetExecutionPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_NetExecutionPolicy = { "NetExecutionPolicy", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULGAAction, NetExecutionPolicy), Z_Construct_UEnum_LegoAbility_EGameplayActionNetExecutionPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetExecutionPolicy_MetaData), NewProp_NetExecutionPolicy_MetaData) }; // 3985628125
void Z_Construct_UClass_ULGAAction_Statics::NewProp_bReplicateToSimulation_SetBit(void* Obj)
{
	((ULGAAction*)Obj)->bReplicateToSimulation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULGAAction_Statics::NewProp_bReplicateToSimulation = { "bReplicateToSimulation", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ULGAAction), &Z_Construct_UClass_ULGAAction_Statics::NewProp_bReplicateToSimulation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReplicateToSimulation_MetaData), NewProp_bReplicateToSimulation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULGAAction_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bCanEditSingleFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bSupportPreview,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActionColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActualEndTime,
#endif // WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bIsSingleFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActionTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_ActivationRequirements,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bGuaranteedToBeTriggered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bIgnoreInitialSkip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_NetExecutionPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_NetExecutionPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULGAAction_Statics::NewProp_bReplicateToSimulation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ULGAAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_LegoAbility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULGAAction_Statics::ClassParams = {
	&ULGAAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ULGAAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Statics::PropPointers),
	0,
	0x001020A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULGAAction_Statics::Class_MetaDataParams), Z_Construct_UClass_ULGAAction_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULGAAction()
{
	if (!Z_Registration_Info_UClass_ULGAAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULGAAction.OuterSingleton, Z_Construct_UClass_ULGAAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULGAAction.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULGAAction);
// ********** End Class ULGAAction *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGameplayActionNetExecutionPolicy_StaticEnum, TEXT("EGameplayActionNetExecutionPolicy"), &Z_Registration_Info_UEnum_EGameplayActionNetExecutionPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3985628125U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULGAAction, ULGAAction::StaticClass, TEXT("ULGAAction"), &Z_Registration_Info_UClass_ULGAAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULGAAction), 325887555U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_3104625219(TEXT("/Script/LegoAbility"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_LegoAbility_Source_LegoAbility_Public_Actions_LGAAction_h__Script_LegoAbility_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

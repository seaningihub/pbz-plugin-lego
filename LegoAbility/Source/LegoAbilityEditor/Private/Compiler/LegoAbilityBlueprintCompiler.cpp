// Copyright Recursoft LLC 2019-2021. All Rights Reserved.

#include "Compiler/LegoAbilityBlueprintCompiler.h"
#include "LegoAbility.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LGATimeline.h"
#include "Kismet2/KismetReinstanceUtilities.h"

#define LOCTEXT_NAMESPACE "LegoAbility"

bool FLegoAbilityBlueprintCompiler::CanCompile(const UBlueprint* Blueprint)
{
	return Blueprint->IsA<ULegoAbilityBlueprint>();
}

void FLegoAbilityBlueprintCompiler::Compile(UBlueprint* Blueprint, const FKismetCompilerOptions& CompileOptions, FCompilerResultsLog& Results)
{
	FLegoAbilityBlueprintCompilerContext Compiler(Blueprint, Results, CompileOptions);
	Compiler.Compile();
}

bool FLegoAbilityBlueprintCompiler::GetBlueprintTypesForClass(UClass* ParentClass, UClass*& OutBlueprintClass, UClass*& OutBlueprintGeneratedClass) const
{
	if (ParentClass && ParentClass->IsChildOf<ULegoAbility>())
	{
		OutBlueprintClass = ULegoAbilityBlueprint::StaticClass();
		OutBlueprintGeneratedClass = ULegoAbilityBlueprintGeneratedClass::StaticClass();
		return true;
	}
	
	return false;
}

FLegoAbilityBlueprintCompilerContext::FLegoAbilityBlueprintCompilerContext(UBlueprint* InBlueprint, FCompilerResultsLog& InMessageLog, const FKismetCompilerOptions& InCompilerOptions)
	: FKismetCompilerContext(InBlueprint, InMessageLog, InCompilerOptions)
	, NewLegoAbilityBlueprintClass(nullptr)
{
}

void FLegoAbilityBlueprintCompilerContext::CreateClassVariablesFromBlueprint()
{
	FKismetCompilerContext::CreateClassVariablesFromBlueprint();

	ULegoAbilityBlueprint* AbilityBP = Cast<ULegoAbilityBlueprint>(Blueprint);
	if (!AbilityBP)
	{
		return;
	}

	UClass* ParentClass = AbilityBP->ParentClass;

	// Add timelines variables here
	for (ULGATimeline* Timeline : AbilityBP->AbilityTimelines)
	{
		FObjectPropertyBase* ExistingProperty = CastField<FObjectPropertyBase>(ParentClass->FindPropertyByName(Timeline->GetFName()));
		if (ExistingProperty && ExistingProperty->PropertyClass->IsChildOf(ULGATimeline::StaticClass()))
		{
			continue;
		}

		FEdGraphPinType TimelinePinType(UEdGraphSchema_K2::PC_Object, NAME_None, Timeline->GetClass(), EPinContainerType::None, true, FEdGraphTerminalType());
		FProperty* TimelineProperty = CreateVariable(Timeline->GetFName(), TimelinePinType);

		if (TimelineProperty != nullptr)
		{
			const FString DisplayName = Timeline->GetName();
			TimelineProperty->SetMetaData(TEXT("DisplayName"), *DisplayName);
			TimelineProperty->SetMetaData(TEXT("Category"), TEXT("Timelines"));

			TimelineProperty->SetPropertyFlags(CPF_Transient);
			TimelineProperty->SetPropertyFlags(CPF_BlueprintVisible);
			TimelineProperty->SetPropertyFlags(CPF_BlueprintReadOnly);
			TimelineProperty->SetPropertyFlags(CPF_RepSkip);
		}

	}
}

void FLegoAbilityBlueprintCompilerContext::SpawnNewClass(const FString& NewClassName)
{
	NewLegoAbilityBlueprintClass = FindObject<ULegoAbilityBlueprintGeneratedClass>(Blueprint->GetOutermost(), *NewClassName);

	if (NewLegoAbilityBlueprintClass == nullptr)
	{
		NewLegoAbilityBlueprintClass = NewObject<ULegoAbilityBlueprintGeneratedClass>(Blueprint->GetOutermost(), FName(*NewClassName), RF_Public | RF_Transactional);
	}
	else
	{
		// Already existed, but wasn't linked in the Blueprint yet due to load ordering issues
		FBlueprintCompileReinstancer::Create(NewLegoAbilityBlueprintClass);
	}
	NewClass = NewLegoAbilityBlueprintClass;
}

void FLegoAbilityBlueprintCompilerContext::OnNewClassSet(UBlueprintGeneratedClass* ClassToUse)
{
	NewLegoAbilityBlueprintClass = Cast<ULegoAbilityBlueprintGeneratedClass>(ClassToUse);
}

void FLegoAbilityBlueprintCompilerContext::CleanAndSanitizeClass(UBlueprintGeneratedClass* ClassToClean, UObject*& InOutOldCDO)
{
	const bool bRecompilingOnLoad = Blueprint->bIsRegeneratingOnLoad;
	auto RenameObjectToTransientPackage = [bRecompilingOnLoad](UObject* ObjectToRename, const FName BaseName, bool bClearFlags)
	{
		const ERenameFlags RenFlags = REN_DontCreateRedirectors | (bRecompilingOnLoad ? REN_ForceNoResetLoaders : 0) | REN_NonTransactional | REN_DoNotDirty;

		if (BaseName.IsNone())
		{
			ObjectToRename->Rename(nullptr, GetTransientPackage(), RenFlags);
		}
		else
		{
			FName TransientArchetypeName = MakeUniqueObjectName(GetTransientPackage(), ObjectToRename->GetClass(), BaseName);
			ObjectToRename->Rename(*TransientArchetypeName.ToString(), GetTransientPackage(), RenFlags);
		}

		ObjectToRename->SetFlags(RF_Transient);

		if (bClearFlags)
		{
			ObjectToRename->ClearFlags(RF_Public | RF_Standalone | RF_ArchetypeObject);
		}
		FLinkerLoad::InvalidateExport(ObjectToRename);
	};

	FKismetCompilerContext::CleanAndSanitizeClass(ClassToClean, InOutOldCDO);

	// Make sure our typed pointer is set
	check(ClassToClean == NewClass && NewLegoAbilityBlueprintClass == NewClass);

	for (ULGATimeline* Timeline : NewLegoAbilityBlueprintClass->AbilityTimelines)
	{
		if (Timeline)
		{
			RenameObjectToTransientPackage(Timeline, FName(), false);
		}
	}
	NewLegoAbilityBlueprintClass->AbilityTimelines.Empty();
}


void FLegoAbilityBlueprintCompilerContext::SaveSubObjectsFromCleanAndSanitizeClass(FSubobjectCollection& SubObjectsToSave, UBlueprintGeneratedClass* ClassToClean)
{
	FKismetCompilerContext::SaveSubObjectsFromCleanAndSanitizeClass(SubObjectsToSave, ClassToClean);

	// Make sure our typed pointer is set
	check(ClassToClean == NewClass);
	NewLegoAbilityBlueprintClass = CastChecked<ULegoAbilityBlueprintGeneratedClass>((UObject*)NewClass);
}

void FLegoAbilityBlueprintCompilerContext::FinishCompilingClass(UClass* Class)
{
	ULegoAbilityBlueprint* AbilityBP = Cast<ULegoAbilityBlueprint>(Blueprint);
	ULegoAbilityBlueprintGeneratedClass* BPGClass = CastChecked<ULegoAbilityBlueprintGeneratedClass>(Class);

	if (AbilityBP == nullptr || BPGClass == nullptr)
		return;

	UClass* ParentClass = AbilityBP->ParentClass;
	if (ParentClass == nullptr)
		return;

	const bool bIsSkeletonOnly = CompileOptions.CompileType == EKismetCompileType::SkeletonOnly;

	// Don't do a bunch of extra work on the skeleton generated class.
	if (!bIsSkeletonOnly)
	{
		AbilityBP->UpdateTimelineTemplate(BPGClass);
	}

	FKismetCompilerContext::FinishCompilingClass(Class);
}

bool FLegoAbilityBlueprintCompilerContext::ValidateGeneratedClass(UBlueprintGeneratedClass* Class)
{
	return FKismetCompilerContext::ValidateGeneratedClass(Class) && ULegoAbilityBlueprint::ValidateGeneratedClass(Class);
}


void FLegoAbilityBlueprintCompilerContext::OnPostCDOCompiled(const UObject::FPostCDOCompiledContext& Context)
{
	FKismetCompilerContext::OnPostCDOCompiled(Context);

	if (Context.bIsSkeletonOnly)
	{
		return;
	}
}

#undef LOCTEXT_NAMESPACE

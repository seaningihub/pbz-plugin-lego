// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityBlueprint.h"
#include "LegoAbility.h"
#include "LGATimeline.h"
#include "Actions/LGAAction.h"
#include "DiffResults.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "K2Node_Variable.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"


void FLGATimelineOverride::ReplaceTimelineActions(ULGATimeline* InTimeline) const
{
	if (!InTimeline)
	{
		return;
	}

	for (FLGAActionEvent& ActionEvent : InTimeline->Actions)
	{
		if (ActionOverrides.Contains(ActionEvent.Guid))
		{
			ActionEvent.Action = ActionOverrides[ActionEvent.Guid];
		}
	}
}


/** Returns the most base ability blueprint for a given blueprint (if it is inherited from another ability blueprint, returning null if only native / non-ability BP classes are it's parent) */
ULegoAbilityBlueprint* ULegoAbilityBlueprint::FindRootLegoAbilityBlueprint(ULegoAbilityBlueprint* DerivedBlueprint)
{
	ULegoAbilityBlueprint* ParentBP = nullptr;

	// Determine if there is a ability blueprint in the ancestry of this class
	for (UClass* ParentClass = DerivedBlueprint->ParentClass; ParentClass != UObject::StaticClass(); ParentClass = ParentClass->GetSuperClass())
	{
		if (ULegoAbilityBlueprint* TestBP = Cast<ULegoAbilityBlueprint>(ParentClass->ClassGeneratedBy))
		{
			ParentBP = TestBP;
		}
	}

	return ParentBP;
}

bool ULegoAbilityBlueprint::ValidateGeneratedClass(const UClass* InClass)
{
	const ULegoAbilityBlueprintGeneratedClass* GeneratedClass = Cast<const ULegoAbilityBlueprintGeneratedClass>(InClass);
	if (!ensure(GeneratedClass))
	{
		return false;
	}

	const ULegoAbilityBlueprint* Blueprint = Cast<ULegoAbilityBlueprint>(GetBlueprintFromClass(GeneratedClass));
	if (!ensure(Blueprint))
	{
		return false;
	}

	return true;
}

bool ULegoAbilityBlueprint::RenameTimeline(ULegoAbilityBlueprint* Blueprint, const FName OldNameRef, const FName NewName)
{
	check(Blueprint);

	bool bRenamed = false;

	// make a copy, in case we alter the value of what is referenced by 
	// OldNameRef through the course of this function
	FName OldName = OldNameRef;

	TSharedPtr<INameValidatorInterface> NameValidator = MakeShareable(new FKismetNameValidator(Blueprint));
	const FString NewTemplateName = NewName.ToString();
	// NewName should be already validated. But one must make sure that NewTemplateName is also unique.
	const bool bUniqueNameForTemplate = (EValidatorResult::Ok == NameValidator->IsValid(NewTemplateName));

	ULGATimeline* Template = Blueprint->GetTimelineByName(OldName);
	ULGATimeline* NewTemplate = Blueprint->GetTimelineByName(NewName);
	if ((!NewTemplate && bUniqueNameForTemplate) || NewTemplate == Template)
	{
		if (Template)
		{
			Blueprint->Modify();
			Template->Modify();

			TArray<UK2Node_Variable*> TimelineVarNodes;
			FBlueprintEditorUtils::GetAllNodesOfClass<UK2Node_Variable>(Blueprint, TimelineVarNodes);
			for (int32 It = 0; It < TimelineVarNodes.Num(); It++)
			{
				UK2Node_Variable* TestNode = TimelineVarNodes[It];
				if (TestNode && (OldName == TestNode->GetVarName()))
				{
					UEdGraphPin* TestPin = TestNode->FindPin(OldName);
					if (TestPin && (ULGATimeline::StaticClass() == TestPin->PinType.PinSubCategoryObject.Get()))
					{
						TestNode->Modify();
						if (TestNode->VariableReference.IsSelfContext())
						{
							TestNode->VariableReference.SetSelfMember(NewName);
						}
						else
						{
							//TODO:
							UClass* ParentClass = TestNode->VariableReference.GetMemberParentClass((UClass*)nullptr);
							TestNode->VariableReference.SetExternalMember(NewName, ParentClass);
						}
						TestPin->Modify();
						TestPin->PinName = NewName;
					}
				}
			}

			Blueprint->AbilityTimelines.Remove(Template);

			UObject* ExistingObject = StaticFindObject(nullptr, Template->GetOuter(), *NewTemplateName, true);
			if (ExistingObject != Template && ExistingObject != nullptr)
			{
				ExistingObject->Rename(*MakeUniqueObjectName(ExistingObject->GetOuter(), ExistingObject->GetClass(), ExistingObject->GetFName()).ToString());
			}
			Template->Rename(*NewTemplateName, Template->GetOuter(), (Blueprint->bIsRegeneratingOnLoad ? REN_ForceNoResetLoaders : REN_None));
			Blueprint->AbilityTimelines.Add(Template);

			// Validate child blueprints and adjust variable names to avoid a potential name collision
			FBlueprintEditorUtils::ValidateBlueprintChildVariables(Blueprint, NewName);

			// Refresh references and flush editors
			FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
			bRenamed = true;
		}
	}
	return bRenamed;
}

void ULegoAbilityBlueprint::DeleteTimeline(ULegoAbilityBlueprint* Blueprint, ULGATimeline* Timeline)
{
	check(Blueprint);

	if (!Blueprint->AbilityTimelines.Contains(Timeline))
	{
		return;
	}


	Timeline->Rename(nullptr, GetTransientPackage(), REN_DontCreateRedirectors);
	Blueprint->AbilityTimelines.Remove(Timeline);


	// Iterate over currently-loaded Blueprints and potentially adjust their override timeline
	for (TObjectIterator<ULegoAbilityBlueprint> BlueprintIt; BlueprintIt; ++BlueprintIt)
	{
		ULegoAbilityBlueprint* ChildBP = *BlueprintIt;
		if (ChildBP != nullptr && ChildBP->ParentClass != nullptr)
		{
			TArray<UBlueprint*> ParentBPArray;
			// Get the parent hierarchy
			UBlueprint::GetBlueprintHierarchyFromClass(ChildBP->ParentClass, ParentBPArray);

			if (ParentBPArray.Contains(Blueprint))
			{
				if (ChildBP->AbilityTimelineOverrides.ContainsByPredicate([=](const FLGATimelineOverride& Item) {return Item.OverriddenTimeline == Timeline; }))
				{
					ChildBP->Modify();
					if (ChildBP->AbilityTimelineOverrides.RemoveAll([=](const FLGATimelineOverride& Item) {return Item.OverriddenTimeline == Timeline; }))
					{
						FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(ChildBP);
					}
				}
				
			}
		}
	}
}

ULGATimeline* ULegoAbilityBlueprint::GetTimelineByName(FName InName, bool bIncludeOverride) const
{
	for (ULGATimeline* Timeline : AbilityTimelines)
	{
		if (Timeline->GetFName() == InName)
		{
			return Timeline;
		}
	}

	if (bIncludeOverride)
	{
		for (const FLGATimelineOverride& Override : AbilityTimelineOverrides)
		{
			if (Override.OverriddenTimeline->GetFName() == InName && !Override.bInheritMode)
			{
				return Override.Timeline;
			}
		}
	}

	return nullptr;
}

ULGATimeline* ULegoAbilityBlueprint::FindLatestTimelineTamplate(ULGATimeline* OverriddenTimeline)
{
	TArray<UBlueprint*> ParentBPArray;
	// Get the parent hierarchy
	UBlueprint::GetBlueprintHierarchyFromClass(ParentClass, ParentBPArray);

	for (int32 i = 0; i < ParentBPArray.Num(); ++i)
	{
		if (ULegoAbilityBlueprint* LegoBlueprint = Cast<ULegoAbilityBlueprint>(ParentBPArray[i]))
		{
			if (FLGATimelineOverride* OverrideInfo = LegoBlueprint->AbilityTimelineOverrides.FindByPredicate([=](const FLGATimelineOverride& Item) {return OverriddenTimeline == Item.OverriddenTimeline;}))
			{
				if (!OverrideInfo->bInheritMode)
				{
					return OverrideInfo->Timeline;	
				}
			}
		}
	}

	return OverriddenTimeline;
}

bool ULegoAbilityBlueprint::HasChildrenTimeline(ULGATimeline* ParentTimeline) const
{
	for (const FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline && Override.bInheritMode)
		{
			if (Override.ParentTimeline == ParentTimeline)
			{
				return true;
			}
		}
	}

	return false;
}

bool ULegoAbilityBlueprint::HasTimeline(ULGATimeline* InTimeline) const
{
	for (ULGATimeline* Timeline : AbilityTimelines)
	{
		if (Timeline == InTimeline)
		{
			return true;
		}
	}

	for (const FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.Timeline == InTimeline && !Override.bInheritMode)
		{
			return true;
		}
	}

	return false;
}

ULGAAction* ULegoAbilityBlueprint::GetOverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid)
{
	for (const FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline && Override.bInheritMode)
		{
			if (Override.ParentTimeline == ParentTimeline)
			{
				if (Override.ActionOverrides.Contains(ActionGuid))
				{
					return Override.ActionOverrides[ActionGuid];
				}
			}
		}
	}

	return nullptr;
}

bool ULegoAbilityBlueprint::OverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid)
{
	for (FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline && Override.bInheritMode)
		{
			if (Override.ParentTimeline == ParentTimeline)
			{
				if (FLGAActionEvent* ParentActionEvent = ParentTimeline->GetActionEventByGuid(ActionGuid))
				{
					ULGAAction* NewAction = Cast<ULGAAction>(StaticDuplicateObject(ParentActionEvent->Action, this));
					Override.ActionOverrides.FindOrAdd(ActionGuid) = NewAction;

					return true;
				}
			}
		}
	}

	return false;
}

bool ULegoAbilityBlueprint::ResetOverrideAction(ULGATimeline* ParentTimeline, const FGuid& ActionGuid)
{
	for (FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline && Override.bInheritMode)
		{
			if (Override.ParentTimeline == ParentTimeline)
			{
				if (Override.ActionOverrides.Contains(ActionGuid))
				{
					Override.ActionOverrides.Remove(ActionGuid);

					return true;
				}
			}
		}
	}

	return false;
}


bool ULegoAbilityBlueprint::IsMyOverrideAction(ULGAAction* TestAction)
{
	for (FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline && Override.bInheritMode)
		{
			if (Override.bInheritMode)
			{
				for ( const auto& KeyValue : Override.ActionOverrides)
				{
					if (KeyValue.Value == TestAction)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

#if WITH_EDITOR
UClass* ULegoAbilityBlueprint::GetBlueprintClass() const
{
	return ULegoAbilityBlueprintGeneratedClass::StaticClass();
}

bool ULegoAbilityBlueprint::FindDiffs(const UBlueprint* OtherBlueprint, FDiffResults& Results) const
{
	const ULegoAbilityBlueprint* OtherAbilityBP = Cast<ULegoAbilityBlueprint>(OtherBlueprint);
	if (!OtherAbilityBP)
	{
		return false;
	}

	for (ULGATimeline* Timeline : AbilityTimelines)
	{
		FName TimelineName = Timeline->GetFName();
		if (ULGATimeline* OtherTimeline = OtherAbilityBP->GetTimelineByName(TimelineName))
		{
			// Already exist timeline
			FDiffSingleResult Diff;
			Diff.Diff = EDiffType::OBJECT_REQUEST_DIFF;
			Diff.Object1 = Timeline;
			Diff.Object2 = OtherTimeline;

			FFormatNamedArguments Args;
			Args.Add(TEXT("TimelineName"), FText::FromName(TimelineName));
			Diff.DisplayString = FText::Format(LOCTEXT("DIF_RequestTimelineLabel", "Timeline {TimelineName}"), Args);

			Results.Add(Diff);

			// Find diffs for actions
			for (const FLGAActionEvent& Event : Timeline->Actions)
			{
				FString ActionPathName = Event.Action->GetPathName(this);
				if (const FLGAActionEvent* OtherEvent = OtherTimeline->GetActionEventByName(Event.Action->GetFName()))
				{
					// Already exist action
					FDiffSingleResult ActionDiff;
					ActionDiff.Diff = EDiffType::OBJECT_REQUEST_DIFF;
					ActionDiff.Object1 = Event.Action;
					ActionDiff.Object2 = OtherEvent->Action;

					FFormatNamedArguments ActionArgs;
					ActionArgs.Add(TEXT("ActionPath"), FText::FromString(ActionPathName));
					ActionDiff.DisplayString = FText::Format(LOCTEXT("DIF_RequestActionLabel", "Action {ActionPath}"), ActionArgs);

					Results.Add(ActionDiff);
				}
				else
				{
					// Newly added action
					FDiffSingleResult ActionDiff;
					ActionDiff.Diff = EDiffType::OBJECT_ADDED;
					ActionDiff.Object1 = Event.Action;

					FFormatNamedArguments ActionArgs;
					ActionArgs.Add(TEXT("ActionPath"), FText::FromString(ActionPathName));
					ActionDiff.DisplayString = FText::Format(LOCTEXT("DIF_AddedActionLabel", "Added Action {ActionPath}"), ActionArgs);

					Results.Add(ActionDiff);
				}
			}

			for (const FLGAActionEvent& Event : OtherTimeline->Actions)
			{
				if (!Timeline->GetActionEventByName(Event.Action->GetFName()))
				{
					// Deleted action
					FDiffSingleResult ActionDiff;
					ActionDiff.Diff = EDiffType::OBJECT_REMOVED;
					ActionDiff.Object1 = Event.Action;

					FFormatNamedArguments ActionArgs;
					ActionArgs.Add(TEXT("ActionPath"), FText::FromString(Event.Action->GetPathName(OtherAbilityBP)));
					ActionDiff.DisplayString = FText::Format(LOCTEXT("DIF_RemovedActionLabel", "Removed Action {ActionPath}"), ActionArgs);

					Results.Add(ActionDiff);
				}
			}
		}
		else
		{
			// Newly added timeline
			FDiffSingleResult Diff;
			Diff.Diff = EDiffType::OBJECT_ADDED;
			Diff.Object1 = Timeline;

			FFormatNamedArguments Args;
			Args.Add(TEXT("TimelineName"), FText::FromName(TimelineName));
			Diff.DisplayString = FText::Format(LOCTEXT("DIF_AddedTimelineLabel", "Added Timeline {TimelineName}"), Args);

			Results.Add(Diff);
		}
	}

	for (ULGATimeline* Timeline : OtherAbilityBP->AbilityTimelines)
	{
		FName TimelineName = Timeline->GetFName();
		if (!GetTimelineByName(TimelineName))
		{
			// Deleted timeline
			FDiffSingleResult Diff;
			Diff.Diff = EDiffType::OBJECT_REMOVED;
			Diff.Object1 = Timeline;

			FFormatNamedArguments Args;
			Args.Add(TEXT("TimelineName"), FText::FromName(TimelineName));
			Diff.DisplayString = FText::Format(LOCTEXT("DIF_RemovedTimelineLabel", "Removed Timeline {TimelineName}"), Args);

			Results.Add(Diff);
		}
	}

	return true;
}

void ULegoAbilityBlueprint::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if (PropertyChangedEvent.GetNumObjectsBeingEdited() > 0 && PropertyChangedEvent.GetObjectBeingEdited(0)->IsA<ULGAAction>())
	{
		UpdateTimelineTemplate();
	}
}

void ULegoAbilityBlueprint::ClearInvalidTimelines()
{
	bool bDirty = false;
	int32 Index = AbilityTimelineOverrides.Num() - 1;
	while (Index >= 0)
	{
		ULGATimeline* CurrentOverridenTimeline = AbilityTimelineOverrides[Index].OverriddenTimeline;
		if (CurrentOverridenTimeline == nullptr)
		{
			AbilityTimelineOverrides.RemoveAt(Index);
			bDirty = true;
		}
		else
		{
			bool bHasValidParent = false;
			TArray<UBlueprint*> ParentBPArray;

			const ULegoAbilityBlueprint* CurrentBlueprint = this;

			// Get the parent hierarchy
			UBlueprint::GetBlueprintHierarchyFromClass(CurrentBlueprint->ParentClass, ParentBPArray);
			for (int32 i = 0; i < ParentBPArray.Num(); ++i)
			{
				if (ULegoAbilityBlueprint* LegoBlueprint = Cast<ULegoAbilityBlueprint>(ParentBPArray[i]))
				{
					bHasValidParent = LegoBlueprint->AbilityTimelines.ContainsByPredicate(
						[CurrentOverridenTimeline](ULGATimeline* Item)
						{
							return Item == CurrentOverridenTimeline;
						}
					);
					if (bHasValidParent)
					{
						break;
					}
				}
			}
			if (!bHasValidParent)
			{
				AbilityTimelineOverrides.RemoveAt(Index);
				bDirty = true;
			}
		}

		--Index;
	}

	if (bDirty)
	{
		this->Modify();
	}
}

void ULegoAbilityBlueprint::PostLoad()
{
	Super::PostLoad();

	
}

#endif

void ULegoAbilityBlueprint::UpdateTimelineTemplate(UObject* TargetClass /*= nullptr*/)
{
	if (!TargetClass)
	{
		TargetClass = GeneratedClass;
	}

	if (!TargetClass)
	{
		return;
	}

	ULegoAbilityBlueprintGeneratedClass* BPGClass = CastChecked<ULegoAbilityBlueprintGeneratedClass>(TargetClass);
	BPGClass->AbilityTimelines.Reset();
	BPGClass->ActionOverrides.Reset();

	int32 TimelineIndex = 0;
	for (const ULGATimeline* Timeline : AbilityTimelines)
	{
		ULGATimeline* ClonedTimeline = DuplicateObject<ULGATimeline>(Timeline, BPGClass, *(Timeline->GetName() /*+ TEXT("_INST")*/));

		BPGClass->AbilityTimelines.Add(ClonedTimeline);
		TimelineIndex++;
	}

	for (const FLGATimelineOverride& Override : AbilityTimelineOverrides)
	{
		if (Override.OverriddenTimeline)
		{
			if (Override.bInheritMode)
			{
				FLGAActionOverride* ActionOverride = BPGClass->ActionOverrides.FindByPredicate([=](const FLGAActionOverride& Item){return Override.OverriddenTimeline->GetFName() == Item.TimelineName;});
				if (!ActionOverride)
				{
					ActionOverride = &BPGClass->ActionOverrides.Emplace_GetRef();
					ActionOverride->TimelineName = Override.OverriddenTimeline->GetFName();
				}

				ActionOverride->TimeStretchCurveName = Override.Timeline ? Override.Timeline->TimeStretchCurveName : FName("Rate");
				ActionOverride->StartTimeSeconds = Override.Timeline ? Override.Timeline->StartTimeSeconds : 0.f;
				if (Override.Timeline)
				{
					ActionOverride->DynamicBlendSettings = Override.Timeline->DynamicBlendSettings;
				}

				for (const auto& GuidAction : Override.ActionOverrides)
				{
					ULGAAction* ClonedAction = DuplicateObject<ULGAAction>(GuidAction.Value, BPGClass, *(GuidAction.Value->GetName()));;
					ActionOverride->Overrides.Add(GuidAction.Key) = ClonedAction;
				}
			}
			else
			{
				ULGATimeline* ClonedTimeline = DuplicateObject<ULGATimeline>(Override.Timeline, BPGClass, *(Override.OverriddenTimeline->GetName()));
				ClonedTimeline->bAutoPlay = Override.OverriddenTimeline->bAutoPlay;
				ClonedTimeline->bLooping = Override.OverriddenTimeline->bLooping;
				ClonedTimeline->bStopAbility = Override.OverriddenTimeline->bStopAbility;

				BPGClass->AbilityTimelines.Add(ClonedTimeline);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE 



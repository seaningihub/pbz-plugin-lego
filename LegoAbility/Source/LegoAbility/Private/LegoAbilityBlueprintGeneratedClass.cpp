// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LegoAbility.h"
#include "LGATimeline.h"
#include "Actions/LGAAction.h"

#define LOCTEXT_NAMESPACE "LegoAbility"

void ULegoAbilityBlueprintGeneratedClass::InitializeAbility(ULegoAbility* LegoAbility) const
{
	if (LegoAbility->IsTemplate())
	{
		return;
	}

	TArray<const ULGATimeline*> AllTimelines = GetAllTimelines();

	for (const ULGATimeline* ConstTimeline : AllTimelines)
	{
		ULGATimeline* Timeline = const_cast<ULGATimeline*>(ConstTimeline);
		ULGATimeline* NewTimeline = NewObject<ULGATimeline>(LegoAbility, Timeline->GetClass(), Timeline->GetFName(), RF_Transactional, Timeline);
		NewTimeline->SetFlags(RF_Transient | RF_DuplicateTransient);
		LegoAbility->AddTimeline(NewTimeline);

		// Override actions
		if (const FLGAActionOverride* ActionOverride = ActionOverrides.FindByPredicate([=](const FLGAActionOverride& Item){return NewTimeline->GetFName() == Item.TimelineName;}))
		{
			for (FLGAActionEvent& ActionEvent : NewTimeline->Actions)
			{
				if (ActionOverride->Overrides.Contains(ActionEvent.Guid))
				{
					ULGAAction* OverrideAction = ActionOverride->Overrides[ActionEvent.Guid];
					ULGAAction* NewAction = DuplicateObject<ULGAAction>(OverrideAction, NewTimeline, OverrideAction->GetFName());
					ActionEvent.Action = NewAction;
				}
			}
			NewTimeline->TimeStretchCurveName = ActionOverride->TimeStretchCurveName;
			NewTimeline->StartTimeSeconds = ActionOverride->StartTimeSeconds;
			NewTimeline->DynamicBlendSettings = ActionOverride->DynamicBlendSettings;
		}

		// Find property with the same name as the animation and assign the animation to it.
		if (FObjectPropertyBase* Property = FindFProperty<FObjectPropertyBase>(LegoAbility->GetClass(), Timeline->GetFName()))
		{
			Property->SetObjectPropertyValue_InContainer(LegoAbility, NewTimeline);
		}
	}
}

TArray<const ULGATimeline*> ULegoAbilityBlueprintGeneratedClass::GetAllTimelines() const
{
	TArray<const ULGATimeline*> AllTimelines;

	// Include current class timelines.
	AllTimelines.Append(AbilityTimelines);

	// Include all super class timelines.
	UClass* SuperClass = GetSuperClass();
	while (ULegoAbilityBlueprintGeneratedClass* BGC = Cast<ULegoAbilityBlueprintGeneratedClass>(SuperClass))
	{
		for (ULGATimeline* InheritTimeline : BGC->AbilityTimelines)
		{
			if (AllTimelines.ContainsByPredicate([=](const ULGATimeline* Item) {return Item->GetFName() == InheritTimeline->GetFName();}))
			{
				continue;
			}

			AllTimelines.Add(InheritTimeline);
		}
		
		SuperClass = SuperClass->GetSuperClass();
	}

	return MoveTemp(AllTimelines);
}

#undef LOCTEXT_NAMESPACE
// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGADetailsTabBody.h"
#include "IDetailsView.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "LegoAbilityBlueprintGeneratedClass.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorSettings.h"
#include "Timeline/LGATimelineModel.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

void SLGADetailsTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	FDetailsViewArgs DetailsViewArgs;
			
	DetailsViewArgs.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;
	DetailsViewArgs.NotifyHook = InAbilityEditor.Get();
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsViewArgs.bHideSelectionTip = true;

	PropertyView = FModuleManager::Get().GetModuleChecked<FPropertyEditorModule>("PropertyEditor").CreateDetailView(DetailsViewArgs);

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			PropertyView.ToSharedRef()
		]
	];

	PropertyView->SetObject(InAbilityEditor->GetAbilityBlueprintGeneratedClass()->GetDefaultObject());
}

void SActionDetailsTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	FDetailsViewArgs DetailsViewArgs;

	DetailsViewArgs.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;
	DetailsViewArgs.NotifyHook = InAbilityEditor.Get();
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsViewArgs.bHideSelectionTip = true;


	PropertyView = FModuleManager::Get().GetModuleChecked<FPropertyEditorModule>("PropertyEditor").CreateDetailView(DetailsViewArgs);

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			PropertyView.ToSharedRef()
		]

		+ SVerticalBox::Slot()
		[
			SNew(SVerticalBox)
				.Visibility(this, &SActionDetailsTabBody::ShowActionButtons)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBox)
						.Visibility(this, &SActionDetailsTabBody::ShowActionOverrideButton)
						.HeightOverride(30)
						.WidthOverride(200)
						[
							SNew(SButton)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								.Text(LOCTEXT("Override Action", "Override Action"))
								.OnClicked(this, &SActionDetailsTabBody::OverrideAction)
						]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SBox)
						.Visibility(this, &SActionDetailsTabBody::ShowActionResetButton)
						.HeightOverride(30)
						.WidthOverride(200)
						[
							SNew(SButton)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								.Text(LOCTEXT("Reset to Default", "Reset to Default"))
								.OnClicked(this, &SActionDetailsTabBody::ResetToDefault)
						]
				]
		]
		
	];

	TimelineModel = InAbilityEditor->GetAnimModel();
	InAbilityEditor->GetAnimModel()->OnSelectObjects = FOnObjectsSelected::CreateSP(this, &SActionDetailsTabBody::OnObjectsSelected);

	PropertyView->SetEnabled(TAttribute<bool>(this, &SActionDetailsTabBody::IsPropertyEditable));
}


void SActionDetailsTabBody::OnObjectsSelected(const TArray<UObject*>& InObjects)
{
	SelectedActionObject.Reset();
	EditingOverrideActionObject.Reset();
	IsInheritTimelineSelected = false;

	if (InObjects.Num() > 1)
	{
		PropertyView->SetObject(nullptr);
		return;
	}

	bool IsTimelineSelected = false;
	if (InObjects.Num() == 1)
	{
		SelectedActionObject = Cast<ULGAAction>(InObjects[0]);
		if (SelectedActionObject.IsValid())
		{
			TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
			ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
			ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();
			FLGAActionEvent* ActionEvent = CurrentTimeline->GetActionEventByAction(SelectedActionObject.Get());

			if (ULGAAction* OverrideAction = AbilityBlueprint->GetOverrideAction(CurrentTimeline, ActionEvent->Guid))
			{
				TArray<UObject*> Objects;
				Objects.Add(OverrideAction);

				PropertyView->SetObjects(Objects);

				EditingOverrideActionObject = OverrideAction;
				return;
			}
		}

		if (Cast<ULGATimeline>(InObjects[0]))
		{
			IsTimelineSelected = true;
		}
	}
	
	if (IsTimelineSelected || InObjects.IsEmpty())
	{
		TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
		ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
		ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();

		if (CurrentTimeline && CurrentTimeline != ULGATimeline::GetNullTimeline())
		{
			if (FLGATimelineOverride* OverrideInfo = AbilityBlueprint->AbilityTimelineOverrides.FindByPredicate(
				[=](const FLGATimelineOverride& Item) {return CurrentTimeline == Item.ParentTimeline && Item.OverriddenTimeline && Item.bInheritMode; }))
			{
				CurrentTimeline = OverrideInfo->Timeline;
				IsInheritTimelineSelected = true;
			}
		}

		PropertyView->SetObject(CurrentTimeline);
		return;
	}


	PropertyView->SetObjects(InObjects);
}

FReply SActionDetailsTabBody::OverrideAction()
{
	if (!SelectedActionObject.IsValid())
	{
		return FReply::Handled();
	}

	if (!TimelineModel.IsValid())
	{
		return FReply::Handled();
	}

	TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
	if (!AbilityEditor.IsValid())
	{
		return  FReply::Handled();
	}

	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();
	if (!CurrentTimeline)
	{
		return FReply::Handled();
	}

	FLGAActionEvent* ActionEvent = CurrentTimeline->GetActionEventByAction(SelectedActionObject.Get());
	if (!ActionEvent)
	{
		return FReply::Handled();
	}

	AbilityBlueprint->OverrideAction(CurrentTimeline, ActionEvent->Guid);

	FPropertyChangedEvent PropertyChangedEvent(nullptr);
	SelectedActionObject->PostEditChangeProperty(PropertyChangedEvent);
	
	
	return FReply::Handled();
}

FReply SActionDetailsTabBody::ResetToDefault()
{
	if (!SelectedActionObject.IsValid())
	{
		return FReply::Handled();
	}

	if (!TimelineModel.IsValid())
	{
		return FReply::Handled();
	}

	TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
	if (!AbilityEditor.IsValid())
	{
		return  FReply::Handled();
	}

	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();
	if (!CurrentTimeline)
	{
		return FReply::Handled();
	}

	FLGAActionEvent* ActionEvent = CurrentTimeline->GetActionEventByAction(SelectedActionObject.Get());
	if (!ActionEvent)
	{
		return FReply::Handled();
	}

	AbilityBlueprint->ResetOverrideAction(CurrentTimeline, ActionEvent->Guid);

	FPropertyChangedEvent PropertyChangedEvent(nullptr);
	SelectedActionObject->PostEditChangeProperty(PropertyChangedEvent);
	
	
	return FReply::Handled();
}

EVisibility SActionDetailsTabBody::ShowActionButtons() const
{
	if (SelectedActionObject.IsValid())
	{
		if (TimelineModel.IsValid())
		{
			TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
			if (!AbilityEditor.Pin()->IsCurrentTimelineLocal())
			{
				return EVisibility::Visible;
			}
		}
	}

	return EVisibility::Collapsed;
}

EVisibility SActionDetailsTabBody::ShowActionOverrideButton() const
{
	if (SelectedActionObject.IsValid())
	{
		if (TimelineModel.IsValid())
		{
			TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
			ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

			ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();
			FLGAActionEvent* ActionEvent = CurrentTimeline->GetActionEventByAction(SelectedActionObject.Get());
			
			if (AbilityBlueprint && ActionEvent && !AbilityBlueprint->GetOverrideAction(CurrentTimeline, ActionEvent->Guid))
			{
				return EVisibility::Visible;
			}
		}
	}

	return EVisibility::Collapsed;
}

EVisibility SActionDetailsTabBody::ShowActionResetButton() const
{
	if (SelectedActionObject.IsValid())
	{
		if (TimelineModel.IsValid())
		{
			TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
			ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

			ULGATimeline* CurrentTimeline = TimelineModel.Pin()->GetAbilityTimeline();
			FLGAActionEvent* ActionEvent = CurrentTimeline->GetActionEventByAction(SelectedActionObject.Get());
			
			if (AbilityBlueprint && ActionEvent && EditingOverrideActionObject.IsValid() && AbilityBlueprint->GetOverrideAction(CurrentTimeline, ActionEvent->Guid))
			{
				return EVisibility::Visible;
			}
		}
	}

	return EVisibility::Collapsed;
}

bool SActionDetailsTabBody::IsPropertyEditable() const
{
	TWeakPtr<FLegoAbilityEditor> AbilityEditor = TimelineModel.Pin()->GetAbilityEditor();
	bool IsLocalTimeline = AbilityEditor.Pin()->IsCurrentTimelineLocal();


	return IsLocalTimeline || ShowActionResetButton() == EVisibility::Visible || IsInheritTimelineSelected;
}


void SLegoAbilityEditorSettingsTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	SSingleObjectDetailsPanel::Construct(SSingleObjectDetailsPanel::FArguments(), false, true);

	TArray<UObject*> Objects;
	Objects.Add(&InAbilityEditor->GetEditorSettings());
	SetPropertyWindowContents(Objects);
}

#undef LOCTEXT_NAMESPACE


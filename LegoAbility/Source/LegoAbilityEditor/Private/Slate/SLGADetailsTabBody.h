// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SSingleObjectDetailsPanel.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

class FLegoAbilityEditor;
class FLGATimelineModel;

// Ability Details Tab
class SLGADetailsTabBody : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGADetailsTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);

private:
	TSharedPtr<class IDetailsView> PropertyView;
};

// Action Details Tab
class SActionDetailsTabBody : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SActionDetailsTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);
	void OnObjectsSelected(const TArray<UObject*>& InObjects);

	FReply OverrideAction();
	FReply ResetToDefault();

	EVisibility ShowActionButtons() const;

	EVisibility ShowActionOverrideButton() const;
	EVisibility ShowActionResetButton() const;
	bool IsPropertyEditable() const;

private:
	TSharedPtr<class IDetailsView> PropertyView;

	TWeakPtr<FLGATimelineModel> TimelineModel;

	TWeakObjectPtr<ULGAAction> SelectedActionObject;
	TWeakObjectPtr<ULGAAction> EditingOverrideActionObject;

	bool IsInheritTimelineSelected;
};

// Editor Settings Properties Tab
class SLegoAbilityEditorSettingsTabBody : public SSingleObjectDetailsPanel
{
public:
	SLATE_BEGIN_ARGS(SLegoAbilityEditorSettingsTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);
};

#undef LOCTEXT_NAMESPACE
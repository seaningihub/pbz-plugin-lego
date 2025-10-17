// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Views/SListView.h"
#include "LegoAbilityBlueprint.h"

class SSearchBox;
class FLegoAbilityEditor;
class FUICommandList;
class ULGATimeline;

struct FAbilityTimelineListItem
{
	FAbilityTimelineListItem(ULGATimeline* InTimeline, bool bInRenameRequestPending = false, bool bInNewTimeline = false)
		: Timeline(InTimeline)
		, bRenameRequestPending(bInRenameRequestPending)
		, bNewTimeline(bInNewTimeline)
	{}

	ULGATimeline* Timeline;
	bool bRenameRequestPending;
	bool bNewTimeline;
};

typedef SListView<TSharedPtr<FAbilityTimelineListItem>> SAbilityTimelineListView;


struct FAbilityTimelineOverrideListItem
{
	FAbilityTimelineOverrideListItem(const FLGATimelineOverride& InTimelineOverride)
		: TimelineOverride(InTimelineOverride)
	{}

	FLGATimelineOverride TimelineOverride;
};

typedef SListView<TSharedPtr<FAbilityTimelineOverrideListItem>> SAbilityTimelineOverrideListView;


class SLGATimelineListTabBody : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineListTabBody) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor);
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

private:
	void RegenTimelineListItems();
	void SelectDefaultTimeline();
	void RestoreSelection();
	void RefreshTimelineList();
	void OnItemScrolledIntoView(TSharedPtr<FAbilityTimelineListItem> InListItem, const TSharedPtr<ITableRow>& InWidget) const;
	FReply OnNewTimelineClicked();
	void OnSearchChanged(const FText& InSearchText);
	void OnSelectionChanged(TSharedPtr<FAbilityTimelineListItem> InSelectedItem, ESelectInfo::Type SelectionInfo);
	TSharedPtr<SWidget> OnContextMenuOpening() const;
	TSharedRef<ITableRow> OnGenerateRow(TSharedPtr<FAbilityTimelineListItem> InListItem, const TSharedRef<STableViewBase>& InOwnerTableView);
	void CreateCommandList();
	bool CanExecuteContextMenuAction() const;
	void OnDuplicateTimeline();
	void OnDeleteTimeline();
	void OnRenameTimeline();
	void ConvertToOverrideMode();
	void ConvertToInheritMode();

	void OnOverrideSelectionChanged(TSharedPtr<FAbilityTimelineOverrideListItem> InSelectedItem, ESelectInfo::Type SelectionInfo);
	TSharedPtr<SWidget> OnOverrideContextMenuOpening();
	TSharedRef<ITableRow> OnGenerateOverrideRow(TSharedPtr<FAbilityTimelineOverrideListItem> InListItem, const TSharedRef<STableViewBase>& InOwnerTableView);
	void OverrideTimeline(ULGATimeline* Timeline);
	TSharedRef<SWidget> OnGetOverrideTimelineList();
	TArray<ULGATimeline*> GetParrentTimelines(bool bCanOverride=false);

	void OnBlueprintChanged(UBlueprint* InBlueprint);

private:
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
	TSharedPtr<FUICommandList> CommandList;
	TSharedPtr<SAbilityTimelineListView> TimelineListView;
	TArray<TSharedPtr<FAbilityTimelineListItem>> Timelines;
	TSharedPtr<SSearchBox> SearchBoxPtr;

	TSharedPtr<SAbilityTimelineOverrideListView> TimelineOverrideListView;
	TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> TimelineOverrides;
	TSharedPtr<SVerticalBox> OverrideTimelineBox;
};

// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGATimelineTrack.h"

namespace ELGATimingElementType { enum Type; }
class SLGAActionPanel;
class SVerticalBox;
class SInlineEditableTextBlock;

/** A timeline track that re-uses the legacy panel widget to display all ability actions */
class FLGATimelineTrack_ActionsPanel : public FLGATimelineTrack
{
public:
	static const float NotificationTrackHeight;

	FLGATimelineTrack_ActionsPanel(const TSharedRef<FLGATimelineModelBase>& InModel);

	/** FAnimTimelineTrack interface */
	virtual TSharedRef<SWidget> GenerateContainerWidgetForTimeline() override;
	virtual TSharedRef<SWidget> GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow) override;
	virtual bool SupportsFiltering() const override { return false; }

	void Update();

	/** Request a rename next update */
	void RequestTrackRename(int32 InTrackIndex) { PendingRenameTrackIndex = InTrackIndex; }

private:
	TSharedRef<SWidget> BuildNotifiesPanelSubMenu(int32 InTrackIndex);
	void InsertTrack(int32 InTrackIndexToInsert);
	void RemoveTrack(int32 InTrackIndexToRemove);
	void RefreshOutlinerWidget();
	FText GetTrackName(int32 TrackIndex) const;
	void OnCommitTrackName(const FText& InText, ETextCommit::Type CommitInfo, int32 TrackIndex);
	EVisibility OnGetTimingNodeVisibility(ELGATimingElementType::Type ElementType) const;
	EActiveTimerReturnType HandlePendingRenameTimer(double InCurrentTime, float InDeltaTime, TWeakPtr<SInlineEditableTextBlock> InInlineEditableTextBlock);

	/** The legacy notify panel */
	TSharedPtr<SLGAActionPanel> AnimNotifyPanel;

	/** The outliner widget to allow for dynamic refresh */
	TSharedPtr<SVerticalBox> OutlinerWidget;

	/** Track index we want to trigger a rename for */
	int32 PendingRenameTrackIndex;
};
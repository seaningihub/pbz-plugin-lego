// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "LGATimelineTrack.h"

class FLGATimelineTrack_ActionsPanel;

/** A timeline track that re-uses the legacy panel widget to display ability actions category */
class FLGATimelineTrack_Actions : public FLGATimelineTrack
{
public:
	FLGATimelineTrack_Actions(const TSharedRef<FLGATimelineModelBase>& InModel);

	/** FAnimTimelineTrack interface */
	virtual TSharedRef<SWidget> GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow) override;

	/** Get a new, unused track name using the specified anim sequence */
	static FName GetNewTrackName(ULGATimeline* Timeline);

	void SetAnimNotifyPanel(const TSharedRef<FLGATimelineTrack_ActionsPanel>& InNotifiesPanel) { NotifiesPanel = InNotifiesPanel; }

private:
	/** Populate the track menu */
	TSharedRef<SWidget> BuildNotifiesSubMenu();

	/** Add a new track */
	void AddTrack();
	
	/** The legacy notifies panel we are linked to */
	TWeakPtr<FLGATimelineTrack_ActionsPanel> NotifiesPanel;
};
// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LGATimelineTrack.h"

class SLGATimelineTimingPanel;

/** A timeline track that re-uses the legacy panel widget to display anim timing panel */
class FLGATimelineTrack_TimingPanel : public FLGATimelineTrack
{
public:
	FLGATimelineTrack_TimingPanel(const TSharedRef<FLGATimelineModelBase>& InModel);

	/** FAnimTimelineTrack interface */
	virtual TSharedRef<SWidget> GenerateContainerWidgetForTimeline() override;
	virtual TSharedRef<SWidget> GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow) override;
	virtual bool SupportsFiltering() const override { return false; }

private:
	TSharedRef<SWidget> BuildTimingSubMenu();

	/** The legacy timing panel */
	TSharedPtr<SLGATimelineTimingPanel> AnimTimingPanel;
};
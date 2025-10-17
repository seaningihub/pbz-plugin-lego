// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "SLGATrack.h"

class FArrangedChildren;

//////////////////////////////////////////////////////////////////////////
// Specialised anim track which arranges overlapping nodes into groups
class SLGATimelineTimingTrack : public SLGATrack
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineTimingTrack) {}

	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_ATTRIBUTE(float, TrackMaxValue)
	SLATE_ATTRIBUTE(float, TrackMinValue)
	SLATE_ATTRIBUTE(int32, TrackNumDiscreteValues)

	SLATE_END_ARGS()

	void Construct(const FArguments& Args);

	virtual void OnArrangeChildren( const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren ) const override;
};

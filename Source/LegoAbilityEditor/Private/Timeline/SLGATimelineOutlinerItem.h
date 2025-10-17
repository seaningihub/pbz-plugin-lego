// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Views/STableViewBase.h"
#include "Widgets/Views/STableRow.h"
#include "LGATimelineTrack.h"

class SLGATimelineTrack;

class SLGATimelineOutlinerItem : public SMultiColumnTableRow<TSharedRef<FLGATimelineTrack>>
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineOutlinerItem) {}

	/** Text to highlight when searching */
	SLATE_ATTRIBUTE(FText, HighlightText)

	SLATE_END_ARGS()

	~SLGATimelineOutlinerItem();

	void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTableView, const TSharedRef<FLGATimelineTrack>& InTrack);

	/** SWidget interface */
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual bool IsHovered() const;

	/** SMultiColumnTableRow interface */
	virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnId) override;

	/** Get the track this item represents */
	TSharedRef<FLGATimelineTrack> GetTrack() const { return Track.Pin().ToSharedRef(); }

	/** Add a reference to the specified track, keeping it alive until this row is destroyed */
	void AddTrackAreaReference(const TSharedPtr<SLGATimelineTrack>& InTrackWidget);

	/** Get the text to highlight when searching */
	TAttribute<FText> GetHighlightText() const { return HighlightText; }

private:
	/** The track that we represent */
	TWeakPtr<FLGATimelineTrack> Track;

	/** Cached reference to a track lane that we relate to. This keeps the track lane alive (it's a weak widget) as long as we are in view. */
	TSharedPtr<SLGATimelineTrack> TrackWidget;

	/** Text to highlight when searching */
	TAttribute<FText> HighlightText;
};
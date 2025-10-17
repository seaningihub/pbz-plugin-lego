// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "Templates/SharedPointer.h"
#include "ITimeSlider.h"
#include "UObject/GCObject.h"
#include "AnimatedRange.h"

enum class EViewRangeInterpolation;
class FLGATimelineTrack;
class FMenuBuilder;
class FLegoAbilityEditor;
class FUICommandList;
class ULGATimeline;
class FLGATimelinePreviewer;


/** Support structure for EditCurves */
struct FCurveEditInfo
{
	FCurveEditInfo(ULGATimeline* InTimeline, FName InCurveName, FSimpleDelegate InOnCurveModified)
		: Timeline(InTimeline)
		, CurveName(InCurveName)
		, OnCurveModified(InOnCurveModified)
	{}

	bool operator==(const FCurveEditInfo& InCurveEditInfo) const
	{
		return Timeline == InCurveEditInfo.Timeline && CurveName == InCurveEditInfo.CurveName;
	}

	ULGATimeline* Timeline;
	FName CurveName;

	FSimpleDelegate OnCurveModified;
};


// Called to display a selected object in a details panel
DECLARE_DELEGATE_OneParam(FOnObjectsSelected, const TArray<UObject*>& /*InObjects*/);

// Called to invoke the curve editor
DECLARE_DELEGATE_OneParam(FOnEditCurves, const FCurveEditInfo& /*InCurveInfo*/);


/** Model of the ability timeline's data */
class FLGATimelineModelBase : public TSharedFromThis<FLGATimelineModelBase>
{
public:
	FLGATimelineModelBase(const TSharedRef<FUICommandList>& InCommandList, TSharedPtr<FLegoAbilityEditor> AbilityEditor);

	virtual ~FLGATimelineModelBase();

	/** Bind commands and perform any one-time initialization */
	virtual void Initialize() {}

	TWeakPtr<FLegoAbilityEditor> GetAbilityEditor(){ return WeakAbilityEditor; }

	/** Get the root tracks representing the tree */
	TArray<TSharedRef<FLGATimelineTrack>>& GetRootTracks() { return RootTracks; }
	const TArray<TSharedRef<FLGATimelineTrack>>& GetRootTracks() const { return RootTracks; }

	/* Get the previewer for timeline*/
	TSharedPtr<FLGATimelinePreviewer> GetTimelinePreviewer();

	/** Get the current view range */
	FAnimatedRange GetViewRange() const;

	/** Set the current view range */
	void SetViewRange(TRange<double> InRange);

	/** Fit timeline lenght to acturul action's occupancy */
	void ResizeTimelineToActions();

	/** Get the working range of the model's data */
	FAnimatedRange GetWorkingRange() const;

	/** Get the playback range of the model's data */
	TRange<FFrameNumber> GetPlaybackRange() const;

	/** Set the playback range of the model's data */
	void SetPlaybackRange(TRange<FFrameNumber> NewRange);

	/** Get the current scrub position */
	FFrameNumber GetScrubPosition() const;

	/** Set the current scrub position */
	void SetScrubPosition(FFrameTime NewScrubPostion) const;

	/** Handle the view range being changed */
	void HandleViewRangeChanged(TRange<double> InRange, EViewRangeInterpolation InInterpolation);

	/** Handle the working range being changed */
	void HandleWorkingRangeChanged(TRange<double> InRange);

	/** Delegate fired when tracks have changed */
	DECLARE_EVENT(FLGATimelineModelBase, FOnTracksChanged)
	FOnTracksChanged& OnTracksChanged() { return OnTracksChangedDelegate; }

	/** Delegate fired when objects have been selected */
	DECLARE_EVENT_OneParam(FLGATimelineModelBase, FOnHandleObjectsSelected, const TArray<UObject*>& /*InObjects*/)
	FOnHandleObjectsSelected& OnHandleObjectsSelected() { return OnHandleObjectsSelectedDelegate; }

	/** Refresh the tracks we have using our underlying asset */
	virtual void RefreshTracks() = 0;

	/** Update the displayed range if the length of the sequence could have changed */
	virtual void UpdateRange(bool ResetWorkingRange = false) = 0;

	/** Get the underlying ability timeline */
	virtual ULGATimeline* GetAbilityTimeline() const = 0;

	/** Get the command list */
	TSharedRef<FUICommandList> GetCommandList() const { return WeakCommandList.Pin().ToSharedRef(); }

	/** Get whether a track is selected */
	bool IsTrackSelected(const TSharedRef<FLGATimelineTrack>& InTrack) const;

	/** Clear all track selection */
	void ClearTrackSelection();

	/** Set whether a track is selected */
	void SetTrackSelected(const TSharedRef<FLGATimelineTrack>& InTrack, bool bIsSelected);
	
	/** 'Selects' objects and shows them in the details view */
	void SelectObjects(const TArray<UObject*>& Objects);

	TArray<class ULGAAction*>& GetSelectedActions(){return SelectedActions;};

	/** Clears the detail view of whatever we displayed last */
	void ClearDetailsView();

	/**
	 * Calculates the sequence length of the object 
	 *  @return		New sequence length
	 */
	virtual float CalculateSequenceLengthOfEditorObject() const;

	/** Access editable times */
	const TArray<double>& GetEditableTimes() const { return EditableTimes; }
	void SetEditableTimes(const TArray<double>& InTimes) { EditableTimes = InTimes; }

	/** Set an editable time */
	void SetEditableTime(int32 TimeIndex, double Time, bool bIsDragging);

	/** Override point for derived types to handle setting a time */
	virtual void OnSetEditableTime(int32 TimeIndex, double Time, bool bIsDragging) {}

	/** Get the framerate specified by the anim sequence */
	double GetFrameRate() const;

	/** Get the tick resolution we are displaying at */
	int32 GetTickResolution() const;

	/** Delegate used to edit object details */
	FOnObjectsSelected OnSelectObjects;

	/** 
	 * Snaps a time to the currently set snap times
	 * @param	InOutTime		The time to snap
	 * @param	InSnapMargin	The margin (in seconds) to limit the snap to
	 * @return true if a snap occurred
	 */
	bool Snap(float& InOutTime, float InSnapMargin, bool bEnableSnapToFrame) const;
	bool Snap(double& InOutTime, double InSnapMargin, bool bEnableSnapToFrame) const;

	/** Build a context menu for selected items */
	virtual void BuildContextMenu(FMenuBuilder& InMenuBuilder);

	/** Delegate used to edit curves */
	FOnEditCurves OnEditCurves;

protected:
	/** Tracks used to generate a tree */
	TArray<TSharedRef<FLGATimelineTrack>> RootTracks;

	/** Tracks that are selected */
	TSet<TSharedRef<FLGATimelineTrack>> SelectedTracks;

	TArray<class ULGAAction*> SelectedActions;

	/** The range we are currently viewing */
	FAnimatedRange ViewRange;

	/** The working range of this model, encompassing the view range */
	FAnimatedRange WorkingRange;

	/** Delegate fired when tracks change */
	FOnTracksChanged OnTracksChangedDelegate;

	/** Delegate fired when selection changes */
	FOnHandleObjectsSelected OnHandleObjectsSelectedDelegate;

	/** The command list we bind to */
	TWeakPtr<FUICommandList> WeakCommandList;

	/** The ability editor we bind to */
	TWeakPtr<FLegoAbilityEditor> WeakAbilityEditor;

	/** Times that can be edited by dragging bars in the UI */
	TArray<double> EditableTimes;

	/** Struct describing the type of a snap */
	struct FSnapType
	{
		FSnapType(const FName& InType, const FText& InDisplayName, bool bInEnabled)
			: Type(InType)
			, DisplayName(InDisplayName)
			, bEnabled(bInEnabled)
		{}

		/** Identifier for this snap type */
		FName Type;

		/** Display name for this snap type */
		FText DisplayName;

		/** Whether this snap type is enabled */
		bool bEnabled;

		/** Built-in snap types */
		static const FSnapType CompositeSegment;
	};

	/** Struct describing a time that can be snapped to */
	struct FSnapTime
	{
		FSnapTime(const FName& InType, double InTime)
			: Type(InType)
			, Time(InTime)
		{}

		/** Type corresponding to a FSnapType */
		FName Type;

		/** The time to snap to */
		double Time;
	};

	/** Snap types for this model */
	TMap<FName, FSnapType> SnapTypes;

	/** Times that can be snapped to when dragging */
	TArray<FSnapTime> SnapTimes;

	/** Recursion guard for selection */
	bool bIsSelecting;

	// previewer
	TSharedPtr<FLGATimelinePreviewer> TimelinePreviewer;
};
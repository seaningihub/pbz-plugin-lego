// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Visibility.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Input/Reply.h"
#include "Widgets/SCompoundWidget.h"
#include "SLGATimelineTrackPanel.h"
#include "SLGATrack.h"

class SBorder;
struct FLGAActionEvent;
class FLGATimelineModel;
class ULGATimeline;

//////////////////////////////////////////////////////////////////////////
// FTimingRelevantElement - data object holding timing data

namespace ELGATimingElementType
{
	enum Type
	{
		InstantAction,
		DurationActionBegin,
		DurationActionEnd,
		Max,
	};
};

struct FLGATimingRelevantElementBase
{
	virtual FName GetTypeName() = 0;
	virtual float GetElementTime() const = 0;
	virtual int32 GetElementSortPriority() const = 0;
	virtual ELGATimingElementType::Type GetType() const = 0;
	virtual FLGAActionEvent* GetActionEvent() const = 0;

	// Get a list of descriptions key/values to describe the element.
	// Intended for UI/Tooltip use
	virtual void GetDescriptionItems(TMap<FString, FText>& Items) const = 0;

	// Comparison for sorting lists of elements
	virtual bool Compare(const FLGATimingRelevantElementBase& Other)
	{
		float MyTime = GetElementTime();
		float OtherTime = Other.GetElementTime();
		return FMath::IsNearlyEqual(MyTime, OtherTime) ? GetElementSortPriority() < Other.GetElementSortPriority() : MyTime < OtherTime;
	}

	// Where in the order for the sequence this element will trigger
	int32 TriggerIdx;
};

// Small helper to store information about timing relevant elements (notifies, branch points, sections etc.)
struct FLGATimingRelevantElement_Action : public FLGATimingRelevantElementBase
{
	FLGATimingRelevantElement_Action(ULGATimeline* InTimeline, int32 InActionIndex) : Timeline(InTimeline), ActionIndex(InActionIndex) {}

	virtual FName GetTypeName() override;
	virtual float GetElementTime() const override;
	virtual int32 GetElementSortPriority() const override;
	virtual ELGATimingElementType::Type GetType() const override;
	virtual FLGAActionEvent* GetActionEvent() const override;
	virtual void GetDescriptionItems(TMap<FString, FText>& Items) const override;

	ULGATimeline* Timeline;	// The timeline the action exists within
	int32 ActionIndex;					// The index of the action in the timeline
};

// Small helper to store information about timing relevant elements (notifies, branch points, sections etc.)
struct FLGATimingRelevantElement_ActionEnd : public FLGATimingRelevantElement_Action
{
	FLGATimingRelevantElement_ActionEnd(ULGATimeline* InTimeline, int32 InActionIndex) : FLGATimingRelevantElement_Action(InTimeline, InActionIndex) {}

	virtual FName GetTypeName() override { return FName("Duration Action (End)"); }
	virtual float GetElementTime() const override;
	virtual ELGATimingElementType::Type GetType() const override { return ELGATimingElementType::DurationActionEnd; }
};

// Delegate to get the visibility of a type of timing node on an external panel (not the timing track)
DECLARE_DELEGATE_RetVal_OneParam(EVisibility, FOnGetTimingNodeVisibility, ELGATimingElementType::Type)

//////////////////////////////////////////////////////////////////////////
// The content of SLGATimingNode, separated to be used in non STrack widgets
//////////////////////////////////////////////////////////////////////////
class SLGATimingNode : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGATimingNode)
		: _InElement()
		, _bUseTooltip(true)
	{}

	SLATE_ARGUMENT(TSharedPtr<FLGATimingRelevantElementBase>, InElement)
	SLATE_ARGUMENT(bool, bUseTooltip)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual FVector2D ComputeDesiredSize(float) const override;

protected:

	// The observed element
	TSharedPtr<FLGATimingRelevantElementBase> Element;
};

//////////////////////////////////////////////////////////////////////////
// Track node containing an identifier for trigger order of a timing element
//////////////////////////////////////////////////////////////////////////
class SLGATimingTrackNode : public SLGATrackNode
{
public:
	SLATE_BEGIN_ARGS(SLGATimingTrackNode)
		: _bUseTooltip(true)
	{}

	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_ATTRIBUTE(FString, NodeName)
	SLATE_ATTRIBUTE(FLinearColor, NodeColor)
	SLATE_ARGUMENT(TSharedPtr<FLGATimingRelevantElementBase>, Element)
	SLATE_ARGUMENT(bool, bUseTooltip)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};

//////////////////////////////////////////////////////////////////////////
// Panel containing a track for timing nodes, to display the order
// that events in a montage occur (Notifies, sections, branching pts etc.)
//////////////////////////////////////////////////////////////////////////
class SLGATimelineTimingPanel : public SLGATimelineTrackPanel
{
public:
	SLATE_BEGIN_ARGS(SLGATimelineTimingPanel)
		: _WidgetWidth(0)
		, _CurrentPosition(0)
		, _ViewInputMin(0)
		, _ViewInputMax(0)
		, _InputMin(0)
		, _InputMax(0)
		, _OnSetInputViewRange()
	{}
	SLATE_ARGUMENT(float, WidgetWidth)
	SLATE_ATTRIBUTE(float, CurrentPosition)
	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_ATTRIBUTE(float, InputMin)
	SLATE_ATTRIBUTE(float, InputMax)
	SLATE_EVENT(FOnSetInputViewRange, OnSetInputViewRange)
	SLATE_END_ARGS()

	// Construct the panel
	// @param InArgs - Slate arguments
	void Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModel>& InModel);
	~SLGATimelineTimingPanel();

	// Updates panel widgets
	void Update();

	// Access to display enabled flags in multiple forms
	bool IsElementDisplayEnabled(ELGATimingElementType::Type ElementType) const;
	ECheckBoxState IsElementDisplayChecked(ELGATimingElementType::Type ElementType) const;
	EVisibility IsElementDisplayVisible(ELGATimingElementType::Type ElementType) const;

	// Callback from slate when element display flag changes
	// @param ElementType - Flag to set
	void OnElementDisplayEnabledChanged(ELGATimingElementType::Type ElementType);

	// Inspects the provided sequence, collect and sorts the requested elements
	// @param Sequence - Sequence to inspect
	// @param Elements - Out array of elements
	static void GetTimingRelevantElements(ULGATimeline* Timeline, TArray<TSharedPtr<FLGATimingRelevantElementBase>>& Elements);

protected:
	// Clears the timing track and rebuilds the nodes
	void RefreshTrackNodes();

	/** The model for our data */
	TWeakPtr<FLGATimelineModel> WeakModel;

	/** Observed timing elements */
	TArray<TSharedPtr<FLGATimingRelevantElementBase>> Elements;

	/** Anim sequence that contains the timing elements we are observing */
	ULGATimeline* Timeline;

	/** Main panel widget */
	TSharedPtr<SBorder> PanelArea;

	/** The track to place timing nodes on */
	TSharedPtr<SLGATrack> Track;

	/** Delegate handle for track changes */
	FDelegateHandle TracksChangedDelegateHandle;
};

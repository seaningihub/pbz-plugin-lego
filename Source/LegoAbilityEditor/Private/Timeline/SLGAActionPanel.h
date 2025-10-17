// Copyright S-Game, Inc. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "UObject/UObjectGlobals.h"
#include "Misc/Attribute.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Input/Reply.h"
#include "Widgets/SWidget.h"
#include "EditorStyleSet.h"
#include "Framework/MarqueeRect.h"
#include "SLGATimelineTrackPanel.h"
#include "AssetRegistry/AssetData.h"
#include "Framework/Commands/Commands.h"
#include "SLGATimelineTimingPanel.h"
#include "EditorUndoClient.h"
#include "LGATimelineModelBase.h"

class FSlateWindowElementList;
class SLGAActionNode;
class SLGAActionTrack;
class SBorder;
class SScrollBar;
struct Rect;

DECLARE_DELEGATE_OneParam(FOnSelectionChanged, const TArray<UObject*>&)
DECLARE_DELEGATE(FOnTrackSelectionChanged)
DECLARE_DELEGATE(FOnUpdatePanel)
DECLARE_DELEGATE_RetVal(float, FOnGetScrubValue)
DECLARE_DELEGATE(FRefreshOffsetsRequest)
DECLARE_DELEGATE(FDeleteAction)
DECLARE_DELEGATE_RetVal(bool, FOnGetIsActionSelectionValidForReplacement)
DECLARE_DELEGATE_TwoParams(FReplaceWithAction, FString, UClass*)
DECLARE_DELEGATE_TwoParams(FReplaceWithBlueprintAction, FString, FString)
DECLARE_DELEGATE(FDeselectAllActions)
DECLARE_DELEGATE_OneParam(FOnGetBlueprintActionData, TArray<FAssetData>&)
DECLARE_DELEGATE_OneParam(FOnGetNativeActionClasses, TArray<UClass*>&)
DECLARE_DELEGATE_RetVal_ThreeParams(bool, FOnSnapPosition, float& /*InOutTimeToSnap*/, float /*InSnapMargin*/, bool /*bSnapToFrameStep*/)

class SLGAActionNode;
class SLGAActionTrack;
class SLGAActionEdTrack;
class FActionDragDropOp;

namespace ELGAActionPasteMode
{
	enum Type
	{
		MousePosition,
		OriginalTime
	};
}

namespace ELGAActionPasteMultipleMode
{
	enum Type
	{
		Relative,
		Absolute
	};
}

namespace ELGAActionStateHandleHit
{
	enum Type
	{
		None	= -1,
		Start	= -2,
		End		= -3,
	};
}

struct FLGAActionMarqueeOperation
{
	FLGAActionMarqueeOperation()
		: Operation(Add)
		, bActive(false)
	{
	}

	enum Type
	{
		/** Holding down Ctrl removes nodes */
		Remove,
		/** Holding down Shift adds to the selection */
		Add,
		/** When nothing is pressed, marquee replaces selection */
		Replace
	} Operation;

	bool IsValid() const
	{
		return Rect.IsValid() && bActive;
	}

	void Start(const FVector2D& InStartLocation, FLGAActionMarqueeOperation::Type InOperationType, TArray<TSharedPtr<SLGAActionNode>>& InOriginalSelection)
	{
		Rect = FMarqueeRect(InStartLocation);
		Operation = InOperationType;
		OriginalSelection = InOriginalSelection;
	}

	void End()
	{
		Rect = FMarqueeRect();
	}


	/** Given a mouse event, figure out what the marquee selection should do based on the state of Shift and Ctrl keys */
	static FLGAActionMarqueeOperation::Type OperationTypeFromMouseEvent(const FPointerEvent& MouseEvent)
	{
		if (MouseEvent.IsControlDown())
		{
			return FLGAActionMarqueeOperation::Remove;
		}
		else if (MouseEvent.IsShiftDown())
		{
			return FLGAActionMarqueeOperation::Add;
		}
		else
		{
			return FLGAActionMarqueeOperation::Replace;
		}
	}

public:
	/** The marquee rectangle being dragged by the user */
	FMarqueeRect Rect;

	/** Whether the marquee has been activated, usually by a drag */
	bool bActive;

	/** The original selection state before the marquee selection */
	TArray<TSharedPtr<SLGAActionNode>> OriginalSelection;
};

DECLARE_DELEGATE_FourParams(FOnActionHandleBeingDragged, TSharedPtr<SLGAActionNode> /*NotifyNode*/, const FPointerEvent& /*PointerEvent*/, ELGAActionStateHandleHit::Type /*Handle*/, float /*Time*/)
DECLARE_DELEGATE_FourParams(FOnActionNodesBeingDragged, const TArray<TSharedPtr<SLGAActionNode>>& /*NotifyNodes*/, const class FDragDropEvent& /*DragDropEvent*/, float /*XPosition*/, float /*Time*/)

//////////////////////////////////////////////////////////////////////////
// SAnimNotifyPanel

// @todo anim : register when it's opened for the animsequence
// broadcast when animsequence changed, so that we refresh for multiple window
class SLGAActionPanel: public SLGATimelineTrackPanel, public FEditorUndoClient
{
public:
	SLATE_BEGIN_ARGS(SLGAActionPanel)
		: _CurrentPosition()
		, _ViewInputMin()
		, _ViewInputMax()
		, _InputMin()
		, _InputMax()
		, _OnSetInputViewRange()
		, _OnSelectionChanged()
		, _OnGetScrubValue()
		, _OnRequestRefreshOffsets()
	{}
	SLATE_ARGUMENT(float, WidgetWidth)
	SLATE_ATTRIBUTE(float, CurrentPosition)
	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_ATTRIBUTE(float, InputMin)
	SLATE_ATTRIBUTE(float, InputMax)
	SLATE_EVENT(FOnSetInputViewRange, OnSetInputViewRange)
	SLATE_EVENT(FOnSelectionChanged, OnSelectionChanged)
	SLATE_EVENT(FOnGetScrubValue, OnGetScrubValue)
	SLATE_EVENT(FRefreshOffsetsRequest, OnRequestRefreshOffsets)
	SLATE_EVENT(FOnGetTimingNodeVisibility, OnGetTimingNodeVisibility)
	SLATE_EVENT(FSimpleDelegate, OnNotifiesChanged)
	SLATE_EVENT(FOnSnapPosition, OnSnapPosition)
	SLATE_EVENT(FOnActionHandleBeingDragged, OnActionHandleBeingDragged)
	SLATE_EVENT(FOnActionNodesBeingDragged, OnActionNodesBeingDragged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModelBase>& InModel);
	virtual ~SLGAActionPanel();

	// Generate a new track name (smallest integer number that isn't currently used)
	FName GetNewTrackName() const;

	FReply AddTrack();
	FReply InsertTrack(int32 TrackIndexToInsert);
	FReply DeleteTrack(int32 TrackIndexToDelete);
	bool CanDeleteTrack(int32 TrackIndexToDelete);

	void Update();
	void UpdateEditable();

	/** Returns the position of the notify node currently being dragged. Returns -1 if no node is being dragged */
	float CalculateDraggedNodePos() const;

	/**Handler for when a notify node drag has been initiated */
	FReply OnNotifyNodeDragStarted(TArray<TSharedPtr<SLGAActionNode>> NotifyNodes, TSharedRef<SWidget> Decorator, const FVector2D& ScreenCursorPos, const FVector2D& ScreenNodePosition, const bool bDragOnMarker);

	void CopySelectedNodesToClipboard() const;
	void OnPasteNodes(SLGAActionTrack* RequestTrack, float ClickTime, ELGAActionPasteMode::Type PasteMode, ELGAActionPasteMultipleMode::Type MultiplePasteType);

	/** Handler for properties changing on objects */
	void OnPropertyChanged(UObject* ChangedObject, FPropertyChangedEvent& PropertyEvent);

	/** SWidget Interface */
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnFocusLost(const FFocusEvent& InFocusEvent) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	/** End SWidget Interface */

	void RefreshMarqueeSelectedNodes(const FGeometry& PanelGeo);

	/** Check to make sure the current AnimNotify selection is a valid selection for replacing (i.e., AnimNotifies and AnimNotifyStates aren't mixed together in the selection) */
	bool IsNotifySelectionValidForReplacement();

	/** Handler for replacing with notify */
	void OnReplaceSelectedWithNotify(FString NewNotifyName, UClass* NewNotifyClass);

	/** Handler for replacing with notify blueprint */
	void OnReplaceSelectedWithNotifyBlueprint(FString NewBlueprintNotifyName, FString NewBlueprintNotifyClass);

	void HandleObjectsSelected(const TArray<UObject*>& InObjects);

	TSharedRef<FUICommandList> GetCommandList() const { return WeakCommandList.Pin().ToSharedRef(); }

	bool GetActionEditable() const { return bActionEditable; }

private:
	friend struct FScopedSavedNotifySelection;

	TSharedPtr<SBorder> PanelArea;
	TSharedPtr<SScrollBar> NotifyTrackScrollBar;
	TWeakPtr<FLGATimelineModelBase> Model;
	float WidgetWidth;
	TAttribute<float> CurrentPosition;
	FOnSelectionChanged OnSelectionChanged;
	FOnGetScrubValue OnGetScrubValue;
	FOnGetTimingNodeVisibility OnGetTimingNodeVisibility;

	/** Manager for mouse controlled marquee selection */
	FLGAActionMarqueeOperation Marquee;

	/** Delegate to request a refresh of the offsets calculated for notifies */
	FRefreshOffsetsRequest OnRequestRefreshOffsets;

	/** Store the position of a currently dragged node for display across tracks */
	float CurrentDragXPosition;

	/** Cached list of anim tracks for notify node drag drop */
	TArray<TSharedPtr<SLGAActionTrack>> NotifyAnimTracks;

	// this just refresh notify tracks - UI purpose only
	// do not call this from here. This gets called by asset. 
	void RefreshNotifyTracks();

	/** FEditorUndoClient interface */
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override;

	/** Handler for delete command */
	void OnDeletePressed();

	/** Deletes all currently selected notifies in the panel */
	void DeleteSelectedNodeObjects();

	/** We support keyboard focus to detect when we should process key commands like delete */
	virtual bool SupportsKeyboardFocus() const override
	{
		return true;
	}

	// Called when a track changes it's selection; iterates all tracks collecting selected items
	void OnTrackSelectionChanged();

	// Called to deselect all notifies across all tracks
	void DeselectAllNotifies();

	// Binds the UI commands for this widget to delegates
	void BindCommands();

	virtual void InputViewRangeChanged(float ViewMin, float ViewMax) override;

	/** Delegate used to snap when dragging */
	FOnSnapPosition OnSnapPosition;

	/** UI commands for this widget */
	TWeakPtr<FUICommandList> WeakCommandList;

	/** Delegate handle for track changes */
	FDelegateHandle TracksChangedDelegateHandle;

	/** Handle to the registered OnPropertyChangedHandle delegate */
	FDelegateHandle OnPropertyChangedHandleDelegateHandle;

	/** Delegate used to inform others that notifies have changed (for timing) */
	FSimpleDelegate OnNotifiesChanged;

	/** Delegate used to inform others that a notify state handle is being dragged */
	FOnActionHandleBeingDragged OnActionHandleBeingDragged;

	/** Delegate used to inform others that one or more notifies nodes are being dragged */
	FOnActionNodesBeingDragged OnActionNodesBeingDragged;

	/** Recursion guard for selection */
	bool bIsSelecting;

	/** Recursion guard for updating */
	bool bIsUpdating;

	bool bActionEditable;
};

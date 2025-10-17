// Copyright S-Game, Inc. All Rights Reserved.


#include "SLGAActionPanel.h"
#include "Actions/LGAAction.h"
#include "LGATimelineTrack_ActionsPanel.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetSelection.h"
#include "ClassViewerFilter.h"
#include "ClassViewerModule.h"
#include "Editor/EditorEngine.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Fonts/FontMeasure.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "HAL/PlatformApplicationMisc.h"
#include "Layout/WidgetPath.h"
#include "Modules/ModuleManager.h"
#include "Rendering/DrawElements.h"
#include "ScopedTransaction.h"
#include "Styling/CoreStyle.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "LegoAbilityEditorCommands.h"
#include "LGATimeline.h"
#include "UObject/UObjectHash.h"
#include "UObject/UObjectIterator.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityEditor.h"

extern UNREALED_API UEditorEngine* GEditor;

// Action Drawing
const float NotifyHeightOffset = 0.f;
const float NotifyHeight = FLGATimelineTrack_ActionsPanel::NotificationTrackHeight;
const FVector2D ScrubHandleSize(12.0f, 12.0f);
const FVector2D AlignmentMarkerSize(10.f, 20.f);
const FVector2D TextBorderSize(1.f, 1.f);

#define LOCTEXT_NAMESPACE "AnimNotifyPanel"

DECLARE_DELEGATE_RetVal_FourParams(FReply, FOnNotifyNodeDragStarted, TSharedRef<SLGAActionNode>, const FPointerEvent&, const FVector2D&, const bool)
DECLARE_DELEGATE_RetVal_FiveParams(FReply, FOnNotifyNodesDragStarted, TArray<TSharedPtr<SLGAActionNode>>, TSharedRef<SWidget>, const FVector2D&, const FVector2D&, const bool)
DECLARE_DELEGATE_RetVal(float, FOnGetDraggedNodePos)
DECLARE_DELEGATE_TwoParams(FPanTrackRequest, int32, FVector2D)
DECLARE_DELEGATE(FCopyNodes)
DECLARE_DELEGATE_FourParams(FPasteNodes, SLGAActionTrack*, float, ELGAActionPasteMode::Type, ELGAActionPasteMultipleMode::Type)
DECLARE_DELEGATE_RetVal_OneParam(EVisibility, FOnGetTimingNodeVisibilityForNode, TSharedPtr<SLGAActionNode>)

FText MakeTooltipFromTime(const ULGATimeline* InTimeline, float InSeconds, float InDuration)
{
	const FText Frame = FText::AsNumber(InTimeline->GetFrameAtTime(InSeconds));
	const FText Seconds = FText::AsNumber(InSeconds);

	if (InDuration > 0.0f)
	{
		const FText Duration = FText::AsNumber(InDuration);
		return FText::Format(LOCTEXT("NodeToolTipLong", "@ {0} sec (frame {1}) for {2} sec"), Seconds, Frame, Duration);
	}
	else
	{
		return FText::Format(LOCTEXT("NodeToolTipShort", "@ {0} sec (frame {1})"), Seconds, Frame);
	}
}

// Read common info from the clipboard
bool ReadNotifyPasteHeader(FString& OutPropertyString, const TCHAR*& OutBuffer, float& OutOriginalTime, float& OutOriginalLength, int32& OutTrackSpan)
{
	OutBuffer = NULL;
	OutOriginalTime = -1.f;

	FPlatformApplicationMisc::ClipboardPaste(OutPropertyString);

	if (!OutPropertyString.IsEmpty())
	{
		//Remove header text
		const FString HeaderString(TEXT("COPY_ABILITYACTIONEVENT"));

		//Check for string identifier in order to determine whether the text represents an FAbilityActionEvent.
		if (OutPropertyString.StartsWith(HeaderString) && OutPropertyString.Len() > HeaderString.Len())
		{
			int32 HeaderSize = HeaderString.Len();
			OutBuffer = *OutPropertyString;
			OutBuffer += HeaderSize;

			FString ReadLine;
			// Read the original time from the first notify
			FParse::Line(&OutBuffer, ReadLine);
			FParse::Value(*ReadLine, TEXT("OriginalTime="), OutOriginalTime);
			FParse::Value(*ReadLine, TEXT("OriginalLength="), OutOriginalLength);
			FParse::Value(*ReadLine, TEXT("TrackSpan="), OutTrackSpan);
			return true;
		}
	}

	return false;
}

namespace ENodeObjectTypes
{
	enum Type
	{
		ACTION,
	};
};

struct INodeObjectInterface
{
	virtual ENodeObjectTypes::Type GetType() const = 0;
	virtual FLGAActionEvent* GetNotifyEvent() = 0;
	virtual int GetTrackIndex() const = 0;
	virtual float GetTime() const = 0;
	virtual float GetDuration() = 0;
	virtual FName GetName() = 0;
	virtual TOptional<FLinearColor> GetEditorColor() = 0;
	virtual FText GetNodeTooltip(const ULGATimeline* Timeline) = 0;
	virtual TOptional<UObject*> GetObjectBeingDisplayed() = 0;
	bool operator<(const INodeObjectInterface& Rhs) const { return GetTime() < Rhs.GetTime(); }

	virtual void SetTime(float Time) = 0;
	virtual void SetDuration(float Duration) = 0;

	virtual void HandleDrop(ULGATimeline* Timeline, float Time, int32 TrackIndex) = 0;
	virtual void CacheName() = 0;

	virtual void Delete(ULGATimeline* Timeline) = 0;
	virtual void MarkForDelete(ULGATimeline* Timeline) = 0;

	virtual void ExportForCopy(ULGATimeline* Timeline, FString& StrValue) const = 0;

	virtual FGuid GetGuid() const = 0;

	virtual void SetEditable(bool Editable) = 0;
	virtual bool GetEditable() const = 0;
};

struct FNotifyNodeInterface : public INodeObjectInterface
{
	FLGAActionEvent* ActionEvent;

	// Cached notify name (can be generated by blueprints so want to cache this instead of hitting VM) 
	FName CachedNotifyName;

	// Stable Guid that allows us to refer to notify event
	FGuid Guid;

	bool bEditable;

	FNotifyNodeInterface(FLGAActionEvent* InActionEvent) : ActionEvent(InActionEvent), Guid(ActionEvent->Guid) {}
	virtual ENodeObjectTypes::Type GetType() const override { return ENodeObjectTypes::ACTION; }
	virtual FLGAActionEvent* GetNotifyEvent() override { return ActionEvent; }
	virtual int GetTrackIndex() const override{ return ActionEvent->TrackIndex; }
	virtual float GetTime() const override { return ActionEvent->GetStartTime(); }
	virtual float GetDuration() override { return ActionEvent->GetDuration(); }
	virtual FName GetName() override { return CachedNotifyName; }
	virtual TOptional<FLinearColor> GetEditorColor() override 
	{
		TOptional<FLinearColor> ReturnColour;
		if (ActionEvent->Action)
		{
			ReturnColour = ActionEvent->Action->GetEditorColor();
		}
		return ReturnColour;
	}

	virtual FText GetNodeTooltip(const ULGATimeline* Timeline) override
	{
		FText ToolTipText = MakeTooltipFromTime(Timeline, ActionEvent->GetStartTime(), ActionEvent->GetDuration());
		if (ActionEvent->Action)
		{
			const FString& Desc = ActionEvent->Action->GetDescription();
			if (Desc.IsEmpty())
			{
				ToolTipText = FText::Format(LOCTEXT("Action_ToolTipActionClass", "{0}\nClass: {1}"), ToolTipText, ActionEvent->Action->GetClass()->GetDisplayNameText());
			}
			else
			{
				ToolTipText = FText::Format(LOCTEXT("Action_ToolTipActionClass", "{0}\nClass: {1}\n{2}"), ToolTipText, ActionEvent->Action->GetClass()->GetDisplayNameText(), FText::FromString(Desc));
			}
		}

		return ToolTipText;
	}

	virtual TOptional<UObject*> GetObjectBeingDisplayed() override
	{
		if (ActionEvent->Action)
		{
			return TOptional<UObject*>(ActionEvent->Action);
		}

		return TOptional<UObject*>();
	}

	virtual void SetTime(float Time) override { ActionEvent->SetStartTime(Time); }
	virtual void SetDuration(float Duration) override { ActionEvent->SetDuration(Duration); }

	virtual void SetEditable(bool Editable) override { bEditable = Editable; }
	virtual bool GetEditable() const override { return bEditable; }

	virtual void HandleDrop(ULGATimeline* Timeline, float Time, int32 TrackIndex) override
	{
		float EventDuration = ActionEvent->GetDuration();

		ActionEvent->SetStartTime(Time);
		ActionEvent->RefreshTriggerOffset(Timeline->CalculateOffsetForNotify(ActionEvent->GetStartTime()));

		if (EventDuration > 0.0f)
		{
			//ActionEvent->EndLink.Link(Timeline, ActionEvent->GetStartTime() + EventDuration, ActionEvent->GetSlotIndex());
			//ActionEvent->RefreshEndTriggerOffset(Timeline->CalculateOffsetForNotify(ActionEvent->EndLink.GetTime()));
		}
		else
		{
			ActionEvent->EndTriggerTimeOffset = 0.0f;
		}

		ActionEvent->TrackIndex = TrackIndex;
	}

	virtual void CacheName() override 
	{
		if (ActionEvent->Action)
		{
			CachedNotifyName = FName(*ActionEvent->Action->GetActionName());
		}
	}

	virtual void Delete(ULGATimeline* Timeline) override
	{
		for (int32 I = 0; I < Timeline->Actions.Num(); ++I)
		{
			if (ActionEvent == &(Timeline->Actions[I]))
			{
				Timeline->Actions.RemoveAt(I);
				Timeline->PostEditChange();
				Timeline->MarkPackageDirty();
				break;
			}
		}
	}

	virtual void MarkForDelete(ULGATimeline* Timeline) override
	{
		for (int32 I = 0; I < Timeline->Actions.Num(); ++I)
		{
			if (ActionEvent == &(Timeline->Actions[I]))
			{
				Timeline->Actions[I].Guid = FGuid();
				break;
			}
		}
	}

	virtual void ExportForCopy(ULGATimeline* Timeline, FString& StrValue) const override
	{
		int32 Index = INDEX_NONE;
		for (int32 NotifyIdx = 0; NotifyIdx < Timeline->Actions.Num(); ++NotifyIdx)
		{
			if (ActionEvent == &Timeline->Actions[NotifyIdx])
			{
				Index = NotifyIdx;
				break;
			}
		}

		check(Index != INDEX_NONE);

		FArrayProperty* ArrayProperty;
		uint8* PropertyData = Timeline->FindNotifyPropertyData(Index, ArrayProperty);
		if (PropertyData && ArrayProperty)
		{
			ArrayProperty->Inner->ExportTextItem_Direct(StrValue, PropertyData, PropertyData, nullptr, PPF_Copy);
		}
	}

	virtual FGuid GetGuid() const override
	{
		return Guid;
	}

	static void RemoveInvalidNotifies(ULGATimeline* Timeline)
	{
		Timeline->Actions.RemoveAll([](const FLGAActionEvent& InActionEvent){ return !InActionEvent.Guid.IsValid(); });
		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();
	}
};

// Struct that allows us to get the max value of 2 numbers at compile time
template<int32 A, int32 B>
struct CompileTimeMax
{
	enum Max{ VALUE = (A > B) ? A : B };
};

// Size of biggest object that we can store in our node, if new node interfaces are added they should be part of this calculation
const int32 MAX_NODE_OBJECT_INTERFACE_SIZE = sizeof(FNotifyNodeInterface);


//////////////////////////////////////////////////////////////////////////
// SLGAActionNode

class SLGAActionNode : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SLGAActionNode)
		: _Timeline()
		, _Action(nullptr)
		, _OnNodeDragStarted()
		, _OnActionHandleBeingDragged()
		, _OnUpdatePanel()
		, _PanTrackRequest()
		, _OnSelectionChanged()
		, _ViewInputMin()
		, _ViewInputMax()
	{}
	SLATE_ARGUMENT(class ULGATimeline*, Timeline)
	SLATE_ARGUMENT(FLGAActionEvent*, Action)
	SLATE_EVENT(FOnNotifyNodeDragStarted, OnNodeDragStarted)
	SLATE_EVENT(FOnActionHandleBeingDragged, OnActionHandleBeingDragged)
	SLATE_EVENT(FOnUpdatePanel, OnUpdatePanel)
	SLATE_EVENT(FPanTrackRequest, PanTrackRequest)
	SLATE_EVENT(FOnTrackSelectionChanged, OnSelectionChanged)
	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_ARGUMENT(TSharedPtr<SLGATimingNode>, StateEndTimingNode)
	SLATE_EVENT(FOnSnapPosition, OnSnapPosition)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	// SWidget interface
	virtual FReply OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual void OnFocusLost(const FFocusEvent& InFocusEvent) override;
	virtual bool SupportsKeyboardFocus() const override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	// End of SWidget interface

	// SNodePanel::SNode interface
	void UpdateSizeAndPosition(const FGeometry& AllottedGeometry);
	FVector2D GetWidgetPosition() const;
	FVector2D GetNotifyPosition() const;
	FVector2D GetNotifyPositionOffset() const;
	FVector2D GetSize() const;
	bool HitTest(const FGeometry& AllottedGeometry, FVector2D MouseLocalPose) const;

	// Extra hit testing to decide whether or not the duration handles were hit on a state node
	int32 DurationHandleHitTest(const FVector2D& CursorScreenPosition) const;

	UObject* GetObjectBeingDisplayed() const;
	// End of SNodePanel::SNode

	virtual FVector2D ComputeDesiredSize(float) const override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const /*override*/;

	/** Helpers to draw scrub handles and snap offsets */
	void DrawHandleOffset(const float& Offset, const float& HandleCentre, FSlateWindowElementList& OutDrawElements, int32 MarkerLayer, const FGeometry &AllottedGeometry, const FSlateRect& MyCullingRect, FLinearColor NodeColour) const;
	void DrawScrubHandle(float ScrubHandleCentre, FSlateWindowElementList& OutDrawElements, int32 ScrubHandleID, const FGeometry &AllottedGeometry, const FSlateRect& MyCullingRect, FLinearColor NodeColour) const;

	FLinearColor GetNotifyColor() const;
	FText GetNotifyText() const;

	/** Node object interface */
	INodeObjectInterface* NodeObjectInterface;

	/** In object storage for our interface struct, saves us having to dynamically allocate what will be a very small struct*/
	uint8 NodeObjectInterfaceStorage[MAX_NODE_OBJECT_INTERFACE_SIZE];

	/** Helper function to create our node interface object */
	template<typename InterfaceType, typename ParamType>
	void MakeNodeInterface(ParamType& InParam)
	{
		check(sizeof(InterfaceType) <= MAX_NODE_OBJECT_INTERFACE_SIZE); //Not enough space, check definiton of MAX_NODE_OBJECT_INTERFACE_SIZE
		NodeObjectInterface = new(NodeObjectInterfaceStorage)InterfaceType(InParam);
	}

	void DropCancelled();

	/** Returns the size of this notifies duration in screen space */
	float GetDurationSize() const { return NotifyDurationSizeX;}

	/** Sets the position the mouse was at when this node was last hit */
	void SetLastMouseDownPosition(const FVector2D& CursorPosition) {LastMouseDownPosition = CursorPosition;}

	const FVector2D& GetScreenPosition() const
	{
		return ScreenPosition;
	}

	const float GetLastSnappedTime() const
	{
		return LastSnappedTime;
	}

	void ClearLastSnappedTime()
	{
		LastSnappedTime = -1.0f;
	}

	void SetLastSnappedTime(float NewSnapTime)
	{
		LastSnappedTime = NewSnapTime;
	}

private:
	FText GetNodeTooltip() const;

	/** Detects any overflow on the anim notify track and requests a track pan */
	float HandleOverflowPan(const FVector2D& ScreenCursorPos, float TrackScreenSpaceXPosition, float TrackScreenSpaceMin, float TrackScreenSpaceMax);

	/** Finds a snap position if possible for the provided scrub handle, if it is not possible, returns -1.0f */
	float GetScrubHandleSnapPosition(float NotifyLocalX, ELGAActionStateHandleHit::Type HandleToCheck, bool bEnableSnapToFrame);

	virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent) override;

	/** The timeline that the ActionEvent lives in */
	ULGATimeline* Timeline;
	FSlateFontInfo Font;

	TAttribute<float>			ViewInputMin;
	TAttribute<float>			ViewInputMax;
	FVector2D					CachedAllotedGeometrySize;
	FVector2D					ScreenPosition;
	float						LastSnappedTime;

	bool						bDrawTooltipToRight;
	bool						bBeingDragged;
	bool						bSelected;

	// Index for undo transactions for dragging, as a check to make sure it's active
	int32						DragActionTransactionIdx;

	/** The scrub handle currently being dragged, if any */
	int32						CurrentDragHandle;
	
	float						NotifyTimePositionX;
	float						NotifyDurationSizeX;
	float						NotifyScrubHandleCentre;
	
	float						WidgetX;
	FVector2D					WidgetSize;
	
	FVector2D					TextSize;
	float						LabelWidth;

	/** Last position the user clicked in the widget */
	FVector2D					LastMouseDownPosition;

	/** Delegate that is called when the user initiates dragging */
	FOnNotifyNodeDragStarted	OnNodeDragStarted;

	/** Delegate that is called when a notify state handle is being dragged */
	FOnActionHandleBeingDragged	OnActionHandleBeingDragged;

	/** Delegate to pan the track, needed if the markers are dragged out of the track */
	FPanTrackRequest			PanTrackRequest;

	/** Delegate used to snap positions */
	FOnSnapPosition				OnSnapPosition;

	/** Delegate to signal selection changing */
	FOnTrackSelectionChanged	OnSelectionChanged;

	/** Delegate to redraw the notify panel */
	FOnUpdatePanel				OnUpdatePanel;

	/** Cached owning track geometry */
	FGeometry CachedTrackGeometry;

	TSharedPtr<SOverlay> EndMarkerNodeOverlay;

	friend class SLGAActionTrack;
};

class SLGAActionPair : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGAActionPair) {}
	SLATE_NAMED_SLOT(FArguments, LeftContent)
	SLATE_ARGUMENT(TSharedPtr<SLGAActionNode>, Node);
	SLATE_EVENT(FOnGetTimingNodeVisibilityForNode, OnGetTimingNodeVisibilityForNode)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	float GetWidgetPaddingLeft();

protected:
	TSharedPtr<SWidget> PairedWidget;
	TSharedPtr<SLGAActionNode> NodePtr;
};

void SLGAActionPair::Construct(const FArguments& InArgs)
{
	NodePtr = InArgs._Node;
	PairedWidget = InArgs._LeftContent.Widget;
	check(NodePtr.IsValid());
	check(PairedWidget.IsValid());

	float ScaleMult = 1.0f;
	FVector2D NodeSize = NodePtr->ComputeDesiredSize(ScaleMult);
	SetVisibility(EVisibility::SelfHitTestInvisible);

	this->ChildSlot
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SBox)
			.HAlign(EHorizontalAlignment::HAlign_Center)
			.VAlign(EVerticalAlignment::VAlign_Center)
			[
				PairedWidget->AsShared()
			]
		]
		+ SHorizontalBox::Slot()
		[
			NodePtr->AsShared()
		]
	];
}

float SLGAActionPair::GetWidgetPaddingLeft()
{
	return NodePtr->GetWidgetPosition().X - PairedWidget->GetDesiredSize().X;
}

//////////////////////////////////////////////////////////////////////////
// SLGAActionTrack

class SLGAActionTrack : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLGAActionTrack)
		: _Timeline(NULL)
		, _ViewInputMin()
		, _ViewInputMax()
		, _TrackIndex()
		, _TrackColor(FLinearColor::White)
		, _OnSelectionChanged()
		, _OnUpdatePanel()
		, _OnGetScrubValue()
		, _OnGetDraggedNodePos()
		, _OnNodeDragStarted()
		, _OnActionHandleBeingDragged()
		, _OnRequestTrackPan()
		, _OnRequestOffsetRefresh()
		, _OnDeleteNotify()
		, _OnGetIsAnimNotifySelectionValidForReplacement()
		, _OnReplaceSelectedWithNotify()
		, _OnReplaceSelectedWithBlueprintNotify()
		, _OnDeselectAllNotifies()
		, _OnCopyNodes()
		, _OnPasteNodes()
		, _OnSetInputViewRange()
		, _ActionEditable()
		{}
		SLATE_ARGUMENT(class ULGATimeline*, Timeline)
		SLATE_ARGUMENT(TArray<FLGAActionEvent*>, Actions)
		SLATE_ARGUMENT(TArray<TSharedPtr<FLGATimingRelevantElementBase>>, TimingElements)
		SLATE_ATTRIBUTE(float, ViewInputMin)
		SLATE_ATTRIBUTE(float, ViewInputMax)
		SLATE_EVENT(FOnSnapPosition, OnSnapPosition)
		SLATE_ARGUMENT(int32, TrackIndex)
		SLATE_ARGUMENT(FLinearColor, TrackColor)
		SLATE_ATTRIBUTE(EVisibility, QueuedNotifyTimingNodeVisibility)
		SLATE_EVENT(FOnTrackSelectionChanged, OnSelectionChanged)
		SLATE_EVENT(FOnUpdatePanel, OnUpdatePanel)
		SLATE_EVENT(FOnGetScrubValue, OnGetScrubValue)
		SLATE_EVENT(FOnGetDraggedNodePos, OnGetDraggedNodePos)
		SLATE_EVENT(FOnNotifyNodesDragStarted, OnNodeDragStarted)
		SLATE_EVENT(FOnActionHandleBeingDragged, OnActionHandleBeingDragged)
		SLATE_EVENT(FPanTrackRequest, OnRequestTrackPan)
		SLATE_EVENT(FRefreshOffsetsRequest, OnRequestOffsetRefresh)
		SLATE_EVENT(FDeleteAction, OnDeleteNotify)
		SLATE_EVENT(FOnGetIsActionSelectionValidForReplacement, OnGetIsAnimNotifySelectionValidForReplacement)
		SLATE_EVENT(FReplaceWithAction, OnReplaceSelectedWithNotify)
		SLATE_EVENT(FReplaceWithBlueprintAction, OnReplaceSelectedWithBlueprintNotify)
		SLATE_EVENT(FDeselectAllActions, OnDeselectAllNotifies)
		SLATE_EVENT(FCopyNodes, OnCopyNodes)
		SLATE_EVENT(FPasteNodes, OnPasteNodes)
		SLATE_EVENT(FOnSetInputViewRange, OnSetInputViewRange)
		SLATE_EVENT(FOnGetTimingNodeVisibility, OnGetTimingNodeVisibility)
		SLATE_ARGUMENT(TSharedPtr<FUICommandList>, CommandList)
		SLATE_ARGUMENT(bool, ActionEditable)
		SLATE_END_ARGS()
public:

	/** Type used for list widget of tracks */
	void Construct(const FArguments& InArgs);

	// SWidget interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override { UpdateCachedGeometry(AllottedGeometry); }
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;
	virtual bool SupportsKeyboardFocus() const override { return true; }
	// End of SWidget interface

	/**
	 * Update the nodes to match the data that the panel is observing
	 */
	void Update();

	/** Returns the cached rendering geometry of this track */
	const FGeometry& GetCachedGeometry() const { return CachedGeometry; }

	FTrackScaleInfo GetCachedScaleInfo() const { return FTrackScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0.f, 0.f, CachedGeometry.GetLocalSize()); }

	/** Updates sequences when a notify node has been successfully dragged to a new position
	 *	@param Offset - Offset from the widget to the time handle 
	 */
	void HandleNodeDrop(TSharedPtr<SLGAActionNode> Node, float Offset = 0.0f);

	// Number of nodes in the track currently selected
	int32 GetNumSelectedNodes() const { return SelectedNodeIndices.Num(); }

	// Index of the track in the notify panel
	int32 GetTrackIndex() const { return TrackIndex; }

	// Time at the position of the last mouseclick
	float GetLastClickedTime() const { return LastClickedTime; }

	// Removes the node widgets from the track and adds them to the provided Array
	void DisconnectSelectedNodesForDrag(TArray<TSharedPtr<SLGAActionNode>>& DragNodes);

	// Adds our current selection to the provided set
	void AppendSelectionToSet(FGraphPanelSelectionSet& SelectionSet);
	// Adds our current selection to the provided array
	void AppendSelectionToArray(TArray<INodeObjectInterface*>& Selection) const;
	// Gets the currently selected SAnimNotifyNode instances
	void AppendSelectedNodeWidgetsToArray(TArray<TSharedPtr<SLGAActionNode>>& NodeArray) const;
	// Gets the indices of the selected notifies
	const TArray<int32>& GetSelectedNotifyIndices() const {return SelectedNodeIndices;}

	INodeObjectInterface* GetNodeObjectInterface(int32 NodeIndex) { return NotifyNodes[NodeIndex]->NodeObjectInterface; }
	/**
	* Deselects all currently selected notify nodes
	* @param bUpdateSelectionSet - Whether we should report a selection change to the panel
	*/
	void DeselectAllNotifyNodes(bool bUpdateSelectionSet = true);

	/** Select all nodes contained in the supplied Guid set. */
	void SelectNodesByGuid(const TSet<FGuid>& InGuids, bool bUpdateSelectionSet);

	/** Get the number of notify nodes we contain */
	int32 GetNumNotifyNodes() const { return NotifyNodes.Num(); }

	/** Check whether a node is selected */
	bool IsNodeSelected(int32 NodeIndex) const { return NotifyNodes[NodeIndex]->bSelected; }

	// Paste a single Notify into this track from an exported string
	void PasteSingleNotify(FString& NotifyString, float PasteTime);

	// Uses the given track space rect and marquee information to refresh selection information
	void RefreshMarqueeSelectedNodes(FSlateRect& Rect, FLGAActionMarqueeOperation& Marquee);

	// Create new actions
	FLGAActionEvent& CreateNewAction(FString NewActionName, UClass* ActionClass, float StartTime, bool bNotifyEditChange = true);

	// Get the Blueprint Class from the path of the Blueprint
	static TSubclassOf<UObject> GetBlueprintClassFromPath(FString BlueprintPath);

	// Get the default Notify Name for a given blueprint notify asset
	FString MakeBlueprintNotifyName(const FString& InNotifyClassName);

	// Need to make sure tool tips are cleared during node clear up so slate system won't
	// call into invalid notify.
	void ClearNodeTooltips();

protected:
	// Build up a "New Notify..." menu
	void MakeNewNotifyPicker(FMenuBuilder& MenuBuilder, bool bIsReplaceWithMenu = false);
	void FillNewNotifyMenu(FMenuBuilder& MenuBuilderbool, bool bIsReplaceWithMenu = false);

	// New notify functions
	void CreateNewActionAtCursor(FString NewActionName, UClass* ActionClass);

	// "Replace with... " commands
	void ReplaceSelectedWithBlueprintNotify(FString NewNotifyName, FString BlueprintPath);
	void ReplaceSelectedWithNotify(FString NewNotifyName, UClass* NotifyClass);

	// Whether we have one node selected
	bool IsSingleNodeSelected();
	// Checks the clipboard for an anim notify buffer, and returns whether there's only one notify
	bool IsSingleNodeInClipboard();

	/** Function to check whether it is possible to paste anim notify event */
	bool CanPasteAnimNotify() const;

	/** Handler for context menu paste command */
	void OnPasteNotifyClicked(ELGAActionPasteMode::Type PasteMode, ELGAActionPasteMultipleMode::Type MultiplePasteType = ELGAActionPasteMultipleMode::Absolute);

	/** Opens the supplied blueprint in an editor */
	void OnOpenNotifySource(UBlueprint* InSourceBlueprint) const;

	/**
	 * Selects a node on the track. Supports multi selection
	 * @param TrackNodeIndex - Index of the node to select.
	 * @param Append - Whether to append to to current selection or start a new one.
	 * @param bUpdateSelection - Whether to immediately inform Persona of a selection change
	 */
	void SelectTrackObjectNode(int32 TrackNodeIndex, bool Append, bool bUpdateSelection = true);
	
	/**
	 * Toggles the selection status of a notify node, for example when
	 * Control is held when clicking.
	 * @param NotifyIndex - Index of the notify to toggle the selection status of
	 * @param bUpdateSelection - Whether to immediately inform Persona of a selection change
	 */
	void ToggleTrackObjectNodeSelectionStatus(int32 TrackNodeIndex, bool bUpdateSelection = true);

	/**
	 * Deselects requested notify node
	 * @param NotifyIndex - Index of the notify node to deselect
	 * @param bUpdateSelection - Whether to immediately inform Persona of a selection change
	 */
	void DeselectTrackObjectNode(int32 TrackNodeIndex, bool bUpdateSelection = true);

	int32 GetHitNotifyNode(const FGeometry& MyGeometry, const FVector2D& Position);

	void SummonContextMenu(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	virtual FVector2D ComputeDesiredSize(float) const override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	float CalculateTime(const FGeometry& MyGeometry, FVector2D NodePos, bool bInputIsAbsolute = true);

	// Handler that is called when the user starts dragging a node
	FReply OnNotifyNodeDragStarted(TSharedRef<SLGAActionNode> NotifyNode, const FPointerEvent& MouseEvent, const FVector2D& ScreenNodePosition, const bool bDragOnMarker, int32 NotifyIndex);

	const EVisibility GetTimingNodeVisibility(TSharedPtr<SLGAActionNode> NotifyNode);

private:

	// Data structure for bluprint notify context menu entries
	struct BlueprintNotifyMenuInfo
	{
		FString NotifyName;
		FString BlueprintPath;
		UClass* BaseClass;
	};

	// Store the tracks geometry for later use
	void UpdateCachedGeometry(const FGeometry& InGeometry);

	// Returns the padding needed to render the notify in the correct track position
	FMargin GetNotifyTrackPadding(int32 NotifyIndex) const
	{
		float LeftMargin = NotifyPairs[NotifyIndex]->GetWidgetPaddingLeft();
		float RightMargin = CachedGeometry.GetLocalSize().X - NotifyNodes[NotifyIndex]->GetWidgetPosition().X - NotifyNodes[NotifyIndex]->GetSize().X;
		return FMargin(LeftMargin, 0, RightMargin, 0);
	}

	// Returns the padding needed to render the notify in the correct track position
	FMargin GetSyncMarkerTrackPadding(int32 SyncMarkerIndex) const
	{
		float LeftMargin = NotifyNodes[SyncMarkerIndex]->GetWidgetPosition().X;
		float RightMargin = CachedGeometry.GetLocalSize().X - NotifyNodes[SyncMarkerIndex]->GetWidgetPosition().X - NotifyNodes[SyncMarkerIndex]->GetSize().X;
		return FMargin(LeftMargin, 0, RightMargin, 0);
	}

	// Builds a UObject selection set and calls the OnSelectionChanged delegate
	void SendSelectionChanged()
	{
		OnSelectionChanged.ExecuteIfBound();
	}

protected:
	TWeakPtr<FUICommandList> WeakCommandList;

	float LastClickedTime;

	class ULGATimeline*			Timeline; // need for menu generation of anim notifies - 
	TArray<TSharedPtr<SLGAActionNode>>		NotifyNodes;
	TArray<TSharedPtr<SLGAActionPair>>		NotifyPairs;
	TArray<FLGAActionEvent*>			Actions;
	TAttribute<float>						ViewInputMin;
	TAttribute<float>						ViewInputMax;
	TAttribute<float>						InputMin;
	TAttribute<float>						InputMax;
	TAttribute<FLinearColor>				TrackColor;
	int32									TrackIndex;
	TAttribute<EVisibility>					NotifyTimingNodeVisibility;
	FOnTrackSelectionChanged				OnSelectionChanged;
	FOnUpdatePanel							OnUpdatePanel;
	FOnGetScrubValue						OnGetScrubValue;
	FOnGetDraggedNodePos					OnGetDraggedNodePos;
	FOnNotifyNodesDragStarted				OnNodeDragStarted;
	FOnActionHandleBeingDragged				OnActionHandleBeingDragged;
	FPanTrackRequest						OnRequestTrackPan;
	FDeselectAllActions						OnDeselectAllNotifies;
	FCopyNodes								OnCopyNodes;
	FPasteNodes								OnPasteNodes;
	FOnSetInputViewRange					OnSetInputViewRange;
	FOnGetTimingNodeVisibility				OnGetTimingNodeVisibility;

	/** Delegate to call when offsets should be refreshed in a montage */
	FRefreshOffsetsRequest					OnRequestRefreshOffsets;

	/** Delegate to call when deleting notifies */
	FDeleteAction							OnDeleteNotify;

	/** Delegates to call when replacing notifies */
	FOnGetIsActionSelectionValidForReplacement OnGetIsAnimNotifySelectionValidforReplacement;
	FReplaceWithAction						OnReplaceSelectedWithNotify;
	FReplaceWithBlueprintAction				OnReplaceSelectedWithBlueprintNotify;

	TSharedPtr<SBorder>						TrackArea;

	/** Cache the SOverlay used to store all this tracks nodes */
	TSharedPtr<SOverlay> NodeSlots;

	/** Cached for drag drop handling code */
	FGeometry CachedGeometry;

	/** Delegate used to snap when dragging */
	FOnSnapPosition OnSnapPosition;

	/** Nodes that are currently selected */
	TArray<int32> SelectedNodeIndices;

	/** Timing relevant elements generated when SAnimNotifyPanel::RefreshNotifyTracks called */
	TArray<TSharedPtr<FLGATimingRelevantElementBase>> TimingElements;

	bool bActionEditable;
};

//////////////////////////////////////////////////////////////////////////
// 

/** Widget for drawing a single track */
class SLGAActionEdTrack : public SCompoundWidget
{
private:
	/** Index of Track in Sequence **/
	int32							TrackIndex;

	/** Ability timeline **/
	class ULGATimeline*	Timeline;

	/** Pointer to notify panel for drawing*/
	TWeakPtr<SLGAActionPanel>		AnimPanelPtr;

	/** Timing relevant elements generated when SAnimNotifyPanel::RefreshNotifyTracks called */
	TArray<TSharedPtr<FLGATimingRelevantElementBase>> TimingElements;

public:
	SLATE_BEGIN_ARGS(SLGAActionEdTrack)
		: _TrackIndex(INDEX_NONE)
		, _AnimNotifyPanel()
		, _Timeline()
		, _WidgetWidth()
		, _ViewInputMin()
		, _ViewInputMax()
		, _OnSelectionChanged()
		, _OnUpdatePanel()
		, _OnDeleteNotify()
		, _OnDeselectAllNotifies()
		, _OnCopyNodes()
		, _OnSetInputViewRange()
	{}
	SLATE_ARGUMENT(int32, TrackIndex)
	SLATE_ARGUMENT(TSharedPtr<SLGAActionPanel>, AnimNotifyPanel)
	SLATE_ARGUMENT(class ULGATimeline*, Timeline)
	SLATE_ARGUMENT(float, WidgetWidth)
	SLATE_ATTRIBUTE(float, ViewInputMin)
	SLATE_ATTRIBUTE(float, ViewInputMax)
	SLATE_EVENT(FOnSnapPosition, OnSnapPosition)
	SLATE_ATTRIBUTE(EVisibility, NotifyTimingNodeVisibility)
	SLATE_EVENT(FOnTrackSelectionChanged, OnSelectionChanged)
	SLATE_EVENT(FOnGetScrubValue, OnGetScrubValue)
	SLATE_EVENT(FOnGetDraggedNodePos, OnGetDraggedNodePos)
	SLATE_EVENT(FOnUpdatePanel, OnUpdatePanel)
	SLATE_EVENT(FOnNotifyNodesDragStarted, OnNodeDragStarted)
	SLATE_EVENT(FOnActionHandleBeingDragged, OnActionHandleBeingDragged)
	SLATE_EVENT(FRefreshOffsetsRequest, OnRequestRefreshOffsets)
	SLATE_EVENT(FDeleteAction, OnDeleteNotify)
	SLATE_EVENT(FDeselectAllActions, OnDeselectAllNotifies)
	SLATE_EVENT(FCopyNodes, OnCopyNodes)
	SLATE_EVENT(FPasteNodes, OnPasteNodes)
	SLATE_EVENT(FOnSetInputViewRange, OnSetInputViewRange)
	SLATE_EVENT(FOnGetTimingNodeVisibility, OnGetTimingNodeVisibility)
	SLATE_ARGUMENT(TArray<TSharedPtr<FLGATimingRelevantElementBase>>, TimingElements)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	bool CanDeleteTrack();

	/** Pointer to actual anim notify track */
	TSharedPtr<class SLGAActionTrack>	NotifyTrack;

	/** Return the tracks name as an FText */
	FText GetTrackName() const
	{
		if (Timeline->AbilityActionTracks.IsValidIndex(TrackIndex))
		{
			return FText::FromName(Timeline->AbilityActionTracks[TrackIndex].TrackName);
		}

		/** Should never be possible but better than crashing the editor */
		return LOCTEXT("TrackName_Invalid", "Invalid Track");
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class FLGAActionDragDropOp : public FDragDropOperation
{
public:
	FLGAActionDragDropOp(float& InCurrentDragXPosition)
		: CurrentDragXPosition(InCurrentDragXPosition)
		, SnapTime(-1.f)
		, SelectionTimeLength(0.0f)
	{
	}

	struct FTrackClampInfo
	{
		int32 TrackPos;
		int32 TrackSnapTestPos;
		TSharedPtr<SLGAActionTrack> NotifyTrack;
	};

	DRAG_DROP_OPERATOR_TYPE(FLGAActionDragDropOp, FDragDropOperation)

	virtual void OnDrop(bool bDropWasHandled, const FPointerEvent& MouseEvent) override
	{
		if (bDropWasHandled == false)
		{
			int32 NumNodes = SelectedNodes.Num();

			const FScopedTransaction Transaction(NumNodes > 1 ? LOCTEXT("MoveActions", "Move Actions") : LOCTEXT("MoveAction", "Move Action"));
			Timeline->Modify();
			
			for (int32 CurrentNode = 0; CurrentNode < NumNodes; ++CurrentNode)
			{
				TSharedPtr<SLGAActionNode> Node = SelectedNodes[CurrentNode];
				float NodePositionOffset = NodeXOffsets[CurrentNode];
				const FTrackClampInfo& ClampInfo = GetTrackClampInfo(Node->GetScreenPosition());
				ClampInfo.NotifyTrack->HandleNodeDrop(Node, NodePositionOffset);
				Node->DropCancelled();
			}

			Timeline->PostEditChange();
			Timeline->MarkPackageDirty();
			
			OnUpdatePanel.ExecuteIfBound();
		}
		
		FDragDropOperation::OnDrop(bDropWasHandled, MouseEvent);
	}

	virtual void OnDragged(const class FDragDropEvent& DragDropEvent) override
	{
		// Reset snapped node pointer
		SnappedNode = NULL;

		NodeGroupPosition = DragDropEvent.GetScreenSpacePosition() + DragOffset;

		FTrackClampInfo* SelectionPositionClampInfo = &GetTrackClampInfo(DragDropEvent.GetScreenSpacePosition());
		if ((SelectionPositionClampInfo->NotifyTrack->GetTrackIndex() + TrackSpan) >= ClampInfos.Num())
		{
			// Our selection has moved off the bottom of the notify panel, adjust the clamping information to keep it on the panel
			SelectionPositionClampInfo = &ClampInfos[ClampInfos.Num() - TrackSpan - 1];
		}
		
		const FGeometry& TrackGeom = SelectionPositionClampInfo->NotifyTrack->GetCachedGeometry();
		const FTrackScaleInfo& TrackScaleInfo = SelectionPositionClampInfo->NotifyTrack->GetCachedScaleInfo();

		FVector2D SelectionBeginPosition = TrackGeom.LocalToAbsolute(TrackGeom.AbsoluteToLocal(NodeGroupPosition) + SelectedNodes[0]->GetNotifyPositionOffset());
	
		float LocalTrackMin = TrackScaleInfo.InputToLocalX(0.0f);
		float LocalTrackMax = TrackScaleInfo.InputToLocalX(Timeline->GetPlayLength());
		float LocalTrackWidth = LocalTrackMax - LocalTrackMin;

		// Tracks the movement amount to apply to the selection due to a snap.
		float SnapMovement = 0.0f;
		// Clamp the selection into the track
		float SelectionBeginLocalPositionX = TrackGeom.AbsoluteToLocal(SelectionBeginPosition).X;
		const float ClampedEnd = FMath::Clamp(SelectionBeginLocalPositionX + NodeGroupSize.X, LocalTrackMin, LocalTrackMax);
		const float ClampedBegin = FMath::Clamp(SelectionBeginLocalPositionX, LocalTrackMin, LocalTrackMax);
		if (ClampedBegin > SelectionBeginLocalPositionX)
		{
			SelectionBeginLocalPositionX = ClampedBegin;
		}
		else if (ClampedEnd < SelectionBeginLocalPositionX + NodeGroupSize.X)
		{
			SelectionBeginLocalPositionX = ClampedEnd - NodeGroupSize.X;
		}

		SelectionBeginPosition.X = TrackGeom.LocalToAbsolute(FVector2D(SelectionBeginLocalPositionX, 0.0f)).X;

		// Handle node snaps
		bool bSnapped = false;
		for (int32 NodeIdx = 0; NodeIdx < SelectedNodes.Num() && !bSnapped; ++NodeIdx)
		{
			TSharedPtr<SLGAActionNode> CurrentNode = SelectedNodes[NodeIdx];

			// Clear off any snap time currently stored
			CurrentNode->ClearLastSnappedTime();

			const FTrackClampInfo& NodeClamp = GetTrackClampInfo(CurrentNode->GetScreenPosition());

			FVector2D EventPosition = SelectionBeginPosition + FVector2D(TrackScaleInfo.PixelsPerInput * NodeTimeOffsets[NodeIdx], 0.0f);

			// Look for a snap on the first scrub handle
			FVector2D TrackNodePos = TrackGeom.AbsoluteToLocal(EventPosition);
			const FVector2D OriginalNodePosition = TrackNodePos;
			float SequenceEnd = TrackScaleInfo.InputToLocalX(Timeline->SequenceLength);

			// Always clamp the Y to the current track
			SelectionBeginPosition.Y = SelectionPositionClampInfo->TrackPos - 1.0f;

			float SnapX = GetSnapPosition(NodeClamp, TrackNodePos.X, DragDropEvent.IsControlDown(), bSnapped);
			if (FLGAActionEvent* CurrentEvent = CurrentNode->NodeObjectInterface->GetNotifyEvent())
			{
				if (bSnapped)
				{
					EAnimEventTriggerOffsets::Type Offset = EAnimEventTriggerOffsets::NoOffset;
					if (SnapX == 0.0f || SnapX == SequenceEnd)
					{
						Offset = SnapX > 0.0f ? EAnimEventTriggerOffsets::OffsetBefore : EAnimEventTriggerOffsets::OffsetAfter;
					}
					else
					{
						Offset = (SnapX < TrackNodePos.X) ? EAnimEventTriggerOffsets::OffsetAfter : EAnimEventTriggerOffsets::OffsetBefore;
					}

					CurrentEvent->TriggerTimeOffset = GetTriggerTimeOffsetForType(Offset);
					CurrentNode->SetLastSnappedTime(TrackScaleInfo.LocalXToInput(SnapX));

					if (SnapMovement == 0.0f)
					{
						SnapMovement = SnapX - TrackNodePos.X;
						TrackNodePos.X = SnapX;
						SnapTime = TrackScaleInfo.LocalXToInput(SnapX);
						SnappedNode = CurrentNode;
					}
					EventPosition = NodeClamp.NotifyTrack->GetCachedGeometry().LocalToAbsolute(TrackNodePos);
				}
				else
				{
					CurrentEvent->TriggerTimeOffset = GetTriggerTimeOffsetForType(EAnimEventTriggerOffsets::NoOffset);
				}

				if (CurrentNode.IsValid() && CurrentEvent->GetDuration() > 0)
				{
					// If we didn't snap the beginning of the node, attempt to snap the end
					if (!bSnapped)
					{
						FVector2D TrackNodeEndPos = TrackNodePos + CurrentNode->GetDurationSize();
						SnapX = GetSnapPosition(*SelectionPositionClampInfo, TrackNodeEndPos.X, DragDropEvent.IsControlDown(), bSnapped);

						// Only attempt to snap if the node will fit on the track
						if (SnapX >= CurrentNode->GetDurationSize())
						{
							EAnimEventTriggerOffsets::Type Offset = EAnimEventTriggerOffsets::NoOffset;
							if (SnapX == SequenceEnd)
							{
								// Only need to check the end of the sequence here; end handle can't hit the beginning
								Offset = EAnimEventTriggerOffsets::OffsetBefore;
							}
							else
							{
								Offset = (SnapX < TrackNodeEndPos.X) ? EAnimEventTriggerOffsets::OffsetAfter : EAnimEventTriggerOffsets::OffsetBefore;
							}
							CurrentEvent->EndTriggerTimeOffset = GetTriggerTimeOffsetForType(Offset);

							if (SnapMovement == 0.0f)
							{
								SnapMovement = SnapX - TrackNodeEndPos.X;
								SnapTime = TrackScaleInfo.LocalXToInput(SnapX) - CurrentEvent->GetDuration();
								CurrentNode->SetLastSnappedTime(SnapTime);
								SnappedNode = CurrentNode;
							}
						}
						else
						{
							// Remove any trigger time if we can't fit the node in.
							CurrentEvent->EndTriggerTimeOffset = GetTriggerTimeOffsetForType(EAnimEventTriggerOffsets::NoOffset);
						}
					}
				}
			}
		}

		SelectionBeginPosition.X += SnapMovement;

		CurrentDragXPosition = TrackGeom.AbsoluteToLocal(FVector2D(SelectionBeginPosition.X,0.0f)).X;

		CursorDecoratorWindow->MoveWindowTo(TrackGeom.LocalToAbsolute(TrackGeom.AbsoluteToLocal(SelectionBeginPosition) - SelectedNodes[0]->GetNotifyPositionOffset()));
		NodeGroupPosition = SelectionBeginPosition;

		//scroll view
		float LocalMouseXPos = TrackGeom.AbsoluteToLocal(DragDropEvent.GetScreenSpacePosition()).X;
		float LocalViewportMin = 0.0f;
		float LocalViewportMax = TrackGeom.GetLocalSize().X;
		if (LocalMouseXPos < LocalViewportMin && LocalViewportMin > LocalTrackMin - 10.0f)
		{
			float ScreenDelta = FMath::Max(LocalMouseXPos - LocalViewportMin, -10.0f);
			RequestTrackPan.Execute(ScreenDelta, FVector2D(LocalTrackWidth, 1.f));
		}
		else if (LocalMouseXPos > LocalViewportMax && LocalViewportMax < LocalTrackMax + 10.0f)
		{
			float ScreenDelta =  FMath::Max(LocalMouseXPos - LocalViewportMax, 10.0f);
			RequestTrackPan.Execute(ScreenDelta, FVector2D(LocalTrackWidth, 1.f));
		}

		OnNodesBeingDragged.ExecuteIfBound(SelectedNodes, DragDropEvent, CurrentDragXPosition, TrackScaleInfo.LocalXToInput(CurrentDragXPosition));
	}

	float GetSnapPosition(const FTrackClampInfo& ClampInfo, float WidgetSpaceNotifyPosition, bool bEnableSnapToFrame, bool& bOutSnapped)
	{
		const FTrackScaleInfo& ScaleInfo = ClampInfo.NotifyTrack->GetCachedScaleInfo();

		const float MaxSnapDist = 5.f;

		float CurrentMinSnapDest = MaxSnapDist;
		float SnapPosition = ScaleInfo.LocalXToInput(WidgetSpaceNotifyPosition);
		bOutSnapped = OnSnapPosition.IsBound() && OnSnapPosition.Execute(SnapPosition, MaxSnapDist / ScaleInfo.PixelsPerInput, bEnableSnapToFrame);
		SnapPosition = ScaleInfo.InputToLocalX(SnapPosition);

		float WidgetSpaceStartPosition = ScaleInfo.InputToLocalX(0.0f);
		float WidgetSpaceEndPosition = ScaleInfo.InputToLocalX(Timeline->SequenceLength);

		if (!bOutSnapped)
		{
			// Didn't snap to a bar, snap to the track bounds
			float SnapDistBegin = FMath::Abs(WidgetSpaceStartPosition - WidgetSpaceNotifyPosition);
			float SnapDistEnd = FMath::Abs(WidgetSpaceEndPosition - WidgetSpaceNotifyPosition);
			if (SnapDistBegin < CurrentMinSnapDest)
			{
				SnapPosition = WidgetSpaceStartPosition;
				bOutSnapped = true;
			}
			else if (SnapDistEnd < CurrentMinSnapDest)
			{
				SnapPosition = WidgetSpaceEndPosition;
				bOutSnapped = true;
			}
		}

		return SnapPosition;
	}

	FTrackClampInfo& GetTrackClampInfo(const FVector2D NodePos)
	{
		int32 ClampInfoIndex = 0;
		int32 SmallestNodeTrackDist = FMath::Abs(ClampInfos[0].TrackSnapTestPos - NodePos.Y);
		for (int32 i = 0; i < ClampInfos.Num(); ++i)
		{
			int32 Dist = FMath::Abs(ClampInfos[i].TrackSnapTestPos - NodePos.Y);
			if (Dist < SmallestNodeTrackDist)
			{
				SmallestNodeTrackDist = Dist;
				ClampInfoIndex = i;
			}
		}
		return ClampInfos[ClampInfoIndex];
	}

	class ULGATimeline*		Timeline;				// The owning timeline
	FVector2D							DragOffset;				// Offset from the mouse to place the decorator
	TArray<FTrackClampInfo>				ClampInfos;				// Clamping information for all of the available tracks
	float&								CurrentDragXPosition;	// Current X position of the drag operation
	FPanTrackRequest					RequestTrackPan;		// Delegate to request a pan along the edges of a zoomed track
	TArray<float>						NodeTimes;				// Times to drop each selected node at
	float								SnapTime;				// The time that the snapped node was snapped to
	TWeakPtr<SLGAActionNode>			SnappedNode;			// The node chosen for the snap
	TArray<TSharedPtr<SLGAActionNode>> SelectedNodes;			// The nodes that are in the current selection
	TArray<float>						NodeTimeOffsets;		// Time offsets from the beginning of the selection to the nodes.
	TArray<float>						NodeXOffsets;			// Offsets in X from the widget position to the scrub handle for each node.
	FVector2D							NodeGroupPosition;		// Position of the beginning of the selection
	FVector2D							NodeGroupSize;			// Size of the entire selection
	TSharedPtr<SWidget>					Decorator;				// The widget to display when dragging
	float								SelectionTimeLength;	// Length of time that the selection covers
	int32								TrackSpan;				// Number of tracks that the selection spans
	FOnUpdatePanel						OnUpdatePanel;			// Delegate to redraw the notify panel
	FOnSnapPosition						OnSnapPosition;			// Delegate used to snap times
	FOnActionNodesBeingDragged			OnNodesBeingDragged;	// Delegate to notify panel when the mouse was moved during the DragDropOp

	static TSharedRef<FLGAActionDragDropOp> New(
		TArray<TSharedPtr<SLGAActionNode>>			NotifyNodes, 
		TSharedPtr<SWidget>							Decorator, 
		const TArray<TSharedPtr<SLGAActionTrack>>& NotifyTracks, 
		class ULGATimeline*				Timeline,
		const FVector2D&							CursorPosition, 
		const FVector2D&							SelectionScreenPosition, 
		const FVector2D&							SelectionSize, 
		float&										CurrentDragXPosition, 
		FPanTrackRequest&							RequestTrackPanDelegate, 
		FOnSnapPosition&							OnSnapPosition,
		FOnUpdatePanel&								UpdatePanel,
		FOnActionNodesBeingDragged&					OnNodesBeingDragged
		)
	{
		TSharedRef<FLGAActionDragDropOp> Operation = MakeShareable(new FLGAActionDragDropOp(CurrentDragXPosition));
		Operation->Timeline = Timeline;
		Operation->RequestTrackPan = RequestTrackPanDelegate;
		Operation->OnUpdatePanel = UpdatePanel;
		Operation->OnNodesBeingDragged = OnNodesBeingDragged;

		Operation->NodeGroupPosition = SelectionScreenPosition;
		Operation->NodeGroupSize = SelectionSize;
		Operation->DragOffset = SelectionScreenPosition - CursorPosition;
		Operation->OnSnapPosition = OnSnapPosition;
		Operation->Decorator = Decorator;
		Operation->SelectedNodes = NotifyNodes;
		Operation->TrackSpan = NotifyNodes.Last()->NodeObjectInterface->GetTrackIndex() - NotifyNodes[0]->NodeObjectInterface->GetTrackIndex();
		
		// Caclulate offsets for the selected nodes
		float BeginTime = MAX_flt;
		for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
		{
			float NotifyTime = Node->NodeObjectInterface->GetTime();

			if (NotifyTime < BeginTime)
			{
				BeginTime = NotifyTime;
			}
		}

		// Initialise node data
		for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
		{
			float NotifyTime = Node->NodeObjectInterface->GetTime();

			Node->ClearLastSnappedTime();
			Operation->NodeTimeOffsets.Add(NotifyTime - BeginTime);
			Operation->NodeTimes.Add(NotifyTime);
			Operation->NodeXOffsets.Add(Node->GetNotifyPositionOffset().X);

			// Calculate the time length of the selection. Because it is possible to have states
			// with arbitrary durations we need to search all of the nodes and find the furthest
			// possible point
			Operation->SelectionTimeLength = FMath::Max(Operation->SelectionTimeLength, NotifyTime + Node->NodeObjectInterface->GetDuration() - BeginTime);
		}

		Operation->Construct();

		for (int32 i = 0; i < NotifyTracks.Num(); ++i)
		{
			FTrackClampInfo Info;
			Info.NotifyTrack = NotifyTracks[i];
			const FGeometry& CachedGeometry = Info.NotifyTrack->GetCachedGeometry();
			Info.TrackPos = CachedGeometry.AbsolutePosition.Y;
			Info.TrackSnapTestPos = Info.TrackPos + (CachedGeometry.Size.Y / 2);
			Operation->ClampInfos.Add(Info);
		}

		Operation->CursorDecoratorWindow->SetOpacity(0.5f);
		return Operation;
	}
	
	/** The widget decorator to use */
	virtual TSharedPtr<SWidget> GetDefaultDecorator() const override
	{
		return Decorator;
	}

	FText GetHoverText() const
	{
		FText HoverText = LOCTEXT("Invalid", "Invalid");

		if (SelectedNodes[0].IsValid())
		{
			HoverText = FText::FromName(SelectedNodes[0]->NodeObjectInterface->GetName());
		}

		return HoverText;
	}
};

//////////////////////////////////////////////////////////////////////////
// SLGAActionNode

void SLGAActionNode::Construct(const FArguments& InArgs)
{
	Timeline = InArgs._Timeline;
	Font = FCoreStyle::GetDefaultFontStyle("Regular", 10);
	bBeingDragged = false;
	CurrentDragHandle = ELGAActionStateHandleHit::None;
	bDrawTooltipToRight = true;
	bSelected = false;
	DragActionTransactionIdx = INDEX_NONE;
	
	if (InArgs._Action)
	{
		MakeNodeInterface<FNotifyNodeInterface>(InArgs._Action);
	}
	else
	{
		check(false);	// Must specify something for this node to represent
	}
	// Cache notify name for blueprint / Native notifies.
	NodeObjectInterface->CacheName();

	OnNodeDragStarted = InArgs._OnNodeDragStarted;
	OnActionHandleBeingDragged = InArgs._OnActionHandleBeingDragged;
	PanTrackRequest = InArgs._PanTrackRequest;
	OnSelectionChanged = InArgs._OnSelectionChanged;
	OnUpdatePanel = InArgs._OnUpdatePanel;

	ViewInputMin = InArgs._ViewInputMin;
	ViewInputMax = InArgs._ViewInputMax;
	OnSnapPosition = InArgs._OnSnapPosition;

	if (InArgs._StateEndTimingNode.IsValid())
	{
		// The overlay will use the desired size to calculate the notify node size,
		// compute that once here.
		InArgs._StateEndTimingNode->SlatePrepass(1.0f);
		SAssignNew(EndMarkerNodeOverlay, SOverlay)
		+ SOverlay::Slot()
		[
			InArgs._StateEndTimingNode.ToSharedRef()
		];
	}

	SetClipping(EWidgetClipping::ClipToBounds);

	SetToolTipText(TAttribute<FText>(this, &SLGAActionNode::GetNodeTooltip));
}

FReply SLGAActionNode::OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FVector2D ScreenNodePosition = FVector2D(MyGeometry.AbsolutePosition.X, MyGeometry.AbsolutePosition.Y);
	
	// Whether the drag has hit a duration marker
	bool bDragOnMarker = false;
	bBeingDragged = true;

	if (GetDurationSize() > 0.0f)
	{
		// This is a state node, check for a drag on the markers before movement. Use last screen space position before the drag started
		// as using the last position in the mouse event gives us a mouse position after the drag was started.
		int32 MarkerHit = DurationHandleHitTest(LastMouseDownPosition);
		if (MarkerHit != ELGAActionStateHandleHit::None)
		{
			bDragOnMarker = true;
			bBeingDragged = false;
			CurrentDragHandle = MarkerHit;

			// Modify the owning timeline as we're now dragging the action and begin a transaction
			check(DragActionTransactionIdx == INDEX_NONE);
			DragActionTransactionIdx = GEditor->BeginTransaction(LOCTEXT("DragActionMarker", "Drag Action Marker"));
			Timeline->Modify();
		}
	}

	return OnNodeDragStarted.Execute(SharedThis(this), MouseEvent, ScreenNodePosition, bDragOnMarker);
}

FLinearColor SLGAActionNode::GetNotifyColor() const
{
	TOptional<FLinearColor> Color = NodeObjectInterface->GetEditorColor();
	FLinearColor BaseColor = Color.Get(FLinearColor(1, 1, 0.5f));

	bool bEditable = NodeObjectInterface->GetEditable();
	if (!bEditable)
	{
		BaseColor = FLinearColor(0.3f, 0.3f, 0.3f);
	}

	BaseColor.A = 0.67f;

	return BaseColor;
}

FText SLGAActionNode::GetNotifyText() const
{
	// Combine comment from notify struct and from function on object
	return FText::FromName(NodeObjectInterface->GetName());
}

FText SLGAActionNode::GetNodeTooltip() const
{
	return NodeObjectInterface->GetNodeTooltip(Timeline);
}

/** @return the Node's position within the graph */
UObject* SLGAActionNode::GetObjectBeingDisplayed() const
{
	TOptional<UObject*> Object = NodeObjectInterface->GetObjectBeingDisplayed();
	return Object.Get(Timeline);
}

void SLGAActionNode::DropCancelled()
{
	bBeingDragged = false;
}

FVector2D SLGAActionNode::ComputeDesiredSize(float) const
{
	return GetSize();
}

bool SLGAActionNode::HitTest(const FGeometry& AllottedGeometry, FVector2D MouseLocalPose) const
{
	FVector2D Position = GetWidgetPosition();
	FVector2D Size = GetSize();

	return MouseLocalPose.ComponentwiseAllGreaterOrEqual(Position)
		&& MouseLocalPose.ComponentwiseAllLessOrEqual(Position + Size);
}

int32 SLGAActionNode::DurationHandleHitTest(const FVector2D& CursorTrackPosition) const
{
	int32 MarkerHit = ELGAActionStateHandleHit::None;

	FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent();
	if (ActionEvent && ActionEvent->Action && !ActionEvent->Action->CanChangeDuration())
	{
		return MarkerHit;
	}

	// Make sure this node has a duration box (meaning it is a state node)
	if (NotifyDurationSizeX > 0.0f)
	{
		// Test for mouse inside duration box with handles included
		const double ScrubHandleHalfWidth = ScrubHandleSize.X / 2.0f;

		// Position and size of the notify node including the scrub handles
		const FVector2D NotifyNodePosition(NotifyScrubHandleCentre - ScrubHandleHalfWidth, 0.0);
		const FVector2D NotifyNodeSize(NotifyDurationSizeX + ScrubHandleHalfWidth * 2.0, NotifyHeight);

		const FVector2D MouseRelativePosition(CursorTrackPosition - GetWidgetPosition());

		if (MouseRelativePosition.ComponentwiseAllGreaterThan(NotifyNodePosition) &&
			MouseRelativePosition.ComponentwiseAllLessThan(NotifyNodePosition + NotifyNodeSize))
		{
			// Definitely inside the duration box, need to see which handle we hit if any
			if (MouseRelativePosition.X <= (NotifyNodePosition.X + ScrubHandleSize.X))
			{
				// Left Handle
				MarkerHit = ELGAActionStateHandleHit::Start;
			}
			else if (MouseRelativePosition.X >= (NotifyNodePosition.X + NotifyNodeSize.X - ScrubHandleSize.X))
			{
				// Right Handle
				MarkerHit = ELGAActionStateHandleHit::End;
			}
		}

		if (MarkerHit == ELGAActionStateHandleHit::None)
		{
			for (int32 i = 0; i < ActionEvent->Sections.Num(); ++i)
			{
				FLGAActionEventSection& Section = ActionEvent->Sections[i];
				if (i + 1 < ActionEvent->Sections.Num())
				{
					float DelimiterCenter = NotifyScrubHandleCentre + NotifyDurationSizeX * ActionEvent->GetSectionStartTime(i + 1) / ActionEvent->GetDuration();
					const float Distance = FMath::Abs(MouseRelativePosition.X - DelimiterCenter);
					if (Distance < ScrubHandleHalfWidth)
					{
						MarkerHit = i;
					}
				}
			}
		}
	}

	return MarkerHit;
}

void SLGAActionNode::UpdateSizeAndPosition(const FGeometry& AllottedGeometry)
{
	FTrackScaleInfo ScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0, 0, AllottedGeometry.Size);

	// Cache the geometry information, the alloted geometry is the same size as the track.
	CachedAllotedGeometrySize = AllottedGeometry.Size * AllottedGeometry.Scale;

	NotifyTimePositionX = ScaleInfo.InputToLocalX(NodeObjectInterface->GetTime());
	NotifyDurationSizeX = ScaleInfo.PixelsPerInput * NodeObjectInterface->GetDuration();

	const TSharedRef<FSlateFontMeasure> FontMeasureService = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	TextSize = FontMeasureService->Measure(GetNotifyText(), Font);
	LabelWidth = TextSize.X + (TextBorderSize.X * 2.f) + (ScrubHandleSize.X / 2.f);

	//Calculate scrub handle box size (the notional box around the scrub handle and the alignment marker)
	float NotifyHandleBoxWidth = FMath::Max(ScrubHandleSize.X, AlignmentMarkerSize.X * 2);

	// Work out where we will have to draw the tool tip
	FVector2D Size = GetSize();
	float LeftEdgeToNotify = NotifyTimePositionX;
	float RightEdgeToNotify = AllottedGeometry.Size.X - NotifyTimePositionX;
	bDrawTooltipToRight = NotifyDurationSizeX > 0.0f || ((RightEdgeToNotify > LabelWidth) || (RightEdgeToNotify > LeftEdgeToNotify));

	// Calculate widget width/position based on where we are drawing the tool tip
	WidgetX = bDrawTooltipToRight ? (NotifyTimePositionX - (NotifyHandleBoxWidth / 2.f)) : (NotifyTimePositionX - LabelWidth);
	WidgetSize = bDrawTooltipToRight ? FVector2D((NotifyDurationSizeX > 0.0f ? NotifyDurationSizeX : FMath::Max(LabelWidth, NotifyDurationSizeX)), NotifyHeight) : FVector2D((LabelWidth + NotifyDurationSizeX), NotifyHeight);
	WidgetSize.X += NotifyHandleBoxWidth;
	
	if (EndMarkerNodeOverlay.IsValid())
	{
		FVector2D OverlaySize = EndMarkerNodeOverlay->GetDesiredSize();
		WidgetSize.X += OverlaySize.X;
	}

	// Widget position of the notify marker
	NotifyScrubHandleCentre = bDrawTooltipToRight ? NotifyHandleBoxWidth / 2.f : LabelWidth;
}

/** @return the Node's position within the track */
FVector2D SLGAActionNode::GetWidgetPosition() const
{
	return FVector2D(WidgetX, NotifyHeightOffset);
}

FVector2D SLGAActionNode::GetNotifyPosition() const
{
	return FVector2D(NotifyTimePositionX, NotifyHeightOffset);
}

FVector2D SLGAActionNode::GetNotifyPositionOffset() const
{
	return GetNotifyPosition() - GetWidgetPosition();
}

FVector2D SLGAActionNode::GetSize() const
{
	return WidgetSize;
}

int32 SLGAActionNode::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	int32 SectionLayer = LayerId + 1;
	int32 MarkerLayer = SectionLayer + 1;
	int32 ScrubHandleID = MarkerLayer + 1;
	int32 TextLayerID = ScrubHandleID + 1;
	int32 BranchPointLayerID = TextLayerID + 1;

	FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent();

	// Paint marker node if we have one
	if (EndMarkerNodeOverlay.IsValid())
	{
		FVector2D MarkerSize = EndMarkerNodeOverlay->GetDesiredSize();
		FVector2D MarkerOffset(NotifyDurationSizeX + MarkerSize.X * 0.5f + 5.0f, (NotifyHeight - MarkerSize.Y) * 0.5f);
		EndMarkerNodeOverlay->Paint(Args.WithNewParent(this), AllottedGeometry.MakeChild(MarkerSize, FSlateLayoutTransform(MarkerOffset)), MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	}

	const FSlateBrush* StyleInfo = FAppStyle::GetBrush(TEXT("SpecialEditableTextImageNormal"));

	FText Text = GetNotifyText();
	bool bEditable = NodeObjectInterface->GetEditable();
	FLinearColor NodeColor = SLGAActionNode::GetNotifyColor();
	FLinearColor BoxColor = bSelected ? FAppStyle::GetSlateColor("SelectionColor").GetSpecifiedColor() : SLGAActionNode::GetNotifyColor();

	float HalfScrubHandleWidth = ScrubHandleSize.X / 2.0f;

	// Show duration of AnimNotifyState
	if (NotifyDurationSizeX > 0.f)
	{
		FVector2D DurationBoxSize = FVector2D(NotifyDurationSizeX, TextSize.Y + TextBorderSize.Y * 2.f);
		FVector2D DurationBoxPosition = FVector2D(NotifyScrubHandleCentre, (NotifyHeight - TextSize.Y) * 0.5f);
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(DurationBoxSize, FSlateLayoutTransform(DurationBoxPosition)),
			StyleInfo,
			ESlateDrawEffect::None,
			BoxColor);
		
		// Draw Sections
		for (int32 i=0; i < ActionEvent->Sections.Num(); ++i)
		{
			FLGAActionEventSection& Section = ActionEvent->Sections[i];
			if (ActionEvent->GetDuration() > 0)
			{
				float RelativeSectionStart = ActionEvent->GetSectionStartTime(i) / ActionEvent->GetDuration();
				float RelativeSectionLength = ActionEvent->GetSectionDuration(i) / ActionEvent->GetDuration();

				FVector2D SectionBoxSize = FVector2D(NotifyDurationSizeX * RelativeSectionLength, TextSize.Y + TextBorderSize.Y * 2.f);
				FVector2D SectionBoxPosition = FVector2D(NotifyScrubHandleCentre + NotifyDurationSizeX * RelativeSectionStart, (NotifyHeight - TextSize.Y) * 0.5f);

				FSlateDrawElement::MakeBox(
					OutDrawElements,
					SectionLayer,
					AllottedGeometry.ToPaintGeometry(SectionBoxSize, FSlateLayoutTransform(SectionBoxPosition)),
					StyleInfo,
					ESlateDrawEffect::None,
					bEditable ? Section.Color : NodeColor);
			}

			if (i + 1 < ActionEvent->Sections.Num())
			{
				float RelativeSectionEnd = ActionEvent->GetSectionEndTime(i) / ActionEvent->GetDuration();
				float DelimiterCenter = NotifyScrubHandleCentre + NotifyDurationSizeX * RelativeSectionEnd;
				DrawScrubHandle(DelimiterCenter, OutDrawElements, ScrubHandleID, AllottedGeometry, MyCullingRect, NodeColor);
			}
		}

		DrawScrubHandle(static_cast<float>(DurationBoxPosition.X + DurationBoxSize.X), OutDrawElements, ScrubHandleID, AllottedGeometry, MyCullingRect, NodeColor);

		// Render offsets if necessary
		//if (ActionEvent && ActionEvent->EndTriggerTimeOffset != 0.f) //Do we have an offset to render?
		//{
		//	const float EndTime = ActionEvent->GetTime() + ActionEvent->GetDuration();
		//	if (EndTime != Sequence->GetPlayLength()) //Don't render offset when we are at the end of the sequence, doesnt help the user
		//	{
		//		// ScrubHandle
		//		const float HandleCentre = NotifyDurationSizeX + (static_cast<float>(ScrubHandleSize.X) - 2.0f);
		//		DrawHandleOffset(ActionEvent->EndTriggerTimeOffset, HandleCentre, OutDrawElements, MarkerLayer, AllottedGeometry, MyCullingRect, NodeColor);
		//	}
		//}
	}

	// Background
	FVector2D LabelSize = TextSize + TextBorderSize * 2.f;
	LabelSize.X += HalfScrubHandleWidth;

	FVector2D LabelPosition(bDrawTooltipToRight ? NotifyScrubHandleCentre : NotifyScrubHandleCentre - LabelSize.X, (NotifyHeight - TextSize.Y) * 0.5f);

	if (NotifyDurationSizeX == 0.f)
	{
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId,
			AllottedGeometry.ToPaintGeometry(LabelSize, FSlateLayoutTransform(LabelPosition)),
			StyleInfo,
			ESlateDrawEffect::None,
			BoxColor);
	}

	// Text
	FVector2D TextPosition = LabelPosition + TextBorderSize;
	if (bDrawTooltipToRight)
	{
		TextPosition.X += HalfScrubHandleWidth;
	}

	FVector2D DrawTextSize;
	DrawTextSize.X = (NotifyDurationSizeX > 0.0f ? FMath::Min(NotifyDurationSizeX - ScrubHandleSize.X, TextSize.X + ScrubHandleSize.X) : TextSize.X);
	DrawTextSize.Y = TextSize.Y;

	FPaintGeometry TextGeometry = AllottedGeometry.ToPaintGeometry(DrawTextSize, FSlateLayoutTransform(TextPosition));
	OutDrawElements.PushClip(FSlateClippingZone(TextGeometry));

	FSlateDrawElement::MakeText(
		OutDrawElements,
		TextLayerID,
		TextGeometry,
		Text,
		Font,
		ESlateDrawEffect::None,
		FLinearColor::Black
	);

	OutDrawElements.PopClip();

	DrawScrubHandle(NotifyScrubHandleCentre , OutDrawElements, ScrubHandleID, AllottedGeometry, MyCullingRect, NodeColor);

	//if (ActionEvent && ActionEvent->TriggerTimeOffset != 0.f) //Do we have an offset to render?
	//{
	//	float NotifyTime = ActionEvent->GetTime();
	//	if (NotifyTime != 0.f && NotifyTime != Sequence->GetPlayLength()) //Don't render offset when we are at the start/end of the sequence, doesn't help the user
	//	{
	//		float HandleCentre = NotifyScrubHandleCentre;
	//		float& Offset = ActionEvent->TriggerTimeOffset;

	//		DrawHandleOffset(ActionEvent->TriggerTimeOffset, NotifyScrubHandleCentre, OutDrawElements, MarkerLayer, AllottedGeometry, MyCullingRect, NodeColor);
	//	}
	//}

	return TextLayerID;
}

FReply SLGAActionNode::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	// Don't do scrub handle dragging if we haven't captured the mouse.
	if (!this->HasMouseCapture()) return FReply::Unhandled();

	if (CurrentDragHandle == ELGAActionStateHandleHit::None)
	{
		// We've had focus taken away - realease the mouse
		FSlateApplication::Get().ReleaseAllPointerCapture();
		return FReply::Unhandled();
	}
	
	FTrackScaleInfo ScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0, 0, CachedAllotedGeometrySize);
	
	float XPositionInTrack = MyGeometry.AbsolutePosition.X - CachedTrackGeometry.AbsolutePosition.X;
	float TrackScreenSpaceXPosition = MyGeometry.AbsolutePosition.X - XPositionInTrack;
	float TrackScreenSpaceOrigin = CachedTrackGeometry.LocalToAbsolute(FVector2D(ScaleInfo.InputToLocalX(0.0f), 0.0f)).X;
	float TrackScreenSpaceLimit = CachedTrackGeometry.LocalToAbsolute(FVector2D(ScaleInfo.InputToLocalX(Timeline->GetPlayLength()), 0.0f)).X;

	float MinimumStateDuration = NodeObjectInterface->GetNotifyEvent()->GetMinimumStateDuration();

	if (CurrentDragHandle == ELGAActionStateHandleHit::Start)
	{
		// Check track bounds
		float OldDisplayTime = NodeObjectInterface->GetTime();

		if (MouseEvent.GetScreenSpacePosition().X >= TrackScreenSpaceXPosition && MouseEvent.GetScreenSpacePosition().X <= TrackScreenSpaceXPosition + CachedAllotedGeometrySize.X)
		{
			float NewDisplayTime = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X);
			float NewDuration = NodeObjectInterface->GetDuration() + OldDisplayTime - NewDisplayTime;

			// Check to make sure the duration is not less than the minimum allowed
			if (NewDuration < MinimumStateDuration)
			{
				NewDisplayTime -= MinimumStateDuration - NewDuration;
			}

			NodeObjectInterface->SetTime(FMath::Max(0.0f, NewDisplayTime));
			NodeObjectInterface->SetDuration(NodeObjectInterface->GetDuration() + OldDisplayTime - NodeObjectInterface->GetTime());
		}
		else if (NodeObjectInterface->GetDuration() > MinimumStateDuration)
		{
			float Overflow = HandleOverflowPan(MouseEvent.GetScreenSpacePosition(), TrackScreenSpaceXPosition, TrackScreenSpaceOrigin, TrackScreenSpaceLimit);

			// Update scale info to the new view inputs after panning
			ScaleInfo.ViewMinInput = ViewInputMin.Get();
			ScaleInfo.ViewMaxInput = ViewInputMax.Get();

			float NewDisplayTime = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X);
			NodeObjectInterface->SetTime(FMath::Max(0.0f, NewDisplayTime));
			NodeObjectInterface->SetDuration(NodeObjectInterface->GetDuration() + OldDisplayTime - NodeObjectInterface->GetTime());

			// Adjust incase we went under the minimum
			if (NodeObjectInterface->GetDuration() < MinimumStateDuration)
			{
				float EndTimeBefore = NodeObjectInterface->GetTime() + NodeObjectInterface->GetDuration();
				NodeObjectInterface->SetTime(NodeObjectInterface->GetTime() + NodeObjectInterface->GetDuration() - MinimumStateDuration);
				NodeObjectInterface->SetDuration(MinimumStateDuration);
				float EndTimeAfter = NodeObjectInterface->GetTime() + NodeObjectInterface->GetDuration();
			}
		}

		// Now we know where the marker should be, look for possible snaps on montage marker bars
		if (FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent())
		{
			float NodePositionX = ScaleInfo.InputToLocalX(ActionEvent->GetStartTime());
			float MarkerSnap = GetScrubHandleSnapPosition(NodePositionX, ELGAActionStateHandleHit::Start, MouseEvent.IsControlDown());
			if (MarkerSnap != -1.0f)
			{
				// We're near to a snap bar
				EAnimEventTriggerOffsets::Type Offset = (MarkerSnap < NodePositionX) ? EAnimEventTriggerOffsets::OffsetAfter : EAnimEventTriggerOffsets::OffsetBefore;
				ActionEvent->TriggerTimeOffset = GetTriggerTimeOffsetForType(Offset);
				NodePositionX = MarkerSnap;

				// Adjust our start marker
				OldDisplayTime = ActionEvent->GetStartTime();
				ActionEvent->SetStartTime(ScaleInfo.LocalXToInput(NodePositionX));
				ActionEvent->SetDuration(ActionEvent->GetDuration() + OldDisplayTime - ActionEvent->GetStartTime());
			}
			else
			{
				ActionEvent->TriggerTimeOffset = GetTriggerTimeOffsetForType(EAnimEventTriggerOffsets::NoOffset);
			}
		}

		OnActionHandleBeingDragged.ExecuteIfBound(SharedThis(this), MouseEvent, ELGAActionStateHandleHit::Start, NodeObjectInterface->GetTime());
	}
	else if (CurrentDragHandle == ELGAActionStateHandleHit::End)
	{
		if (MouseEvent.GetScreenSpacePosition().X >= TrackScreenSpaceXPosition && MouseEvent.GetScreenSpacePosition().X <= TrackScreenSpaceXPosition + CachedAllotedGeometrySize.X)
		{
			float NewDuration = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X) - NodeObjectInterface->GetTime();

			NodeObjectInterface->SetDuration(FMath::Max(NewDuration, MinimumStateDuration));
		}
		else if (NodeObjectInterface->GetDuration() > MinimumStateDuration)
		{
			float Overflow = HandleOverflowPan(MouseEvent.GetScreenSpacePosition(), TrackScreenSpaceXPosition, TrackScreenSpaceOrigin, TrackScreenSpaceLimit);

			// Update scale info to the new view inputs after panning
			ScaleInfo.ViewMinInput = ViewInputMin.Get();
			ScaleInfo.ViewMaxInput = ViewInputMax.Get();

			float NewDuration = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X) - NodeObjectInterface->GetTime();
			NodeObjectInterface->SetDuration(FMath::Max(NewDuration, MinimumStateDuration));
		}

		if (NodeObjectInterface->GetTime() + NodeObjectInterface->GetDuration() > Timeline->GetPlayLength())
		{
			NodeObjectInterface->SetDuration(Timeline->GetPlayLength() - NodeObjectInterface->GetTime());
		}

		// Now we know where the scrub handle should be, look for possible snaps on montage marker bars
		if (FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent())
		{
			float NodePositionX = ScaleInfo.InputToLocalX(ActionEvent->GetStartTime() + ActionEvent->GetDuration());
			float MarkerSnap = GetScrubHandleSnapPosition(NodePositionX, ELGAActionStateHandleHit::End, MouseEvent.IsControlDown());
			if (MarkerSnap != -1.0f)
			{
				// We're near to a snap bar
				EAnimEventTriggerOffsets::Type Offset = (MarkerSnap < NodePositionX) ? EAnimEventTriggerOffsets::OffsetAfter : EAnimEventTriggerOffsets::OffsetBefore;
				ActionEvent->EndTriggerTimeOffset = GetTriggerTimeOffsetForType(Offset);
				NodePositionX = MarkerSnap;

				// Adjust our end marker
				ActionEvent->SetDuration(ScaleInfo.LocalXToInput(NodePositionX) - ActionEvent->GetStartTime());
			}
			else
			{
				ActionEvent->EndTriggerTimeOffset = GetTriggerTimeOffsetForType(EAnimEventTriggerOffsets::NoOffset);
			}
		}

		OnActionHandleBeingDragged.ExecuteIfBound(SharedThis(this), MouseEvent, ELGAActionStateHandleHit::End, (NodeObjectInterface->GetTime() + NodeObjectInterface->GetDuration()));
	}
	else if(FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent())
	{
		float StartSectionTime = ActionEvent->GetAbsoluteSectionStartTime(CurrentDragHandle);

		if (MouseEvent.GetScreenSpacePosition().X >= TrackScreenSpaceXPosition && MouseEvent.GetScreenSpacePosition().X <= TrackScreenSpaceXPosition + CachedAllotedGeometrySize.X)
		{
			float NewDuration = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X) - StartSectionTime;

			ActionEvent->SetSectionDuration(CurrentDragHandle, FMath::Max(NewDuration, 0.f));
		}
		else if (NodeObjectInterface->GetDuration() > MinimumStateDuration)
		{
			float Overflow = HandleOverflowPan(MouseEvent.GetScreenSpacePosition(), TrackScreenSpaceXPosition, TrackScreenSpaceOrigin, TrackScreenSpaceLimit);

			// Update scale info to the new view inputs after panning
			ScaleInfo.ViewMinInput = ViewInputMin.Get();
			ScaleInfo.ViewMaxInput = ViewInputMax.Get();

			float NewDuration = ScaleInfo.LocalXToInput((MouseEvent.GetScreenSpacePosition() - MyGeometry.AbsolutePosition + XPositionInTrack).X) - StartSectionTime;
			ActionEvent->SetSectionDuration(CurrentDragHandle, FMath::Max(NewDuration, 0.f));
		}

		OnActionHandleBeingDragged.ExecuteIfBound(SharedThis(this), MouseEvent, ELGAActionStateHandleHit::None, ActionEvent->GetAbsoluteSectionEndTime(CurrentDragHandle));
	}

	return FReply::Handled();
}

FReply SLGAActionNode::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bool bLeftButton = MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton;

	if (bLeftButton && CurrentDragHandle != ELGAActionStateHandleHit::None)
	{
		// Clear the drag marker and give the mouse back
		CurrentDragHandle = ELGAActionStateHandleHit::None;

		// Signal selection changing so details panels get updated
		OnSelectionChanged.ExecuteIfBound();

		// End drag transaction before handing mouse back
		check(DragActionTransactionIdx != INDEX_NONE);
		GEditor->EndTransaction();
		DragActionTransactionIdx = INDEX_NONE;

		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();

		OnUpdatePanel.ExecuteIfBound();

		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

float SLGAActionNode::GetScrubHandleSnapPosition(float NotifyLocalX, ELGAActionStateHandleHit::Type HandleToCheck, bool bEnableSnapToFrame)
{
	FTrackScaleInfo ScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0, 0, CachedAllotedGeometrySize);

	const float MaxSnapDist = 5.0f;

	float CurrentMinSnapDistance = MaxSnapDist;
	float SnapPosition = ScaleInfo.LocalXToInput(NotifyLocalX);

	if (OnSnapPosition.IsBound())
	{
		if (OnSnapPosition.Execute(SnapPosition, MaxSnapDist / ScaleInfo.PixelsPerInput, bEnableSnapToFrame))
		{
			return ScaleInfo.InputToLocalX(SnapPosition);
		}
	}	

	return -1.0f;
}

FReply SLGAActionNode::OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent)
{
	return FReply::Handled().SetUserFocus(AsShared(), EFocusCause::SetDirectly, true);
}

float SLGAActionNode::HandleOverflowPan(const FVector2D &ScreenCursorPos, float TrackScreenSpaceXPosition, float TrackScreenSpaceMin, float TrackScreenSpaceMax)
{
	float Overflow = 0.0f;

	if (ScreenCursorPos.X < TrackScreenSpaceXPosition && TrackScreenSpaceXPosition > TrackScreenSpaceMin - 10.0f)
	{
		// Overflow left edge
		Overflow = FMath::Min(ScreenCursorPos.X - TrackScreenSpaceXPosition, -10.0f);
	}
	else if (ScreenCursorPos.X > CachedAllotedGeometrySize.X && (TrackScreenSpaceXPosition + CachedAllotedGeometrySize.X) < TrackScreenSpaceMax + 10.0f)
	{
		// Overflow right edge
		Overflow = FMath::Max(ScreenCursorPos.X - (TrackScreenSpaceXPosition + CachedAllotedGeometrySize.X), 10.0f);
	}

	PanTrackRequest.ExecuteIfBound(Overflow, CachedAllotedGeometrySize);

	return Overflow;
}

void SLGAActionNode::DrawScrubHandle(float ScrubHandleCentre, FSlateWindowElementList& OutDrawElements, int32 ScrubHandleID, const FGeometry &AllottedGeometry, const FSlateRect& MyCullingRect, FLinearColor NodeColour) const
{
	FVector2D ScrubHandlePosition(ScrubHandleCentre - ScrubHandleSize.X / 2.0f, (NotifyHeight - ScrubHandleSize.Y) / 2.f);
	FSlateDrawElement::MakeBox(
		OutDrawElements,
		ScrubHandleID,
		AllottedGeometry.ToPaintGeometry(ScrubHandleSize, FSlateLayoutTransform(ScrubHandlePosition)),
		FAppStyle::GetBrush(TEXT("Sequencer.KeyDiamond")),
		ESlateDrawEffect::None,
		NodeColour
	);

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		ScrubHandleID,
		AllottedGeometry.ToPaintGeometry(ScrubHandleSize, FSlateLayoutTransform(ScrubHandlePosition)),
		FAppStyle::GetBrush(TEXT("Sequencer.KeyDiamondBorder")),
		ESlateDrawEffect::None,
		bSelected ? FAppStyle::GetSlateColor("SelectionColor").GetSpecifiedColor() : FLinearColor::Black
	);
}

void SLGAActionNode::DrawHandleOffset(const float& Offset, const float& HandleCentre, FSlateWindowElementList& OutDrawElements, int32 MarkerLayer, const FGeometry &AllottedGeometry, const FSlateRect& MyCullingRect, FLinearColor NodeColor) const
{
	FVector2D MarkerPosition;
	FVector2D MarkerSize = AlignmentMarkerSize;

	if (Offset < 0.f)
	{
		MarkerPosition.Set(HandleCentre - AlignmentMarkerSize.X, (NotifyHeight - AlignmentMarkerSize.Y) / 2.f);
	}
	else
	{
		MarkerPosition.Set(HandleCentre + AlignmentMarkerSize.X, (NotifyHeight - AlignmentMarkerSize.Y) / 2.f);
		MarkerSize.X = -AlignmentMarkerSize.X;
	}

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		MarkerLayer,
		AllottedGeometry.ToPaintGeometry(MarkerSize, FSlateLayoutTransform(MarkerPosition)),
		FAppStyle::GetBrush(TEXT("Sequencer.Timeline.NotifyAlignmentMarker")),
		ESlateDrawEffect::None,
		NodeColor
	);
}

void SLGAActionNode::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	ScreenPosition = FVector2D(AllottedGeometry.AbsolutePosition.X, AllottedGeometry.AbsolutePosition.Y);
}

void SLGAActionNode::OnFocusLost(const FFocusEvent& InFocusEvent)
{
	if (CurrentDragHandle != ELGAActionStateHandleHit::None)
	{
		// Lost focus while dragging a state node, clear the drag and end the current transaction
		CurrentDragHandle = ELGAActionStateHandleHit::None;
		
		check(DragActionTransactionIdx != INDEX_NONE);
		GEditor->EndTransaction();
		DragActionTransactionIdx = INDEX_NONE;
	}
}

bool SLGAActionNode::SupportsKeyboardFocus() const
{
	// Need to support focus on the node so we can end drag transactions if the user alt-tabs
	// from the editor while in the proceess of dragging a state notify duration marker.
	return true;
}

FCursorReply SLGAActionNode::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	// Show resize cursor if the cursor is hoverring over either of the scrub handles of a notify state node
	if (IsHovered() && GetDurationSize() > 0.0f)
	{
		FVector2D RelMouseLocation = MyGeometry.AbsoluteToLocal(CursorEvent.GetScreenSpacePosition());

		const float HandleHalfWidth = ScrubHandleSize.X / 2.0f;
		const float DistFromFirstHandle = FMath::Abs(RelMouseLocation.X - NotifyScrubHandleCentre);
		const float DistFromSecondHandle = FMath::Abs(RelMouseLocation.X - (NotifyScrubHandleCentre + NotifyDurationSizeX));

		if (DistFromFirstHandle < HandleHalfWidth || DistFromSecondHandle < HandleHalfWidth || CurrentDragHandle != ELGAActionStateHandleHit::None)
		{
			return FCursorReply::Cursor(EMouseCursor::ResizeLeftRight);
		}

		FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent();
		for (int32 i = 0; i < ActionEvent->Sections.Num(); ++i)
		{
			FLGAActionEventSection& Section = ActionEvent->Sections[i];
			if (i + 1 < ActionEvent->Sections.Num())
			{
				float RelativeSectionEnd = ActionEvent->GetSectionEndTime(i) / ActionEvent->GetDuration();
				float DelimiterCenter = NotifyScrubHandleCentre + NotifyDurationSizeX * RelativeSectionEnd;
				const float Distance = FMath::Abs(RelMouseLocation.X - DelimiterCenter);
				if (Distance < HandleHalfWidth || CurrentDragHandle != ELGAActionStateHandleHit::None)
				{
					return FCursorReply::Cursor(EMouseCursor::ResizeLeftRight);
				}
			}
		}
	}
	return FCursorReply::Unhandled();
}

//////////////////////////////////////////////////////////////////////////
// SLGAActionTrack

void SLGAActionTrack::Construct(const FArguments& InArgs)
{
	SetClipping(EWidgetClipping::ClipToBounds);

	WeakCommandList = InArgs._CommandList;
	Timeline = InArgs._Timeline;
	ViewInputMin = InArgs._ViewInputMin;
	ViewInputMax = InArgs._ViewInputMax;
	OnSelectionChanged = InArgs._OnSelectionChanged;
	Actions = InArgs._Actions;
	TimingElements = InArgs._TimingElements;
	OnUpdatePanel = InArgs._OnUpdatePanel;
	TrackIndex = InArgs._TrackIndex;
	OnGetScrubValue = InArgs._OnGetScrubValue;
	OnGetDraggedNodePos = InArgs._OnGetDraggedNodePos;
	OnNodeDragStarted = InArgs._OnNodeDragStarted;
	OnActionHandleBeingDragged = InArgs._OnActionHandleBeingDragged;
	TrackColor = InArgs._TrackColor;
	OnSnapPosition = InArgs._OnSnapPosition;
	OnRequestTrackPan = InArgs._OnRequestTrackPan;
	OnRequestRefreshOffsets = InArgs._OnRequestOffsetRefresh;
	OnDeleteNotify = InArgs._OnDeleteNotify;
	OnGetIsAnimNotifySelectionValidforReplacement = InArgs._OnGetIsAnimNotifySelectionValidForReplacement;
	OnReplaceSelectedWithNotify = InArgs._OnReplaceSelectedWithNotify;
	OnReplaceSelectedWithBlueprintNotify = InArgs._OnReplaceSelectedWithBlueprintNotify;
	OnDeselectAllNotifies = InArgs._OnDeselectAllNotifies;
	OnCopyNodes = InArgs._OnCopyNodes;
	OnPasteNodes = InArgs._OnPasteNodes;
	OnSetInputViewRange = InArgs._OnSetInputViewRange;
	OnGetTimingNodeVisibility = InArgs._OnGetTimingNodeVisibility;
	bActionEditable = InArgs._ActionEditable;

	this->ChildSlot
	[
		SAssignNew(TrackArea, SBorder)
		.Visibility(EVisibility::SelfHitTestInvisible)
		.BorderImage(FAppStyle::GetBrush("NoBorder"))
		.Padding(FMargin(0.f, 0.f))
	];

	Update();
}

FVector2D SLGAActionTrack::ComputeDesiredSize(float) const
{
	FVector2D Size;
	Size.X = 200;
	Size.Y = NotifyHeight;
	return Size;
}

int32 SLGAActionTrack::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const FSlateBrush* StyleInfo = FAppStyle::GetBrush(TEXT("Persona.NotifyEditor.NotifyTrackBackground"));
	FLinearColor Color = TrackColor.Get();

	FPaintGeometry MyGeometry = AllottedGeometry.ToPaintGeometry();

	int32 CustomLayerId = LayerId + 1; 
	FTrackScaleInfo ScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0.f, 0.f, AllottedGeometry.Size);

	bool bAnyDraggedNodes = false;
	for (int32 I = 0; I < NotifyNodes.Num(); ++I)
	{
		if (NotifyNodes[I].Get()->bBeingDragged == false)
		{
			NotifyNodes[I].Get()->UpdateSizeAndPosition(AllottedGeometry);
		}
		else
		{
			bAnyDraggedNodes = true;
		}
	}

	if (TrackIndex < Timeline->AbilityActionTracks.Num() - 1)
	{
		// Draw track bottom border
		FSlateDrawElement::MakeLines(
			OutDrawElements,
			CustomLayerId,
			AllottedGeometry.ToPaintGeometry(),
			TArray<FVector2D>({ FVector2D(0.0f, AllottedGeometry.GetLocalSize().Y), FVector2D(AllottedGeometry.GetLocalSize().X, AllottedGeometry.GetLocalSize().Y) }),
			ESlateDrawEffect::None,
			FLinearColor(0.1f, 0.1f, 0.1f, 0.3f)
		);
	}

	++CustomLayerId;

	float Value = 0.f;

	if (bAnyDraggedNodes && OnGetDraggedNodePos.IsBound())
	{
		Value = OnGetDraggedNodePos.Execute();

		if (Value >= 0.0f)
		{
			float XPos = Value;
			TArray<FVector2D> LinePoints;
			LinePoints.Add(FVector2D(XPos, 0.f));
			LinePoints.Add(FVector2D(XPos, AllottedGeometry.Size.Y));

			FSlateDrawElement::MakeLines(
				OutDrawElements,
				CustomLayerId,
				MyGeometry,
				LinePoints,
				ESlateDrawEffect::None,
				FLinearColor(1.0f, 0.5f, 0.0f)
			);
		}
	}

	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, CustomLayerId, InWidgetStyle, bParentEnabled);
}

FCursorReply SLGAActionTrack::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	if (ViewInputMin.Get() > 0.f || ViewInputMax.Get() < Timeline->SequenceLength)
	{
		return FCursorReply::Cursor(EMouseCursor::GrabHand);
	}

	return FCursorReply::Unhandled();
}

void SLGAActionTrack::MakeNewNotifyPicker(FMenuBuilder& MenuBuilder, bool bIsReplaceWithMenu)
{
	class FActionClassFilter : public IClassViewerFilter
	{
	public:
		FActionClassFilter() {}

		bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef<FClassViewerFilterFuncs> InFilterFuncs) override
		{
			const bool bChildOfObjectClass = InClass->IsChildOf(ULGAAction::StaticClass());
			const bool bMatchesFlags = !InClass->HasAnyClassFlags(CLASS_Hidden | CLASS_HideDropDown | CLASS_Deprecated | CLASS_Abstract);
			return bChildOfObjectClass && bMatchesFlags;
		}

		virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef<const IUnloadedBlueprintData> InUnloadedClassData, TSharedRef< FClassViewerFilterFuncs > InFilterFuncs) override
		{
			const bool bChildOfObjectClass = InUnloadedClassData->IsChildOf(ULGAAction::StaticClass());
			const bool bMatchesFlags = !InUnloadedClassData->HasAnyClassFlags(CLASS_Hidden | CLASS_HideDropDown | CLASS_Deprecated | CLASS_Abstract);
			return bChildOfObjectClass && bMatchesFlags;
		}
	};

	// MenuBuilder always has a search widget added to it by default, hence if larger then 1 then something else has been added to it
	if (MenuBuilder.GetMultiBox()->GetBlocks().Num() > 1)
	{
		MenuBuilder.AddMenuSeparator();
	}

	FClassViewerInitializationOptions InitOptions;
	InitOptions.Mode = EClassViewerMode::ClassPicker;
	InitOptions.bShowObjectRootClass = false;
	InitOptions.bShowUnloadedBlueprints = true;
	InitOptions.bShowNoneOption = false;
	InitOptions.bEnableClassDynamicLoading = true;
	InitOptions.bExpandRootNodes = true;
	InitOptions.NameTypeToDisplay = EClassViewerNameTypeToDisplay::DisplayName;
	InitOptions.ClassFilters.Add(MakeShared<FActionClassFilter>());
	InitOptions.bShowBackgroundBorder = false;

	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");
	MenuBuilder.AddWidget(
		SNew(SBox)
		.MinDesiredWidth(300.0f)
		.MaxDesiredHeight(400.0f)
		[
			ClassViewerModule.CreateClassViewer(InitOptions, FOnClassPicked::CreateLambda([this, bIsReplaceWithMenu](UClass* InClass)
			{
				FSlateApplication::Get().DismissAllMenus();
				if (bIsReplaceWithMenu)
				{
					ReplaceSelectedWithNotify(MakeBlueprintNotifyName(InClass->GetName()), InClass);
				}
				else
				{
					CreateNewActionAtCursor(MakeBlueprintNotifyName(InClass->GetName()), InClass);
				}
			}))
		],
		FText(), true, false);
}

void SLGAActionTrack::FillNewNotifyMenu(FMenuBuilder& MenuBuilder, bool bIsReplaceWithMenu)
{
	// Add a notify picker
	MakeNewNotifyPicker(MenuBuilder, bIsReplaceWithMenu);
}

FLGAActionEvent& SLGAActionTrack::CreateNewAction(FString NewActionName, UClass* ActionClass, float StartTime, bool bNotifyEditChange)
{
	// Insert a new action record and spawn the new action object
	FLGAActionEvent& NewEvent = Timeline->Actions[Timeline->Actions.Emplace()];
	NewEvent.Guid = FGuid::NewGuid();

	NewEvent.SetStartTime(StartTime);
	NewEvent.TriggerTimeOffset = GetTriggerTimeOffsetForType(Timeline->CalculateOffsetForNotify(StartTime));
	NewEvent.TrackIndex = TrackIndex;
	NewEvent.Action = NewObject<ULGAAction>(Timeline, ActionClass, NAME_None, Timeline->GetMaskedFlags(RF_PropagateToSubObjects));
	if (!NewEvent.Action->IsSingleFrame())
	{
		NewEvent.SetDuration(1 / 30.f);
	}

	if (bNotifyEditChange)
	{
		NewEvent.Action->PostEditChange();
		Timeline->PostEditChange();
	}

	Timeline->MarkPackageDirty();

	return NewEvent;
}

void SLGAActionTrack::CreateNewActionAtCursor(FString NewActionName, UClass* ActionClass)
{
	const FScopedTransaction Transaction(LOCTEXT("AddAction", "Add Action"));
	Timeline->Modify();
	CreateNewAction(NewActionName, ActionClass, LastClickedTime);
	OnUpdatePanel.ExecuteIfBound();
}

void SLGAActionTrack::ReplaceSelectedWithBlueprintNotify(FString NewNotifyName, FString BlueprintPath)
{
	OnReplaceSelectedWithBlueprintNotify.ExecuteIfBound(NewNotifyName, BlueprintPath);
}

void SLGAActionTrack::ReplaceSelectedWithNotify(FString NewNotifyName, UClass* NotifyClass)
{
	OnReplaceSelectedWithNotify.ExecuteIfBound(NewNotifyName, NotifyClass);
}

TSubclassOf<UObject> SLGAActionTrack::GetBlueprintClassFromPath(FString BlueprintPath)
{
	TSubclassOf<UObject> BlueprintClass = NULL;
	if (!BlueprintPath.IsEmpty())
	{
		UBlueprint* BlueprintLibPtr = LoadObject<UBlueprint>(NULL, *BlueprintPath, NULL, 0, NULL);
		BlueprintClass = BlueprintLibPtr->GeneratedClass;
	}
	return BlueprintClass;
}

FReply SLGAActionTrack::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bool bLeftMouseButton =  MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton;
	bool bRightMouseButton =  MouseEvent.GetEffectingButton() == EKeys::RightMouseButton;
	bool bShift = MouseEvent.IsShiftDown();
	bool bCtrl = MouseEvent.IsControlDown();

	if (bRightMouseButton)
	{
		if (bActionEditable)
		{
			SummonContextMenu(MyGeometry, MouseEvent);
		}

		return FReply::Handled().ReleaseMouseCapture();
	}
	else if (bLeftMouseButton)
	{
		FVector2D CursorPos = MouseEvent.GetScreenSpacePosition();
		CursorPos = MyGeometry.AbsoluteToLocal(CursorPos);
		int32 NotifyIndex = GetHitNotifyNode(MyGeometry, CursorPos);
		LastClickedTime = CalculateTime(MyGeometry, MouseEvent.GetScreenSpacePosition());

		if (NotifyIndex == INDEX_NONE)
		{
			// Clicked in empty space, clear selection
			OnDeselectAllNotifies.ExecuteIfBound();
		}
		else
		{
			if (bCtrl)
			{
				ToggleTrackObjectNodeSelectionStatus(NotifyIndex);
			}
			else
			{
				SelectTrackObjectNode(NotifyIndex, bShift);
			}
		}

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

void SLGAActionTrack::SelectTrackObjectNode(int32 TrackNodeIndex, bool Append, bool bUpdateSelection)
{
	if (TrackNodeIndex != INDEX_NONE)
	{
		// Deselect all other notifies if necessary.
		if (Timeline && !Append)
		{
			OnDeselectAllNotifies.ExecuteIfBound();
		}

		// Check to see if we've already selected this node
		if (!SelectedNodeIndices.Contains(TrackNodeIndex))
		{
			// select new one
			if (NotifyNodes.IsValidIndex(TrackNodeIndex))
			{
				TSharedPtr<SLGAActionNode> Node = NotifyNodes[TrackNodeIndex];
				Node->bSelected = true;
				SelectedNodeIndices.Add(TrackNodeIndex);

				if (bUpdateSelection)
				{
					SendSelectionChanged();
				}
			}
		}
	}
}

void SLGAActionTrack::ToggleTrackObjectNodeSelectionStatus(int32 TrackNodeIndex, bool bUpdateSelection)
{
	check(NotifyNodes.IsValidIndex(TrackNodeIndex));

	bool bSelected = SelectedNodeIndices.Contains(TrackNodeIndex);
	if (bSelected)
	{
		SelectedNodeIndices.Remove(TrackNodeIndex);
	}
	else
	{
		SelectedNodeIndices.Add(TrackNodeIndex);
	}

	TSharedPtr<SLGAActionNode> Node = NotifyNodes[TrackNodeIndex];
	Node->bSelected = !Node->bSelected;

	if (bUpdateSelection)
	{
		SendSelectionChanged();
	}
}

void SLGAActionTrack::DeselectTrackObjectNode(int32 TrackNodeIndex, bool bUpdateSelection)
{
	check(NotifyNodes.IsValidIndex(TrackNodeIndex));
	TSharedPtr<SLGAActionNode> Node = NotifyNodes[TrackNodeIndex];
	Node->bSelected = false;

	int32 ItemsRemoved = SelectedNodeIndices.Remove(TrackNodeIndex);
	check(ItemsRemoved > 0);

	if (bUpdateSelection)
	{
		SendSelectionChanged();
	}
}

void SLGAActionTrack::DeselectAllNotifyNodes(bool bUpdateSelectionSet)
{
	for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
	{
		Node->bSelected = false;
	}
	SelectedNodeIndices.Empty();

	if (bUpdateSelectionSet)
	{
		SendSelectionChanged();
	}
}

void SLGAActionTrack::SelectNodesByGuid(const TSet<FGuid>& InGuids, bool bUpdateSelectionSet)
{
	SelectedNodeIndices.Empty();

	for (int32 NodeIndex = 0; NodeIndex < NotifyNodes.Num(); ++NodeIndex)
	{
		TSharedPtr<SLGAActionNode> Node = NotifyNodes[NodeIndex];
		Node->bSelected = InGuids.Contains(Node->NodeObjectInterface->GetGuid());
		if (Node->bSelected)
		{
			SelectedNodeIndices.Add(NodeIndex);
		}
	}

	if (bUpdateSelectionSet)
	{
		SendSelectionChanged();
	}
}

void SLGAActionTrack::SummonContextMenu(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FVector2D CursorPos = MouseEvent.GetScreenSpacePosition();
	int32 NodeIndex = GetHitNotifyNode(MyGeometry, MyGeometry.AbsoluteToLocal(CursorPos));
	LastClickedTime = CalculateTime(MyGeometry, MouseEvent.GetScreenSpacePosition());

	INodeObjectInterface* NodeObject = NodeIndex != INDEX_NONE ? NotifyNodes[NodeIndex]->NodeObjectInterface : nullptr;
	FLGAActionEvent* ActionEvent = NodeObject ? NodeObject->GetNotifyEvent(): nullptr;
	int32 NotifyIndex = ActionEvent ? Actions.IndexOfByKey(ActionEvent) : INDEX_NONE;

	FMenuBuilder MenuBuilder(true, WeakCommandList.Pin());
	MenuBuilder.BeginSection("Action", LOCTEXT("NotifyHeading", "Action"));
	{
		if (NodeObject)
		{
			if (!NotifyNodes[NodeIndex]->bSelected)
			{
				SelectTrackObjectNode(NodeIndex, MouseEvent.IsControlDown());
			}

			if (IsSingleNodeSelected())
			{
				// Add item to directly set notify time
				TSharedRef<SWidget> TimeWidget = 
					SNew(SBox)
					.HAlign(HAlign_Right)
					.ToolTipText(LOCTEXT("SetTimeToolTip", "Set the time of this notify directly"))
					[
						SNew(SBox)
						.Padding(FMargin(4.0f, 0.0f, 0.0f, 0.0f))
						.WidthOverride(100.0f)
						[
							SNew(SNumericEntryBox<float>)
							.Font(FAppStyle::GetFontStyle(TEXT("MenuItem.Font")))
							.MinValue(0.0f)
							.MaxValue(Timeline->SequenceLength)
							.Value(NodeObject->GetTime())
							.AllowSpin(false)
							.OnValueCommitted_Lambda([this, NodeIndex](float InValue, ETextCommit::Type InCommitType)
							{
								if (InCommitType == ETextCommit::OnEnter && NotifyNodes.IsValidIndex(NodeIndex))
								{
									INodeObjectInterface* LocalNodeObject = NotifyNodes[NodeIndex]->NodeObjectInterface;

									float NewTime = FMath::Clamp(InValue, 0.0f, Timeline->SequenceLength - LocalNodeObject->GetDuration());
									LocalNodeObject->SetTime(NewTime);

									if (FLGAActionEvent* Event = LocalNodeObject->GetNotifyEvent())
									{
										Event->RefreshTriggerOffset(Timeline->CalculateOffsetForNotify(Event->GetStartTime()));
										if (Event->GetDuration() > 0.0f)
										{
											Event->RefreshEndTriggerOffset(Timeline->CalculateOffsetForNotify(Event->GetStartTime() + Event->GetDuration()));
										}
									}
									OnUpdatePanel.ExecuteIfBound();

									FSlateApplication::Get().DismissAllMenus();
								}
							})
						]
					];

				MenuBuilder.AddWidget(TimeWidget, LOCTEXT("TimeMenuText", "Action Begin Time"));

				// Add item to directly set notify frame
				TSharedRef<SWidget> FrameWidget = 
					SNew(SBox)
					.HAlign(HAlign_Right)
					.ToolTipText(LOCTEXT("SetFrameToolTip", "Set the frame of this action directly"))
					[
						SNew(SBox)
						.Padding(FMargin(4.0f, 0.0f, 0.0f, 0.0f))
						.WidthOverride(100.0f)
						[
							SNew(SNumericEntryBox<int32>)
							.Font(FAppStyle::GetFontStyle(TEXT("MenuItem.Font")))
							.MinValue(0)
							.MaxValue(Timeline->GetNumberOfFrames())
							.Value(Timeline->GetFrameAtTime(NodeObject->GetTime()))
							.AllowSpin(false)						
							.OnValueCommitted_Lambda([this, NodeIndex](int32 InValue, ETextCommit::Type InCommitType)
							{
								if (InCommitType == ETextCommit::OnEnter && NotifyNodes.IsValidIndex(NodeIndex))
								{
									INodeObjectInterface* LocalNodeObject = NotifyNodes[NodeIndex]->NodeObjectInterface;

									float NewTime = FMath::Clamp(Timeline->GetTimeAtFrame(InValue), 0.0f, Timeline->SequenceLength - LocalNodeObject->GetDuration());
									LocalNodeObject->SetTime(NewTime);

									if (FLGAActionEvent* Event = LocalNodeObject->GetNotifyEvent())
									{
										Event->RefreshTriggerOffset(Timeline->CalculateOffsetForNotify(Event->GetStartTime()));
										if (Event->GetDuration() > 0.0f)
										{
											Event->RefreshEndTriggerOffset(Timeline->CalculateOffsetForNotify(Event->GetStartTime() + Event->GetDuration()));
										}
									}
									OnUpdatePanel.ExecuteIfBound();

									FSlateApplication::Get().DismissAllMenus();
								}
							})
						]
					];

				MenuBuilder.AddWidget(FrameWidget, LOCTEXT("FrameMenuText", "Action Frame"));

				if (ActionEvent)
				{
					// add menu to get threshold weight for triggering this notify
					/*TSharedRef<SWidget> ThresholdWeightWidget =
						SNew(SBox)
						.HAlign(HAlign_Right)
						.ToolTipText(LOCTEXT("MinTriggerWeightToolTip", "The minimum weight to trigger this action"))
						[
							SNew(SBox)
							.Padding(FMargin(4.0f, 0.0f, 0.0f, 0.0f))
							.WidthOverride(100.0f)
							[
								SNew(SNumericEntryBox<float>)
								.Font(FAppStyle::GetFontStyle(TEXT("MenuItem.Font")))
								.MinValue(0.0f)
								.MaxValue(1.0f)
								.Value(ActionEvent->TriggerWeightThreshold)
								.AllowSpin(false)
								.OnValueCommitted_Lambda([this, NotifyIndex](float InValue, ETextCommit::Type InCommitType)
								{
									if (InCommitType == ETextCommit::OnEnter && Actions.IsValidIndex(NotifyIndex))
									{
										float NewWeight = FMath::Max(InValue, ZERO_ANIMWEIGHT_THRESH);
										Actions[NotifyIndex]->TriggerWeightThreshold = NewWeight;

										FSlateApplication::Get().DismissAllMenus();
									}
								})
							]
						];

					MenuBuilder.AddWidget(ThresholdWeightWidget, LOCTEXT("MinTriggerWeight", "Min Trigger Weight"));*/

					// Add menu for changing duration if this is an AnimNotifyState
					if (!ActionEvent->Action->IsSingleFrame())
					{
						float MinimumStateDuration = ActionEvent->GetMinimumStateDuration();

						// add menu to get threshold weight for triggering this notify
						TSharedRef<SWidget> NotifyStateDurationWidget = 
							SNew(SBox)
							.HAlign(HAlign_Right)
							.ToolTipText(LOCTEXT("SetActionDuration_ToolTip", "The duration of this action"))
							[
								SNew(SBox)
								.Padding(FMargin(4.0f, 0.0f, 0.0f, 0.0f))
								.WidthOverride(100.0f)
								[
									SNew(SNumericEntryBox<float>)
									.Font(FAppStyle::GetFontStyle(TEXT("MenuItem.Font")))
									.MinValue(MinimumStateDuration)
									.MinSliderValue(MinimumStateDuration)
									.MaxSliderValue(100.0f)
									.Value(ActionEvent->GetDuration())
									.AllowSpin(false)						
									.OnValueCommitted_Lambda([this, NotifyIndex, MinimumStateDuration](float InValue, ETextCommit::Type InCommitType)
									{
										if (InCommitType == ETextCommit::OnEnter && Actions.IsValidIndex(NotifyIndex))
										{
											float NewDuration = FMath::Max(InValue, MinimumStateDuration);
											float MaxDuration = Timeline->SequenceLength - Actions[NotifyIndex]->GetStartTime();
											NewDuration = FMath::Min(NewDuration, MaxDuration);
											Actions[NotifyIndex]->SetDuration(NewDuration);

											// If we have a delegate bound to refresh the offsets, call it.
											// This is used by the montage editor to keep the offsets up to date.
											OnRequestRefreshOffsets.ExecuteIfBound();

											FSlateApplication::Get().DismissAllMenus();
										}
									})
								]
							];

						MenuBuilder.AddWidget(NotifyStateDurationWidget, LOCTEXT("SetActionDuration", "Action Duration"));
					}
				}
			}
		}
		else
		{
			MenuBuilder.AddSubMenu(
				NSLOCTEXT("NewNotifySubMenu", "NewNotifySubMenuAddNotify", "Add Action..."),
				NSLOCTEXT("NewNotifySubMenu", "NewNotifySubMenuAddNotifyToolTip", "Add ActionEvent"),
				FNewMenuDelegate::CreateRaw(this, &SLGAActionTrack::FillNewNotifyMenu, false));
		}
	}
	MenuBuilder.EndSection();

	FUIAction NewAction;
	NewAction.CanExecuteAction = 0;

	MenuBuilder.BeginSection("AnimEdit", LOCTEXT("NotifyEditHeading", "Edit"));
	{
		if (NodeObject)
		{
			// copy action menu item
			MenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().CopyActions);

			// allow it to delete
			MenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().DeleteAction);

			if (ActionEvent)
			{
				// For the "Replace With..." menu, make sure the current Action selection is valid for replacement
				if (OnGetIsAnimNotifySelectionValidforReplacement.IsBound() && OnGetIsAnimNotifySelectionValidforReplacement.Execute())
				{
					MenuBuilder.AddSubMenu(
						NSLOCTEXT("NewNotifySubMenu", "NewNotifySubMenuReplaceWithNotify", "Replace with Action..."),
						NSLOCTEXT("NewNotifySubMenu", "NewNotifySubMenuReplaceWithNotifyToolTip", "Replace with ActionEvent"),
						FNewMenuDelegate::CreateRaw(this, &SLGAActionTrack::FillNewNotifyMenu, true));
				}
			}
		}
		else
		{
			FString PropertyString;
			const TCHAR* Buffer;
			float OriginalTime;
			float OriginalLength;
			int32 TrackSpan;

			//Check whether can we show menu item to paste anim notify event
			if (ReadNotifyPasteHeader(PropertyString, Buffer, OriginalTime, OriginalLength, TrackSpan))
			{
				// paste notify menu item
				if (IsSingleNodeInClipboard())
				{
					MenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().PasteActions);
				}
				else
				{
					NewAction.ExecuteAction.BindRaw(this, &SLGAActionTrack::OnPasteNotifyClicked, ELGAActionPasteMode::MousePosition, ELGAActionPasteMultipleMode::Relative);

					MenuBuilder.AddMenuEntry(LOCTEXT("PasteMultRel", "Paste Multiple Relative"), LOCTEXT("PasteMultRelToolTip", "Paste multiple actions beginning at the mouse cursor, maintaining the same relative spacing as the source."), FSlateIcon(), NewAction);

					MenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().PasteActions, NAME_None, LOCTEXT("PasteMultAbs", "Paste Multiple Absolute"), LOCTEXT("PasteMultAbsToolTip", "Paste multiple actions beginning at the mouse cursor, maintaining absolute spacing."));
				}

				if (OriginalTime < Timeline->SequenceLength)
				{
					NewAction.ExecuteAction.BindRaw(this, &SLGAActionTrack::OnPasteNotifyClicked, ELGAActionPasteMode::OriginalTime, ELGAActionPasteMultipleMode::Absolute);

					FText DisplayText = FText::Format(LOCTEXT("PasteAtOriginalTime", "Paste at original time ({0})"), FText::AsNumber(OriginalTime));
					MenuBuilder.AddMenuEntry(DisplayText, LOCTEXT("PasteAtOriginalTimeToolTip", "Paste ability action event at the time it was set to when it was copied"), FSlateIcon(), NewAction);
				}
			}
		}
	}
	MenuBuilder.EndSection(); //AnimEdit

	if (ActionEvent)
	{
		MenuBuilder.BeginSection("ViewSource", LOCTEXT("NotifyViewHeading", "View"));

		UClass* ActionClass = ActionEvent->Action->GetClass();
		if (Cast<UBlueprintGeneratedClass>(ActionClass))
		{
			if (UBlueprint* Blueprint = Cast<UBlueprint>(ActionClass->ClassGeneratedBy))
			{
				NewAction.ExecuteAction.BindRaw(this, &SLGAActionTrack::OnOpenNotifySource, Blueprint);
				MenuBuilder.AddMenuEntry(LOCTEXT("OpenActionBlueprint", "Open Action Blueprint"), LOCTEXT("OpenActionBlueprintTooltip", "Opens the source blueprint for this action"), FSlateIcon(), NewAction);
			}
		}

		MenuBuilder.EndSection(); //ViewSource
	}

	FWidgetPath WidgetPath = MouseEvent.GetEventPath() != nullptr ? *MouseEvent.GetEventPath() : FWidgetPath();

	// Display the newly built menu
	FSlateApplication::Get().PushMenu(SharedThis(this), WidgetPath, MenuBuilder.MakeWidget(), CursorPos, FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));
}

bool SLGAActionTrack::CanPasteAnimNotify() const
{
	FString PropertyString;
	const TCHAR* Buffer;
	float OriginalTime;
	float OriginalLength;
	int32 TrackSpan;
	return ReadNotifyPasteHeader(PropertyString, Buffer, OriginalTime, OriginalLength, TrackSpan);
}

void SLGAActionTrack::OnPasteNotifyClicked(ELGAActionPasteMode::Type PasteMode, ELGAActionPasteMultipleMode::Type MultiplePasteType)
{
	float ClickTime = PasteMode == ELGAActionPasteMode::MousePosition ? LastClickedTime : -1.0f;
	OnPasteNodes.ExecuteIfBound(this, ClickTime, PasteMode, MultiplePasteType);
}

void SLGAActionTrack::OnOpenNotifySource(UBlueprint* InSourceBlueprint) const
{
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(InSourceBlueprint);
}

bool SLGAActionTrack::IsSingleNodeSelected()
{
	return SelectedNodeIndices.Num() == 1;
}

bool SLGAActionTrack::IsSingleNodeInClipboard()
{
	FString PropString;
	const TCHAR* Buffer;
	float OriginalTime;
	float OriginalLength;
	int32 TrackSpan;
	uint32 Count = 0;
	if (ReadNotifyPasteHeader(PropString, Buffer, OriginalTime, OriginalLength, TrackSpan))
	{
		// If reading a single line empties the buffer then we only have one notify in there.
		FString TempLine;
		FParse::Line(&Buffer, TempLine);
		return *Buffer == 0;
	}
	return false;
}

void SLGAActionTrack::Update()
{
	NotifyPairs.Empty();
	NotifyNodes.Empty();

	TrackArea->SetContent(SAssignNew(NodeSlots, SOverlay));

	for (int32 ActionIndex = 0; ActionIndex < Actions.Num(); ++ActionIndex)
	{
		TSharedPtr<SLGAActionNode> AnimNotifyNode;
		TSharedPtr<SLGAActionPair> NotifyPair;
		TSharedPtr<SLGATimingNode> TimingNode;
		TSharedPtr<SLGATimingNode> EndTimingNode;

		FLGAActionEvent* Event = Actions[ActionIndex];
		TSharedPtr<FLGATimingRelevantElementBase>* Element = TimingElements.FindByPredicate([Event](TSharedPtr<FLGATimingRelevantElementBase>& ElementToTest)
		{
			if (ElementToTest.IsValid())
			{
				return ElementToTest->GetActionEvent() == Event;
			}
			return false;
		});
		check(Element);

		// Create visibility attribute to control timing node visibility for notifies
		TAttribute<EVisibility> TimingNodeVisibility = TAttribute<EVisibility>::Create(TAttribute<EVisibility>::FGetter::CreateLambda([this]()
		{
			if (OnGetTimingNodeVisibility.IsBound())
			{
				return OnGetTimingNodeVisibility.Execute(ELGATimingElementType::InstantAction);
			}
			return EVisibility(EVisibility::Hidden);
		}));

		SAssignNew(TimingNode, SLGATimingNode)
			.InElement(*Element)
			.bUseTooltip(true)
			.Visibility(TimingNodeVisibility);

		if (Event->Action)
		{
			if (!Event->Action->IsSingleFrame())
			{
				TSharedPtr<FLGATimingRelevantElementBase>* ActionEndElement = TimingElements.FindByPredicate([Event](TSharedPtr<FLGATimingRelevantElementBase>& ElementToTest)
				{
					if (ElementToTest.IsValid())
					{
						return ElementToTest->GetActionEvent() == Event;
					}
					return false;
				});

				if (ActionEndElement)
				{
					// Create an end timing node if we have a state
					SAssignNew(EndTimingNode, SLGATimingNode)
						.InElement(*ActionEndElement)
						.bUseTooltip(true)
						.Visibility(TimingNodeVisibility);
				}
			}
		}

		SAssignNew(AnimNotifyNode, SLGAActionNode)
			.IsEnabled(bActionEditable)
			.Timeline(Timeline)
			.Action(Event)
			.OnNodeDragStarted(this, &SLGAActionTrack::OnNotifyNodeDragStarted, ActionIndex)
			.OnActionHandleBeingDragged(OnActionHandleBeingDragged)
			.OnUpdatePanel(OnUpdatePanel)
			.PanTrackRequest(OnRequestTrackPan)
			.ViewInputMin(ViewInputMin)
			.ViewInputMax(ViewInputMax)
			.OnSnapPosition(OnSnapPosition)
			.OnSelectionChanged(OnSelectionChanged)
			.StateEndTimingNode(EndTimingNode);

		SAssignNew(NotifyPair, SLGAActionPair)
		.LeftContent()
		[
			TimingNode.ToSharedRef()
		]
		.Node(AnimNotifyNode);

		NodeSlots->AddSlot()
		.Padding(TAttribute<FMargin>::Create(TAttribute<FMargin>::FGetter::CreateSP(this, &SLGAActionTrack::GetNotifyTrackPadding, ActionIndex)))
		.VAlign(VAlign_Center)
		[
			NotifyPair->AsShared()
		];

		NotifyNodes.Add(AnimNotifyNode);
		NotifyPairs.Add(NotifyPair);
	}
}

int32 SLGAActionTrack::GetHitNotifyNode(const FGeometry& MyGeometry, const FVector2D& CursorPosition)
{
	for (int32 I = NotifyNodes.Num() - 1; I >= 0; --I) //Run through from 'top most' Notify to bottom
	{
		if (NotifyNodes[I].Get()->HitTest(MyGeometry, CursorPosition))
		{
			return I;
		}
	}

	return INDEX_NONE;
}

FReply SLGAActionTrack::OnNotifyNodeDragStarted(TSharedRef<SLGAActionNode> NotifyNode, const FPointerEvent& MouseEvent, const FVector2D& ScreenNodePosition, const bool bDragOnMarker, int32 NotifyIndex)
{
	// Check to see if we've already selected the triggering node
	if (!NotifyNode->bSelected)
	{
		SelectTrackObjectNode(NotifyIndex, MouseEvent.IsShiftDown());
	}

	// Sort our nodes so we're acessing them in time order
	SelectedNodeIndices.Sort([this](const int32& A, const int32& B)
	{
		float TimeA = NotifyNodes[A]->NodeObjectInterface->GetTime();
		float TimeB = NotifyNodes[B]->NodeObjectInterface->GetTime();
		return TimeA < TimeB;
	});

	// If we're dragging one of the direction markers we don't need to call any further as we don't want the drag drop op
	if (!bDragOnMarker)
	{
		TArray<TSharedPtr<SLGAActionNode>> NodesToDrag;
		TSharedRef<SOverlay> DragBox = SNew(SOverlay);
		for (int32 NodeIndex : SelectedNodeIndices)
		{
			NodesToDrag.Add(NotifyNodes[NodeIndex]);
		}

		FVector2D DecoratorPosition = NodesToDrag[0]->GetWidgetPosition();
		DecoratorPosition = CachedGeometry.LocalToAbsolute(DecoratorPosition);
		return OnNodeDragStarted.Execute(NodesToDrag, DragBox, MouseEvent.GetScreenSpacePosition(), DecoratorPosition, bDragOnMarker);
	}
	else
	{
		// Capture the mouse in the node
		return FReply::Handled().CaptureMouse(NotifyNode).UseHighPrecisionMouseMovement(NotifyNode);
	}
}

FReply SLGAActionTrack::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FVector2D CursorPos = MouseEvent.GetScreenSpacePosition();
	CursorPos = MyGeometry.AbsoluteToLocal(CursorPos);
	int32 HitIndex = GetHitNotifyNode(MyGeometry, CursorPos);

	if (HitIndex != INDEX_NONE)
	{
		if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
		{
			// Hit a node, record the mouse position for use later so we can know when / where a
			// drag happened on the node handles if necessary.
			NotifyNodes[HitIndex]->SetLastMouseDownPosition(CursorPos);

			return FReply::Handled().DetectDrag(NotifyNodes[HitIndex].ToSharedRef(), EKeys::LeftMouseButton);
		}
		else if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
		{
			// Hit a node, return handled so we can pop a context menu on mouse up
			return FReply::Handled();
		}
	}

	return FReply::Unhandled();
}

float SLGAActionTrack::CalculateTime(const FGeometry& MyGeometry, FVector2D NodePos, bool bInputIsAbsolute)
{
	if (bInputIsAbsolute)
	{
		NodePos = MyGeometry.AbsoluteToLocal(NodePos);
	}
	FTrackScaleInfo ScaleInfo(ViewInputMin.Get(), ViewInputMax.Get(), 0, 0, MyGeometry.Size);
	return FMath::Clamp<float>(ScaleInfo.LocalXToInput(NodePos.X), 0.f, Timeline->SequenceLength);
}

FReply SLGAActionTrack::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	return FReply::Unhandled();
}

void SLGAActionTrack::HandleNodeDrop(TSharedPtr<SLGAActionNode> Node, float Offset)
{
	ensure(Node.IsValid());

	float LocalX = GetCachedGeometry().AbsoluteToLocal(Node->GetScreenPosition() + Offset).X;
	float SnapTime = Node->GetLastSnappedTime();
	float Time = SnapTime != -1.0f ? SnapTime : GetCachedScaleInfo().LocalXToInput(LocalX);
	Node->NodeObjectInterface->HandleDrop(Timeline, Time, TrackIndex);
}

void SLGAActionTrack::DisconnectSelectedNodesForDrag(TArray<TSharedPtr<SLGAActionNode>>& DragNodes)
{
	if (SelectedNodeIndices.Num() == 0)
	{
		return;
	}

	for (int32 NodeIndex : SelectedNodeIndices)
	{
		TSharedPtr<SLGAActionNode> Node = NotifyNodes[NodeIndex];
		if (Node->NodeObjectInterface->GetNotifyEvent())
		{
			TSharedPtr<SLGAActionPair> Pair = NotifyPairs[NodeIndex];
			NodeSlots->RemoveSlot(Pair->AsShared());
		}
		else
		{
			NodeSlots->RemoveSlot(Node->AsShared());
		}

		DragNodes.Add(Node);
	}
}

void SLGAActionTrack::AppendSelectionToSet(FGraphPanelSelectionSet& SelectionSet)
{
	// Add our selection to the provided set
	for (int32 Index : SelectedNodeIndices)
	{
		if (FLGAActionEvent* Event = NotifyNodes[Index]->NodeObjectInterface->GetNotifyEvent())
		{
			if (Event->Action)
			{
				SelectionSet.Add(Event->Action);
			}
		}
	}
}

void SLGAActionTrack::AppendSelectionToArray(TArray<INodeObjectInterface*>& Selection) const
{
	for (int32 Idx : SelectedNodeIndices)
	{
		Selection.Add(NotifyNodes[Idx]->NodeObjectInterface);
	}
}

void SLGAActionTrack::PasteSingleNotify(FString& NotifyString, float PasteTime)
{
	FArrayProperty* ArrayProperty;
	int32 NewIdx = Timeline->Actions.Add(FLGAActionEvent());
	uint8* PropertyData = Timeline->FindNotifyPropertyData(NewIdx, ArrayProperty);

	if (PropertyData && ArrayProperty)
	{
		ArrayProperty->Inner->ImportText_Direct(*NotifyString, PropertyData, NULL, PPF_Copy);

		FLGAActionEvent& NewAction = Timeline->Actions[NewIdx];

		// We have to link to the montage / sequence again, we need a correct time set and we could be pasting to a new montage / sequence
		//int32 NewSlotIndex = 0;
		float NewNotifyTime = PasteTime != 1.0f ? PasteTime : NewAction.GetStartTime();
		NewNotifyTime = FMath::Clamp(NewNotifyTime, 0.0f, Timeline->SequenceLength);

		//if (UAnimMontage* Montage = Cast<UAnimMontage>(Timeline))
		//{
		//	// We have a montage, validate slots
		//	int32 OldSlotIndex = NewAction.GetSlotIndex();
		//	if (Montage->SlotAnimTracks.IsValidIndex(OldSlotIndex))
		//	{
		//		// Link to the same slot index
		//		NewSlotIndex = OldSlotIndex;
		//	}
		//}
		NewAction.SetStartTime(PasteTime);

		NewAction.TriggerTimeOffset = GetTriggerTimeOffsetForType(Timeline->CalculateOffsetForNotify(NewAction.GetStartTime()));
		NewAction.TrackIndex = TrackIndex;

		if (NewAction.Action)
		{
			ULGAAction* NewActionObject = Cast<ULGAAction>(StaticDuplicateObject(NewAction.Action, Timeline));
			check(NewActionObject);
			NewAction.Action = NewActionObject;
			//NewAction.SetDuration(FMath::Clamp(NewAction.GetDuration(), 1 / 30.0f, Timeline->SequenceLength - NewAction.GetStartTime()));
			NewAction.EndTriggerTimeOffset = GetTriggerTimeOffsetForType(Timeline->CalculateOffsetForNotify(NewAction.GetStartTime() + NewAction.GetDuration()));
		}

		NewAction.Guid = FGuid::NewGuid();
	}
	else
	{
		// Paste failed, remove the notify
		Timeline->Actions.RemoveAt(NewIdx);
	}

	OnDeselectAllNotifies.ExecuteIfBound();
	Timeline->PostEditChange();
	Timeline->MarkPackageDirty();
	OnUpdatePanel.ExecuteIfBound();
}

void SLGAActionTrack::AppendSelectedNodeWidgetsToArray(TArray<TSharedPtr<SLGAActionNode>>& NodeArray) const
{
	for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
	{
		if (Node->bSelected)
		{
			NodeArray.Add(Node);
		}
	}
}

void SLGAActionTrack::RefreshMarqueeSelectedNodes(FSlateRect& Rect, FLGAActionMarqueeOperation& Marquee)
{
	if (Marquee.Operation != FLGAActionMarqueeOperation::Replace)
	{
		// Maintain the original selection from before the operation
		for (int32 Idx = 0; Idx < NotifyNodes.Num(); ++Idx)
		{
			TSharedPtr<SLGAActionNode> Notify = NotifyNodes[Idx];
			bool bWasSelected = Marquee.OriginalSelection.Contains(Notify);
			if (bWasSelected)
			{
				SelectTrackObjectNode(Idx, true, false);
			}
			else if (SelectedNodeIndices.Contains(Idx))
			{
				DeselectTrackObjectNode(Idx, false);
			}
		}
	}

	for (int32 Index = 0; Index < NotifyNodes.Num(); ++Index)
	{
		TSharedPtr<SLGAActionNode> Node = NotifyNodes[Index];
		FSlateRect NodeRect = FSlateRect(Node->GetWidgetPosition(), Node->GetWidgetPosition() + Node->GetSize());

		if (FSlateRect::DoRectanglesIntersect(Rect, NodeRect))
		{
			// Either select or deselect the intersecting node, depending on the type of selection operation
			if (Marquee.Operation == FLGAActionMarqueeOperation::Remove)
			{
				if (SelectedNodeIndices.Contains(Index))
				{
					DeselectTrackObjectNode(Index, false);
				}
			}
			else
			{
				SelectTrackObjectNode(Index, true, false);
			}
		}
	}
}

FString SLGAActionTrack::MakeBlueprintNotifyName(const FString& InNotifyClassName)
{
	FString DefaultNotifyName = InNotifyClassName;
	DefaultNotifyName = DefaultNotifyName.Replace(TEXT("Action_"), TEXT(""), ESearchCase::CaseSensitive);

	return DefaultNotifyName;
}

void SLGAActionTrack::ClearNodeTooltips()
{
	FText EmptyTooltip;

	for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
	{
		Node->SetToolTipText(EmptyTooltip);
	}
}

const EVisibility SLGAActionTrack::GetTimingNodeVisibility(TSharedPtr<SLGAActionNode> NotifyNode)
{
	if (OnGetTimingNodeVisibility.IsBound())
	{
		if (FLGAActionEvent* Event = NotifyNode->NodeObjectInterface->GetNotifyEvent())
		{
			return OnGetTimingNodeVisibility.Execute(ELGATimingElementType::InstantAction);
		}
	}

	// No visibility defined, not visible
	return EVisibility::Hidden;
}

void SLGAActionTrack::UpdateCachedGeometry(const FGeometry& InGeometry)
{
	CachedGeometry = InGeometry;

	for (TSharedPtr<SLGAActionNode> Node : NotifyNodes)
	{
		Node->CachedTrackGeometry = InGeometry;
	}
}

//////////////////////////////////////////////////////////////////////////
// SSequenceEdTrack

void SLGAActionEdTrack::Construct(const FArguments& InArgs)
{
	Timeline = InArgs._Timeline;
	TrackIndex = InArgs._TrackIndex;
	FLGAActionTrack& Track = Timeline->AbilityActionTracks[TrackIndex];
	// @Todo anim: we need to fix this to allow track color to be customizable. 
	// for now name, and track color are given
	Track.TrackColor = ((TrackIndex & 1) != 0) ? FLinearColor(0.9f, 0.9f, 0.9f, 0.9f) : FLinearColor(0.5f, 0.5f, 0.5f);

	TSharedRef<SLGAActionPanel> PanelRef = InArgs._AnimNotifyPanel.ToSharedRef();
	AnimPanelPtr = InArgs._AnimNotifyPanel;
	TimingElements = InArgs._TimingElements;

	//////////////////////////////
	this->ChildSlot
	[
		SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		.FillWidth(1)
		[
			// Notification editor panel
			SAssignNew(NotifyTrack, SLGAActionTrack)
			.Timeline(Timeline)
			.TrackIndex(TrackIndex)
			.Actions(Track.Actions)
			.TimingElements(TimingElements)
			.ViewInputMin(InArgs._ViewInputMin)
			.ViewInputMax(InArgs._ViewInputMax)
			.OnSelectionChanged(InArgs._OnSelectionChanged)
			.OnUpdatePanel(InArgs._OnUpdatePanel)
			.OnGetScrubValue(InArgs._OnGetScrubValue)
			.OnGetDraggedNodePos(InArgs._OnGetDraggedNodePos)
			.OnNodeDragStarted(InArgs._OnNodeDragStarted)
			.OnActionHandleBeingDragged(InArgs._OnActionHandleBeingDragged)
			.OnSnapPosition(InArgs._OnSnapPosition)
			.TrackColor(Track.TrackColor)
			.OnRequestTrackPan(FPanTrackRequest::CreateSP(PanelRef, &SLGAActionPanel::PanInputViewRange))
			.OnRequestOffsetRefresh(InArgs._OnRequestRefreshOffsets)
			.OnDeleteNotify(InArgs._OnDeleteNotify)
			.OnGetIsAnimNotifySelectionValidForReplacement(PanelRef, &SLGAActionPanel::IsNotifySelectionValidForReplacement)
			.OnReplaceSelectedWithNotify(PanelRef, &SLGAActionPanel::OnReplaceSelectedWithNotify)
			.OnReplaceSelectedWithBlueprintNotify(PanelRef, &SLGAActionPanel::OnReplaceSelectedWithNotifyBlueprint)
			.OnDeselectAllNotifies(InArgs._OnDeselectAllNotifies)
			.OnCopyNodes(InArgs._OnCopyNodes)
			.OnPasteNodes(InArgs._OnPasteNodes)
			.OnSetInputViewRange(InArgs._OnSetInputViewRange)
			.OnGetTimingNodeVisibility(InArgs._OnGetTimingNodeVisibility)
			.CommandList(PanelRef->GetCommandList())
			.ActionEditable(PanelRef->GetActionEditable())
		]
	];
}

bool SLGAActionEdTrack::CanDeleteTrack()
{
	return AnimPanelPtr.Pin()->CanDeleteTrack(TrackIndex);
}

//////////////////////////////////////////////////////////////////////////
// SAnimNotifyPanel

void SLGAActionPanel::Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModelBase>& InModel)
{
	SLGATimelineTrackPanel::Construct(SLGATimelineTrackPanel::FArguments()
		.WidgetWidth(InArgs._WidgetWidth)
		.ViewInputMin(InArgs._ViewInputMin)
		.ViewInputMax(InArgs._ViewInputMax)
		.InputMin(InArgs._InputMin)
		.InputMax(InArgs._InputMax)
		.OnSetInputViewRange(InArgs._OnSetInputViewRange));

	Model = InModel;
	WeakCommandList = InModel->GetCommandList();
	OnNotifiesChanged = InArgs._OnNotifiesChanged;
	OnSnapPosition = InArgs._OnSnapPosition;
	OnActionHandleBeingDragged = InArgs._OnActionHandleBeingDragged;
	OnActionNodesBeingDragged = InArgs._OnActionNodesBeingDragged;
	bIsSelecting = false;
	bIsUpdating = false;

	bActionEditable = false;

	InModel->OnHandleObjectsSelected().AddSP(this, &SLGAActionPanel::HandleObjectsSelected);

	BindCommands();

	TracksChangedDelegateHandle = InModel->OnTracksChanged().Add(FSimpleDelegate::CreateSP(this, &SLGAActionPanel::RefreshNotifyTracks));

	if (GEditor)
	{
		GEditor->RegisterForUndo(this);
	}

	CurrentPosition = InArgs._CurrentPosition;
	OnSelectionChanged = InArgs._OnSelectionChanged;
	WidgetWidth = InArgs._WidgetWidth;
	OnGetScrubValue = InArgs._OnGetScrubValue;
	OnRequestRefreshOffsets = InArgs._OnRequestRefreshOffsets;
	OnGetTimingNodeVisibility = InArgs._OnGetTimingNodeVisibility;

	this->ChildSlot
	[
		SAssignNew(PanelArea, SBorder)
		.Visibility(EVisibility::SelfHitTestInvisible)
		.AddMetaData<FTagMetaData>(TEXT("AnimNotify.Notify"))
		.BorderImage(FAppStyle::GetBrush("NoBorder"))
		.Padding(0.0f)
		.ColorAndOpacity(FLinearColor::White)
	];

	OnPropertyChangedHandleDelegateHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddSP(this, &SLGAActionPanel::OnPropertyChanged);

	Update();
}

SLGAActionPanel::~SLGAActionPanel()
{
	FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(OnPropertyChangedHandleDelegateHandle);

	if (GEditor)
	{
		GEditor->UnregisterForUndo(this);
	}

	if (Model.IsValid())
	{
		Model.Pin()->OnTracksChanged().Remove(TracksChangedDelegateHandle);
	}
}

FName SLGAActionPanel::GetNewTrackName() const
{
	TArray<FName> TrackNames;
	TrackNames.Reserve(50);

	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	for (const FLGAActionTrack& Track : Timeline->AbilityActionTracks)
	{
		TrackNames.Add(Track.TrackName);
	}

	FName NameToTest;
	int32 TrackIndex = 1;
	
	do 
	{
		NameToTest = *FString::FromInt(TrackIndex++);
	} while (TrackNames.Contains(NameToTest));

	return NameToTest;
}

FReply SLGAActionPanel::InsertTrack(int32 TrackIndexToInsert)
{
	// before insert, make sure everything behind is fixed
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	for (int32 I = TrackIndexToInsert; I < Timeline->AbilityActionTracks.Num(); ++I)
	{
		FLGAActionTrack& Track = Timeline->AbilityActionTracks[I];

		const int32 NewTrackIndex = I + 1;

		for (FLGAActionEvent* Action : Track.Actions)
		{
			// fix notifies indices
			Action->TrackIndex = NewTrackIndex;
		}
	}

	FLGAActionTrack NewItem;
	NewItem.TrackName = GetNewTrackName();
	NewItem.TrackColor = FLinearColor::White;

	Timeline->AbilityActionTracks.Insert(NewItem, TrackIndexToInsert);
	Timeline->PostEditChange();
	Timeline->MarkPackageDirty();

	Update();

	return FReply::Handled();
}

FReply SLGAActionPanel::AddTrack()
{
	FLGAActionTrack NewItem;
	NewItem.TrackName = GetNewTrackName();
	NewItem.TrackColor = FLinearColor::White;

	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	Timeline->AbilityActionTracks.Add(NewItem);
	Timeline->MarkPackageDirty();

	Update();

	return FReply::Handled();
}

FReply SLGAActionPanel::DeleteTrack(int32 TrackIndexToDelete)
{
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	if (Timeline->AbilityActionTracks.IsValidIndex(TrackIndexToDelete))
	{
		if (Timeline->AbilityActionTracks[TrackIndexToDelete].Actions.Num() == 0)
		{
			// before insert, make sure everything behind is fixed
			for (int32 I = TrackIndexToDelete + 1; I < Timeline->AbilityActionTracks.Num(); ++I)
			{
				FLGAActionTrack& Track = Timeline->AbilityActionTracks[I];
				const int32 NewTrackIndex = I - 1;

				for (FLGAActionEvent* Action : Track.Actions)
				{
					// fix notifies indices
					Action->TrackIndex = NewTrackIndex;
				}
			}

			Timeline->AbilityActionTracks.RemoveAt(TrackIndexToDelete);
			Timeline->PostEditChange();
			Timeline->MarkPackageDirty();
			Update();
		}
	}
	return FReply::Handled();
}

bool SLGAActionPanel::CanDeleteTrack(int32 TrackIndexToDelete)
{
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	if (Timeline->AbilityActionTracks.Num() > 1 && Timeline->AbilityActionTracks.IsValidIndex(TrackIndexToDelete))
	{
		return Timeline->AbilityActionTracks[TrackIndexToDelete].Actions.Num() == 0;
	}

	return false;
}

void SLGAActionPanel::Update()
{
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	if (!bIsUpdating)
	{
		TGuardValue<bool> ScopeGuard(bIsUpdating, true);

		if (Timeline)
		{
			bActionEditable = (Model.Pin()->GetAbilityEditor().Pin()->IsCurrentTimelineLocal());

			Timeline->RefreshCacheData();
			OnNotifiesChanged.ExecuteIfBound();
		}

		UpdateEditable();
	}	
}

void SLGAActionPanel::UpdateEditable()
{
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	if (Timeline)
	{
		// update action editable
		ULegoAbilityBlueprint* AbilityBlueprint = Model.Pin()->GetAbilityEditor().Pin()->GetAbilityBlueprint();
		for (int32 TrackIdx = 0; TrackIdx < NotifyAnimTracks.Num(); ++TrackIdx)
		{
			TSharedPtr<SLGAActionTrack> Track = NotifyAnimTracks[TrackIdx];

			for (int32 NodeIndex = 0; NodeIndex < Track->GetNumNotifyNodes(); ++NodeIndex)
			{
				INodeObjectInterface* NodeObjectInterface = Track->GetNodeObjectInterface(NodeIndex);
				if (bActionEditable)
				{
					NodeObjectInterface->SetEditable(true);
				}
				else
				{
					ULGAAction* OverrideAction = AbilityBlueprint->GetOverrideAction(Timeline, NodeObjectInterface->GetGuid());
					NodeObjectInterface->SetEditable(OverrideAction != nullptr);
				}
			}
		}
	}	
}

// Helper to save/restore selection state when widgets are recreated
struct FScopedSavedNotifySelection
{
	FScopedSavedNotifySelection(SLGAActionPanel& InPanel)
		: Panel(InPanel)
	{
		for (TSharedPtr<SLGAActionTrack> Track : InPanel.NotifyAnimTracks)
		{
			for (int32 NodeIndex = 0; NodeIndex < Track->GetNumNotifyNodes(); ++NodeIndex)
			{
				if (Track->IsNodeSelected(NodeIndex))
				{
					SelectedNodeGuids.Add(Track->GetNodeObjectInterface(NodeIndex)->GetGuid());	
				}
			}
		}
	}

	~FScopedSavedNotifySelection()
	{
		// Re-apply selection state
		for (TSharedPtr<SLGAActionTrack> Track : Panel.NotifyAnimTracks)
		{
			Track->SelectNodesByGuid(SelectedNodeGuids, false);
		}
	}

	SLGAActionPanel& Panel;
	TSet<FGuid> SelectedNodeGuids;
};

void SLGAActionPanel::RefreshNotifyTracks()
{
	{
		FScopedSavedNotifySelection ScopedSelection(*this);

		TSharedPtr<SVerticalBox> ActionSlots;
		PanelArea->SetContent(SAssignNew(ActionSlots, SVerticalBox));

		// Clear node tool tips to stop slate referencing them and possibly
		// causing a crash if the notify has gone away
		for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
		{
			Track->ClearNodeTooltips();
		}
		NotifyAnimTracks.Empty();

		TArray<TSharedPtr<FLGATimingRelevantElementBase>> TimingElements;
		ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
		SLGATimelineTimingPanel::GetTimingRelevantElements(Timeline, TimingElements);

		for (int32 TrackIndex = 0; TrackIndex < Timeline->AbilityActionTracks.Num(); TrackIndex++)
		{
			TSharedPtr<SLGAActionEdTrack> EdTrack;

			ActionSlots->AddSlot()
			.AutoHeight()
			.VAlign(VAlign_Center)
			[
				SAssignNew(EdTrack, SLGAActionEdTrack)
				.TrackIndex(TrackIndex)
				.Timeline(Timeline)
				.TimingElements(TimingElements)
				.AnimNotifyPanel(SharedThis(this))
				.WidgetWidth(WidgetWidth)
				.ViewInputMin(ViewInputMin)
				.ViewInputMax(ViewInputMax)
				.OnGetScrubValue(OnGetScrubValue)
				.OnGetDraggedNodePos(this, &SLGAActionPanel::CalculateDraggedNodePos)
				.OnUpdatePanel(this, &SLGAActionPanel::Update)
				.OnSelectionChanged(this, &SLGAActionPanel::OnTrackSelectionChanged)
				.OnNodeDragStarted(this, &SLGAActionPanel::OnNotifyNodeDragStarted)
				.OnActionHandleBeingDragged(OnActionHandleBeingDragged)
				.OnSnapPosition(OnSnapPosition)
				.OnRequestRefreshOffsets(OnRequestRefreshOffsets)
				.OnDeleteNotify(this, &SLGAActionPanel::DeleteSelectedNodeObjects)
				.OnDeselectAllNotifies(this, &SLGAActionPanel::DeselectAllNotifies)
				.OnCopyNodes(this, &SLGAActionPanel::CopySelectedNodesToClipboard)
				.OnPasteNodes(this, &SLGAActionPanel::OnPasteNodes)
				.OnSetInputViewRange(this, &SLGAActionPanel::InputViewRangeChanged)
				.OnGetTimingNodeVisibility(OnGetTimingNodeVisibility)
			];

			NotifyAnimTracks.Add(EdTrack->NotifyTrack);
		}
	}

	UpdateEditable();

	// Signal selection change to refresh details panel
	OnTrackSelectionChanged();
}

float SLGAActionPanel::CalculateDraggedNodePos() const
{
	return CurrentDragXPosition;
}

FReply SLGAActionPanel::OnNotifyNodeDragStarted(TArray<TSharedPtr<SLGAActionNode>> NotifyNodes, TSharedRef<SWidget> Decorator, const FVector2D& ScreenCursorPos, const FVector2D& ScreenNodePosition, const bool bDragOnMarker)
{
	TSharedRef<SOverlay> NodeDragDecoratorOverlay = SNew(SOverlay);
	TSharedRef<SBorder> NodeDragDecorator = SNew(SBorder)
	.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
	[
		NodeDragDecoratorOverlay
	];

	TArray<TSharedPtr<SLGAActionNode>> Nodes;

	for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
	{
		Track->DisconnectSelectedNodesForDrag(Nodes);
	}

	FBox2D OverlayBounds(Nodes[0]->GetScreenPosition(), Nodes[0]->GetScreenPosition() + FVector2D(Nodes[0]->GetDurationSize(), 0.0f));
	for (int32 Idx = 1; Idx < Nodes.Num(); ++Idx)
	{
		TSharedPtr<SLGAActionNode> Node = Nodes[Idx];
		FVector2D NodePosition = Node->GetScreenPosition();
		float NodeDuration = Node->GetDurationSize();

		OverlayBounds += FBox2D(NodePosition, NodePosition + FVector2D(NodeDuration, 0.0f));
	}

	FVector2D OverlayOrigin = OverlayBounds.Min;
	FVector2D OverlayExtents = OverlayBounds.GetSize();

	for (TSharedPtr<SLGAActionNode> Node : Nodes)
	{
		FVector2D OffsetFromFirst(Node->GetScreenPosition() - OverlayOrigin);

		NodeDragDecoratorOverlay->AddSlot()
		.Padding(FMargin(OffsetFromFirst.X, OffsetFromFirst.Y, 0.0f, 0.0f))
		[
			Node->AsShared()
		];
	}

	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	FPanTrackRequest PanRequestDelegate = FPanTrackRequest::CreateSP(this, &SLGAActionPanel::PanInputViewRange);
	FOnUpdatePanel UpdateDelegate = FOnUpdatePanel::CreateSP(this, &SLGAActionPanel::Update);
	return FReply::Handled().BeginDragDrop(FLGAActionDragDropOp::New(Nodes, NodeDragDecorator, NotifyAnimTracks, Timeline, ScreenCursorPos, OverlayOrigin, OverlayExtents, CurrentDragXPosition, PanRequestDelegate, OnSnapPosition, UpdateDelegate, OnActionNodesBeingDragged));
}

void SLGAActionPanel::PostUndo(bool bSuccess)
{
	Update();
}

void SLGAActionPanel::PostRedo(bool bSuccess)
{
	Update();
}

void SLGAActionPanel::OnDeletePressed()
{
	// If there's no focus on the panel it's likely the user is not editing notifies
	// so don't delete anything when the key is pressed.
	if (HasKeyboardFocus() || HasFocusedDescendants()) 
	{
		DeleteSelectedNodeObjects();
	}
}

void SLGAActionPanel::DeleteSelectedNodeObjects()
{
	TArray<INodeObjectInterface*> SelectedNodes;
	for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
	{
		Track->AppendSelectionToArray(SelectedNodes);
	}

	int32 NumNodes = SelectedNodes.Num();
	if (NumNodes > 0)
	{
		FScopedTransaction Transaction(NumNodes > 1 ? LOCTEXT("DeleteActions", "Delete Actions") : LOCTEXT("DeleteAction", "Delete Action"));
		ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
		Timeline->Modify();

		// As we address node object's source data by pointer, we need to mark for delete then
		// delete invalid entries to avoid concurrent modification of containers
		for (INodeObjectInterface* NodeObject : SelectedNodes)
		{
			NodeObject->MarkForDelete(Timeline);
		}

		FNotifyNodeInterface::RemoveInvalidNotifies(Timeline);
	}

	// clear selection and update the panel
	TArray<UObject*> Objects;
	OnSelectionChanged.ExecuteIfBound(Objects);

	Update();
}

void SLGAActionPanel::OnTrackSelectionChanged()
{
	if (!bIsSelecting)
	{
		TGuardValue<bool> GuardValue(bIsSelecting, true);

		// Need to collect selection info from all tracks
		TArray<UObject*> ActionObjects;
		ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
		for (int32 TrackIdx = 0; TrackIdx < NotifyAnimTracks.Num(); ++TrackIdx)
		{
			TSharedPtr<SLGAActionTrack> Track = NotifyAnimTracks[TrackIdx];
			const TArray<int32>& ActionIndices = Track->GetSelectedNotifyIndices();
			for (int32 ActionIdx : ActionIndices)
			{
				INodeObjectInterface* NodeObjectInterface = Track->GetNodeObjectInterface(ActionIdx);
				if (FLGAActionEvent* ActionEvent = NodeObjectInterface->GetNotifyEvent())
				{
					ActionObjects.AddUnique(ActionEvent->Action);
				}
			}
		}

		OnSelectionChanged.ExecuteIfBound(ActionObjects);
	}
}

void SLGAActionPanel::DeselectAllNotifies()
{
	if (!bIsSelecting)
	{
		TGuardValue<bool> GuardValue(bIsSelecting, true);

		for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
		{
			Track->DeselectAllNotifyNodes(false);
		}

		TArray<UObject*> NotifyObjects;
		OnSelectionChanged.ExecuteIfBound(NotifyObjects);
	}
}

void SLGAActionPanel::CopySelectedNodesToClipboard() const
{
	// Grab the selected events
	TArray<INodeObjectInterface*> SelectedNodes;
	for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
	{
		Track->AppendSelectionToArray(SelectedNodes);
	}

	const FString HeaderString(TEXT("COPY_ABILITYACTIONEVENT"));
	
	if (SelectedNodes.Num() > 0)
	{
		FString StrValue(HeaderString);

		// Sort by track
		SelectedNodes.Sort([](const INodeObjectInterface& A, const INodeObjectInterface& B)
		{
			return (A.GetTrackIndex() < B.GetTrackIndex()) || (A.GetTrackIndex() == B.GetTrackIndex() && A.GetTime() < B.GetTime());
		});

		// Need to find how many tracks this selection spans and the minimum time to use as the beginning of the selection
		int32 MinTrack = MAX_int32;
		int32 MaxTrack = MIN_int32;
		float MinTime = MAX_flt;
		for (const INodeObjectInterface* NodeObject : SelectedNodes)
		{
			MinTrack = FMath::Min(MinTrack, NodeObject->GetTrackIndex());
			MaxTrack = FMath::Max(MaxTrack, NodeObject->GetTrackIndex());
			MinTime = FMath::Min(MinTime, NodeObject->GetTime());
		}

		int32 TrackSpan = MaxTrack - MinTrack + 1;
		ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
		StrValue += FString::Printf(TEXT("OriginalTime=%f,"), MinTime);
		StrValue += FString::Printf(TEXT("OriginalLength=%f,"), Timeline->SequenceLength);
		StrValue += FString::Printf(TEXT("TrackSpan=%d"), TrackSpan);

		for (const INodeObjectInterface* NodeObject : SelectedNodes)
		{
			// Locate the notify in the sequence, we need the sequence index; but also need to
			// keep the order we're currently in.

			StrValue += "\n";
			StrValue += FString::Printf(TEXT("AbsTime=%f,NodeObjectType=%i,"), NodeObject->GetTime(), (int32)NodeObject->GetType());

			NodeObject->ExportForCopy(Timeline, StrValue);
		}
		FPlatformApplicationMisc::ClipboardCopy(*StrValue);
	}
}

bool SLGAActionPanel::IsNotifySelectionValidForReplacement()
{
	// Grab the selected events
	TArray<INodeObjectInterface*> SelectedNodes;
	for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
	{
		Track->AppendSelectionToArray(SelectedNodes);
	}

	bool bSelectionContainsAnimNotify = false;
	bool bSelectionContainsAnimNotifyState = false;
	for (INodeObjectInterface* NodeObject : SelectedNodes)
	{
		FLGAActionEvent* ActionEvent = NodeObject->GetNotifyEvent();
		if (ActionEvent)
		{
			if (ActionEvent->Action)
			{
				bSelectionContainsAnimNotify = true;
			}
			else if (ActionEvent->Duration > 0)
			{
				bSelectionContainsAnimNotifyState = true;
			}
			// Custom AnimNotifies have no class, but they are like AnimNotify class notifies in that they have no duration
			else
			{
				bSelectionContainsAnimNotify = true;
			}
		}
	}

	// Only allow replacement for selections that contain _only_ AnimNotifies, or _only_ AnimNotifyStates, but not both
	// (Want to disallow replacement of AnimNotify with AnimNotifyState, and vice-versa)
	bool bIsValidSelection = bSelectionContainsAnimNotify != bSelectionContainsAnimNotifyState;

	return bIsValidSelection;
}


void SLGAActionPanel::OnReplaceSelectedWithNotify(FString NewNotifyName, UClass* NewNotifyClass)
{
	TArray<INodeObjectInterface*> SelectedNodes;
	for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
	{
		Track->AppendSelectionToArray(SelectedNodes);
	}

	TArray<FLGAActionEvent> SelectedActions;
	for (INodeObjectInterface* NodeObject : SelectedNodes)
	{
		FLGAActionEvent* Event = NodeObject->GetNotifyEvent();
		if (Event)
		{
			SelectedActions.Add(*Event);
		}
	}

	const FScopedTransaction Transaction(LOCTEXT("ReplaceAction", "Replace Action"));
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	Timeline->Modify();

	for (FLGAActionEvent& SelectAction : SelectedActions)
	{
		FLGAActionEvent* OldEvent = &SelectAction;
		if (OldEvent)
		{
			float BeginTime = OldEvent->GetStartTime();
			float Length = OldEvent->GetDuration();
			int32 TargetTrackIndex = OldEvent->TrackIndex;
			float TriggerTimeOffset = OldEvent->TriggerTimeOffset;
			float EndTriggerTimeOffset = OldEvent->EndTriggerTimeOffset;
			//int32 SlotIndex = OldEvent->GetSlotIndex();
			//int32 EndSlotIndex = OldEvent->EndLink.GetSlotIndex();
			//int32 SegmentIndex = OldEvent->GetSegmentIndex();
			//int32 EndSegmentIndex = OldEvent->GetSegmentIndex();
			//EAnimLinkMethod::Type LinkMethod = OldEvent->GetLinkMethod();
			//EAnimLinkMethod::Type EndLinkMethod = OldEvent->EndLink.GetLinkMethod();

			ULGAAction* OldEventPayload = OldEvent->Action;


			for (int32 I = 0; I < Timeline->Actions.Num(); ++I)
			{
				if (OldEvent->Action == Timeline->Actions[I].Action)
				{
					Timeline->Actions.RemoveAt(I);
					Timeline->PostEditChange();
					Timeline->MarkPackageDirty();
					break;
				}
			}

			FLGAActionEvent& NewEvent = NotifyAnimTracks[TargetTrackIndex]->CreateNewAction(NewNotifyName, NewNotifyClass, BeginTime, false);

			NewEvent.TriggerTimeOffset = TriggerTimeOffset;
			//NewEvent.ChangeSlotIndex(SlotIndex);
			//NewEvent.SetSegmentIndex(SegmentIndex);
			//NewEvent.ChangeLinkMethod(LinkMethod);

			// Copy what we can across from the payload
			if ((OldEventPayload != nullptr) && (NewEvent.Action != nullptr))
			{
				UEngine::FCopyPropertiesForUnrelatedObjectsParams CopyParams;
				CopyParams.bNotifyObjectReplacement = true;
				UEngine::CopyPropertiesForUnrelatedObjects(OldEventPayload, NewEvent.Action, CopyParams);
			}

			// For Anim Notify States, handle the end time and link
			//if (NewEvent.Duration > 0)
			{
				NewEvent.SetDuration(Length);
				NewEvent.EndTriggerTimeOffset = EndTriggerTimeOffset;
				//NewEvent.EndLink.ChangeSlotIndex(EndSlotIndex);
				//NewEvent.EndLink.SetSegmentIndex(EndSegmentIndex);
				//NewEvent.EndLink.ChangeLinkMethod(EndLinkMethod);
			}
						
			//NewEvent.Update();
		}
	}

	// clear selection  
	TArray<UObject*> Objects;
	OnSelectionChanged.ExecuteIfBound(Objects);
	// TODO: set selection to new notifies?
	// update the panel

	Timeline->PostEditChange();
	Timeline->MarkPackageDirty();

	Update();
}

void SLGAActionPanel::OnReplaceSelectedWithNotifyBlueprint(FString NewBlueprintNotifyName, FString NewBlueprintNotifyClass)
{
	TSubclassOf<UObject> BlueprintClass = SLGAActionTrack::GetBlueprintClassFromPath(NewBlueprintNotifyClass);
	OnReplaceSelectedWithNotify(NewBlueprintNotifyName, BlueprintClass);
}

void SLGAActionPanel::OnPasteNodes(SLGAActionTrack* RequestTrack, float ClickTime, ELGAActionPasteMode::Type PasteMode, ELGAActionPasteMultipleMode::Type MultiplePasteType)
{
	if (RequestTrack == nullptr)
	{
		for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
		{
			if (Track->HasKeyboardFocus())
			{
				RequestTrack = Track.Get();
				if (ClickTime == -1.0f)
				{
					ClickTime = RequestTrack->GetLastClickedTime();
				}
				break;
			}
		}
	}

	int32 PasteIdx = RequestTrack != nullptr ? RequestTrack->GetTrackIndex() : 0;
	int32 NumTracks = NotifyAnimTracks.Num();
	FString PropString;
	const TCHAR* Buffer;
	float OrigBeginTime;
	float OrigLength;
	int32 TrackSpan;
	int32 FirstTrack = -1;
	float ScaleMultiplier = 1.0f;

	if (ReadNotifyPasteHeader(PropString, Buffer, OrigBeginTime, OrigLength, TrackSpan))
	{
		DeselectAllNotifies();

		FScopedTransaction Transaction(LOCTEXT("PasteActions", "Paste Actions"));
		ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
		Timeline->Modify();

		if (ClickTime == -1.0f)
		{
			// We want to place the notifies exactly where they were
			ClickTime = OrigBeginTime;
		}

		// Expand the number of tracks if we don't have enough.
		check(TrackSpan > 0);
		if (PasteIdx + TrackSpan > NumTracks)
		{
			int32 TracksToAdd = (PasteIdx + TrackSpan) - NumTracks;
			while (TracksToAdd)
			{
				AddTrack();
				--TracksToAdd;
			}
			NumTracks = NotifyAnimTracks.Num();
		}

		// Scaling for relative paste
		if (MultiplePasteType == ELGAActionPasteMultipleMode::Relative)
		{
			ScaleMultiplier = Timeline->SequenceLength / OrigLength;
		}

		// Process each line of the paste buffer and spawn notifies
		FString CurrentLine;
		while (FParse::Line(&Buffer, CurrentLine))
		{
			int32 OriginalTrack;
			float OrigTime;
			int32 NodeObjectType;
			float PasteTime = -1.0f;
			if (FParse::Value(*CurrentLine, TEXT("TrackIndex="), OriginalTrack) && FParse::Value(*CurrentLine, TEXT("AbsTime="), OrigTime) && FParse::Value(*CurrentLine, TEXT("NodeObjectType="), NodeObjectType))
			{
				const int32 FirstComma = CurrentLine.Find(TEXT(","), ESearchCase::CaseSensitive, ESearchDir::FromStart);
				const int32 SecondComma = CurrentLine.Find(TEXT(","), ESearchCase::CaseSensitive, ESearchDir::FromStart, FirstComma + 1);
				FString NotifyExportString = CurrentLine.RightChop(SecondComma + 1);

				// Store the first track so we know where to place notifies
				if (FirstTrack < 0)
				{
					FirstTrack = OriginalTrack;
				}
				int32 TrackOffset = OriginalTrack - FirstTrack;

				float TimeOffset = OrigTime - OrigBeginTime;
				float TimeToPaste = ClickTime + TimeOffset * ScaleMultiplier;

				TSharedPtr<SLGAActionTrack> TrackToUse = NotifyAnimTracks[PasteIdx + TrackOffset];
				if (NodeObjectType == ENodeObjectTypes::ACTION)
				{
					TrackToUse->PasteSingleNotify(NotifyExportString, TimeToPaste);
				}
				else
				{
					check(false); //Unknown value in paste
				}
			}
		}
	}
}

void SLGAActionPanel::OnPropertyChanged(UObject* ChangedObject, FPropertyChangedEvent& PropertyEvent)
{
	// Don't process if it's an interactive change; wait till we receive the final event.
	if (PropertyEvent.ChangeType != EPropertyChangeType::Interactive)
	{
		if (ChangedObject->IsA<ULGAAction>())
		{
			if(ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline())
			{
				for (const FLGAActionEvent& Event : Timeline->Actions)
				{
					if (Event.Action == ChangedObject)
					{
						// If we've changed a action present in the timeline, refresh our tracks.
						Update();
						break;
					}
				}
			}

			if (Model.Pin()->GetAbilityEditor().Pin()->GetAbilityBlueprint()->IsMyOverrideAction(Cast<ULGAAction>(ChangedObject)))
			{
				Update();
			}
		}

		if (ChangedObject->IsA<ULGATimeline>())
		{
			if (ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline())
			{
				if (Timeline == ChangedObject)
				{
					Update();
				}
			}
		}
	}
}

void SLGAActionPanel::BindCommands()
{
	TSharedRef<FUICommandList> CommandList = GetCommandList();
	const FLegoAbilityEditorTimelineCommands& Commands = FLegoAbilityEditorTimelineCommands::Get();

	CommandList->UnmapAction(Commands.DeleteAction);
	CommandList->MapAction(Commands.DeleteAction, FExecuteAction::CreateSP(this, &SLGAActionPanel::OnDeletePressed));

	CommandList->UnmapAction(Commands.CopyActions);
	CommandList->MapAction(Commands.CopyActions,FExecuteAction::CreateSP(this, &SLGAActionPanel::CopySelectedNodesToClipboard));

	CommandList->UnmapAction(Commands.PasteActions);
	CommandList->MapAction(Commands.PasteActions, FExecuteAction::CreateSP(this, &SLGAActionPanel::OnPasteNodes, (SLGAActionTrack*)nullptr, -1.0f, ELGAActionPasteMode::MousePosition, ELGAActionPasteMultipleMode::Absolute));
}

FReply SLGAActionPanel::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	if (GetCommandList()->ProcessCommandBindings(InKeyEvent))
	{
		return FReply::Handled();
	}
	return FReply::Unhandled();
}

FReply SLGAActionPanel::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SLGATimelineTrackPanel::OnMouseButtonDown(MyGeometry, MouseEvent);

	bool bLeftButton = MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton);

	if (bLeftButton)
	{
		TArray<TSharedPtr<SLGAActionNode>> SelectedNodes;
		for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
		{
			Track->AppendSelectedNodeWidgetsToArray(SelectedNodes);
		}

		Marquee.Start(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()), Marquee.OperationTypeFromMouseEvent(MouseEvent), SelectedNodes);
		if (Marquee.Operation == FLGAActionMarqueeOperation::Replace)
		{
			// Remove and Add operations preserve selections, replace starts afresh
			DeselectAllNotifies();
		}

		return FReply::Handled().DetectDrag(SharedThis(this), EKeys::LeftMouseButton);
	}

	return FReply::Unhandled();
}

FReply SLGAActionPanel::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (Marquee.bActive)
	{
		OnTrackSelectionChanged();
		Marquee = FLGAActionMarqueeOperation();
		return FReply::Handled().ReleaseMouseCapture();
	}

	return SLGATimelineTrackPanel::OnMouseButtonUp(MyGeometry, MouseEvent);
}

FReply SLGAActionPanel::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FReply BaseReply = SLGATimelineTrackPanel::OnMouseMove(MyGeometry, MouseEvent);
	if (!BaseReply.IsEventHandled())
	{
		bool bLeftButton = MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton);

		if (bLeftButton && Marquee.bActive)
		{
			Marquee.Rect.UpdateEndPoint(MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition()));
			RefreshMarqueeSelectedNodes(MyGeometry);
			return FReply::Handled();
		}
	}

	return BaseReply;
}

int32 SLGAActionPanel::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	LayerId = SLGATimelineTrackPanel::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FVector2D Origin = AllottedGeometry.AbsoluteToLocal(Marquee.Rect.GetUpperLeft());
	FVector2D Extents = AllottedGeometry.AbsoluteToLocal(Marquee.Rect.GetSize());

	if (Marquee.IsValid())
	{
		FSlateDrawElement::MakeBox(
			OutDrawElements,
			LayerId++,
			AllottedGeometry.ToPaintGeometry(Marquee.Rect.GetSize(), FSlateLayoutTransform(Marquee.Rect.GetUpperLeft())),
			FAppStyle::GetBrush(TEXT("MarqueeSelection"))
		);
	}

	return LayerId;
}

void SLGAActionPanel::RefreshMarqueeSelectedNodes(const FGeometry& PanelGeo)
{
	if (Marquee.IsValid())
	{
		FSlateRect MarqueeRect = Marquee.Rect.ToSlateRect();
		for (TSharedPtr<SLGAActionTrack> Track : NotifyAnimTracks)
		{
			if (Marquee.Operation == FLGAActionMarqueeOperation::Replace || Marquee.OriginalSelection.Num() == 0)
			{
				Track->DeselectAllNotifyNodes(false);
			}

			const FGeometry& TrackGeo = Track->GetCachedGeometry();

			FSlateRect TrackClip = TrackGeo.GetLayoutBoundingRect();
			FSlateRect PanelClip = PanelGeo.GetLayoutBoundingRect();
			FVector2D PanelSpaceOrigin = TrackClip.GetTopLeft() - PanelClip.GetTopLeft();
			FVector2D TrackSpaceOrigin = MarqueeRect.GetTopLeft() - PanelSpaceOrigin;
			FSlateRect MarqueeTrackSpace(TrackSpaceOrigin, TrackSpaceOrigin + MarqueeRect.GetSize());

			Track->RefreshMarqueeSelectedNodes(MarqueeTrackSpace, Marquee);
		}
	}
}

FReply SLGAActionPanel::OnDragDetected(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Marquee.bActive = true;
	return FReply::Handled().CaptureMouse(SharedThis(this));
}

void SLGAActionPanel::OnFocusLost(const FFocusEvent& InFocusEvent)
{
	if (Marquee.bActive)
	{
		OnTrackSelectionChanged();
	}
	Marquee = FLGAActionMarqueeOperation();
}

void SLGAActionPanel::InputViewRangeChanged(float ViewMin, float ViewMax)
{
	ULGATimeline* Timeline = Model.Pin()->GetAbilityTimeline();
	float Ratio = (ViewMax - ViewMin) / Timeline->SequenceLength;
	float OffsetFraction = ViewMin / Timeline->SequenceLength;
	if (NotifyTrackScrollBar.IsValid())
	{
		NotifyTrackScrollBar->SetState(OffsetFraction, Ratio);
	}

	SLGATimelineTrackPanel::InputViewRangeChanged(ViewMin, ViewMax);
}

void SLGAActionPanel::HandleObjectsSelected(const TArray<UObject*>& InObjects)
{
	if (!bIsSelecting)
	{
		DeselectAllNotifies();
	}
}

#undef LOCTEXT_NAMESPACE

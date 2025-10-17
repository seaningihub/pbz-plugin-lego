// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Timeline/LGATimelineTrack.h"
#include "EditorUndoClient.h"
#include "Timeline/LGATimelineModel.h"

class FCurveEditor;
struct FRichCurve;
class SHorizontalBox;
class SCurveBoundsOverlay;

struct FFloatCurve;
class SBorder;

class FLGATimelineTrack_FloatCurve : public FLGATimelineTrack, public FSelfRegisteringEditorUndoClient
{
public:
	FLGATimelineTrack_FloatCurve(FName CurveName, const TSharedRef<FLGATimelineModel>& InModel);

	/** FLGATimelineTrack interface */
	virtual TSharedRef<SWidget> MakeTimelineWidgetContainer();
	/** Make the curve widget itself */
	virtual TSharedRef<SWidget> MakeCurveWidget();

	virtual TSharedRef<SWidget> GenerateContainerWidgetForTimeline() override;
	virtual TSharedRef<SWidget> GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow) override;
	virtual bool SupportsSelection() const override { return true; }
	virtual void AddToContextMenu(FMenuBuilder& InMenuBuilder, TSet<FName>& InOutExistingMenuTypes) const override;

	virtual TSharedRef<SWidget> BuildCurveTrackMenu();
	virtual FText GetLabel() const override;
	virtual bool CanEditCurve(int32 InCurveIndex) const;
	virtual bool CanRename() const override { return true; }
	virtual void RequestRename() override;
	virtual void AddCurveTrackButton(TSharedPtr<SHorizontalBox> InnerHorizontalBox);

	/** Should this track draw its curves, by default, hide curves in parent tracks when children are expanded. */
	virtual bool ShowCurves() const;

	/** Delegate handing curve changing externally */
	void HandleCurveChanged();

	virtual void HandleEditCurve();

	/** FEditorUndoClient interface */
	virtual void PostUndo(bool bSuccess) override { PostUndoRedo(); }
	virtual void PostRedo(bool bSuccess) override { PostUndoRedo(); }
	
	/** Access the curve we are editing */
	const FFloatCurve* GetFloatCurve();

	/** Get this curves name */
	FName GetFName() const { return CurveName; }

protected:
	/** Handle undo/redo */
	void PostUndoRedo();

	/** Zoom the view to fit the bounds of the curve */
	void ZoomToFit();

	/** Edit this curve when double clicked */
	FReply HandleDoubleClicked(const FGeometry& InGeometry, const FPointerEvent& InPointerEvent);

	/** Push a popup menu when we right-click */
	FReply HandleMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InPointerEvent);

private:
	void RemoveCurve();
	void OnCommitCurveName(const FText& InText, ETextCommit::Type CommitInfo);

private:
	/** The curve we are editing */
	FName CurveName;

	/** Label we can edit */
	TSharedPtr<SInlineEditableTextBlock> EditableTextLabel;

	/** Container widget for timeline */
	TSharedPtr<SBorder> TimelineWidgetContainer;

	/** Curve editor */
	TSharedPtr<FCurveEditor> CurveEditor;

	/** Overlay widget used to display bounds */
	TSharedPtr<SCurveBoundsOverlay> CurveOverlay;
};

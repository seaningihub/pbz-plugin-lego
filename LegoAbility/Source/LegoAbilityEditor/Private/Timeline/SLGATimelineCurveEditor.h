// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "EditorUndoClient.h"
#include "RichCurveEditorModel.h"
#include "CurveEditorTypes.h"

class FCurveEditor;
class ITimeSliderController;
class SCurveEditorTree;
class SCurveEditorPanel;
class FTabManager;
class FLGATimelinePreviewer;
class ULGATimeline;

class FTimelineCurveEditorModel : public FRichCurveEditorModel
{
public:

	FTimelineCurveEditorModel(ULGATimeline* InTimeline, const FName& InName);

	virtual ~FTimelineCurveEditorModel();

	virtual bool IsValid() const override;
	virtual FRichCurve& GetRichCurve() override;
	virtual const FRichCurve& GetReadOnlyRichCurve() const override;

	virtual void SetKeyPositions(TArrayView<const FKeyHandle> InKeys, TArrayView<const FKeyPosition> InKeyPositions, EPropertyChangeType::Type ChangeType) override;
	virtual void SetKeyAttributes(TArrayView<const FKeyHandle> InKeys, TArrayView<const FKeyAttributes> InAttributes, EPropertyChangeType::Type ChangeType = EPropertyChangeType::Unspecified) override;
	virtual void SetCurveAttributes(const FCurveAttributes& InCurveAttributes) override;
	virtual void RemoveKeys(TArrayView<const FKeyHandle> InKeys) override;

	TWeakObjectPtr<ULGATimeline> Timeline;
	FName CurveName;
};


class SLGATimelineCurveEditor : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SLGATimelineCurveEditor) {}

	SLATE_ARGUMENT(TSharedPtr<ITimeSliderController>, ExternalTimeSliderController)

	SLATE_ARGUMENT(TSharedPtr<FTabManager>, TabManager)

	SLATE_END_ARGS()

	~SLGATimelineCurveEditor();

	void Construct(const FArguments& InArgs, TSharedPtr<FLGATimelinePreviewer> InTimelinePreviewer);

	/** IAnimSequenceCurveEditor interface */
	virtual void ResetCurves();
	virtual void AddCurve(ULGATimeline* InTimeline, FName CurveName, FSimpleDelegate InOnCurveModified);
	virtual void RemoveCurve(ULGATimeline* InTimeline, const FName& InName);
	virtual void ZoomToFit();

	void ClearInvalidCurves();
	
private:
	// Build the toolbar for this curve editor
	TSharedRef<SWidget> MakeToolbar(TSharedRef<SCurveEditorPanel> InEditorPanel);
	TSharedPtr<SWidget> OnContextMenuOpening();

private:
	/** The actual curve editor */
	TSharedPtr<FCurveEditor> CurveEditor;

	/** The search widget for filtering curves in the Curve Editor tree. */
	TSharedPtr<SWidget> CurveEditorSearchBox;

	/** The tree widget in the curve editor */
	TSharedPtr<SCurveEditorTree> CurveEditorTree;
};
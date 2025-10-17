// Copyright Epic Games, Inc. All Rights Reserved.

#include "Timeline/LGATimelineTrack_FloatCurve.h"
#include "CurveEditor.h"
#include "Widgets/Layout/SBorder.h"
#include "Styling/AppStyle.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ScopedTransaction.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/Colors/SColorBlock.h"
#include "PersonaUtils.h"
#include "Widgets/Colors/SColorPicker.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Layout/SBox.h"
#include "Timeline/SLGATimelineOutlinerItem.h"
#include "LegoAbilityEditorStyle.h"
#include "LegoAbilityEditorCommands.h"
#include "LGATimeline.h"

#include "SCurveViewerPanel.h"
#include "RichCurveEditorModel.h"
#include "Fonts/FontMeasure.h"
#include "Preferences/PersonaOptions.h"
#include "Framework/Commands/GenericCommands.h"
#include "SLGATimelineCurveEditor.h"
#include "Animation/AnimCurveTypes.h"

#define LOCTEXT_NAMESPACE "FLGATimelineTrack_FloatCurve"

class FLGAModelCurveEditorBounds : public ICurveEditorBounds
{
public:
	FLGAModelCurveEditorBounds(const TSharedRef<FLGATimelineModelBase>& InModel)
		: Model(InModel)
	{}

	virtual void GetInputBounds(double& OutMin, double& OutMax) const override
	{
		FAnimatedRange ViewRange = Model.Pin()->GetViewRange();
		OutMin = ViewRange.GetLowerBoundValue();
		OutMax = ViewRange.GetUpperBoundValue();
	}

	virtual void SetInputBounds(double InMin, double InMax) override
	{
		Model.Pin()->SetViewRange(TRange<double>(InMin, InMax));
	}

	TWeakPtr<FLGATimelineModelBase> Model;
};

/** Widget used for drawing bounds on top of the curve viewer */
class SCurveBoundsOverlay : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SCurveBoundsOverlay)
		: _BoundsLabelFormat(LOCTEXT("BoundsFormat2D", "{0}s, {1}"))
		{
		}

		SLATE_ATTRIBUTE(FText, BoundsLabelFormat)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedRef<FCurveEditor> InCurveEditor)
	{
		BoundsLabelFormatAttribute = InArgs._BoundsLabelFormat;
		CurveEditor = InCurveEditor;

		BuildBoundsLabels();
	}

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override
	{
		// Rendering info
		constexpr float LabelOffsetPx = 2.0f;
		const float Width = static_cast<float>(AllottedGeometry.GetLocalSize().X);
		const float Height = static_cast<float>(AllottedGeometry.GetLocalSize().Y);
		const FPaintGeometry PaintGeometry = AllottedGeometry.ToPaintGeometry();
		const FSlateFontInfo FontInfo = FCoreStyle::GetDefaultFontStyle("Regular", 8);
		TSharedRef<FSlateFontMeasure> FontMeasureService = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
		const ESlateDrawEffect DrawEffects = ShouldBeEnabled(bParentEnabled) ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect;
		auto DrawLabel = [&AllottedGeometry, &LayerId, &OutDrawElements, &FontInfo, DrawEffects](const FText& InText, const FPaintGeometry& InLabelGeometry)
			{
				const FLinearColor LabelColor = FLinearColor::White.CopyWithNewOpacity(0.65f);

				FSlateDrawElement::MakeText(
					OutDrawElements,
					LayerId,
					InLabelGeometry,
					InText,
					FontInfo,
					DrawEffects,
					LabelColor
				);
			};

		DrawLabel(TopLeftLabel, AllottedGeometry.ToPaintGeometry(FSlateLayoutTransform(FVector2D(LabelOffsetPx, LabelOffsetPx))));

		FVector2D LabelSize = FontMeasureService->Measure(TopRightLabel, FontInfo);
		DrawLabel(TopRightLabel, AllottedGeometry.ToPaintGeometry(FSlateLayoutTransform(FVector2D(Width - (LabelSize.X + LabelOffsetPx), LabelOffsetPx))));

		LabelSize = FontMeasureService->Measure(BottomLeftLabel, FontInfo);
		DrawLabel(BottomLeftLabel, AllottedGeometry.ToPaintGeometry(FSlateLayoutTransform(FVector2D(LabelOffsetPx, Height - (LabelSize.Y + LabelOffsetPx)))));

		LabelSize = FontMeasureService->Measure(BottomRightLabel, FontInfo);
		DrawLabel(BottomRightLabel, AllottedGeometry.ToPaintGeometry(FSlateLayoutTransform(FVector2D(Width - (LabelSize.X + LabelOffsetPx), Height - (LabelSize.Y + LabelOffsetPx)))));

		return LayerId + 1;
	}

	FVector2D ComputeDesiredSize(float) const override
	{
		return FVector2D(8.0f, 8.0f);
	}

	void BuildBoundsLabels()
	{
		double InputMin = TNumericLimits<double>::Max(), InputMax = TNumericLimits<double>::Lowest(), OutputMin = TNumericLimits<double>::Max(), OutputMax = TNumericLimits<double>::Lowest();

		for (const TPair<FCurveModelID, TUniquePtr<FCurveModel>>& ModelPair : CurveEditor.Pin()->GetCurves())
		{
			double LocalMin, LocalMax;
			ModelPair.Value->GetTimeRange(LocalMin, LocalMax);
			InputMin = FMath::Min(InputMin, LocalMin);
			InputMax = FMath::Max(InputMax, LocalMax);
			ModelPair.Value->GetValueRange(LocalMin, LocalMax);
			OutputMin = FMath::Min(OutputMin, LocalMin);
			OutputMax = FMath::Max(OutputMax, LocalMax);
		}

		const FText BoundsLabelFormat = BoundsLabelFormatAttribute.Get();

		TopLeftLabel = FText::Format(BoundsLabelFormat, FText::AsNumber(InputMin), FText::AsNumber(OutputMax));
		TopRightLabel = FText::Format(BoundsLabelFormat, FText::AsNumber(InputMax), FText::AsNumber(OutputMax));
		BottomLeftLabel = FText::Format(BoundsLabelFormat, FText::AsNumber(InputMin), FText::AsNumber(OutputMin));
		BottomRightLabel = FText::Format(BoundsLabelFormat, FText::AsNumber(InputMax), FText::AsNumber(OutputMin));
	}

	// The curve editor we are using to get out values
	TWeakPtr<FCurveEditor> CurveEditor;

	// The format to use to display the bounds
	TAttribute<FText> BoundsLabelFormatAttribute;

	// Labels for each corner of the bounds
	FText TopLeftLabel;
	FText TopRightLabel;
	FText BottomLeftLabel;
	FText BottomRightLabel;
};


FLGATimelineTrack_FloatCurve::FLGATimelineTrack_FloatCurve(FName InCurveName, const TSharedRef<FLGATimelineModel>& InModel)
	: FLGATimelineTrack(FText::FromName(InCurveName), FText::FromName(InCurveName), InModel)
	, CurveName(InCurveName)
{
	SetHeight(32.0f);
}

TSharedRef<SWidget> FLGATimelineTrack_FloatCurve::MakeTimelineWidgetContainer()
{
	TSharedRef<SWidget> CurveWidget = MakeCurveWidget();

	// zoom to fit now we have a view
	CurveEditor->ZoomToFit(EAxisList::Y);

	FLinearColor CurveColor =  GetFloatCurve()->GetColor().Desaturate(0.75f);
	FName FloatCurveName = GetFloatCurve()->GetName();
	auto ColorLambda = [this, CurveColor, FloatCurveName]()
	{
		if(GetModel()->IsTrackSelected(AsShared()))
		{
			return FAppStyle::GetSlateColor("SelectionColor").GetSpecifiedColor().CopyWithNewOpacity(0.75f);
		}
		else
		{
			FName StretchCurveName = GetModel()->GetAbilityTimeline()->GetTimeStretchName();
			if (!GetModel()->GetAbilityTimeline()->GetCurveByName(StretchCurveName))
			{
				StretchCurveName = GetModel()->GetAbilityTimeline()->TimeStretchCurveName;
			}
			if (!StretchCurveName.IsNone() && FloatCurveName == StretchCurveName)
			{
				return FAppStyle::GetSlateColor("SelectionColor").GetSpecifiedColor().CopyWithNewOpacity(0.5f);
			}

			return CurveColor;
		}
	};

	return
		SAssignNew(TimelineWidgetContainer, SBorder)
		.Padding(0.0f)
		.BorderImage(FAppStyle::GetBrush("AnimTimeline.Outliner.DefaultBorder"))
		.BorderBackgroundColor_Lambda(ColorLambda)
		[
			CurveWidget
		];
}


TSharedRef<SWidget> FLGATimelineTrack_FloatCurve::MakeCurveWidget()
{
	return
		SNew(SOverlay)
		+ SOverlay::Slot()
		[
			SNew(SCurveViewerPanel, CurveEditor.ToSharedRef())
				.Visibility_Lambda([this]()
					{
						// Dont show curves in parent tracks when children are expanded
						return ShowCurves() ? EVisibility::Visible : EVisibility::Hidden;
					})
				.CurveThickness_Lambda([this]()
					{
						return IsHovered() ? 2.0f : 1.0f;
					})
		]
		+ SOverlay::Slot()
		[
			SAssignNew(CurveOverlay, SCurveBoundsOverlay, CurveEditor.ToSharedRef())
				.BoundsLabelFormat(LOCTEXT("BoundsFormat", "{1}"))	// Only want to display the Y axis
				.Visibility_Lambda([this]()
					{
						// Dont show curves in parent tracks when children are expanded
						return ShowCurves() && IsHovered() ? EVisibility::Visible : EVisibility::Hidden;
					})
		];
}

TSharedRef<SWidget> FLGATimelineTrack_FloatCurve::GenerateContainerWidgetForTimeline()
{
	CurveEditor = MakeShared<FCurveEditor>();
	CurveEditor->SetBounds(MakeUnique<FLGAModelCurveEditorBounds>(GetModel()));
	CurveEditor->InputZoomToFitPadding = 0.0f;
	CurveEditor->OutputZoomToFitPadding = 0.01f;
	FCurveEditorInitParams CurveEditorInitParams;
	CurveEditor->InitCurveEditor(CurveEditorInitParams);

	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	{
		TUniquePtr<FTimelineCurveEditorModel> NewCurveModel = MakeUnique<FTimelineCurveEditorModel>(Timeline, CurveName);
		NewCurveModel->SetColor(GetFloatCurve()->GetColor(), false);
		NewCurveModel->SetIsKeyDrawEnabled(MakeAttributeLambda([]() { return GetDefault<UPersonaOptions>()->bTimelineDisplayCurveKeys; }));
		CurveEditor->AddCurve(MoveTemp(NewCurveModel));
	}

	TSharedRef<SWidget> TimelineWidget = MakeTimelineWidgetContainer();

	bool bTimlineEditable = (Model.Pin()->GetAbilityEditor().Pin()->IsCurrentTimelineLocal());
	TimelineWidget->SetEnabled(bTimlineEditable);

	{
		TimelineWidget->SetOnMouseDoubleClick(FPointerEventHandler::CreateSP(this, &FLGATimelineTrack_FloatCurve::HandleDoubleClicked));
		TimelineWidget->SetOnMouseButtonUp(FPointerEventHandler::CreateSP(this, &FLGATimelineTrack_FloatCurve::HandleMouseButtonUp));
	}

	return TimelineWidget;
}

TSharedRef<SWidget> FLGATimelineTrack_FloatCurve::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedPtr<SBorder> OuterBorder;
	TSharedPtr<SHorizontalBox> InnerHorizontalBox;
	TSharedRef<SWidget> OutlinerWidget = GenerateStandardOutlinerWidget(InRow, false, OuterBorder, InnerHorizontalBox);

	InnerHorizontalBox->AddSlot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Left)
		.Padding(2.0f, 1.0f)
		.FillWidth(1.0f)
		[
			SAssignNew(EditableTextLabel, SInlineEditableTextBlock)
			.IsReadOnly(false)
			.Text(this, &FLGATimelineTrack_FloatCurve::GetLabel)
			.IsSelected_Lambda([this](){ return GetModel()->IsTrackSelected(SharedThis(this)); })
			.OnTextCommitted(this, &FLGATimelineTrack_FloatCurve::OnCommitCurveName)
			.HighlightText(InRow->GetHighlightText())
		];

	{
		OuterBorder->SetOnMouseDoubleClick(FPointerEventHandler::CreateSP(this, &FLGATimelineTrack_FloatCurve::HandleDoubleClicked));
		AddCurveTrackButton(InnerHorizontalBox);
	}

	return OutlinerWidget;
}


void FLGATimelineTrack_FloatCurve::AddToContextMenu(FMenuBuilder& InMenuBuilder, TSet<FName>& InOutExistingMenuTypes) const
{

}

TSharedRef<SWidget> FLGATimelineTrack_FloatCurve::BuildCurveTrackMenu()
{
	FMenuBuilder MenuBuilder(true, GetModel()->GetCommandList());

	MenuBuilder.BeginSection("Curve", LOCTEXT("CurveMenuSection", "Curve"));
	{
		
		{
			MenuBuilder.AddMenuEntry(
				FLegoAbilityEditorTimelineCommands::Get().EditCurve->GetLabel(),
				FLegoAbilityEditorTimelineCommands::Get().EditCurve->GetDescription(),
				FLegoAbilityEditorTimelineCommands::Get().EditCurve->GetIcon(),
				FUIAction(FExecuteAction::CreateSP(this, &FLGATimelineTrack_FloatCurve::HandleEditCurve)));
		}

		MenuBuilder.AddMenuEntry(
			FLegoAbilityEditorTimelineCommands::Get().RemoveCurve->GetLabel(),
			FLegoAbilityEditorTimelineCommands::Get().RemoveCurve->GetDescription(),
			FLegoAbilityEditorTimelineCommands::Get().RemoveCurve->GetIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FLGATimelineTrack_FloatCurve::RemoveCurve)
			)
		);
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}


void FLGATimelineTrack_FloatCurve::RemoveCurve()
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	FName FloatCurveName = CurveName;

	if (Timeline->FloatCurves.RemoveAll([FloatCurveName](FFloatCurve& Item) { return FloatCurveName == Item.GetName(); }))
	{
		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();

		GetModel()->RefreshTracks();
	}
}

void FLGATimelineTrack_FloatCurve::OnCommitCurveName(const FText& InText, ETextCommit::Type CommitInfo)
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	
	// only do this if the name isn't same
	FText CurrentCurveName = GetLabel();
	if (!CurrentCurveName.EqualToCaseIgnored(InText))
	{
		// Check that the name doesn't already exist
		const FName RequestedName = FName(*InText.ToString());
		
		if (Timeline->GetCurveByName(RequestedName))
		{
			FFormatNamedArguments Args;
			Args.Add(TEXT("InvalidName"), FText::FromName(RequestedName));
			FNotificationInfo Info(FText::Format(LOCTEXT("TimelineCurveRenamedInUse", "The name \"{InvalidName}\" is already used."), Args));

			Info.bUseLargeFont = false;
			Info.ExpireDuration = 5.0f;

			TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(Info);
			if (Notification.IsValid())
			{
				Notification->SetCompletionState(SNotificationItem::CS_Fail);
			}
			return;
		}
		
		GetModel()->GetAbilityTimeline()->GetCurveByName(CurveName)->SetName(RequestedName);
		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();

		GetModel()->RefreshTracks();
	}
}

FText FLGATimelineTrack_FloatCurve::GetLabel() const
{
	return FText::FromName(CurveName);
}

bool FLGATimelineTrack_FloatCurve::CanEditCurve(int32 InCurveIndex) const
{
	return true;
}

void FLGATimelineTrack_FloatCurve::RequestRename()
{
	if(EditableTextLabel.IsValid())
	{
		EditableTextLabel->EnterEditingMode();
	}
}

void FLGATimelineTrack_FloatCurve::AddCurveTrackButton(TSharedPtr<SHorizontalBox> InnerHorizontalBox)
{
	InnerHorizontalBox->AddSlot()
	.AutoWidth()
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Center)
	.Padding(0.0f, 1.0f)
	[
		PersonaUtils::MakeTrackButton(LOCTEXT("EditCurveButtonText", "Curve"), FOnGetContent::CreateSP(this, &FLGATimelineTrack_FloatCurve::BuildCurveTrackMenu), MakeAttributeSP(this, &FLGATimelineTrack_FloatCurve::IsHovered))
	];

	FLinearColor CurveColor = GetFloatCurve()->Color;
	auto SetValue = [this](FLinearColor InNewColor)
	{
		const_cast<FFloatCurve*>(this->GetFloatCurve())->Color = InNewColor;

		ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();

		// Set display curves too
		for(const TPair<FCurveModelID, TUniquePtr<FCurveModel>>& CurvePair : CurveEditor->GetCurves())
		{
			CurvePair.Value->SetColor(InNewColor, false);
		}
	};

	auto OnGetMenuContent = [this, CurveColor, SetValue]()
	{
		// Open a color picker
		return SNew(SColorPicker)
			.TargetColorAttribute(CurveColor)
			.UseAlpha(false)
			.DisplayInlineVersion(true)
			.OnColorCommitted_Lambda(SetValue)
			.OnInteractivePickBegin_Lambda([this]()
			{
					
			})
			.OnInteractivePickEnd_Lambda([this]()
			{
				
			});
	};

	InnerHorizontalBox->AddSlot()
	.AutoWidth()
	.HAlign(HAlign_Right)
	.VAlign(VAlign_Fill)
	.Padding(2.0f, 0.0f, 0.0f, 0.0f)
	[
		SNew(SComboButton)
		.ToolTipText(LOCTEXT("EditCurveColor", "Edit Curve Color"))
		.ContentPadding(0.0f)
		.HasDownArrow(false)
		.ButtonStyle(FLegoAbilityEditorStyle::Get(), "Sequencer.AnimationOutliner.ColorStrip")
		.OnGetMenuContent_Lambda(OnGetMenuContent)
		.CollapseMenuOnParentFocus(true)
		.VAlign(VAlign_Fill)
		.ButtonContent()
		[
			SNew(SColorBlock)
			.Color(CurveColor)
			.ShowBackgroundForAlpha(false)
			.AlphaDisplayMode(EColorBlockAlphaDisplayMode::Ignore)
			.Size(FVector2D(OutlinerRightPadding - 2.0f, OutlinerRightPadding))
		]
	];
}


bool FLGATimelineTrack_FloatCurve::ShowCurves() const
{
	// Dont show curves in parent tracks when children are expanded
	return !IsExpanded() || Children.Num() == 0;
}

void FLGATimelineTrack_FloatCurve::HandleCurveChanged()
{
	ZoomToFit();
}

void FLGATimelineTrack_FloatCurve::HandleEditCurve()
{
	FCurveEditInfo EditCurveInfo(GetModel()->GetAbilityTimeline(), CurveName, FSimpleDelegate::CreateSP(this, &FLGATimelineTrack_FloatCurve::HandleCurveChanged));
	GetModel()->OnEditCurves.ExecuteIfBound(EditCurveInfo);

}


const FFloatCurve* FLGATimelineTrack_FloatCurve::GetFloatCurve()
{
	return GetModel()->GetAbilityTimeline()->GetCurveByName(CurveName);
}


void FLGATimelineTrack_FloatCurve::PostUndoRedo()
{
	ZoomToFit();
}


void FLGATimelineTrack_FloatCurve::ZoomToFit()
{
	if (CurveEditor.IsValid())
	{
		CurveEditor->ZoomToFit(EAxisList::Y);
	}
	if (CurveOverlay.IsValid())
	{
		CurveOverlay->BuildBoundsLabels();
	}
}


FReply FLGATimelineTrack_FloatCurve::HandleMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InPointerEvent)
{
	if (InPointerEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		FMenuBuilder MenuBuilder(true, GetModel()->GetCommandList());

		GetModel()->BuildContextMenu(MenuBuilder);

		FWidgetPath WidgetPath = InPointerEvent.GetEventPath() != nullptr ? *InPointerEvent.GetEventPath() : FWidgetPath();
		FSlateApplication::Get().PushMenu(TimelineWidgetContainer.ToSharedRef(), WidgetPath, MenuBuilder.MakeWidget(), FSlateApplication::Get().GetCursorPos(), FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

FReply FLGATimelineTrack_FloatCurve::HandleDoubleClicked(const FGeometry& InGeometry, const FPointerEvent& InPointerEvent)
{
	HandleEditCurve();

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE

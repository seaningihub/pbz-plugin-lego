// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimeline.h"
#include "Animation/AnimSequence.h"
#include "LGATimelineModelBase.h"
#include "EditorStyleSet.h"
#include "Fonts/FontMeasure.h"
#include "FrameNumberNumericInterface.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ISequencerWidgetsModule.h"
#include "Modules/ModuleManager.h"
#include "SLGATimelineOverlay.h"
#include "SLGATimelineSplitterOverlay.h"
#include "SLGATimelineTrackArea.h"
#include "SLGATimelineOutliner.h"
#include "SLGATimelineTransportControls.h"
#include "ScopedTransaction.h"
#include "Styling/ISlateStyle.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorSettings.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Input/STextEntryPopup.h"
#include "Widgets/Input/SSpinBox.h"
#include "Widgets/Layout/SScrollBorder.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/SWidget.h"
#include "MovieSceneFwd.h"
#include "Timeline/LGATimelinePreviewer.h"

#define LOCTEXT_NAMESPACE "SLGATimeline"

void SLGATimeline::Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModel>& InModel)
{
	TWeakPtr<FLGATimelineModelBase> WeakModel = InModel;

	Model = InModel;
	OnReceivedFocus = InArgs._OnReceivedFocus;

	int32 TickResolutionValue = InModel->GetTickResolution();
	int32 SequenceFrameRate = FMath::RoundToInt(InModel->GetFrameRate());

	TAttribute<EFrameNumberDisplayFormats> DisplayFormat = MakeAttributeLambda([]()
	{
		return GetDefault<ULegoAbilityEditorSettings>()->TimelineDisplayFormat;
	});

	TAttribute<EFrameNumberDisplayFormats> DisplayFormatSecondary = MakeAttributeLambda([]()
	{
		return GetDefault<ULegoAbilityEditorSettings>()->TimelineDisplayFormat == EFrameNumberDisplayFormats::Frames ? EFrameNumberDisplayFormats::Seconds : EFrameNumberDisplayFormats::Frames;
	});

	TAttribute<FFrameRate> TickResolution = MakeAttributeLambda([WeakModel]()
	{
		return FFrameRate(WeakModel.Pin()->GetTickResolution(), 1);
		//return FFrameRate(TickResolutionValue, 1);
	});

	TAttribute<FFrameRate> DisplayRate = MakeAttributeLambda([WeakModel]()
	{
		return FFrameRate(FMath::RoundToInt(WeakModel.Pin()->GetFrameRate()), 1);
		//return FFrameRate(SequenceFrameRate, 1);
	});

	// Create our numeric type interface so we can pass it to the time slider below.
	NumericTypeInterface = MakeShareable(new FFrameNumberInterface(DisplayFormat, 0, TickResolution, DisplayRate));
	SecondaryNumericTypeInterface = MakeShareable(new FFrameNumberInterface(DisplayFormatSecondary, 0, TickResolution, DisplayRate));

	FTimeSliderArgs TimeSliderArgs;
	TimeSliderArgs.DisplayRate = DisplayRate;
	TimeSliderArgs.TickResolution = TickResolution;

	TimeSliderArgs.ScrubPosition = MakeAttributeLambda([WeakModel](){ return WeakModel.IsValid() ? WeakModel.Pin()->GetScrubPosition() : FFrameTime(0); });
	TimeSliderArgs.OnScrubPositionChanged = FOnScrubPositionChanged::CreateSP(this, &SLGATimeline::HandleScrubPositionChanged);
	
	ViewRange = MakeAttributeLambda([WeakModel]() { return WeakModel.IsValid() ? WeakModel.Pin()->GetViewRange() : FAnimatedRange(0.0, 0.0); });
	TimeSliderArgs.ViewRange = ViewRange;
	TimeSliderArgs.PlaybackRange = MakeAttributeLambda([WeakModel](){ return WeakModel.IsValid() ? WeakModel.Pin()->GetPlaybackRange() : TRange<FFrameNumber>(0, 0); });
	TimeSliderArgs.ClampRange = MakeAttributeLambda([WeakModel](){ return WeakModel.IsValid() ? WeakModel.Pin()->GetWorkingRange() : FAnimatedRange(0.0, 0.0); });

	TimeSliderArgs.OnViewRangeChanged = FOnViewRangeChanged::CreateSP(&InModel.Get(), &FLGATimelineModelBase::HandleViewRangeChanged);
	TimeSliderArgs.OnClampRangeChanged = FOnTimeRangeChanged::CreateSP(&InModel.Get(), &FLGATimelineModelBase::HandleWorkingRangeChanged);
	TimeSliderArgs.OnPlaybackRangeChanged = FOnFrameRangeChanged::CreateSP(&InModel.Get(), &FLGATimelineModelBase::SetPlaybackRange);

	TimeSliderArgs.IsPlaybackRangeLocked = true;
	TimeSliderArgs.PlaybackStatus = EMovieScenePlayerStatus::Stopped;
	TimeSliderArgs.NumericTypeInterface = NumericTypeInterface;
	

	TimeSliderController = MakeShareable(new FLGATimeSliderController(TimeSliderArgs, InModel, SharedThis(this), SecondaryNumericTypeInterface));
	
	InModel->GetTimelinePreviewer().Get()->CurrentTimeSliderContrller = TimeSliderController;

	TSharedRef<FLGATimeSliderController> TimeSliderControllerRef = TimeSliderController.ToSharedRef();

	// Create the top slider
	const bool bMirrorLabels = false;
	ISequencerWidgetsModule& SequencerWidgets = FModuleManager::LoadModuleChecked<ISequencerWidgetsModule>("SequencerWidgets");
	TopTimeSlider = SequencerWidgets.CreateTimeSlider(TimeSliderControllerRef, bMirrorLabels);

	// Create bottom time range slider
	TSharedRef<ITimeSlider> BottomTimeRange = SequencerWidgets.CreateTimeRange(
		FTimeRangeArgs(
			EShowRange::PlaybackRange,
			TimeSliderControllerRef,
			EVisibility::Visible,
			NumericTypeInterface.ToSharedRef()
		),
		SequencerWidgets.CreateTimeRangeSlider(TimeSliderControllerRef)
	);

	TSharedRef<SScrollBar> ScrollBar = SNew(SScrollBar)
		.Thickness(FVector2D(5.0f, 5.0f));

	InModel->RefreshTracks();

	TrackArea = SNew(SLGATimelineTrackArea, InModel, TimeSliderControllerRef);
	Outliner = SNew(SLGATimelineOutliner, InModel, TrackArea.ToSharedRef())
		.ExternalScrollbar(ScrollBar)
		.Clipping(EWidgetClipping::ClipToBounds)
		.FilterText_Lambda([this](){ return FilterText; });

	TrackArea->SetOutliner(Outliner);

	ColumnFillCoefficients[0] = 0.2f;
	ColumnFillCoefficients[1] = 0.8f;

	TAttribute<float> FillCoefficient_0, FillCoefficient_1;
	{
		FillCoefficient_0.Bind(TAttribute<float>::FGetter::CreateSP(this, &SLGATimeline::GetColumnFillCoefficient, 0));
		FillCoefficient_1.Bind(TAttribute<float>::FGetter::CreateSP(this, &SLGATimeline::GetColumnFillCoefficient, 1));
	}

	const int32 Column0 = 0, Column1 = 1;
	const int32 Row0 = 0, Row1 = 1, Row2 = 2, Row3 = 3, Row4 = 4;

	const float CommonPadding = 3.f;
	const FMargin ResizeBarPadding(4.f, 0, 0, 0);

	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SGridPanel)
					.FillRow(1, 1.0f)
					.FillColumn(0, FillCoefficient_0)
					.FillColumn(1, FillCoefficient_1)

					// outliner search box
					+SGridPanel::Slot(Column0, Row0, SGridPanel::Layer(10))
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						[
							SAssignNew(SearchBox, SSearchBox)
							.HintText(LOCTEXT("FilterTracksHint", "Filter"))
							.OnTextChanged(this, &SLGATimeline::OnOutlinerSearchChanged)
						]
						+SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.HAlign(HAlign_Center)
						.AutoWidth()
						.Padding(2.0f, 0.0f, 2.0f, 0.0f)
						[
							SNew(SBox)
							.MinDesiredWidth(30.0f)
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Center)
							[
								// Current Play Time 
								SNew(SSpinBox<double>)
								.Style(&FAppStyle::GetWidgetStyle<FSpinBoxStyle>("Sequencer.PlayTimeSpinBox"))
								.Value_Lambda([this]() -> double
								{
									return Model.Pin()->GetScrubPosition().Value;
								})
								.OnValueChanged(this, &SLGATimeline::SetPlayTime)
								.OnValueCommitted_Lambda([this](double InFrame, ETextCommit::Type)
								{
									SetPlayTime(InFrame);
								})
								.MinValue(TOptional<double>())
								.MaxValue(TOptional<double>())
								.TypeInterface(NumericTypeInterface)
								.Delta(this, &SLGATimeline::GetSpinboxDelta)
								.LinearDeltaSensitivity(25)
							]
						]
					]
					// main timeline area
					+SGridPanel::Slot(Column0, Row1, SGridPanel::Layer(10))
					.ColumnSpan(2)
					[
						SNew(SHorizontalBox)
						+SHorizontalBox::Slot()
						[
							SNew(SOverlay)
							+SOverlay::Slot()
							[
								SNew(SScrollBorder, Outliner.ToSharedRef())
								[
									SNew(SHorizontalBox)

									// outliner tree
									+SHorizontalBox::Slot()
									.FillWidth(FillCoefficient_0)
									[
										SNew(SBox)
										[
											Outliner.ToSharedRef()
										]
									]

									// track area
									+SHorizontalBox::Slot()
									.FillWidth(FillCoefficient_1)
									[
										SNew(SBox)
										.Padding(ResizeBarPadding)
										.Clipping(EWidgetClipping::ClipToBounds)
										[
											TrackArea.ToSharedRef()
										]
									]
								]
							]

							+SOverlay::Slot()
							.HAlign(HAlign_Right)
							[
								ScrollBar
							]
						]
					]

					// Transport controls
					+ SGridPanel::Slot(Column0, Row3, SGridPanel::Layer(10))
					.VAlign(VAlign_Center)
					.HAlign(HAlign_Center)
					[
						SNew(SLGATimelineTransportControls, InModel->GetTimelinePreviewer())
					]

					// Second column
					+SGridPanel::Slot(Column1, Row0)
					.Padding(ResizeBarPadding)
					.RowSpan(2)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
						[
							SNew(SSpacer)
						]
					]

					+SGridPanel::Slot(Column1, Row0, SGridPanel::Layer(10))
					.Padding(ResizeBarPadding)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
						.BorderBackgroundColor(FLinearColor(.50f, .50f, .50f, 1.0f))
						.Padding(0)
						.Clipping(EWidgetClipping::ClipToBounds)
						[
							TopTimeSlider.ToSharedRef()
						]
					]

					// Overlay that draws the tick lines
					+SGridPanel::Slot(Column1, Row1, SGridPanel::Layer(10))
					.Padding(ResizeBarPadding)
					[
						SNew(SLGATimelineOverlay, TimeSliderControllerRef)
						.Visibility(EVisibility::HitTestInvisible)
						.DisplayScrubPosition(false)
						.DisplayTickLines(true)
						.Clipping(EWidgetClipping::ClipToBounds)
						.PaintPlaybackRangeArgs(FPaintPlaybackRangeArgs(FAppStyle::GetBrush("Sequencer.Timeline.PlayRange_L"), FAppStyle::GetBrush("Sequencer.Timeline.PlayRange_R"), 6.f))
					]

					// Overlay that draws the scrub position
					+SGridPanel::Slot(Column1, Row1, SGridPanel::Layer(20))
					.Padding(ResizeBarPadding)
					[
						SNew(SLGATimelineOverlay, TimeSliderControllerRef)
						.Visibility(EVisibility::HitTestInvisible)
						.DisplayScrubPosition(true)
						.DisplayTickLines(false)
						.Clipping(EWidgetClipping::ClipToBounds)
					]

					// play range slider
					+SGridPanel::Slot(Column1, Row3, SGridPanel::Layer(10))
					.Padding(ResizeBarPadding)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.FillWidth(1.0f)
						.VAlign(VAlign_Center)
						[
							SNew(SBorder)
							.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
							.BorderBackgroundColor(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f))
							.Clipping(EWidgetClipping::ClipToBounds)
							.Padding(0)
							[
								BottomTimeRange
							]
						]
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.HAlign(HAlign_Center)
						.AutoWidth()
						.Padding(2.0f, 0.0f, 2.0f, 0.0f)
						[
							SNew(SButton)
							.Text(LOCTEXT("Timeline_clamp_range", "Clamp Timeline"))
							.ToolTipText(LOCTEXT("Timeline_resize_range_tips", "Resize timeline length to actual action's occupancy time."))
							.OnClicked(this, &SLGATimeline::ResizeTimline)
							.Content()
							[
								SNew(SImage)
								.Image(FLegoAbilityEditorStyle::GetBrush("LegoAbilityEditor.Timeline.ResizeToFit"))
							]
						]
					]
				]
				+SOverlay::Slot()
				[
					// track area virtual splitter overlay
					SNew(SLGATimelineSplitterOverlay)
					.Style(FLegoAbilityEditorStyle::Get(), "AnimTimeline.Outliner.Splitter")
					.Visibility(EVisibility::SelfHitTestInvisible)

					+ SSplitter::Slot()
					.Value(FillCoefficient_0)
					.OnSlotResized(SSplitter::FOnSlotResized::CreateSP(this, &SLGATimeline::OnColumnFillCoefficientChanged, 0))
					[
						SNew(SSpacer)
					]

					+ SSplitter::Slot()
					.Value(FillCoefficient_1)
					.OnSlotResized(SSplitter::FOnSlotResized::CreateSP(this, &SLGATimeline::OnColumnFillCoefficientChanged, 1))
					[
						SNew(SSpacer)
					]
				]
			]
		]
	];
}

FReply SLGATimeline::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		FWidgetPath WidgetPath = MouseEvent.GetEventPath() != nullptr ? *MouseEvent.GetEventPath() : FWidgetPath();

		const bool bCloseAfterSelection = true;
		FMenuBuilder MenuBuilder(bCloseAfterSelection, Model.Pin()->GetCommandList());

		MenuBuilder.BeginSection("TimelineOptions", LOCTEXT("TimelineOptions", "Timeline Options"));
		{
			MenuBuilder.AddSubMenu(
				LOCTEXT("TimeFormat", "Time Format"),
				LOCTEXT("TimeFormatTooltip", "Choose the format of times we display in the timeline"),
				FNewMenuDelegate::CreateLambda([](FMenuBuilder& InMenuBuilder)
				{
					InMenuBuilder.BeginSection("TimeFormat", LOCTEXT("TimeFormat", "Time Format"));
					{
						InMenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().DisplaySeconds);
						InMenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().DisplayFrames);
					}
					InMenuBuilder.EndSection();

					InMenuBuilder.BeginSection("TimelineAdditional", LOCTEXT("TimelineAdditional", "Additional Display"));
					{
						InMenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().DisplayPercentage);
						InMenuBuilder.AddMenuEntry(FLegoAbilityEditorTimelineCommands::Get().DisplaySecondaryFormat);
					}
					InMenuBuilder.EndSection();
				})
			);
		}
		MenuBuilder.EndSection();

		FSlateApplication::Get().PushMenu(SharedThis(this), WidgetPath, MenuBuilder.MakeWidget(), FSlateApplication::Get().GetCursorPos(), FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu));

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

TSharedRef<INumericTypeInterface<double>> SLGATimeline::GetNumericTypeInterface() const
{
	return NumericTypeInterface.ToSharedRef();
}

// FFrameRate::ComputeGridSpacing doesnt deal well with prime numbers, so we have a custom impl here
static bool ComputeGridSpacing(const FFrameRate& InFrameRate, float PixelsPerSecond, double& OutMajorInterval, int32& OutMinorDivisions, float MinTickPx, float DesiredMajorTickPx)
{
	// First try built-in spacing
	bool bResult = InFrameRate.ComputeGridSpacing(PixelsPerSecond, OutMajorInterval, OutMinorDivisions, MinTickPx, DesiredMajorTickPx);
	if (!bResult || OutMajorInterval == 1.0)
	{
		if (PixelsPerSecond <= 0.f)
		{
			return false;
		}

		const int32 RoundedFPS = FMath::RoundToInt(InFrameRate.AsDecimal());

		if (RoundedFPS > 0)
		{
			// Showing frames
			TArray<int32, TInlineAllocator<10>> CommonBases;

			// Divide the rounded frame rate by 2s, 3s or 5s recursively
			{
				const int32 Denominators[] = { 2, 3, 5 };

				int32 LowestBase = RoundedFPS;
				for (;;)
				{
					CommonBases.Add(LowestBase);
	
					if (LowestBase % 2 == 0)      { LowestBase = LowestBase / 2; }
					else if (LowestBase % 3 == 0) { LowestBase = LowestBase / 3; }
					else if (LowestBase % 5 == 0) { LowestBase = LowestBase / 5; }
					else
					{ 
						int32 LowestResult = LowestBase;
						for (int32 Denominator : Denominators)
						{
							int32 Result = LowestBase / Denominator;
							if (Result > 0 && Result < LowestResult)
							{
								LowestResult = Result;
							}
						}

						if (LowestResult < LowestBase)
						{
							LowestBase = LowestResult;
						}
						else
						{
							break;
						}
					}
				}
			}

			Algo::Reverse(CommonBases);

			const int32 Scale     = FMath::CeilToInt(DesiredMajorTickPx / PixelsPerSecond * InFrameRate.AsDecimal());
			const int32 BaseIndex = FMath::Min(Algo::LowerBound(CommonBases, Scale), CommonBases.Num()-1);
			const int32 Base      = CommonBases[BaseIndex];

			int32 MajorIntervalFrames = FMath::CeilToInt(Scale / float(Base)) * Base;
			OutMajorInterval  = MajorIntervalFrames * InFrameRate.AsInterval();

			// Find the lowest number of divisions we can show that's larger than the minimum tick size
			OutMinorDivisions = 0;
			for (int32 DivIndex = 0; DivIndex < BaseIndex; ++DivIndex)
			{
				if (Base % CommonBases[DivIndex] == 0)
				{
					int32 MinorDivisions = MajorIntervalFrames/CommonBases[DivIndex];
					if (OutMajorInterval / MinorDivisions * PixelsPerSecond >= MinTickPx)
					{
						OutMinorDivisions = MinorDivisions;
						break;
					}
				}
			}
		}
	}

	return OutMajorInterval != 0;
}

bool SLGATimeline::GetGridMetrics(float PhysicalWidth, double& OutMajorInterval, int32& OutMinorDivisions) const
{
	FSlateFontInfo SmallLayoutFont = FCoreStyle::GetDefaultFontStyle("Regular", 8);
	TSharedRef<FSlateFontMeasure> FontMeasureService = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();

	FFrameRate DisplayRate(FMath::RoundToInt(Model.Pin()->GetFrameRate()), 1);
	double BiggestTime = ViewRange.Get().GetUpperBoundValue();
	FString TickString = NumericTypeInterface->ToString((BiggestTime * DisplayRate).FrameNumber.Value);
	FVector2D MaxTextSize = FontMeasureService->Measure(TickString, SmallLayoutFont);

	static float MajorTickMultiplier = 2.f;

	float MinTickPx = MaxTextSize.X + 5.f;
	float DesiredMajorTickPx = MaxTextSize.X * MajorTickMultiplier;

	if (PhysicalWidth > 0)
	{
		return ComputeGridSpacing(
			DisplayRate,
			PhysicalWidth / ViewRange.Get().Size<double>(),
			OutMajorInterval,
			OutMinorDivisions,
			MinTickPx,
			DesiredMajorTickPx);
	}

	return false;
}

TSharedPtr<ITimeSliderController> SLGATimeline::GetTimeSliderController() const 
{ 
	return TimeSliderController; 
}

void SLGATimeline::OnOutlinerSearchChanged(const FText& Filter)
{
	FilterText = Filter;

	Outliner->RefreshFilter();
}

void SLGATimeline::OnColumnFillCoefficientChanged(float FillCoefficient, int32 ColumnIndex)
{
	ColumnFillCoefficients[ColumnIndex] = FillCoefficient;
}

void SLGATimeline::HandleKeyComplete()
{
	Model.Pin()->RefreshTracks();
}

void SLGATimeline::HandleScrubPositionChanged(FFrameTime NewScrubPosition, bool bIsScrubbing, bool bEvaluate)
{
	Model.Pin()->SetScrubPosition(NewScrubPosition);
}

double SLGATimeline::GetSpinboxDelta() const
{
	return FFrameRate(Model.Pin()->GetTickResolution(), 1).AsDecimal() * FFrameRate(FMath::RoundToInt(Model.Pin()->GetFrameRate()), 1).AsInterval();
}

void SLGATimeline::SetPlayTime(double InFrameTime)
{
	//if (UAnimSingleNodeInstance* PreviewInstance = GetPreviewInstance())
	//{
	//	PreviewInstance->SetPlaying(false);
	//	PreviewInstance->SetPosition(InFrameTime / (double)Model.Pin()->GetTickResolution());
	//}
}

FReply SLGATimeline::ResizeTimline()
{
	Model.Pin()->ResizeTimelineToActions();

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE

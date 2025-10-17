// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineTimingPanel.h"
#include "LGATimelineModelBase.h"
#include "Actions/LGAAction.h"
#include "Fonts/FontMeasure.h"
#include "FrameNumberDisplayFormat.h"
#include "Framework/Application/SlateApplication.h"
#include "Preferences/PersonaOptions.h"
#include "SLGATimelineTimingTrack.h"
#include "Styling/CoreStyle.h"
#include "LegoAbilityEditorSettings.h"
#include "LGATimeline.h"
#include "Timeline/LGATimelineModel.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SToolTip.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "AnimTimingPanel"

namespace AnimTimingConstants
{
	static const float DefaultNodeSize = 18.0f;
	static const int32 FontSize = 10;
}

class SLGATimingNodeTooltip : public SToolTip
{
public:
	void Construct(const FArguments& InArgs, const TSharedRef<FLGATimingRelevantElementBase>& InElement)
	{
		Element = InElement;
		DescriptionBox = SNew(SVerticalBox);

		FArguments Args = InArgs;
		Args._TextMargin = FMargin(1.0f);
		Args._BorderImage = FAppStyle::GetBrush("ContentBrowser.TileViewToolTip.ToolTipBorder");
		Args._Content.Widget =
			SNew(SBorder)
			.Padding(3)
			.BorderImage(FAppStyle::GetBrush("ContentBrowser.TileViewTooltip.NonContentBorder"))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0, 0, 0, 3)
				[
					SNew(SBorder)
					.Padding(6)
					.BorderImage(FAppStyle::GetBrush("ContentBrowser.TileViewTooltip.ContentBorder"))
					[
						SNew(SBox)
						.HAlign(HAlign_Left)
						[
							SNew(STextBlock)
							.Text(FText::FromName(Element->GetTypeName()))
							.Font(FAppStyle::GetFontStyle("ContentBrowser.TileViewTooltip.NameFont"))
						]
					]
				]

				+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(SBorder)
						.Padding(3)
						.BorderImage(FAppStyle::GetBrush("ContentBrowser.TileViewTooltip.ContentBorder"))
						[
							DescriptionBox.ToSharedRef()
						]
					]
				]
			];

		SToolTip::Construct(Args);
	}

	virtual void OnOpening() override
	{
		DescriptionBox->ClearChildren();

		TMap<FString, FText> DescriptionItems;
		Element->GetDescriptionItems(DescriptionItems);
		for (TPair<FString, FText> ItemPair : DescriptionItems)
		{
			DescriptionBox->AddSlot()
				.AutoHeight()
				.Padding(0, 0, 3, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(STextBlock)
						.Text(FText::Format(LOCTEXT("Item", "{0}: "), FText::FromString(ItemPair.Key)))
						.ColorAndOpacity(FSlateColor::UseSubduedForeground())
					]

					+SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(STextBlock)
						.Text(ItemPair.Value)
						.ColorAndOpacity(FSlateColor::UseForeground())
					]
				];
		}
	}

	TSharedPtr<SVerticalBox> DescriptionBox;
	TSharedPtr<FLGATimingRelevantElementBase> Element;
};

void SLGATimingNode::Construct(const FArguments& InArgs)
{
	Element = InArgs._InElement;

	const FSlateBrush* StyleInfo = FAppStyle::GetBrush(TEXT("SpecialEditableTextImageNormal"));
	static FSlateFontInfo LabelFont = FCoreStyle::GetDefaultFontStyle("Regular", AnimTimingConstants::FontSize);

	UPersonaOptions* EditorOptions = UPersonaOptions::StaticClass()->GetDefaultObject<UPersonaOptions>();
	check(EditorOptions);

	this->ChildSlot
	[
		SNew(SBorder)
		.BorderImage(StyleInfo)
		.BorderBackgroundColor(EditorOptions->NotifyTimingNodeColor)
		[
			SNew(STextBlock)
			.Justification(ETextJustify::Center)
			.Text(FText::AsNumber(Element->TriggerIdx))
			.Font(LabelFont)
			.ColorAndOpacity(FSlateColor(FLinearColor::Black))
		]
	];

	if (InArgs._bUseTooltip)
	{
		SetToolTip(SNew(SLGATimingNodeTooltip, Element.ToSharedRef()));
	}
}

FVector2D SLGATimingNode::ComputeDesiredSize(float) const
{
	// Desired height is always the same (a little less than the track height) but the width depends on the text we display
	const TSharedRef<FSlateFontMeasure> FontMeasureService = FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
	static FSlateFontInfo LabelFont = FCoreStyle::GetDefaultFontStyle("Regular", 10);
	float TextWidth = FontMeasureService->Measure(FString::FromInt(Element->TriggerIdx), LabelFont).X;
	return FVector2D(FMath::Max(AnimTimingConstants::DefaultNodeSize, TextWidth), AnimTimingConstants::DefaultNodeSize);
}

void SLGATimingTrackNode::Construct(const FArguments& InArgs)
{
	TAttribute<float> TimeAttr = TAttribute<float>::Create(TAttribute<float>::FGetter::CreateSP(InArgs._Element.ToSharedRef(), &FLGATimingRelevantElementBase::GetElementTime));

	SLGATrackNode::Construct(SLGATrackNode::FArguments()
		.ViewInputMin(InArgs._ViewInputMin)
		.ViewInputMax(InArgs._ViewInputMax)
		.DataStartPos(TimeAttr)
		.NodeName(InArgs._NodeName)
		.CenterOnPosition(true)
		.AllowDrag(false)
		.OverrideContent()
		[
			SNew(SBox)
			.HAlign(HAlign_Center)
			[
				SNew(SLGATimingNode)
				.InElement(InArgs._Element)
				.bUseTooltip(InArgs._bUseTooltip)
			]
		]
	);
}

void SLGATimelineTimingPanel::Construct(const FArguments& InArgs, const TSharedRef<FLGATimelineModel>& InModel)
{
	WeakModel = InModel;

	SLGATimelineTrackPanel::Construct(SLGATimelineTrackPanel::FArguments()
		.WidgetWidth(InArgs._WidgetWidth)
		.ViewInputMin(InArgs._ViewInputMin)
		.ViewInputMax(InArgs._ViewInputMax)
		.InputMin(InArgs._InputMin)
		.InputMax(InArgs._InputMax)
		.OnSetInputViewRange(InArgs._OnSetInputViewRange));

	this->ChildSlot
	[
		SAssignNew(PanelArea, SBorder)
		.BorderImage(FAppStyle::GetBrush("NoBorder"))
		.Padding(0.0f)
		.ColorAndOpacity(FLinearColor::White)
	];

	Update();

	TracksChangedDelegateHandle = InModel->OnTracksChanged().Add(FSimpleDelegate::CreateSP(this, &SLGATimelineTimingPanel::RefreshTrackNodes));
}

SLGATimelineTimingPanel::~SLGATimelineTimingPanel()
{
	if (WeakModel.IsValid())
	{
		WeakModel.Pin()->OnTracksChanged().Remove(TracksChangedDelegateHandle);
	}
}

void SLGATimelineTimingPanel::Update()
{
	TSharedPtr<SVerticalBox> TimingSlots;
	PanelArea->SetContent(SAssignNew(TimingSlots, SVerticalBox));

	TimingSlots->AddSlot()
		.AutoHeight()
		.VAlign(VAlign_Center)
		[
			SAssignNew(Track, SLGATimelineTimingTrack)
			.ViewInputMin(ViewInputMin)
			.ViewInputMax(ViewInputMax)
			.TrackMinValue(InputMin)
			.TrackMaxValue(InputMax)
			.TrackNumDiscreteValues(WeakModel.Pin()->GetAbilityTimeline()->GetNumberOfFrames())
		];

	RefreshTrackNodes();
}

void SLGATimelineTimingPanel::RefreshTrackNodes()
{
	Elements.Empty();
	GetTimingRelevantElements(WeakModel.Pin()->GetAbilityTimeline(), Elements);

	Track->ClearTrack();

	int32 NumElements = Elements.Num();
	for (int32 ElementIdx = 0; ElementIdx < NumElements; ++ElementIdx)
	{
		TSharedPtr<FLGATimingRelevantElementBase> Element = Elements[ElementIdx];
		if (WeakModel.Pin()->IsTimingElementDisplayEnabled(Element->GetType()))
		{
			Track->AddTrackNode(
				SNew(SLGATimingTrackNode)
				.ViewInputMin(ViewInputMin)
				.ViewInputMax(ViewInputMax)
				.NodeName(FString::FromInt(ElementIdx + 1))
				.Element(Element)
			);
		}
	}
}

bool SLGATimelineTimingPanel::IsElementDisplayEnabled(ELGATimingElementType::Type ElementType) const
{
	return WeakModel.Pin()->IsTimingElementDisplayEnabled(ElementType);
}

void SLGATimelineTimingPanel::OnElementDisplayEnabledChanged(ELGATimingElementType::Type ElementType)
{
	WeakModel.Pin()->ToggleTimingElementDisplayEnabled(ElementType);
	Update();
}

ECheckBoxState SLGATimelineTimingPanel::IsElementDisplayChecked(ELGATimingElementType::Type ElementType) const
{
	return WeakModel.Pin()->IsTimingElementDisplayEnabled(ElementType) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

EVisibility SLGATimelineTimingPanel::IsElementDisplayVisible(ELGATimingElementType::Type ElementType) const
{
	return WeakModel.Pin()->IsTimingElementDisplayEnabled(ElementType) ? EVisibility::Visible : EVisibility::Hidden;
}

void SLGATimelineTimingPanel::GetTimingRelevantElements(ULGATimeline* Timeline, TArray<TSharedPtr<FLGATimingRelevantElementBase>>& Elements)
{
	if (Timeline)
	{
		// Grab actions
		for (int32 ActionIdx = 0 ; ActionIdx < Timeline->Actions.Num(); ++ActionIdx)
		{
			const FLGAActionEvent& Event = Timeline->Actions[ActionIdx];
			Elements.Add(TSharedPtr<FLGATimingRelevantElementBase>(new FLGATimingRelevantElement_Action(Timeline, ActionIdx)));

			if (Event.Action && !Event.Action->IsSingleFrame())
			{
				Elements.Add(TSharedPtr<FLGATimingRelevantElementBase>(new FLGATimingRelevantElement_ActionEnd(Timeline, ActionIdx)));
			}
		}

		// Sort everything and give them trigger orders
		Elements.Sort([](const TSharedPtr<FLGATimingRelevantElementBase>& A, const TSharedPtr<FLGATimingRelevantElementBase>& B)
		{
			return A->Compare(*B);
		});

		int32 NumElements = Elements.Num();
		for (int32 Idx = 0 ; Idx < NumElements; ++Idx)
		{
			Elements[Idx]->TriggerIdx = Idx;
		}
	}
}

FName FLGATimingRelevantElement_Action::GetTypeName()
{
	switch (GetType())
	{
	case ELGATimingElementType::InstantAction:
		return FName("Instant Action");
	case ELGATimingElementType::DurationActionBegin:
		return FName("Duration Action (Begin)");
	default:
		return FName("Unknown");
	}
}

float FLGATimingRelevantElement_Action::GetElementTime() const
{
	return Timeline->Actions[ActionIndex].GetStartTime();
}

ELGATimingElementType::Type FLGATimingRelevantElement_Action::GetType() const
{
	const FLGAActionEvent& Event = Timeline->Actions[ActionIndex];
	if (!Event.Action) return ELGATimingElementType::InstantAction;
	return Event.Action->IsSingleFrame() ? ELGATimingElementType::InstantAction : ELGATimingElementType::DurationActionBegin;
}

FLGAActionEvent* FLGATimingRelevantElement_Action::GetActionEvent() const
{
	return &Timeline->Actions[ActionIndex];
}

void FLGATimingRelevantElement_Action::GetDescriptionItems(TMap<FString, FText>& Items) const
{
	FNumberFormattingOptions NumberOptions;
	NumberOptions.MinimumFractionalDigits = 3;

	const FLGAActionEvent& Event = Timeline->Actions[ActionIndex];
	Items.Add(LOCTEXT("ActionName", "Name").ToString(), FText::FromName(Event.Action? Event.Action->GetFName() : "None"));

	if (GetDefault<ULegoAbilityEditorSettings>()->TimelineDisplayFormat == EFrameNumberDisplayFormats::Frames)
	{
		Items.Add(LOCTEXT("ActionTriggerFrame", "Trigger Frame").ToString(), FText::Format(LOCTEXT("ActionTriggerFrame_Val", "{0}"), FText::AsNumber(Timeline->GetFrameAtTime(Event.GetStartTime()))));
	}
	else
	{
		Items.Add(LOCTEXT("ActionTriggerTime", "Trigger Time").ToString(), FText::Format(LOCTEXT("ActionTriggerTime_Val", "{0}s"), FText::AsNumber(Event.GetStartTime(), &NumberOptions)));
	}	

	// +1 as we start at 1 when showing tracks to the user
	Items.Add(LOCTEXT("TrackIdx", "Track").ToString(), FText::AsNumber(Event.TrackIndex + 1));

	if (Event.Action && !Event.Action->IsSingleFrame())
	{
		Items.Add(LOCTEXT("ActionDuration", "Duration").ToString(), FText::Format(LOCTEXT("ActionDuration_Val", "{0}s"), FText::AsNumber(Event.GetDuration(), &NumberOptions)));
	}
}

int32 FLGATimingRelevantElement_Action::GetElementSortPriority() const
{
	return Timeline->Actions[ActionIndex].TrackIndex;
}

float FLGATimingRelevantElement_ActionEnd::GetElementTime() const
{
	return Timeline->Actions[ActionIndex].GetEndTime();
}

#undef LOCTEXT_NAMESPACE

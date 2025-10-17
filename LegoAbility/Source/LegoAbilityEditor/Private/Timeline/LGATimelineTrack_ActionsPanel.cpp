// Copyright S-Game, Inc. All Rights Reserved.

#include "LGATimelineTrack_ActionsPanel.h"
#include "LGATimelineModel.h"
#include "LGATimelineTrack_Actions.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "PersonaUtils.h"
#include "SLGAActionPanel.h"
#include "SLGATimelineOutlinerItem.h"
#include "ScopedTransaction.h"
#include "LegoAbilityEditorCommands.h"
#include "LGATimeline.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"

#define LOCTEXT_NAMESPACE "FAnimTimelineTrack_NotifiesPanel"

const float FLGATimelineTrack_ActionsPanel::NotificationTrackHeight = 24.0f;

FLGATimelineTrack_ActionsPanel::FLGATimelineTrack_ActionsPanel(const TSharedRef<FLGATimelineModelBase>& InModel)
	: FLGATimelineTrack(FText::GetEmpty(), FText::GetEmpty(), InModel)
	, PendingRenameTrackIndex(INDEX_NONE)
{
	SetHeight((float)InModel->GetAbilityTimeline()->AbilityActionTracks.Num() * NotificationTrackHeight);
}

TSharedRef<SWidget> FLGATimelineTrack_ActionsPanel::GenerateContainerWidgetForTimeline()
{
	AnimNotifyPanel = SNew(SLGAActionPanel, GetModel())
		.InputMin(this, &FLGATimelineTrack_ActionsPanel::GetMinInput)
		.InputMax(this, &FLGATimelineTrack_ActionsPanel::GetMaxInput)
		.ViewInputMin(this, &FLGATimelineTrack_ActionsPanel::GetViewMinInput)
		.ViewInputMax(this, &FLGATimelineTrack_ActionsPanel::GetViewMaxInput)
		.OnGetScrubValue(this, &FLGATimelineTrack_ActionsPanel::GetScrubValue)
		.OnSelectionChanged(this, &FLGATimelineTrack_ActionsPanel::SelectObjects)
		.OnSetInputViewRange(this, &FLGATimelineTrack_ActionsPanel::OnSetInputViewRange)
		.OnSnapPosition(&GetModel().Get(), &FLGATimelineModelBase::Snap)
		.OnGetTimingNodeVisibility(this, &FLGATimelineTrack_ActionsPanel::OnGetTimingNodeVisibility)
		.OnNotifiesChanged_Lambda([this]()
		{
			Update();
			GetModel()->OnTracksChanged().Broadcast();
		})
		.OnActionHandleBeingDragged_Lambda([this](TSharedPtr<SLGAActionNode> NotifyNode, const FPointerEvent& Event, ELGAActionStateHandleHit::Type Handle, float Time)
		{
			if (Event.IsShiftDown())
			{
				const FFrameTime FrameTime = FFrameTime::FromDecimal(Time * (double)GetModel()->GetTickResolution());
				GetModel()->SetScrubPosition(FrameTime);
			}

			/*if (!StatusBarMessageHandle.IsValid())
			{
				if (UStatusBarSubsystem* StatusBarSubsystem = GEditor->GetEditorSubsystem<UStatusBarSubsystem>())
				{
					StatusBarMessageHandle = StatusBarSubsystem->PushStatusBarMessage(AnimationEditorStatusBarName,
						LOCTEXT("AutoscrubNotifyStateHandle", "Hold SHIFT while dragging a notify state Begin or End handle to auto scrub the timeline."));
				}
			}*/
		})
		.OnActionNodesBeingDragged_Lambda([this](const TArray<TSharedPtr<SLGAActionNode>>& NotifyNodes, const class FDragDropEvent& Event, float DragXPosition, float DragTime)
			{
				if (Event.IsShiftDown())
				{
					const FFrameTime FrameTime = FFrameTime::FromDecimal(DragTime * (double)GetModel()->GetTickResolution());
					GetModel()->SetScrubPosition(FrameTime);
				}

				/*if (!StatusBarMessageHandle.IsValid())
				{
					if (UStatusBarSubsystem* StatusBarSubsystem = GEditor->GetEditorSubsystem<UStatusBarSubsystem>())
					{
						StatusBarMessageHandle = StatusBarSubsystem->PushStatusBarMessage(AnimationEditorStatusBarName,
							LOCTEXT("AutoscrubNotify", "Hold SHIFT while dragging a notify to auto scrub the timeline."));
					}
				}*/
			});

	AnimNotifyPanel->Update();

	return AnimNotifyPanel.ToSharedRef();
}

TSharedRef<SWidget> FLGATimelineTrack_ActionsPanel::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedRef<SWidget> Widget = 
		SNew(SHorizontalBox)
		.ToolTipText(this, &FLGATimelineTrack::GetToolTipText)
		+ SHorizontalBox::Slot()
		[
			SAssignNew(OutlinerWidget, SVerticalBox)
		];

	RefreshOutlinerWidget();

	return Widget;
}

void FLGATimelineTrack_ActionsPanel::RefreshOutlinerWidget()
{
	OutlinerWidget->ClearChildren();

	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	for (int32 TrackIndex = 0; TrackIndex < Timeline->AbilityActionTracks.Num(); ++TrackIndex)
	{
		TSharedPtr<SBox> SlotBox;
		TSharedPtr<SHorizontalBox> HorizontalBox;
		TSharedPtr<SInlineEditableTextBlock> InlineEditableTextBlock;

		OutlinerWidget->AddSlot()
			.AutoHeight()
			[
				SAssignNew(SlotBox, SBox)
				.HeightOverride(NotificationTrackHeight)
			];

		SlotBox->SetContent(
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Sequencer.Section.BackgroundTint"))
			.BorderBackgroundColor(FLegoAbilityEditorStyle::GetColor("AnimTimeline.Outliner.ItemColor"))
			[
				SAssignNew(HorizontalBox, SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(30.0f, 0.0f, 0.0f, 0.0f)
				[
					SAssignNew(InlineEditableTextBlock, SInlineEditableTextBlock)
					.Text(this, &FLGATimelineTrack_ActionsPanel::GetTrackName, TrackIndex)
					.IsSelected(FIsSelected::CreateLambda([]() { return true; }))
					.OnTextCommitted(this, &FLGATimelineTrack_ActionsPanel::OnCommitTrackName, TrackIndex)
				]
			]
		);

		HorizontalBox->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Right)
			.Padding(OutlinerRightPadding, 1.0f)
			[
				PersonaUtils::MakeTrackButton(LOCTEXT("AddTrackButtonText", "Track"), FOnGetContent::CreateSP(this, &FLGATimelineTrack_ActionsPanel::BuildNotifiesPanelSubMenu, TrackIndex), MakeAttributeSP(SlotBox.Get(), &SWidget::IsHovered))
			];

		if (PendingRenameTrackIndex == TrackIndex)
		{
			TWeakPtr<SInlineEditableTextBlock> WeakInlineEditableTextBlock = InlineEditableTextBlock;
			InlineEditableTextBlock->RegisterActiveTimer(0.0f, FWidgetActiveTimerDelegate::CreateSP(this, &FLGATimelineTrack_ActionsPanel::HandlePendingRenameTimer, WeakInlineEditableTextBlock));
		}
	}
}

EActiveTimerReturnType FLGATimelineTrack_ActionsPanel::HandlePendingRenameTimer(double InCurrentTime, float InDeltaTime, TWeakPtr<SInlineEditableTextBlock> InInlineEditableTextBlock)
{
	if (InInlineEditableTextBlock.IsValid())
	{
		InInlineEditableTextBlock.Pin()->EnterEditingMode();
	}

	PendingRenameTrackIndex = INDEX_NONE;

	return EActiveTimerReturnType::Stop;
}

TSharedRef<SWidget> FLGATimelineTrack_ActionsPanel::BuildNotifiesPanelSubMenu(int32 InTrackIndex)
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	FMenuBuilder MenuBuilder(true, GetModel()->GetCommandList());

	MenuBuilder.BeginSection("NotifyTrack", LOCTEXT("NotifyTrackMenuSection", "Notify Track"));
	{
		MenuBuilder.AddMenuEntry(
			FLegoAbilityEditorTimelineCommands::Get().InsertActionTrack->GetLabel(),
			FLegoAbilityEditorTimelineCommands::Get().InsertActionTrack->GetDescription(),
			FLegoAbilityEditorTimelineCommands::Get().InsertActionTrack->GetIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FLGATimelineTrack_ActionsPanel::InsertTrack, InTrackIndex)
			)
		);

		if (Timeline->AbilityActionTracks.Num() > 1)
		{
			MenuBuilder.AddMenuEntry(
				FLegoAbilityEditorTimelineCommands::Get().RemoveActionTrack->GetLabel(),
				FLegoAbilityEditorTimelineCommands::Get().RemoveActionTrack->GetDescription(),
				FLegoAbilityEditorTimelineCommands::Get().RemoveActionTrack->GetIcon(),
				FUIAction(
					FExecuteAction::CreateSP(this, &FLGATimelineTrack_ActionsPanel::RemoveTrack, InTrackIndex)
				)
			);
		}
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

void FLGATimelineTrack_ActionsPanel::InsertTrack(int32 InTrackIndexToInsert)
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	FScopedTransaction Transaction(LOCTEXT("InsertActionTrack", "Insert Action Track"));
	Timeline->Modify();

	// before insert, make sure everything behind is fixed
	for (int32 TrackIndex = InTrackIndexToInsert; TrackIndex < Timeline->AbilityActionTracks.Num(); ++TrackIndex)
	{
		FLGAActionTrack& Track = Timeline->AbilityActionTracks[TrackIndex];

		const int32 NewTrackIndex = TrackIndex + 1;

		for (FLGAActionEvent* Action : Track.Actions)
		{
			// fix notifies indices
			Action->TrackIndex = NewTrackIndex;
		}
	}

	FLGAActionTrack NewItem;
	NewItem.TrackName = FLGATimelineTrack_Actions::GetNewTrackName(Timeline);
	NewItem.TrackColor = FLinearColor::White;

	Timeline->AbilityActionTracks.Insert(NewItem, InTrackIndexToInsert);

	// Request a rename on rebuild
	PendingRenameTrackIndex = InTrackIndexToInsert;

	Update();
}

void FLGATimelineTrack_ActionsPanel::RemoveTrack(int32 InTrackIndexToRemove)
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	if (Timeline->AbilityActionTracks.IsValidIndex(InTrackIndexToRemove))
	{
		if (Timeline->AbilityActionTracks[InTrackIndexToRemove].Actions.Num() == 0)
		{
			FScopedTransaction Transaction(LOCTEXT("RemoveActionTrack", "Remove Action Track"));
			Timeline->Modify();

			// before insert, make sure everything behind is fixed
			for (int32 TrackIndex = InTrackIndexToRemove + 1; TrackIndex < Timeline->AbilityActionTracks.Num(); ++TrackIndex)
			{
				FLGAActionTrack& Track = Timeline->AbilityActionTracks[TrackIndex];
				const int32 NewTrackIndex = TrackIndex - 1;

				for (FLGAActionEvent* Action : Track.Actions)
				{
					// fix notifies indices
					Action->TrackIndex = NewTrackIndex;
				}
			}

			Timeline->AbilityActionTracks.RemoveAt(InTrackIndexToRemove);

			Update();
		}
	}
}

void FLGATimelineTrack_ActionsPanel::Update()
{
	SetHeight((float)GetModel()->GetAbilityTimeline()->AbilityActionTracks.Num() * NotificationTrackHeight);

	if (OutlinerWidget.IsValid())
	{
		RefreshOutlinerWidget();
	}

	if (AnimNotifyPanel.IsValid())
	{
		AnimNotifyPanel->Update();
	}
}

FText FLGATimelineTrack_ActionsPanel::GetTrackName(int32 TrackIndex) const
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	if (Timeline && Timeline->AbilityActionTracks.IsValidIndex(TrackIndex))
	{
		return FText::FromName(Timeline->AbilityActionTracks[TrackIndex].TrackName);
	}
	else
	{
		return FText::GetEmpty();
	}
}

void FLGATimelineTrack_ActionsPanel::OnCommitTrackName(const FText& InText, ETextCommit::Type CommitInfo, int32 TrackIndex)
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	if (Timeline->AbilityActionTracks.IsValidIndex(TrackIndex))
	{
		FScopedTransaction Transaction(FText::Format(LOCTEXT("RenameActionTrack", "Rename Action Track to '{0}'"), InText));
		Timeline->Modify();

		FText TrimText = FText::TrimPrecedingAndTrailing(InText);
		Timeline->AbilityActionTracks[TrackIndex].TrackName = FName(*TrimText.ToString());
	}
}

EVisibility FLGATimelineTrack_ActionsPanel::OnGetTimingNodeVisibility(ELGATimingElementType::Type ElementType) const
{
	return StaticCastSharedRef<FLGATimelineModel>(GetModel())->IsActionsTimingElementDisplayEnabled(ElementType) ? EVisibility::Visible : EVisibility::Hidden;
}

#undef LOCTEXT_NAMESPACE
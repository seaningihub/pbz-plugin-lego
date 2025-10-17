// Copyright Epic Games, Inc. All Rights Reserved.

#include "Timeline/LGATimelineTrack_Curves.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SSearchBox.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Input/STextEntryPopup.h"
#include "Framework/Application/SlateApplication.h"
#include "ScopedTransaction.h"
#include "Timeline/SLGATimelineOutlinerItem.h"
#include "SListViewSelectorDropdownMenu.h"
#include "LegoAbilityEditorStyle.h"
#include "LGATimeline.h"
#include "PersonaUtils.h"
#include "LegoAbilityEditorCommands.h"
#include "Preferences/PersonaOptions.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "FLGATimelineTrack_Actions"


FLGATimelineTrack_Curves::FLGATimelineTrack_Curves(const TSharedRef<FLGATimelineModelBase>& InModel)
	: FLGATimelineTrack(LOCTEXT("CurvesRootTrackLabel", "Curves"), LOCTEXT("CurvesRootTrackToolTip", "Curve data contained in this asset"), InModel)
{
}

TSharedRef<SWidget> FLGATimelineTrack_Curves::GenerateContainerWidgetForOutliner(const TSharedRef<SLGATimelineOutlinerItem>& InRow)
{
	TSharedPtr<SBorder> OuterBorder;
	TSharedPtr<SHorizontalBox> InnerHorizontalBox;
	OutlinerWidget = GenerateStandardOutlinerWidget(InRow, false, OuterBorder, InnerHorizontalBox);

	OuterBorder->SetBorderBackgroundColor(FLegoAbilityEditorStyle::GetColor("AnimTimeline.Outliner.HeaderColor"));

	InnerHorizontalBox->AddSlot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Left)
		.Padding(2.0f, 1.0f)
		.AutoWidth()
		[
			SNew(STextBlock)
			.TextStyle(&FLegoAbilityEditorStyle::Get()->GetWidgetStyle<FTextBlockStyle>("AnimTimeline.Outliner.Label"))
			.Text(this, &FLGATimelineTrack_Curves::GetLabel)
			.HighlightText(InRow->GetHighlightText())
		];

	InnerHorizontalBox->AddSlot()
		.FillWidth(1.0f)
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(5.0f, 1.0f)
		[
			SNew(STextBlock)
			.TextStyle(&FAppStyle::Get().GetWidgetStyle<FTextBlockStyle>("TinyText"))
			.Text_Lambda([this]()
			{ 
				ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
				return FText::Format(LOCTEXT("CurveCountFormat", "({0})"), FText::AsNumber(Timeline->FloatCurves.Num()));
			})
		];

	
	{
		InnerHorizontalBox->AddSlot()
			.AutoWidth()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(OutlinerRightPadding, 1.0f)
			[
				PersonaUtils::MakeTrackButton(LOCTEXT("EditCurvesButtonText", "Curves"), FOnGetContent::CreateSP(this, &FLGATimelineTrack_Curves::BuildCurvesSubMenu), MakeAttributeSP(this, &FLGATimelineTrack_Curves::IsHovered))
			];
	}

	return OutlinerWidget.ToSharedRef();
}

void FLGATimelineTrack_Curves::DeleteAllCurves()
{
	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
	if (Timeline)
	{
		Timeline->FloatCurves.Empty();
		Timeline->PostEditChange();
		Timeline->MarkPackageDirty();

		GetModel()->RefreshTracks();
	}
}

TSharedRef<SWidget> FLGATimelineTrack_Curves::BuildCurvesSubMenu()
{
	FMenuBuilder MenuBuilder(true, GetModel()->GetCommandList());

	MenuBuilder.BeginSection("Curves", LOCTEXT("CurvesMenuSection", "Curves"));
	{
		MenuBuilder.AddMenuEntry(
			FLegoAbilityEditorTimelineCommands::Get().AddCurve->GetLabel(),
			FLegoAbilityEditorTimelineCommands::Get().AddCurve->GetDescription(),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateSP(this, &FLGATimelineTrack_Curves::CreateNewCurveClicked))
		);

		ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
		if(Timeline->FloatCurves.Num() > 0)
		{
			MenuBuilder.AddMenuEntry(
				FLegoAbilityEditorTimelineCommands::Get().RemoveAllCurves->GetLabel(),
				FLegoAbilityEditorTimelineCommands::Get().RemoveAllCurves->GetDescription(),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateSP(this, &FLGATimelineTrack_Curves::DeleteAllCurves))
			);
		}
	}

	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("Options", LOCTEXT("OptionsMenuSection", "Options"));
	{
		MenuBuilder.AddMenuEntry(
			FLegoAbilityEditorTimelineCommands::Get().ShowCurveKeys->GetLabel(),
			FLegoAbilityEditorTimelineCommands::Get().ShowCurveKeys->GetDescription(),
			FLegoAbilityEditorTimelineCommands::Get().ShowCurveKeys->GetIcon(),
			FUIAction(
				FExecuteAction::CreateSP(this, &FLGATimelineTrack_Curves::HandleShowCurvePoints),
				FCanExecuteAction(),
				FIsActionChecked::CreateSP(this, &FLGATimelineTrack_Curves::IsShowCurvePointsEnabled)
			),
			NAME_None,
			EUserInterfaceActionType::ToggleButton
		);
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}


void FLGATimelineTrack_Curves::CreateNewCurveClicked()
{
	TSharedRef<STextEntryPopup> TextEntry =
		SNew(STextEntryPopup)
		.Label(LOCTEXT("NewCurveEntryLabal", "Curve Name"))
		.OnTextCommitted(this, &FLGATimelineTrack_Curves::CreateTrack);

	FSlateApplication& SlateApp = FSlateApplication::Get();
	SlateApp.PushMenu(
		OutlinerWidget.ToSharedRef(),
		FWidgetPath(),
		TextEntry,
		SlateApp.GetCursorPos(),
		FPopupTransitionEffect::TypeInPopup
		);
}

void FLGATimelineTrack_Curves::CreateTrack(const FText& ComittedText, ETextCommit::Type CommitInfo)
{
	if ( CommitInfo == ETextCommit::OnEnter )
	{
		ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();
		if(Timeline && !ComittedText.IsEmpty())
		{
			const FScopedTransaction Transaction(LOCTEXT("TimelineCurve_AddTrack", "Add New Curve"));

			AddVariableCurve(FName(*ComittedText.ToString()));
		}

		FSlateApplication::Get().DismissAllMenus();
	}
}

void FLGATimelineTrack_Curves::AddVariableCurve(const FName& InCurveName)
{
	FScopedTransaction Transaction(LOCTEXT("AddCurve", "Add Curve"));

	ULGATimeline* Timeline = GetModel()->GetAbilityTimeline();

	if (Timeline->GetCurveByName(InCurveName))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("InvalidName"), FText::FromName(InCurveName));
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

	FFloatCurve NewFloatCurve = FFloatCurve(InCurveName, (int32)ERawCurveTrackTypes::RCT_Float);
	Timeline->FloatCurves.Add(NewFloatCurve);
	Timeline->PostEditChange();
	Timeline->MarkPackageDirty();

	GetModel()->RefreshTracks();
}

void FLGATimelineTrack_Curves::HandleShowCurvePoints()
{
	GetMutableDefault<UPersonaOptions>()->bTimelineDisplayCurveKeys = !GetDefault<UPersonaOptions>()->bTimelineDisplayCurveKeys;
}

bool FLGATimelineTrack_Curves::IsShowCurvePointsEnabled() const
{
	return GetDefault<UPersonaOptions>()->bTimelineDisplayCurveKeys;
}

#undef LOCTEXT_NAMESPACE

// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGATimelineListTabBody.h"
#include "Framework/Commands/GenericCommands.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/Kismet2NameValidators.h"
#include "Misc/TextFilter.h"
#include "ScopedTransaction.h"
#include "LegoAbility.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorStyle.h"
#include "LGATimeline.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Layout/SScrollBorder.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "Widgets/Text/SRichTextBlock.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SComboButton.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

bool VerifyTimelineRename(ULegoAbilityBlueprint* Blueprint, const FString& NewTimelineName, FText& OutErrorMessage)
{
	if (NewTimelineName != SlugStringForValidName(NewTimelineName))
	{
		FString InvalidCharacters = INVALID_OBJECTNAME_CHARACTERS;
		FString CurrentInvalidCharacter;
		FString FoundInvalidCharacters;

		// Create a string with all invalid characters found to output with the error message.
		for (int32 StringIndex = 0; StringIndex < InvalidCharacters.Len(); ++StringIndex)
		{
			CurrentInvalidCharacter = InvalidCharacters.Mid(StringIndex, 1);

			if (NewTimelineName.Contains(CurrentInvalidCharacter))
			{
				FoundInvalidCharacters += CurrentInvalidCharacter;
			}
		}

		OutErrorMessage = FText::Format(LOCTEXT("NameContainsInvalidCharacters", "The timeline name cannot contain the following characters:  {0}"), FText::FromString(FoundInvalidCharacters));
		return false;
	}

	FName NewTimelineNameAsName(*NewTimelineName);
	if (NewTimelineNameAsName.IsNone() || NewTimelineNameAsName == ULGATimeline::GetNullTimeline()->GetFName())
	{
		OutErrorMessage = LOCTEXT("NameIsIllegal", "The timeline name is illegal");
		return false;
	}

	if (FindObject<ULGATimeline>(Blueprint, *NewTimelineName, true))
	{
		OutErrorMessage = LOCTEXT("NameInUseByTimeline", "An timeline with this name already exists");
		return false;
	}

	FKismetNameValidator Validator(Blueprint);
	EValidatorResult ValidationResult = Validator.IsValid(NewTimelineName);

	if (ValidationResult != EValidatorResult::Ok)
	{
		FString ErrorString = FKismetNameValidator::GetErrorString(NewTimelineName, ValidationResult);
		OutErrorMessage = FText::FromString(ErrorString);
		return false;
	}

	return true;
}

class SAbilityTimelineListItem : public STableRow<TSharedPtr<FAbilityTimelineListItem>>
{
public:
	SLATE_BEGIN_ARGS(SAbilityTimelineListItem) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTableView, TSharedPtr<FLegoAbilityEditor> InAbilityEditor, TSharedPtr<FAbilityTimelineListItem> InListItem)
	{
		ListItem = InListItem;
		AbilityEditor = InAbilityEditor;

		STableRow<TSharedPtr<FAbilityTimelineListItem>>::Construct(
			STableRow<TSharedPtr<FAbilityTimelineListItem>>::FArguments()
			.Padding(FMargin(3.0f, 2.0f))
			.Content()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SAssignNew(InlineTextBlock, SInlineEditableTextBlock)
					.Font(FCoreStyle::Get().GetFontStyle("NormalFont"))
					.Text(this, &SAbilityTimelineListItem::GetTimelineNameText)
					.OnVerifyTextChanged(this, &SAbilityTimelineListItem::OnVerifyNameTextChanged)
					.OnTextCommitted(this, &SAbilityTimelineListItem::OnNameTextCommitted)
					.IsSelected(this, &SAbilityTimelineListItem::IsSelectedExclusively)
				]

				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				.FillWidth(1)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SCheckBox)
						.IsChecked(this, &SAbilityTimelineListItem::GetCheckState_AutoPlay)
						.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_AutoPlay)
						.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should be played automatically with ability activation."))
						.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
						.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
						.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
						.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
						.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
						.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SCheckBox)
						.IsChecked(this, &SAbilityTimelineListItem::GetCheckState_Loop)
						.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_Loop)
						.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should loop when it reaches the end"))
						.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
						.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
						.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
						.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
						.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
						.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SCheckBox)
						.IsChecked(this, &SAbilityTimelineListItem::GetCheckState_StopAbility)
						.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_StopAbility)
						.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should end current ability it reaches the end"))
						.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
						.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
						.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
						.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
						.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
						.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
					]
				]
			],
			InOwnerTableView);
	}

	void BeginRename()
	{
		InlineTextBlock->EnterEditingMode();
	}

private:
	FText GetTimelineNameText() const
	{
		if (ListItem.IsValid())
		{
			return FText::FromName(ListItem.Pin()->Timeline->GetFName());
		}

		return FText::GetEmpty();
	}

	bool OnVerifyNameTextChanged(const FText& InText, FText& OutErrorMessage)
	{
		const FString& NewName = InText.ToString();
		ULGATimeline* Timeline = ListItem.Pin()->Timeline;

		if (Timeline->GetName() != NewName)
		{
			TSharedPtr<FLegoAbilityEditor> Editor = AbilityEditor.Pin();
			return Editor.IsValid() && VerifyTimelineRename(Editor->GetAbilityBlueprint(), NewName, OutErrorMessage);
		}

		return true;
	}

	void OnNameTextCommitted(const FText& InText, ETextCommit::Type CommitInfo)
	{
		ULGATimeline* Timeline = ListItem.Pin()->Timeline;
		ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

		// Name has already been checked in VerifyTimelineRename
		const FString& NewName = InText.ToString();
		const FName NewFName = *NewName;
		const FName OldFName = Timeline->GetFName();

		auto ValidateTimeline = [Blueprint](UBlueprint* InChildBP, const FName InVariableName, bool bValidatedVariable) {
			ULegoAbilityBlueprint* ChildAbilityBlueprint = Cast<ULegoAbilityBlueprint>(InChildBP);
			for (int32 TimelineIndex = 0; TimelineIndex < ChildAbilityBlueprint->AbilityTimelines.Num(); ++TimelineIndex)
			{
				ULGATimeline* TimelineTemplate = ChildAbilityBlueprint->AbilityTimelines[TimelineIndex];
				if (TimelineTemplate)
				{
					if (TimelineTemplate->GetFName() == InVariableName)
					{
						FName NewName = FBlueprintEditorUtils::FindUniqueKismetName(ChildAbilityBlueprint, TimelineTemplate->GetName());
						ULegoAbilityBlueprint::RenameTimeline(ChildAbilityBlueprint, TimelineTemplate->GetFName(), NewName);

						UE_LOG(LogBlueprint, Warning, TEXT("Blueprint %s (child of/implements %s) has a timeline with a conflicting name (%s). Changing to %s."), *ChildAbilityBlueprint->GetName(), *Blueprint->GetName(), *InVariableName.ToString(), *NewName.ToString());
						return true;
					}
				}
			}
			return false;
		};

		const bool bNewTimeline = ListItem.Pin()->bNewTimeline;
		if (!OldFName.IsEqual(NewFName) && !NewName.IsEmpty())
		{
			const FString NewNameStr = NewFName.ToString();
			const FString OldNameStr = OldFName.ToString();

			FText TransactionName = bNewTimeline ? LOCTEXT("NewTimeline", "New Timeline") : LOCTEXT("RenameTimeline", "Rename Timeline");
			{
				const FScopedTransaction Transaction(TransactionName);
				Timeline->Modify();
				Timeline->Rename(*NewNameStr, nullptr, REN_DontCreateRedirectors);

				if (bNewTimeline)
				{
					Blueprint->Modify();
					Blueprint->AbilityTimelines.Add(Timeline);
					ListItem.Pin()->bNewTimeline = false;
				}
			}

			FBlueprintEditorUtils::ReplaceVariableReferences(Blueprint, OldFName, NewFName);
			FBlueprintEditorUtils::ValidateBlueprintChildVariables(Blueprint, NewFName, ValidateTimeline);
			FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
		}

		else if (bNewTimeline)
		{
			const FScopedTransaction Transaction(LOCTEXT("NewTimeline", "New Timeline"));
			Blueprint->Modify();
			Blueprint->AbilityTimelines.Add(Timeline);
			ListItem.Pin()->bNewTimeline = false;

			FBlueprintEditorUtils::ValidateBlueprintChildVariables(Blueprint, NewFName, ValidateTimeline);
			FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
		}
	}

	ECheckBoxState GetCheckState_Loop() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->Timeline->bLooping ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}

	void OnCheckStateChanged_Loop(ECheckBoxState NewValue)
	{
		const FScopedTransaction Transaction(LOCTEXT("EditTimelineLooping", "Edit Timeline Looping"));
		ULGATimeline* Timeline = ListItem.Pin()->Timeline;
		Timeline->Modify();
		Timeline->bLooping = (NewValue == ECheckBoxState::Checked);
		if (Timeline->bLooping)
		{
			Timeline->bStopAbility = false;
		}

		FBlueprintEditorUtils::MarkBlueprintAsModified(AbilityEditor.Pin()->GetAbilityBlueprint());
	}

	ECheckBoxState GetCheckState_AutoPlay() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->Timeline->bAutoPlay ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}

	void OnCheckStateChanged_AutoPlay(ECheckBoxState NewValue)
	{
		const FScopedTransaction Transaction(LOCTEXT("EditTimelineLooping", "Edit Timeline Looping"));
		ULGATimeline* Timeline = ListItem.Pin()->Timeline;
		Timeline->Modify();
		Timeline->bAutoPlay = (NewValue == ECheckBoxState::Checked);

		ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
		for (ULGATimeline* OtherTimeline : Blueprint->AbilityTimelines)
		{
			if (OtherTimeline != Timeline && Timeline->bAutoPlay)
			{
				OtherTimeline->bAutoPlay = false;
			}
		}

		FBlueprintEditorUtils::MarkBlueprintAsModified(AbilityEditor.Pin()->GetAbilityBlueprint());
	}

	ECheckBoxState GetCheckState_StopAbility() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->Timeline->bStopAbility ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}

	void OnCheckStateChanged_StopAbility(ECheckBoxState NewValue)
	{
		const FScopedTransaction Transaction(LOCTEXT("EditTimelineLooping", "Edit Timeline Looping"));
		ULGATimeline* Timeline = ListItem.Pin()->Timeline;
		Timeline->Modify();
		Timeline->bStopAbility = (NewValue == ECheckBoxState::Checked);
		if (Timeline->bStopAbility)
		{
			Timeline->bLooping = false;
		}
		FBlueprintEditorUtils::MarkBlueprintAsModified(AbilityEditor.Pin()->GetAbilityBlueprint());
	}

	TWeakPtr<FAbilityTimelineListItem> ListItem;
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
	TSharedPtr<SInlineEditableTextBlock> InlineTextBlock;
};

class SAbilityTimelineOverrideListItem : public STableRow<TSharedPtr<FAbilityTimelineOverrideListItem>>
{
public:
	SLATE_BEGIN_ARGS(SAbilityTimelineOverrideListItem) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTableView, TSharedPtr<FLegoAbilityEditor> InAbilityEditor, TSharedPtr<FAbilityTimelineOverrideListItem> InListItem)
	{
		ListItem = InListItem;
		AbilityEditor = InAbilityEditor;

		STableRow<TSharedPtr<FAbilityTimelineOverrideListItem>>::Construct(
			STableRow<TSharedPtr<FAbilityTimelineOverrideListItem>>::FArguments()
			.Padding(FMargin(3.0f, 2.0f))
			.Content()
			[
				SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					.AutoWidth()
					[
						SAssignNew(InlineTextBlock, STextBlock)
							.Font(FCoreStyle::Get().GetFontStyle("NormalFont"))
							.Text(this, &SAbilityTimelineOverrideListItem::GetTimelineNameText)
					]

					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.FillWidth(1)
					[
						SNew(SRichTextBlock)
							.Text(this, &SAbilityTimelineOverrideListItem::GetOverrideModeText)
							.DecoratorStyleSet(&FAppStyle::Get())
							.TextStyle(FAppStyle::Get(), "RichTextBlock.Italic")

					]

					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Center)
					.FillWidth(1)
					[
						SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SCheckBox)
									.IsChecked(this, &SAbilityTimelineOverrideListItem::GetCheckState_AutoPlay)
									//.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_AutoPlay)
									.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should be played automatically with ability activation."))
									.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
									.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
									.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay"))
									.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
									.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
									.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.AutoPlay_Not"))
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SCheckBox)
									.IsChecked(this, &SAbilityTimelineOverrideListItem::GetCheckState_Loop)
									//.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_Loop)
									.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should loop when it reaches the end"))
									.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
									.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
									.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop"))
									.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
									.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
									.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.Loop_Not"))
							]

							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SCheckBox)
									.IsChecked(this, &SAbilityTimelineOverrideListItem::GetCheckState_StopAbility)
									//.OnCheckStateChanged(this, &SAbilityTimelineListItem::OnCheckStateChanged_StopAbility)
									.ToolTipText(LOCTEXT("IsTimelineLooping", "Whether timeline should end current ability it reaches the end"))
									.CheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
									.CheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
									.CheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility"))
									.UncheckedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
									.UncheckedHoveredImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
									.UncheckedPressedImage(FLegoAbilityEditorStyle::GetBrush("Timeline.StopAbility_Not"))
							]
					]
			],
			InOwnerTableView);
	}

private:
	FText GetTimelineNameText() const
	{
		if (ListItem.IsValid())
		{
			return FText::FromString(ListItem.Pin()->TimelineOverride.OverriddenTimeline->GetName());
		}

		return FText::GetEmpty();
	}

	FText GetOverrideModeText() const
	{
		if (ListItem.IsValid())
		{
			return (ListItem.Pin()->TimelineOverride.bInheritMode) ? LOCTEXT("Inherit", "Inherit")
					: LOCTEXT("Override", "Override");
		}

		return FText::GetEmpty();
	}

	ECheckBoxState GetCheckState_Loop() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->TimelineOverride.OverriddenTimeline->bLooping ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}

	ECheckBoxState GetCheckState_AutoPlay() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->TimelineOverride.OverriddenTimeline->bAutoPlay ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}

	ECheckBoxState GetCheckState_StopAbility() const
	{
		if (ListItem.IsValid())
		{
			return ListItem.Pin()->TimelineOverride.OverriddenTimeline->bStopAbility ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
		}

		return ECheckBoxState::Unchecked;
	}


	TWeakPtr<FAbilityTimelineOverrideListItem> ListItem;
	TWeakPtr<FLegoAbilityEditor> AbilityEditor;
	TSharedPtr<STextBlock> InlineTextBlock;
};

void SLGATimelineListTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	AbilityEditor = InAbilityEditor;

	InAbilityEditor->OnEnterTimelineMode.AddSP(this, &SLGATimelineListTabBody::RestoreSelection);
	InAbilityEditor->OnAbilityBlueprintTransaction.AddSP(this, &SLGATimelineListTabBody::RefreshTimelineList);
	if (InAbilityEditor->GetAbilityBlueprint())
	{
		InAbilityEditor->GetAbilityBlueprint()->OnChanged().AddSP(this, &SLGATimelineListTabBody::OnBlueprintChanged);
	}

	SAssignNew(TimelineListView, SAbilityTimelineListView)
		.ItemHeight(20.0f)
		.SelectionMode(ESelectionMode::Single)
		.OnGenerateRow(this, &SLGATimelineListTabBody::OnGenerateRow)
		.OnItemScrolledIntoView(this, &SLGATimelineListTabBody::OnItemScrolledIntoView)
		.OnSelectionChanged(this, &SLGATimelineListTabBody::OnSelectionChanged)
		.OnContextMenuOpening(this, &SLGATimelineListTabBody::OnContextMenuOpening)
		.ListItemsSource(&Timelines);

	SAssignNew(TimelineOverrideListView, SAbilityTimelineOverrideListView)
		.ItemHeight(20.0f)
		.SelectionMode(ESelectionMode::Single)
		.OnGenerateRow(this, &SLGATimelineListTabBody::OnGenerateOverrideRow)
		.OnSelectionChanged(this, &SLGATimelineListTabBody::OnOverrideSelectionChanged)
		.OnContextMenuOpening(this, &SLGATimelineListTabBody::OnOverrideContextMenuOpening)
		.ListItemsSource(&TimelineOverrides);

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.Padding(2)
			.AutoHeight()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.Padding(0)
				.VAlign(VAlign_Center)
				.AutoWidth()
				[
					SNew(SButton)
					.ButtonStyle(FAppStyle::Get(), "FlatButton.Success")
					.ForegroundColor(FAppStyle::Get().GetSlateColor("Foreground"))
					.ContentPadding(FMargin(2.0f, 1.0f))
					.OnClicked(this, &SLGATimelineListTabBody::OnNewTimelineClicked)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						.AutoWidth()
						[
							SNew(STextBlock)
							.TextStyle(FAppStyle::Get(), "NormalText.Important")
							.Font(FAppStyle::Get().GetFontStyle("FontAwesome.10"))
							.Text(FText::FromString(FString(TEXT("\xf067"))) /*fa-plus*/)
						]

						+ SHorizontalBox::Slot()
						.Padding(2.0f, 0.0f)
						[
							SNew(STextBlock)
							.TextStyle(FAppStyle::Get(), "NormalText.Important")
							.Text(LOCTEXT("NewTimelineButtonText", "Timeline"))
						]
					]
				]
				+ SHorizontalBox::Slot()
				.Padding(2.0f, 0.0f)
				.VAlign(VAlign_Center)
				[
					SAssignNew(SearchBoxPtr, SSearchBox)
					.HintText(LOCTEXT("Search Timelines", "Search Timelines"))
					.OnTextChanged(this, &SLGATimelineListTabBody::OnSearchChanged)
				]
			]
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SNew(SScrollBorder, TimelineListView.ToSharedRef())
				[
					TimelineListView.ToSharedRef()
				]
			]
			+ SVerticalBox::Slot()
			[
				SAssignNew(OverrideTimelineBox, SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(2)
				.AutoHeight()
				[
					SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.VAlign(VAlign_Center)
						[
							SNew(SRichTextBlock)
								.Text(LOCTEXT("OverriddenTimelineListText", "Overridden Timlines"))
								.DecoratorStyleSet(&FAppStyle::Get())
								.TextStyle(FAppStyle::Get(), "DetailsView.CategoryTextStyle")
						]
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Center)
						.HAlign(HAlign_Right)
						[
							SNew(SComboButton)
								.ForegroundColor(FAppStyle::GetSlateColor("DefaultForeground"))
								.OnGetMenuContent(this, &SLGATimelineListTabBody::OnGetOverrideTimelineList)
								.ContentPadding(0.0f)
								.HasDownArrow(true)
								.ButtonContent()
								[
									SNew(STextBlock)
										.TextStyle(FAppStyle::Get(), "NormalText")
										.Text(LOCTEXT("OverrideTimelineButtonText", "Override"))
								]
						]
				]
				+ SVerticalBox::Slot()
				.FillHeight(1.0f)
				[
					SNew(SScrollBorder, TimelineOverrideListView.ToSharedRef())
					[
						TimelineOverrideListView.ToSharedRef()
					]
				]
			]
		]
	];

	RegenTimelineListItems();
	CreateCommandList();
	SelectDefaultTimeline();
}

FReply SLGATimelineListTabBody::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = FReply::Unhandled();
	if (CommandList->ProcessCommandBindings(InKeyEvent))
	{
		Reply = FReply::Handled();
	}

	return Reply;
}

void SLGATimelineListTabBody::RegenTimelineListItems()
{
	Timelines.Empty();
	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
	for (ULGATimeline* Timeline : AbilityBlueprint->AbilityTimelines)
	{
		Timelines.Add(MakeShareable(new FAbilityTimelineListItem(Timeline)));
	}
	TimelineListView->RequestListRefresh();


	TArray<ULGATimeline*> ParentTimelines = GetParrentTimelines();
	TimelineOverrides.Empty();
	for (FLGATimelineOverride& TimelineOverride : AbilityBlueprint->AbilityTimelineOverrides)
	{
		if (ParentTimelines.ContainsByPredicate([=](const ULGATimeline* Item) {return TimelineOverride.OverriddenTimeline == Item; }) )
		{
			TSharedPtr<FAbilityTimelineOverrideListItem> NewItem = MakeShareable(new FAbilityTimelineOverrideListItem(TimelineOverride));
			TimelineOverrides.Add(NewItem);
		}
	}
	TimelineOverrideListView->RequestListRefresh();


	OverrideTimelineBox->SetVisibility(GetParrentTimelines().IsEmpty() ? EVisibility::Collapsed : EVisibility::Visible);
}

void SLGATimelineListTabBody::SelectDefaultTimeline()
{
	if (Timelines.Num() > 0)
	{
		TimelineListView->SetSelection(Timelines[0]);
	}
	else if (TimelineOverrides.Num() > 0)
	{
		TimelineOverrideListView->SetSelection(TimelineOverrides[0]);
	}
}

void SLGATimelineListTabBody::RestoreSelection()
{
	FName TimelineName = AbilityEditor.Pin()->GetCurrentTimelineName();
	if (TimelineName != ULGATimeline::GetNullTimeline()->GetFName())
	{
		const TSharedPtr<FAbilityTimelineListItem>* FoundListItemPtr = Timelines.FindByPredicate([&](const TSharedPtr<FAbilityTimelineListItem>& ListItem) { return ListItem->Timeline->GetFName() == TimelineName; });
		if (FoundListItemPtr)
		{
			TimelineListView->SetSelection(*FoundListItemPtr);
		}
		else
		{
			const TSharedPtr<FAbilityTimelineOverrideListItem>* FoundOverrideListItemPtr = TimelineOverrides.FindByPredicate([&](const TSharedPtr<FAbilityTimelineOverrideListItem>& ListItem) { return ListItem->TimelineOverride.Timeline->GetFName() == TimelineName; });
			if (FoundOverrideListItemPtr)
			{
				TimelineOverrideListView->SetSelection(*FoundOverrideListItemPtr);
			}
		}
	}
}

void SLGATimelineListTabBody::RefreshTimelineList()
{
	RegenTimelineListItems();
	RestoreSelection();
}

void SLGATimelineListTabBody::OnItemScrolledIntoView(TSharedPtr<FAbilityTimelineListItem> InListItem, const TSharedPtr<ITableRow>& InWidget) const
{
	if (InListItem->bRenameRequestPending)
	{
		StaticCastSharedPtr<SAbilityTimelineListItem>(InWidget)->BeginRename();
		InListItem->bRenameRequestPending = false;
	}
}

FReply SLGATimelineListTabBody::OnNewTimelineClicked()
{
	TSharedPtr<FLegoAbilityEditor> Editor = AbilityEditor.Pin();
	if (!Editor.IsValid())
	{
		return FReply::Handled();
	}

	FString BaseName = "NewTimeline";
	FString UniqueName = BaseName;
	int32 NameIndex = 1;
	FText OutErrorMessage;
	ULegoAbilityBlueprint* Blueprint = Editor->GetAbilityBlueprint();

	while (!VerifyTimelineRename(Blueprint, UniqueName, OutErrorMessage))
	{
		UniqueName = FString::Printf(TEXT("%s_%i"), *BaseName, NameIndex);
		NameIndex++;
	}

	ULGATimeline* NewTimeline = NewObject<ULGATimeline>(Blueprint, FName(*UniqueName), Blueprint->GetMaskedFlags(RF_PropagateToSubObjects) | RF_Transactional);
	

	int32 NewIndex = Timelines.Add(MakeShareable(new FAbilityTimelineListItem(NewTimeline, true, true)));
	TimelineListView->RequestScrollIntoView(Timelines[NewIndex]);

	return FReply::Handled();
}

void SLGATimelineListTabBody::OnSearchChanged(const FText& InSearchText)
{
	if (!InSearchText.IsEmpty())
	{
		struct Local
		{
			static void UpdateFilterStrings(ULGATimeline* InTimeline, OUT TArray<FString>& OutFilterStrings)
			{
				OutFilterStrings.Add(InTimeline->GetName());
			}
		};

		TTextFilter<ULGATimeline*> TextFilter(TTextFilter<ULGATimeline*>::FItemToStringArray::CreateStatic(&Local::UpdateFilterStrings));

		TextFilter.SetRawFilterText(InSearchText);
		SearchBoxPtr->SetError(TextFilter.GetFilterErrorText());

		Timelines.Reset();

		for (ULGATimeline* Timeline : AbilityEditor.Pin()->GetAbilityBlueprint()->AbilityTimelines)
		{
			if (TextFilter.PassesFilter(Timeline))
			{
				Timelines.Add(MakeShareable(new FAbilityTimelineListItem(Timeline)));
			}
		}

		TimelineListView->RequestListRefresh();
	}
	else
	{
		SearchBoxPtr->SetError(FText::GetEmpty());

		// Just regenerate the whole list
		RegenTimelineListItems();
	}
}

void SLGATimelineListTabBody::OnSelectionChanged(TSharedPtr<FAbilityTimelineListItem> InSelectedItem, ESelectInfo::Type SelectionInfo)
{
	if (InSelectedItem.IsValid())
	{
		TimelineOverrideListView->ClearSelection();
	}

	AbilityEditor.Pin()->SetCurrentTimeline(InSelectedItem.IsValid() ? InSelectedItem->Timeline : ULGATimeline::GetNullTimeline());
}

TSharedPtr<SWidget> SLGATimelineListTabBody::OnContextMenuOpening() const
{
	FMenuBuilder MenuBuilder(true, CommandList.ToSharedRef());

	MenuBuilder.BeginSection("Edit", LOCTEXT("Edit", "Edit"));
	{
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Rename);
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Duplicate);
		MenuBuilder.AddMenuSeparator();

		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Delete);
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

TSharedRef<ITableRow> SLGATimelineListTabBody::OnGenerateRow(TSharedPtr<FAbilityTimelineListItem> InListItem, const TSharedRef<STableViewBase>& InOwnerTableView)
{
	return SNew(SAbilityTimelineListItem, InOwnerTableView, AbilityEditor.Pin(), InListItem);
}

void SLGATimelineListTabBody::CreateCommandList()
{
	CommandList = MakeShareable(new FUICommandList);

	CommandList->MapAction(
		FGenericCommands::Get().Duplicate,
		FExecuteAction::CreateSP(this, &SLGATimelineListTabBody::OnDuplicateTimeline),
		FCanExecuteAction::CreateSP(this, &SLGATimelineListTabBody::CanExecuteContextMenuAction)
	);

	CommandList->MapAction(
		FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this, &SLGATimelineListTabBody::OnDeleteTimeline),
		FCanExecuteAction::CreateSP(this, &SLGATimelineListTabBody::CanExecuteContextMenuAction)
	);

	CommandList->MapAction(
		FGenericCommands::Get().Rename,
		FExecuteAction::CreateSP(this, &SLGATimelineListTabBody::OnRenameTimeline),
		FCanExecuteAction::CreateSP(this, &SLGATimelineListTabBody::CanExecuteContextMenuAction)
	);
}

bool SLGATimelineListTabBody::CanExecuteContextMenuAction() const
{
	return (TimelineListView->GetNumItemsSelected() + TimelineOverrideListView->GetNumItemsSelected() == 1) && !AbilityEditor.Pin()->IsPlayInEditorActive();
}

void SLGATimelineListTabBody::OnDuplicateTimeline()
{
	TArray<TSharedPtr<FAbilityTimelineListItem>> SelectedTimelines = TimelineListView->GetSelectedItems();
	TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> SelectedTimelineOverrides = TimelineOverrideListView->GetSelectedItems();

	check(SelectedTimelines.Num() + SelectedTimelineOverrides.Num() == 1);

	if (SelectedTimelines.Num() == 1)
	{
		ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
		ULGATimeline* SelectedTimeline = SelectedTimelines[0]->Timeline;

		ULGATimeline* NewTimeline = DuplicateObject<ULGATimeline>(SelectedTimeline, Blueprint, MakeUniqueObjectName(Blueprint, ULGATimeline::StaticClass(), SelectedTimeline->GetFName()));

		int32 NewIndex = Timelines.Add(MakeShareable(new FAbilityTimelineListItem(NewTimeline, true, true)));
		TimelineListView->RequestScrollIntoView(Timelines[NewIndex]);
	}

	if (SelectedTimelineOverrides.Num() == 1)
	{
		ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
		ULGATimeline* SelectedTimeline = SelectedTimelineOverrides[0]->TimelineOverride.Timeline;
		ULGATimeline* OverriddenTimeline = SelectedTimelineOverrides[0]->TimelineOverride.OverriddenTimeline;

		ULGATimeline* NewTimeline = DuplicateObject<ULGATimeline>(SelectedTimeline, Blueprint, MakeUniqueObjectName(Blueprint, ULGATimeline::StaticClass(), OverriddenTimeline->GetFName()));

		int32 NewIndex = Timelines.Add(MakeShareable(new FAbilityTimelineListItem(NewTimeline, true, true)));
		TimelineListView->RequestScrollIntoView(Timelines[NewIndex]);
	}
}

void SLGATimelineListTabBody::OnDeleteTimeline()
{
	TArray<TSharedPtr<FAbilityTimelineListItem>> SelectedTimelines = TimelineListView->GetSelectedItems();
	TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> SelectedTimelineOverrides = TimelineOverrideListView->GetSelectedItems();
	
	check(SelectedTimelines.Num() + SelectedTimelineOverrides.Num() == 1);

	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();
	
	if(SelectedTimelines.Num() == 1)
	{
		const FScopedTransaction Transaction(LOCTEXT("DeleteTimeline", "Delete Timeline"));

		AbilityBlueprint->Modify();

		// Rename the timeline and move it to the transient package to avoid collisions.
		ULGATimeline* SelectedTimeline = SelectedTimelines[0]->Timeline;
		ULegoAbilityBlueprint::DeleteTimeline(AbilityBlueprint, SelectedTimeline);

		RegenTimelineListItems();
	}

	if (SelectedTimelineOverrides.Num() == 1)
	{
		const FScopedTransaction Transaction(LOCTEXT("DeleteTimeline", "Delete Override Timeline"));

		AbilityBlueprint->Modify();

		// Rename the timeline and move it to the transient package to avoid collisions.
		ULGATimeline* SelectedTimeline = SelectedTimelineOverrides[0]->TimelineOverride.Timeline;
		ULGATimeline* OverriddenTimeline = SelectedTimelineOverrides[0]->TimelineOverride.OverriddenTimeline;
		SelectedTimeline->Rename(nullptr, GetTransientPackage(), REN_DontCreateRedirectors);
		AbilityBlueprint->AbilityTimelineOverrides.RemoveAll([=](const FLGATimelineOverride& Item){return Item.OverriddenTimeline == OverriddenTimeline;});

		RegenTimelineListItems();
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(AbilityBlueprint);
}

void SLGATimelineListTabBody::OnRenameTimeline()
{
	TArray<TSharedPtr<FAbilityTimelineListItem>> SelectedTimelines = TimelineListView->GetSelectedItems();
	check(SelectedTimelines.Num() == 1);

	TSharedPtr<FAbilityTimelineListItem> SelectedTimeline = SelectedTimelines[0];
	SelectedTimeline->bRenameRequestPending = true;

	TimelineListView->RequestScrollIntoView(SelectedTimeline);
}

void SLGATimelineListTabBody::ConvertToOverrideMode()
{
	TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> SelectedTimelineOverrides = TimelineOverrideListView->GetSelectedItems();
	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	if (SelectedTimelineOverrides.Num() == 1)
	{
		FLGATimelineOverride& TimlineOverriderInfo = SelectedTimelineOverrides[0]->TimelineOverride;
		ULGATimeline* SelectedTimeline = TimlineOverriderInfo.Timeline;
		ULGATimeline* OverriddenTimeline = TimlineOverriderInfo.OverriddenTimeline;

		FLGATimelineOverride* BlueprintOverrideInfo = AbilityBlueprint->AbilityTimelineOverrides.FindByPredicate([=](const FLGATimelineOverride& Item) {return OverriddenTimeline == Item.OverriddenTimeline;});
		if (!BlueprintOverrideInfo)
		{
			return;
		}

		const FScopedTransaction Transaction(LOCTEXT("ConvertToInheritMode", "Convert To Inherit Mode"));
		AbilityBlueprint->Modify();

		// Rename the timeline and move it to the transient package to avoid collisions.
		if (SelectedTimeline)
		{
			SelectedTimeline->Rename(nullptr, GetTransientPackage(), REN_DontCreateRedirectors);
		}
	
		BlueprintOverrideInfo->bInheritMode = false;
		BlueprintOverrideInfo->ParentTimeline = nullptr;

		ULGATimeline* ParentTimelineTamplate = AbilityBlueprint->FindLatestTimelineTamplate(OverriddenTimeline);
		FString NewName = OverriddenTimeline->GetName() + FString(TEXT("_Override"));
		BlueprintOverrideInfo->Timeline = DuplicateObject<ULGATimeline>(ParentTimelineTamplate, AbilityBlueprint, MakeUniqueObjectName(AbilityBlueprint, ULGATimeline::StaticClass(), FName(*NewName)));


		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(AbilityBlueprint);

		RegenTimelineListItems();
	}
}

void SLGATimelineListTabBody::ConvertToInheritMode()
{
	TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> SelectedTimelineOverrides = TimelineOverrideListView->GetSelectedItems();
	ULegoAbilityBlueprint* AbilityBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	if (SelectedTimelineOverrides.Num() == 1)
	{
		FLGATimelineOverride& TimlineOverriderInfo = SelectedTimelineOverrides[0]->TimelineOverride;
		ULGATimeline* SelectedTimeline = TimlineOverriderInfo.ParentTimeline;
		ULGATimeline* OverriddenTimeline = TimlineOverriderInfo.OverriddenTimeline;

		FLGATimelineOverride* BlueprintOverrideInfo = AbilityBlueprint->AbilityTimelineOverrides.FindByPredicate([=](const FLGATimelineOverride& Item) {return OverriddenTimeline == Item.OverriddenTimeline;});
		if (!BlueprintOverrideInfo)
		{
			return;
		}

		const FScopedTransaction Transaction(LOCTEXT("ConvertToInheritMode", "Convert To Inherit Mode"));
		AbilityBlueprint->Modify();

		BlueprintOverrideInfo->bInheritMode = true;
		BlueprintOverrideInfo->ActionOverrides.Reset();

		ULGATimeline* ParentTimelineTamplate = AbilityBlueprint->FindLatestTimelineTamplate(OverriddenTimeline);
		BlueprintOverrideInfo->ParentTimeline = ParentTimelineTamplate;

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(AbilityBlueprint);

		RegenTimelineListItems();
	}
}

void SLGATimelineListTabBody::OnOverrideSelectionChanged(TSharedPtr<FAbilityTimelineOverrideListItem> InSelectedItem, ESelectInfo::Type SelectionInfo)
{
	ULGATimeline* SelectTimeline = nullptr;

	if (InSelectedItem.IsValid())
	{
		TimelineListView->ClearSelection();

		if (InSelectedItem->TimelineOverride.bInheritMode)
		{
			SelectTimeline = InSelectedItem->TimelineOverride.ParentTimeline;
		}
		else
		{
			SelectTimeline = InSelectedItem->TimelineOverride.Timeline;
		}
	}

	AbilityEditor.Pin()->SetCurrentTimeline(SelectTimeline ? SelectTimeline : ULGATimeline::GetNullTimeline());
}

TSharedPtr<SWidget> SLGATimelineListTabBody::OnOverrideContextMenuOpening()
{
	FMenuBuilder MenuBuilder(true, CommandList.ToSharedRef());

	MenuBuilder.BeginSection("Edit", LOCTEXT("Edit", "Edit"));
	{
		MenuBuilder.AddMenuEntry(FGenericCommands::Get().Delete);

		MenuBuilder.AddSeparator();

		TArray<TSharedPtr<FAbilityTimelineOverrideListItem>> SelectedTimelineOverrides = TimelineOverrideListView->GetSelectedItems();
		if (SelectedTimelineOverrides.Num() == 1)
		{
			FLGATimelineOverride& TimlineOverriderInfo = SelectedTimelineOverrides[0]->TimelineOverride;

			if (TimlineOverriderInfo.bInheritMode)
			{
				MenuBuilder.AddMenuEntry(
					LOCTEXT("ConvertToOverrideMode", "Convert to Override Mode"),
					LOCTEXT("ConvertToOverrideModeDescription", "Convert timeline to override mode"),
					FSlateIcon(),
					FUIAction(
						FExecuteAction::CreateLambda([this]() {
							this->ConvertToOverrideMode();
							})
					)
				);
			}
			else
			{
				MenuBuilder.AddMenuEntry(
					LOCTEXT("ConvertToInheritMode", "Convert to Inherit Mode"),
					LOCTEXT("ConvertToInheritModeDescription", "Convert timeline to inherit mode"),
					FSlateIcon(),
					FUIAction(
						FExecuteAction::CreateLambda([this]() {
							this->ConvertToInheritMode();
							})
					)
				);
			}
		}
	}
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

TSharedRef<ITableRow> SLGATimelineListTabBody::OnGenerateOverrideRow(TSharedPtr<FAbilityTimelineOverrideListItem> InListItem, const TSharedRef<STableViewBase>& InOwnerTableView)
{
	return SNew(SAbilityTimelineOverrideListItem, InOwnerTableView, AbilityEditor.Pin(), InListItem);
}

void SLGATimelineListTabBody::OverrideTimeline(ULGATimeline* Timeline)
{
	ULegoAbilityBlueprint* Blueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	if (Blueprint->AbilityTimelineOverrides.FindByPredicate([=](const FLGATimelineOverride& Item) {return Timeline == Item.OverriddenTimeline;}))
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("OverrideTimeline", "Override Timeline"));

	FLGATimelineOverride NewOverrideTimeline;
	NewOverrideTimeline.OverriddenTimeline = Timeline;
	FString NewName = Timeline->GetName() + FString(TEXT("_Override"));
	ULGATimeline* ParentTemplate = Blueprint->FindLatestTimelineTamplate(Timeline);
	NewOverrideTimeline.Timeline = DuplicateObject<ULGATimeline>(ParentTemplate, Blueprint, MakeUniqueObjectName(Blueprint, ULGATimeline::StaticClass(), FName(*NewName)));

	Blueprint->Modify();
	Blueprint->AbilityTimelineOverrides.Emplace(NewOverrideTimeline);

	int32 NewIndex = TimelineOverrides.Add(MakeShareable(new FAbilityTimelineOverrideListItem(NewOverrideTimeline)));
	TimelineOverrideListView->RequestScrollIntoView(TimelineOverrides[NewIndex]);

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);
}

TSharedRef<SWidget> SLGATimelineListTabBody::OnGetOverrideTimelineList()
{
	const bool bShouldCloseWindowAfterMenuSelection = true;
	FMenuBuilder MenuBuilder(bShouldCloseWindowAfterMenuSelection, CommandList);
	
	TArray<ULGATimeline*> OverrideTimelines = GetParrentTimelines(true);

	MenuBuilder.BeginSection("OverrideTimeline", LOCTEXT("OverrideTimeline", "Override Timeline"));
	{
		for (ULGATimeline* OverrideTimline : OverrideTimelines)
		{
			// Add the timeline name and tooltip 
			TSharedRef<SHorizontalBox> FunctionBox = SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Left)
				.Padding(FMargin(2.0f, 0.0f, 20.0f, 0.0f))
				[
					SNew(STextBlock)
						.Text(FText::FromString(OverrideTimline->GetName()))
				]
				// Where the function came from function came from
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Right)
				.Padding(FMargin(1.0f, 0.0f, 0.0f, 0.0f))
				[
					SNew(STextBlock)
						.Text(OverrideTimline->GetOuter() ? FText::FromString(OverrideTimline->GetOuter()->GetName()) : FText::GetEmpty())
						.ColorAndOpacity(FSlateColor::UseSubduedForeground())
				];

			MenuBuilder.AddMenuEntry(
				FUIAction(
					FExecuteAction::CreateSP(this, &SLGATimelineListTabBody::OverrideTimeline, OverrideTimline)),
				FunctionBox,
				NAME_None,
				FText::GetEmpty(),
				EUserInterfaceActionType::Button
			);
		}
	}
	MenuBuilder.EndSection();

	TSharedRef<SWidget> MenuWidget = MenuBuilder.MakeWidget();

	return MenuWidget;
}

TArray<ULGATimeline*> SLGATimelineListTabBody::GetParrentTimelines(bool bCanOverride/*=false*/)
{
	TArray<ULGATimeline*> OverrideTimelines;
	TArray<UBlueprint*> ParentBPArray;

	ULegoAbilityBlueprint* CurrentBlueprint = AbilityEditor.Pin()->GetAbilityBlueprint();

	// Get the parent hierarchy
	UBlueprint::GetBlueprintHierarchyFromClass(CurrentBlueprint->ParentClass, ParentBPArray);
	for (int32 i = 0; i < ParentBPArray.Num(); ++i)
	{
		if (ULegoAbilityBlueprint* LegoBlueprint = Cast<ULegoAbilityBlueprint>(ParentBPArray[i]))
		{
			for (ULGATimeline* Timeline : LegoBlueprint->AbilityTimelines)
			{
				if (bCanOverride && CurrentBlueprint->AbilityTimelineOverrides.ContainsByPredicate([=](const FLGATimelineOverride& Item) {return Timeline == Item.OverriddenTimeline; }))
				{
					continue;
				}
				OverrideTimelines.Add(Timeline);
			}

		}
	}

	return OverrideTimelines;
}

void SLGATimelineListTabBody::OnBlueprintChanged(UBlueprint* InBlueprint)
{
	RefreshTimelineList();
}

#undef LOCTEXT_NAMESPACE
// Copyright Epic Games, Inc. All Rights Reserved.

#include "SLGATimelineCurveEditor.h"
#include "CurveEditor.h"
#include "RichCurveEditorModel.h"
#include "SCurveEditorPanel.h"
#include "Tree/SCurveEditorTreeTextFilter.h"
#include "Tree/SCurveEditorTreeFilterStatusBar.h"
#include "Tree/SCurveEditorTree.h"
#include "Tree/SCurveEditorTreeSelect.h"
#include "Tree/SCurveEditorTreePin.h"
#include "Widgets/Layout/SScrollBorder.h"
#include "Tree/ICurveEditorTreeItem.h"
#include "Tree/CurveEditorTreeFilter.h"
#include "Editor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"
#include "ITimeSlider.h"
#include "AnimatedRange.h"
#include "SLGATimelineTransportControls.h"

#define LOCTEXT_NAMESPACE "SLGATimelineCurveEditor"

FTimelineCurveEditorModel::FTimelineCurveEditorModel(ULGATimeline* InTimeline, const FName& InName)
	: FRichCurveEditorModel(InTimeline)
	, Timeline(InTimeline)
	, CurveName(InName)
{

}

FTimelineCurveEditorModel::~FTimelineCurveEditorModel()
{

}

bool FTimelineCurveEditorModel::IsValid() const
{
	return Timeline.IsValid() && Timeline->GetCurveByName(CurveName);
}


FRichCurve& FTimelineCurveEditorModel::GetRichCurve()
{
	return Timeline->GetCurveByName(CurveName)->FloatCurve;
}


const FRichCurve& FTimelineCurveEditorModel::GetReadOnlyRichCurve() const
{
	return Timeline->GetCurveByName(CurveName)->FloatCurve;
}


void FTimelineCurveEditorModel::SetKeyPositions(TArrayView<const FKeyHandle> InKeys, TArrayView<const FKeyPosition> InKeyPositions, EPropertyChangeType::Type ChangeType)
{
	FRichCurveEditorModel::SetKeyPositions(InKeys, InKeyPositions, ChangeType);
}


void FTimelineCurveEditorModel::SetKeyAttributes(TArrayView<const FKeyHandle> InKeys, TArrayView<const FKeyAttributes> InAttributes, EPropertyChangeType::Type ChangeType /*= EPropertyChangeType::Unspecified*/)
{
	FRichCurveEditorModel::SetKeyAttributes(InKeys, InAttributes, ChangeType);
}


void FTimelineCurveEditorModel::SetCurveAttributes(const FCurveAttributes& InCurveAttributes)
{
	FRichCurveEditorModel::SetCurveAttributes(InCurveAttributes);
}


void FTimelineCurveEditorModel::RemoveKeys(TArrayView<const FKeyHandle> InKeys)
{
	FRichCurveEditorModel::RemoveKeys(InKeys, 0.f);

	if (IsValid())
	{
		FPropertyChangedEvent PropertyChangeStruct(nullptr, EPropertyChangeType::ArrayRemove);
		Timeline->PostEditChangeProperty(PropertyChangeStruct);
	}
}

class FTimelineCurveEditorItem : public ICurveEditorTreeItem
{
public:
	FTimelineCurveEditorItem(ULGATimeline* InTimeline, const FName& InName, FSimpleDelegate InOnCurveModified, FCurveEditorTreeItemID InTreeId)
		: Timeline(InTimeline)
		, CurveName(InName)
		, OnCurveModified(InOnCurveModified)
		, TreeId(InTreeId)
	{
	}

	virtual TSharedPtr<SWidget> GenerateCurveEditorTreeWidget(const FName& InColumnName, TWeakPtr<FCurveEditor> InCurveEditor, FCurveEditorTreeItemID InTreeItemID, const TSharedRef<ITableRow>& InTableRow) override
	{
		if (InColumnName == ColumnNames.Label)
		{
			return SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.Padding(FMargin(4.f))
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Right)
				.AutoWidth()
				[
					SNew(STextBlock)
					.Text(FText::FromName(CurveName))
					.ColorAndOpacity(FSlateColor(Timeline->GetCurveByName(CurveName)->GetColor()))
				];
		}
		else if (InColumnName == ColumnNames.SelectHeader)
		{
			return SNew(SCurveEditorTreeSelect, InCurveEditor, InTreeItemID, InTableRow);
		}
		else if (InColumnName == ColumnNames.PinHeader)
		{
			return SNew(SCurveEditorTreePin, InCurveEditor, InTreeItemID, InTableRow);
		}

		return nullptr;
	}

	virtual void CreateCurveModels(TArray<TUniquePtr<FCurveModel>>& OutCurveModels) override
	{
		TUniquePtr<FTimelineCurveEditorModel> NewCurveModel = MakeUnique<FTimelineCurveEditorModel>(Timeline.Get(), CurveName);
		NewCurveModel->OnCurveModified().Add(OnCurveModified);

		OutCurveModels.Add(MoveTemp(NewCurveModel));
	}

	virtual bool PassesFilter(const FCurveEditorTreeFilter* InFilter) const override
	{
		if (InFilter->GetType() == ECurveEditorTreeFilterType::Text)
		{
			const FCurveEditorTreeTextFilter* Filter = static_cast<const FCurveEditorTreeTextFilter*>(InFilter);
			for (const FCurveEditorTreeTextFilterTerm& Term : Filter->GetTerms())
			{
				for(const FCurveEditorTreeTextFilterToken& Token : Term.ChildToParentTokens)
				{
					if(Token.Match(*CurveName.ToString()))
					{
						return true;
					}
				}
			}

			return false;
		}

		return false;
	}

	TWeakObjectPtr<ULGATimeline> Timeline;
	FName CurveName;
	
	FSimpleDelegate OnCurveModified;
	FCurveEditorTreeItemID TreeId;
};

class FTimelineCurveEditorBounds : public ICurveEditorBounds
{
public:
	FTimelineCurveEditorBounds(TSharedPtr<ITimeSliderController> InExternalTimeSliderController)
		: ExternalTimeSliderController(InExternalTimeSliderController)
	{}

	virtual void GetInputBounds(double& OutMin, double& OutMax) const override
	{
		FAnimatedRange ViewRange = ExternalTimeSliderController.Pin()->GetViewRange();
		OutMin = ViewRange.GetLowerBoundValue();
		OutMax = ViewRange.GetUpperBoundValue();
	}

	virtual void SetInputBounds(double InMin, double InMax) override
	{
		ExternalTimeSliderController.Pin()->SetViewRange(InMin, InMax, EViewRangeInterpolation::Immediate);
	}

	TWeakPtr<ITimeSliderController> ExternalTimeSliderController;
};

SLGATimelineCurveEditor::~SLGATimelineCurveEditor()
{

}

void SLGATimelineCurveEditor::Construct(const FArguments& InArgs, TSharedPtr<FLGATimelinePreviewer> InTimelinePreviewer)
{
	CurveEditor = MakeShared<FCurveEditor>();
	CurveEditor->GridLineLabelFormatXAttribute = LOCTEXT("GridXLabelFormat", "{0}s");
	CurveEditor->SetBounds(MakeUnique<FTimelineCurveEditorBounds>(InArgs._ExternalTimeSliderController));

	FCurveEditorInitParams CurveEditorInitParams;
	CurveEditor->InitCurveEditor(CurveEditorInitParams);
	//CurveEditor->InputSnapRateAttribute;


	CurveEditorTree = SNew(SCurveEditorTree, CurveEditor)
		.OnContextMenuOpening(this, &SLGATimelineCurveEditor::OnContextMenuOpening);

	TSharedRef<SCurveEditorPanel> CurveEditorPanel = SNew(SCurveEditorPanel, CurveEditor.ToSharedRef())
		.GridLineTint(FLinearColor(0.f, 0.f, 0.f, 0.3f))
		.ExternalTimeSliderController(InArgs._ExternalTimeSliderController)
		.TabManager(InArgs._TabManager)
		.TreeContent()
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SAssignNew(CurveEditorSearchBox, SCurveEditorTreeTextFilter, CurveEditor)
			]
			+SVerticalBox::Slot()
			[
				SNew(SScrollBorder, CurveEditorTree.ToSharedRef())
				[
					CurveEditorTree.ToSharedRef()
				]
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SCurveEditorTreeFilterStatusBar, CurveEditor)
			]
			+SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(SLGATimelineTransportControls, InTimelinePreviewer)
			]
		];

	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0.0f, 0.0f, 0.0f, 3.0f)
		[
			MakeToolbar(CurveEditorPanel)
		]
		+SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			CurveEditorPanel
		]
	];
}

TSharedRef<SWidget> SLGATimelineCurveEditor::MakeToolbar(TSharedRef<SCurveEditorPanel> InEditorPanel)
{
	FToolBarBuilder ToolBarBuilder(InEditorPanel->GetCommands(), FMultiBoxCustomization::None, InEditorPanel->GetToolbarExtender(), true);
	ToolBarBuilder.BeginSection("Asset");
	ToolBarBuilder.EndSection();
	// We just use all of the extenders as our toolbar, we don't have a need to create a separate toolbar.
	return ToolBarBuilder.MakeWidget();
}

TSharedPtr<SWidget> SLGATimelineCurveEditor::OnContextMenuOpening()
{
	const TArray<FCurveEditorTreeItemID>& Selection = CurveEditorTree->GetSelectedItems();
	if (Selection.Num())
	{
		UToolMenus* ToolMenus = UToolMenus::Get();
		static const FName MenuName = "SLGATimelineCurveEditor.CurveEditorTreeContextMenu";
		if (!ToolMenus->IsMenuRegistered(MenuName))
		{
			ToolMenus->RegisterMenu(MenuName);
		}

		FToolMenuContext Context;
		UToolMenu* Menu = ToolMenus->GenerateMenu(MenuName, Context);

		FToolMenuSection& Section = Menu->AddSection("Selection", LOCTEXT("SelectionLablel", "Selection"));
		Section.AddMenuEntry("RemoveSelectedCurves", LOCTEXT("RemoveCurveLabel", "Stop editing selected curve(s)"),
			LOCTEXT("RemoveCurveTooltip", "Removes the currently selected curve(s) from editing"),
			FSlateIcon(),
			FToolUIActionChoice(FExecuteAction::CreateLambda([this]()
				{
					// Remove all selected tree items, and associated curves
					TArray<FCurveModelID> ModelIDs;				
					TArray<FCurveEditorTreeItemID> Selection = CurveEditorTree->GetSelectedItems();
					for (const FCurveEditorTreeItemID& SelectedItem : Selection)
					{
						ModelIDs.Append(CurveEditor->GetTreeItem(SelectedItem).GetCurves());
						CurveEditor->RemoveTreeItem(SelectedItem);
					}
					CurveEditorTree->ClearSelection();

					for (const FCurveModelID& ID : ModelIDs)
					{
						CurveEditor->RemoveCurve(ID);
					}
				}))				
			);

		return ToolMenus->GenerateWidget(Menu);
	}

	return SNullWidget::NullWidget;
}

void SLGATimelineCurveEditor::ResetCurves()
{
	CurveEditor->RemoveAllTreeItems();
	CurveEditor->RemoveAllCurves();
}

void SLGATimelineCurveEditor::AddCurve(ULGATimeline* InTimeline, FName CurveName, FSimpleDelegate InOnCurveModified)
{
	// Ensure that curve is not already being edited
	for (const TPair<FCurveEditorTreeItemID, FCurveEditorTreeItem>& ItemPair : CurveEditor->GetTree()->GetAllItems())
	{
		TSharedPtr<FTimelineCurveEditorItem> Item = StaticCastSharedPtr<FTimelineCurveEditorItem>(ItemPair.Value.GetItem());
		if (Item->Timeline == InTimeline && Item->CurveName == CurveName)
		{
			return;
		}
	}
	
	FCurveEditorTreeItem* TreeItem = CurveEditor->AddTreeItem(FCurveEditorTreeItemID());
	TreeItem->SetStrongItem(MakeShared<FTimelineCurveEditorItem>(InTimeline, CurveName, InOnCurveModified, TreeItem->GetID()));

	// Update selection
	const TMap<FCurveEditorTreeItemID, ECurveEditorTreeSelectionState>& Selection = CurveEditor->GetTreeSelection();
	TArray<FCurveEditorTreeItemID> NewSelection;
	NewSelection.Add(TreeItem->GetID());
	for(const auto& SelectionPair : Selection)
	{
		if(SelectionPair.Value != ECurveEditorTreeSelectionState::None)
		{
			NewSelection.Add(SelectionPair.Key);
		}
	}
	CurveEditor->SetTreeSelection(MoveTemp(NewSelection));
}

void SLGATimelineCurveEditor::RemoveCurve(ULGATimeline* InTimeline, const FName& InName)
{
	for(const FCurveEditorTreeItemID& TreeItemID : CurveEditor->GetRootTreeItems())
	{
		FCurveEditorTreeItem& TreeItem = CurveEditor->GetTreeItem(TreeItemID);
		TSharedPtr<FTimelineCurveEditorItem> CurveItem = StaticCastSharedPtr<FTimelineCurveEditorItem>(TreeItem.GetItem());
		if(CurveItem->Timeline == InTimeline && CurveItem->CurveName == InName)
		{
			CurveEditor->RemoveTreeItem(TreeItemID);
			break;
		}
	}
	
	for(const auto& CurvePair : CurveEditor->GetCurves())
	{
		FTimelineCurveEditorModel* Model = static_cast<FTimelineCurveEditorModel*>(CurvePair.Value.Get());
		if(Model->Timeline == InTimeline && Model->CurveName == InName)
		{
			// Cache ID to prevent use after release
			CurveEditor->RemoveCurve(CurvePair.Key);
			break;
		}
	}
}

void SLGATimelineCurveEditor::ZoomToFit()
{
	CurveEditor->ZoomToFit(EAxisList::Y);
}

void SLGATimelineCurveEditor::ClearInvalidCurves()
{
	TArray<FCurveEditorTreeItemID> InvalidItems;
	for (const FCurveEditorTreeItemID& TreeItemID : CurveEditor->GetRootTreeItems())
	{
		FCurveEditorTreeItem& TreeItem = CurveEditor->GetTreeItem(TreeItemID);
		TSharedPtr<FTimelineCurveEditorItem> CurveItem = StaticCastSharedPtr<FTimelineCurveEditorItem>(TreeItem.GetItem());
		if (!CurveItem->Timeline.IsValid() || !CurveItem->Timeline->GetCurveByName(CurveItem->CurveName))
		{
			InvalidItems.Add(TreeItemID);
		}
	}
	for (FCurveEditorTreeItemID& ItemID : InvalidItems)
	{
		CurveEditor->RemoveTreeItem(ItemID);
	}


	TArray<FCurveModelID> InvalidModels;
	for (const auto& CurvePair : CurveEditor->GetCurves())
	{
		FTimelineCurveEditorModel* Model = static_cast<FTimelineCurveEditorModel*>(CurvePair.Value.Get());
		if (!Model->IsValid())
		{
			InvalidModels.Add(CurvePair.Key);
		}
	}
	for (FCurveModelID& ModelID : InvalidModels)
	{
		CurveEditor->RemoveCurve(ModelID);
	}
}

#undef LOCTEXT_NAMESPACE


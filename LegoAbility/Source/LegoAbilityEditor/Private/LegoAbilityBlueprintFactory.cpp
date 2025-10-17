// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityBlueprintFactory.h"
#include "BlueprintEditorSettings.h"
#include "ClassViewerModule.h" // This has to be before ClassViewFilter
#include "ClassViewerFilter.h"
#include "EditorStyleSet.h"
#include "Editor/EditorEngine.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"
#include "LegoAbilityBlueprint.h"
#include "LegoAbilityBlueprintGeneratedClass.h"

extern UNREALED_API UEditorEngine* GEditor;

#define LOCTEXT_NAMESPACE "LegoAbilitiesBlueprintFactory"

/*------------------------------------------------------------------------------
Dialog to configure creation properties
------------------------------------------------------------------------------*/
class FLegoAbilityBlueprintParentFilter : public IClassViewerFilter
{
public:
	/** All children of these classes will be included unless filtered out by another setting. */
	TSet<const UClass*> m_AllowedChildrenOfClasses;

	FLegoAbilityBlueprintParentFilter() {}

	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef<FClassViewerFilterFuncs> InFilterFuncs) override
	{
		// If it appears on the allowed child-of classes list (or there is nothing on that list)
		return InFilterFuncs->IfInChildOfClassesSet(m_AllowedChildrenOfClasses, InClass) != EFilterReturn::Failed;
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef<const IUnloadedBlueprintData> InUnloadedClassData, TSharedRef<FClassViewerFilterFuncs> InFilterFuncs) override
	{
		// If it appears on the allowed child-of classes list (or there is nothing on that list)
		return InFilterFuncs->IfInChildOfClassesSet(m_AllowedChildrenOfClasses, InUnloadedClassData) != EFilterReturn::Failed;
	}
};

class SLegoAbilityBlueprintCreateDialog : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLegoAbilityBlueprintCreateDialog) {}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs)
	{
		bOkClicked = false;
		ParentClass = ULegoAbility::StaticClass();

		ChildSlot
		[
			SNew(SBorder)
			.Visibility(EVisibility::Visible)
			.BorderImage(FAppStyle::GetBrush("Menu.Background"))
			[
				SNew(SBox)
				.Visibility(EVisibility::Visible)
				.WidthOverride(500.0f)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.FillHeight(1)
					[
						SNew(SBorder)
						.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
						.Content()
						[
							SAssignNew(ParentClassContainer, SVerticalBox)
						]
					]

					// Ok/Cancel buttons
					+ SVerticalBox::Slot()
					.AutoHeight()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Bottom)
					.Padding(8)
					[
						SNew(SUniformGridPanel)
						.SlotPadding(FAppStyle::GetMargin("StandardDialog.SlotPadding"))
						.MinDesiredSlotWidth(FAppStyle::GetFloat("StandardDialog.MinDesiredSlotWidth"))
						.MinDesiredSlotHeight(FAppStyle::GetFloat("StandardDialog.MinDesiredSlotHeight"))
						+ SUniformGridPanel::Slot(0, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
							.OnClicked(this, &SLegoAbilityBlueprintCreateDialog::OkClicked)
							.Text(LOCTEXT("CreateLegoAbilityBlueprintOk", "OK"))
						]
						+ SUniformGridPanel::Slot(1, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
							.OnClicked(this, &SLegoAbilityBlueprintCreateDialog::CancelClicked)
							.Text(LOCTEXT("CreateLegoAbilityBlueprintCancel", "Cancel"))
						]
					]
				]
			]
		];

		MakeParentClassPicker();
	}

	/** Sets properties for the supplied LegoAbilityBlueprintFactory */
	bool ConfigureProperties(TWeakObjectPtr<ULegoAbilityBlueprintFactory> InLegoAbilityBlueprintFactory)
	{
		LegoAbilityBlueprintFactory = InLegoAbilityBlueprintFactory;

		TSharedRef<SWindow> Window = SNew(SWindow)
			.Title(LOCTEXT("CreateLegoAbilityBlueprintOptions", "Create Lego Ability Blueprint"))
			.ClientSize(FVector2D(400, 700))
			.SupportsMinimize(false).SupportsMaximize(false)
			[
				AsShared()
			];

		PickerWindow = Window;

		GEditor->EditorAddModalWindow(Window);
		LegoAbilityBlueprintFactory.Reset();

		return bOkClicked;
	}

private:
	/** Creates the combo menu for the parent class */
	void MakeParentClassPicker()
	{
		// Load the classviewer module to display a class picker
		FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");

		// Fill in options
		FClassViewerInitializationOptions Options;
		Options.Mode = EClassViewerMode::ClassPicker;

		// Only allow parenting to base blueprints.
		Options.bIsBlueprintBaseOnly = true;

		TSharedPtr<FLegoAbilityBlueprintParentFilter> Filter = MakeShareable(new FLegoAbilityBlueprintParentFilter);

		// All child child classes of ULegoAbility are valid.
		Filter->m_AllowedChildrenOfClasses.Add(ULegoAbility::StaticClass());
		Options.ClassFilters.Add(Filter.ToSharedRef());

		ParentClassContainer->ClearChildren();
		ParentClassContainer->AddSlot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("ParentClass", "Parent Class:"))
			.ShadowOffset(FVector2D(1.0f, 1.0f))
		];

		ParentClassContainer->AddSlot()
		[
			ClassViewerModule.CreateClassViewer(Options, FOnClassPicked::CreateSP(this, &SLegoAbilityBlueprintCreateDialog::OnClassPicked))
		];
	}

	/** Handler for when a parent class is selected */
	void OnClassPicked(UClass* ChosenClass)
	{
		ParentClass = ChosenClass;
	}

	/** Handler for when ok is clicked */
	FReply OkClicked()
	{
		if (LegoAbilityBlueprintFactory.IsValid())
		{
			LegoAbilityBlueprintFactory->BlueprintType = BPTYPE_Normal;
			LegoAbilityBlueprintFactory->ParentClass = ParentClass.Get();
		}

		CloseDialog(true);

		return FReply::Handled();
	}

	void CloseDialog(bool bWasPicked = false)
	{
		bOkClicked = bWasPicked;
		if (PickerWindow.IsValid())
		{
			PickerWindow.Pin()->RequestDestroyWindow();
		}
	}

	/** Handler for when cancel is clicked */
	FReply CancelClicked()
	{
		CloseDialog();
		return FReply::Handled();
	}

	FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
	{
		if (InKeyEvent.GetKey() == EKeys::Escape)
		{
			CloseDialog();
			return FReply::Handled();
		}
		return SWidget::OnKeyDown(MyGeometry, InKeyEvent);
	}

private:
	/** The factory for which we are setting up properties */
	TWeakObjectPtr<ULegoAbilityBlueprintFactory> LegoAbilityBlueprintFactory;

	/** A pointer to the window that is asking the user to select a parent class */
	TWeakPtr<SWindow> PickerWindow;

	/** The container for the Parent Class picker */
	TSharedPtr<SVerticalBox> ParentClassContainer;

	/** The selected class */
	TWeakObjectPtr<UClass> ParentClass;

	/** True if Ok was clicked */
	bool bOkClicked;
};


ULegoAbilityBlueprintFactory::ULegoAbilityBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = ULegoAbilityBlueprint::StaticClass();
	ParentClass = ULegoAbility::StaticClass();
}

ULegoAbilityBlueprintFactory::~ULegoAbilityBlueprintFactory()
{

}

bool ULegoAbilityBlueprintFactory::ConfigureProperties()
{
	TSharedRef<SLegoAbilityBlueprintCreateDialog> Dialog = SNew(SLegoAbilityBlueprintCreateDialog);
	return Dialog->ConfigureProperties(this);
};

UObject* ULegoAbilityBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	// Make sure we are trying to factory a gameplay ability blueprint, then create and init one
	check(Class->IsChildOf(ULegoAbilityBlueprint::StaticClass()));

	// If they selected an interface, force the parent class to be UInterface
	if (BlueprintType == BPTYPE_Interface)
	{
		ParentClass = UInterface::StaticClass();
	}

	if ((ParentClass == nullptr) || !FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass) || !ParentClass->IsChildOf(ULegoAbility::StaticClass()))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ClassName"), ParentClass ? FText::FromString(ParentClass->GetName()) : LOCTEXT("Null", "(null)"));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("CannotCreateLegoAbilityBlueprint", "Cannot create a Lego Ability Blueprint based on the class '{ClassName}'."), Args));
		return nullptr;
	}
	else
	{
		ULegoAbilityBlueprint* NewBP = CastChecked<ULegoAbilityBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BlueprintType, ULegoAbilityBlueprint::StaticClass(), ULegoAbilityBlueprintGeneratedClass::StaticClass(), CallingContext));
		if (NewBP)
		{
			if (!ULegoAbilityBlueprint::FindRootLegoAbilityBlueprint(NewBP))
			{
				// Only allow an ability graph if there isn't one in a parent blueprint
				UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(NewBP, TEXT("Gameplay Ability Graph"), UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
#if WITH_EDITORONLY_DATA
				if (NewBP->UbergraphPages.Num())
				{
					FBlueprintEditorUtils::RemoveGraphs(NewBP, NewBP->UbergraphPages);
				}
#endif
				FBlueprintEditorUtils::AddUbergraphPage(NewBP, NewGraph);
				NewBP->LastEditedDocuments.Add(NewGraph);
				NewGraph->bAllowDeletion = false;

				const UBlueprintEditorSettings* Settings = GetDefault<UBlueprintEditorSettings>();
				if (Settings && Settings->bSpawnDefaultBlueprintNodes)
				{
					int32 NodePositionY = 0;
					FKismetEditorUtilities::AddDefaultEventNode(NewBP, NewGraph, FName(TEXT("K2_ActivateAbility")), ULegoAbility::StaticClass(), NodePositionY);
					FKismetEditorUtilities::AddDefaultEventNode(NewBP, NewGraph, FName(TEXT("K2_OnEndAbility")), ULegoAbility::StaticClass(), NodePositionY);
				}
			}

			if (ULegoAbilityBlueprint* ParentBP = Cast<ULegoAbilityBlueprint>(UBlueprint::GetBlueprintFromClass(ParentClass)))
			{
				NewBP->PreviewAsset = ParentBP->PreviewAsset;
			}
		}

		return NewBP;
	}
}

UObject* ULegoAbilityBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

#undef LOCTEXT_NAMESPACE

// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGAEditorViewportToolBar.h"
#include "EditorViewportCommands.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "SEditorViewportToolBarMenu.h"
#include "SEditorViewportViewMenu.h"
#include "SLGAEditorViewport.h"
#include "STransformViewportToolbar.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorSettings.h"
#include "LegoAbilityEditorViewportClient.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

void SLGAEditorViewportToolBar::Construct(const FArguments& InArgs, TSharedPtr<class SViewportTabBody> ViewportTabBody, TSharedPtr<class SEditorViewport> InRealViewport)
{
	Viewport = ViewportTabBody;
	AbilityEditor = InArgs._AbilityEditor;

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("NoBorder"))
		// Color and opacity is changed based on whether or not the mouse cursor is hovering over the toolbar area
		.ColorAndOpacity(this, &SViewportToolBar::GetColorAndOpacity)
		.ForegroundColor(FAppStyle::GetSlateColor("DefaultForeground"))
		[
			SNew(SHorizontalBox)
			// Generic viewport options
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2.0f, 2.0f)
			[
				//Menu
				SNew(SEditorViewportToolbarMenu)
				.ParentToolBar(SharedThis(this))
				.Image("EditorViewportToolBar.MenuDropdown")
				.OnGetMenuContent(this, &SLGAEditorViewportToolBar::GenerateViewMenu)
			]

			// Camera Type (Perspective/Top/etc...)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2.0f, 2.0f)
			[
				SNew(SEditorViewportToolbarMenu)
				.ParentToolBar(SharedThis(this))
				.Label(this, &SLGAEditorViewportToolBar::GetCameraMenuLabel)
				.LabelIcon(this, &SLGAEditorViewportToolBar::GetCameraMenuLabelIcon)
				.OnGetMenuContent(this, &SLGAEditorViewportToolBar::GenerateViewportTypeMenu)
			]

			// View menu (lit, unlit, etc...)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(2.0f, 2.0f)
			[
				SNew(SEditorViewportViewMenu, InRealViewport.ToSharedRef(), SharedThis(this))
			]

			+ SHorizontalBox::Slot()
			.Padding(3.0f, 1.0f)
			.HAlign(HAlign_Right)
			[
				SNew(STransformViewportToolBar)
				.Viewport(InRealViewport)
				.CommandList(InRealViewport->GetCommandList())
				.Visibility(this, &SLGAEditorViewportToolBar::GetTransformToolBarVisibility)
			]
		]
	];

	SViewportToolBar::Construct(SViewportToolBar::FArguments());
}

TSharedRef<SWidget> SLGAEditorViewportToolBar::GenerateViewMenu()
{
	FMenuBuilder ViewMenuBuilder(true, Viewport.Pin()->GetCommandList());
	ViewMenuBuilder.AddMenuEntry(FLegoAbilityEditorViewportCommands::Get().m_CameraFollow);

	return ViewMenuBuilder.MakeWidget();
}

TSharedRef<SWidget> SLGAEditorViewportToolBar::GenerateViewportTypeMenu()
{
	FMenuBuilder CameraMenuBuilder(true, Viewport.Pin()->GetViewportWidget()->GetCommandList());

	// Camera types
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Perspective);

	CameraMenuBuilder.BeginSection("LevelViewportCameraType_Ortho", LOCTEXT("CameraTypeHeader_Ortho", "Orthographic"));
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Top);
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Bottom);
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Left);
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Right);
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Front);
	CameraMenuBuilder.AddMenuEntry(FEditorViewportCommands::Get().Back);
	CameraMenuBuilder.EndSection();

	return CameraMenuBuilder.MakeWidget();
}

FText SLGAEditorViewportToolBar::GetCameraMenuLabel() const
{
	FText Label = LOCTEXT("CameraMenuTitle_Default", "Camera");
	TSharedPtr<SViewportTabBody> ViewportPin(Viewport.Pin());
	if (ViewportPin.IsValid())
	{
		switch (ViewportPin->GetEditorViewportClient()->GetViewportType())
		{
		case LVT_Perspective:
			Label = LOCTEXT("CameraMenuTitle_Perspective", "Perspective");
			break;
		case LVT_OrthoXY:
			Label = LOCTEXT("CameraMenuTitle_Top", "Top");
			break;
		case LVT_OrthoNegativeXZ:
			Label = LOCTEXT("CameraMenuTitle_Left", "Left");
			break;
		case LVT_OrthoNegativeYZ:
			Label = LOCTEXT("CameraMenuTitle_Front", "Front");
			break;
		case LVT_OrthoNegativeXY:
			Label = LOCTEXT("CameraMenuTitle_Bottom", "Bottom");
			break;
		case LVT_OrthoXZ:
			Label = LOCTEXT("CameraMenuTitle_Right", "Right");
			break;
		case LVT_OrthoYZ:
			Label = LOCTEXT("CameraMenuTitle_Back", "Back");
			break;
		case LVT_OrthoFreelook:
			break;
		}
	}

	return Label;
}

const FSlateBrush* SLGAEditorViewportToolBar::GetCameraMenuLabelIcon() const
{
	static FName PerspectiveIcon("EditorViewport.Perspective");
	static FName TopIcon("EditorViewport.Top");
	static FName LeftIcon("EditorViewport.Left");
	static FName FrontIcon("EditorViewport.Front");
	static FName BottomIcon("EditorViewport.Bottom");
	static FName RightIcon("EditorViewport.Right");
	static FName BackIcon("EditorViewport.Back");

	FName Icon = NAME_None;
	TSharedPtr<SViewportTabBody> ViewportPin(Viewport.Pin());
	if (ViewportPin.IsValid())
	{
		switch (ViewportPin->GetEditorViewportClient()->GetViewportType())
		{
		case LVT_Perspective:
			Icon = PerspectiveIcon;
			break;
		case LVT_OrthoXY:
			Icon = TopIcon;
			break;
		case LVT_OrthoNegativeXZ:
			Icon = LeftIcon;
			break;
		case LVT_OrthoNegativeYZ:
			Icon = FrontIcon;
			break;
		case LVT_OrthoNegativeXY:
			Icon = BottomIcon;
			break;
		case LVT_OrthoXZ:
			Icon = RightIcon;
			break;
		case LVT_OrthoYZ:
			Icon = BackIcon;
			break;
		case LVT_OrthoFreelook:
			break;
		}
	}

	return FAppStyle::GetBrush(Icon);
}

EVisibility SLGAEditorViewportToolBar::GetTransformToolBarVisibility() const
{
	return EVisibility::Visible;
}

#undef LOCTEXT_NAMESPACE
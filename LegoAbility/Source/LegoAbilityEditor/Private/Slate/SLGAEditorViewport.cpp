// Copyright S-Game, Inc. All Rights Reserved.

#include "SLGAEditorViewport.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/UICommandList.h"
#include "SLGAEditorViewportToolBar.h"
#include "LegoAbilityEditor.h"
#include "LegoAbilityEditorCommands.h"
#include "LegoAbilityEditorViewportClient.h"

#define LOCTEXT_NAMESPACE "LegoAbilityEditor"

void SLGAEditorViewport::Construct(const FArguments& InArgs, TSharedPtr<class FLegoAbilityEditor> InAbilityEditor, TSharedPtr<class SViewportTabBody> InViewportTabBody)
{
	AbilityEditor = InAbilityEditor;
	ViewportTabBody = InViewportTabBody;

	SEditorViewport::Construct(
		SEditorViewport::FArguments()
		.IsEnabled(FSlateApplication::Get().GetNormalExecutionAttribute())
		.AddMetaData<FTagMetaData>(TEXT("LegoAbility.AbilityEditor.Viewport"))
	);

	Client->VisibilityDelegate.BindSP(this, &SLGAEditorViewport::IsVisible);
}

TSharedRef<FEditorViewportClient> SLGAEditorViewport::MakeEditorViewportClient()
{
	TSharedPtr<FLegoAbilityEditorViewportClient> ViewportClient = MakeShareable(new FLegoAbilityEditorViewportClient(AbilityEditor.Pin()->GetPreviewScene(), AbilityEditor, SharedThis(this)));

	ViewportClient->ViewportType = LVT_Perspective;
	ViewportClient->bSetListenerPosition = false;
	ViewportClient->SetViewLocation(EditorViewportDefs::DefaultPerspectiveViewLocation);
	ViewportClient->SetViewRotation(EditorViewportDefs::DefaultPerspectiveViewRotation);
	ViewportClient->SetRealtime(true);
	ViewportClient->SetShowStats(true);

	return ViewportClient.ToSharedRef();
}

TSharedPtr<SWidget> SLGAEditorViewport::MakeViewportToolbar()
{
	return SNew(SLGAEditorViewportToolBar, ViewportTabBody.Pin(), SharedThis(this))
		.Cursor(EMouseCursor::Default)
		.AbilityEditor(AbilityEditor.Pin());
}

void SViewportTabBody::Construct(const FArguments& InArgs, TSharedPtr<FLegoAbilityEditor> InAbilityEditor)
{
	AbilityEditor = InAbilityEditor;

	check(AbilityEditor.IsValid());
	
	Commands = MakeShareable(new FUICommandList);

	FLegoAbilityEditorViewportCommands::Register();

	ViewportWidget = SNew(SLGAEditorViewport, InAbilityEditor, SharedThis(this));
	EditorViewportClient = ViewportWidget->GetViewportClient();

	this->ChildSlot
	[
		ViewportWidget.ToSharedRef()
	];

	TWeakPtr<SViewportTabBody> WeakTabBody = SharedThis(this);
	AbilityEditor.Pin()->SetViewportTabBody(WeakTabBody);
}

void SViewportTabBody::CaptureThumbnail() const
{
	TSharedPtr<FLegoAbilityEditorViewportClient> ViewportClient = StaticCastSharedPtr<FLegoAbilityEditorViewportClient>(ViewportWidget->GetViewportClient());
	if (ViewportClient.IsValid())
	{
		ViewportClient->CaptureThumbnail();
	}
}

#undef LOCTEXT_NAMESPACE
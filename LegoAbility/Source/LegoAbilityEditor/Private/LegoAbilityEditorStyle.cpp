// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityEditorStyle.h"
#include "Brushes/SlateBorderBrush.h"
#include "Brushes/SlateImageBrush.h"
#include "Brushes/SlateBoxBrush.h"
#include "Misc/Paths.h"
#include "Styling/CoreStyle.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Interfaces/IPluginManager.h"

#define IMAGE_PLUGIN_BRUSH(RelativePath, ...) FSlateImageBrush(FLegoAbilityEditorStyle::InContent(RelativePath, ".png"), __VA_ARGS__)
#define BOX_PLUGIN_BRUSH(RelativePath, ...) FSlateBoxBrush(FLegoAbilityEditorStyle::InContent(RelativePath, ".png"), __VA_ARGS__)

#define IMAGE_PLUGIN_BRUSH_SVG(RelativePath, ...) FSlateVectorImageBrush(FLegoAbilityEditorStyle::InContent(RelativePath, ".svg"), __VA_ARGS__)

#define RootToContentDir StyleSet->RootToContentDir
#define RootToCoreContentDir StyleSet->RootToCoreContentDir

#include "Styling/SlateStyleMacros.h"



TSharedPtr<FSlateStyleSet> FLegoAbilityEditorStyle::StyleSet = nullptr;
FName FLegoAbilityEditorStyle::StyleName(TEXT("LegoAbilityEditorStyle"));

void FLegoAbilityEditorStyle::Initialize()
{
	// Const icon sizes
	const FVector2D Icon16x16(16.0f, 16.0f);
	const FVector2D Icon20x20(20.0f, 20.0f);
	const FVector2D Icon32x32(32.0f, 32.0f);
	const FVector2D Icon40x40(40.0f, 40.0f);

	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	StyleSet->SetContentRoot(FPaths::EngineContentDir() / TEXT("Editor/Slate"));
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	// Text
	const FTextBlockStyle NormalText = FTextBlockStyle()
		.SetFont(DEFAULT_FONT("Regular", 8))
		.SetColorAndOpacity(FSlateColor::UseForeground())
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::Black)
		.SetHighlightColor(FLinearColor(0.02f, 0.3f, 0.0f))
		.SetHighlightShape(CORE_BOX_BRUSH("Common/TextBlockHighlightShape", FMargin(3.f / 8.f)));

	const FTextBlockStyle NormalRichTextStyle = FTextBlockStyle(NormalText)
		.SetFont(DEFAULT_FONT("Regular", 8))
		.SetColorAndOpacity(FSlateColor::UseForeground());

	StyleSet->Set("RichText.Text", NormalRichTextStyle);

	const FButtonStyle DarkHyperlinkButton = FButtonStyle()
		.SetNormal(CORE_BORDER_BRUSH("Old/HyperlinkDotted", FMargin(0, 0, 0, 3 / 16.0f), FSlateColor::UseForeground()))
		.SetPressed(FSlateNoResource())
		.SetHovered(CORE_BORDER_BRUSH("Old/HyperlinkUnderline", FMargin(0, 0, 0, 3 / 16.0f), FSlateColor::UseForeground()));

	const FHyperlinkStyle DarkHyperlink = FHyperlinkStyle()
		.SetUnderlineStyle(DarkHyperlinkButton)
		.SetTextStyle(NormalRichTextStyle)
		.SetPadding(FMargin(0.0f));

	StyleSet->Set("RichText.Hyperlink", DarkHyperlink);

	// Commands
	StyleSet->Set("LegoAbilityEditor.m_CaptureThumbnail", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/TB_CaptureThumbnail_40"), Icon40x40));
	StyleSet->Set("LegoAbilityEditor.m_CaptureThumbnail.Small", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/TB_CaptureThumbnail_40"), Icon20x20));

	// Tab Styles
	StyleSet->Set("LegoAbilityEditor.Tabs.Animation", new IMAGE_PLUGIN_BRUSH("Icons/Tab_Animations_16", Icon16x16));
	StyleSet->Set("LegoAbilityEditor.Tabs.Timeline", new IMAGE_PLUGIN_BRUSH("Icons/Tab_Timeline_16", Icon16x16));
	StyleSet->Set("LegoAbilityEditor.Tabs.EditorSettings", new IMAGE_PLUGIN_BRUSH("Icons/Tab_EditorSettings_16", Icon16x16));
	StyleSet->Set("LegoAbilityEditor.Tabs.AbilityDetails", new IMAGE_PLUGIN_BRUSH("Icons/Tab_AbilityProperties_16", Icon16x16));
	StyleSet->Set("LegoAbilityEditor.Tabs.ActionDetails", new IMAGE_PLUGIN_BRUSH("Icons/Tab_ActionProperties_16", Icon16x16));

	// Mode Icons
	StyleSet->Set("LegoAbilityEditor.TimelineMode", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/Mode_Timeline"), Icon40x40));
	StyleSet->Set("LegoAbilityEditor.TimelineMode.Small", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/Mode_Timeline"), Icon20x20));
	StyleSet->Set("LegoAbilityEditor.GraphMode", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/Mode_Graph"), Icon40x40));
	StyleSet->Set("LegoAbilityEditor.GraphMode.Small", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/Mode_Graph"), Icon20x20));

	StyleSet->Set("LegoAbilityEditor.Timeline.Loop.Enabled", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/Loop_16x"), Icon16x16));
	StyleSet->Set("LegoAbilityEditor.Timeline.Loop.Disabled", new IMAGE_PLUGIN_BRUSH(TEXT("Icons/Loop_Toggle_16x"), Icon16x16));

	// Timeline
	StyleSet->Set("AnimTimeline.Outliner.DefaultBorder", new FSlateColorBrush(FLinearColor::White));
	StyleSet->Set("AnimTimeline.Outliner.Splitter", FSplitterStyle().SetHandleNormalBrush(FSlateNoResource()).SetHandleHighlightBrush(FSlateNoResource()));
	StyleSet->Set("AnimTimeline.Outliner.Label", FTextBlockStyle(NormalText).SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f)).SetShadowOffset(FVector2D(1.0f, 1.0f)));
	StyleSet->Set("AnimTimeline.Outliner.ItemColor", FLinearColor(0.04f, 0.04f, 0.04f, 0.8f));
	StyleSet->Set("AnimTimeline.Outliner.HeaderColor", FLinearColor(0.03f, 0.03f, 0.03f, 1.0f));

	StyleSet->Set("LegoAbilityEditor.Timeline.ResizeToFit", new IMAGE_PLUGIN_BRUSH_SVG("Icons/TimelineFitToActions", Icon16x16));

	StyleSet->Set("Timeline.AutoPlay", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_AutoPlay"), Icon20x20));
	StyleSet->Set("Timeline.AutoPlay_Not", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_AutoPlay_Not"), Icon20x20));
	StyleSet->Set("Timeline.Loop", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_Loop"), Icon20x20));
	StyleSet->Set("Timeline.Loop_Not", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_Loop_Not"), Icon20x20));
	StyleSet->Set("Timeline.StopAbility", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_StopAbility"), Icon20x20));
	StyleSet->Set("Timeline.StopAbility_Not", new IMAGE_PLUGIN_BRUSH_SVG(TEXT("Icons/TL_StopAbility_Not"), Icon20x20));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FLegoAbilityEditorStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}

TSharedPtr<class ISlateStyle> FLegoAbilityEditorStyle::Get()
{
	return StyleSet;
}

const FSlateBrush* FLegoAbilityEditorStyle::GetBrush(FName BrushName)
{
	return StyleSet.IsValid() ? StyleSet->GetBrush(BrushName) : nullptr;
}

const FLinearColor& FLegoAbilityEditorStyle::GetColor(FName ColorName)
{
	return StyleSet.IsValid() ? StyleSet->GetColor(ColorName) : FStyleDefaults::GetColor();
}

FString FLegoAbilityEditorStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("LegoAbility"))->GetContentDir();
	return ContentDir / RelativePath + Extension;
}

#undef IMAGE_PLUGIN_BRUSH
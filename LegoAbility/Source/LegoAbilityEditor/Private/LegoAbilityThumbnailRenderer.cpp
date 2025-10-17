// Copyright S-Game, Inc. All Rights Reserved.

#include "LegoAbilityThumbnailRenderer.h"
#include "CanvasTypes.h"
#include "Engine/Texture2D.h"
#include "LegoAbilityBlueprint.h"
#include "UObject/ConstructorHelpers.h"
#include "TextureResource.h"

ULegoAbilityThumbnailRenderer::ULegoAbilityThumbnailRenderer()
{
	// Borrow the Particle System's texture for as a default image.
	ConstructorHelpers::FObjectFinder<UTexture2D> PSysThumbnail_NoImage(TEXT("/LegoAbility/Textures/AbilityIcon"));
	m_NoImage = PSysThumbnail_NoImage.Object;
}

void ULegoAbilityThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	if (ULegoAbilityBlueprint* AbilityBP = Cast<ULegoAbilityBlueprint>(Object))
	{
		if (AbilityBP->ThumbnailImage)
		{
			if (!AbilityBP->ThumbnailImage->GetResource())
			{
				AbilityBP->ThumbnailImage->UpdateResource();
			}

			if (AbilityBP->ThumbnailImage->GetResource())
			{
				Canvas->DrawTile(X, Y, Width, Height, 0.0f, 0.0f, 1.0f, 1.0f, FLinearColor::White, AbilityBP->ThumbnailImage->GetResource(), false);
			}
		}
		else if (m_NoImage)
		{
			Canvas->DrawTile(X, Y, Width, Height, 0.0f, 0.0f, 1.0f, 1.0f, FLinearColor::White, m_NoImage->GetResource(), true);
		}
	}
}

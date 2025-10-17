// Copyright S-Game, Inc. All Rights Reserved.

#pragma once

#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"
#include "LegoAbilityThumbnailRenderer.generated.h"

/* Simple class that renders a user-captured thumbnail for our Abilities. */
UCLASS()
class ULegoAbilityThumbnailRenderer : public UDefaultSizedThumbnailRenderer
{
	GENERATED_BODY()

public:
	ULegoAbilityThumbnailRenderer();

	// Begin UThumbnailRenderer interface
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	// End UThumbnailRenderer interface

private:
	UPROPERTY()
	class UTexture2D* m_NoImage;
};

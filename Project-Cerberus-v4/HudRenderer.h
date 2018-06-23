#pragma once
#include "TextureArray.h"
#include "SpriteAdapter.h"
#include "Vector2.h"
#include "HudOption.h"

class HudRenderer
{
	const Vector2 _hudSize;
	const Vector2 _hudInitialPosition;
	const Vector2 _chosenMarkerInitialPosition;
	const Vector2 _chosenMarkerNextPositionDistance;
	const Vector2 _firstOptionInitialPosition;

	TextureArray _hudTexture;
	SpriteAdapter _hudSprite;
	TextureArray _chosenMarkerTexture;
	SpriteAdapter _chosenMarkerSprite;
	TextureArray _optionTextures[HudOption::NoHudOption];
	SpriteAdapter _optionSprites[HudOption::NoHudOption];

public:
	HudRenderer(const Vector2 & screenSize, int tileLength);
	int getNoHudFrames() const;
	int getNoOptionFrames(HudOption option) const;
	int getNoChosenMarkerFrames() const;
	void setChosenMarker(HudOption option);
	void draw(Hud & hud, WindowAdapter & window);
	~HudRenderer();
};
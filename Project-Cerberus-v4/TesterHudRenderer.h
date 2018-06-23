#pragma once
#include "TextureArray.h"
#include "SpriteAdapter.h"
#include "Vector2.h"
#include "TesterHudOption.h"

class TesterHudRenderer
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
	TextureArray _optionTextures[TesterHudOption::NoTesterHudOption];
	SpriteAdapter _optionSprites[TesterHudOption::NoTesterHudOption];

public:
	TesterHudRenderer(const Vector2 & screenSize, int tileLength);
	int getNoHudFrames() const;
	int getNoOptionFrames(TesterHudOption option) const;
	int getNoChosenMarkerFrames() const;
	void setChosenMarker(TesterHudOption option);
	void draw(TesterHud & testerHud, WindowAdapter & window);
	~TesterHudRenderer();
};
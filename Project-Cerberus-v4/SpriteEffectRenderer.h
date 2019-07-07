#pragma once
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "SpriteEffectType.h"

class SpriteEffectRenderer
{
	const int TILE_LENGTH;

	SpriteAdapter _sprite;
	TextureArray _effectTextureArrays[SpriteEffectType::NoSpriteEffect];

	void setEffectPosition(const Vector2 & position);
	void setEffectTexture(SpriteEffectType spriteEffect, int frame);
	void setEffectDirection(const Direction4 direction);

public:
	SpriteEffectRenderer(const int TILE_LENGTH);
	void reflect(SpriteEffect & spriteEffect);
	const SpriteAdapter & getSprite() const;
	int getNoFrames(SpriteEffectType spriteEffect) const;
	~SpriteEffectRenderer();
};


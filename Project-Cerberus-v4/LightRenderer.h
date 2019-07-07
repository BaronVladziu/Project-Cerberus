#pragma once
#include "LightTile.h"
#include "SpriteAdapter.h"
#include "TextureArray.h"

class LightRenderer
{
	const int _TILE_LENGTH;

	SpriteAdapter _sprite;
	TextureArray _textures;

public:
	LightRenderer(const int TILE_LENGTH);
	void reflect(Square & square);
	const SpriteAdapter & getSprite() const;
	~LightRenderer();
};
#pragma once
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "TileType.h"

class TileRenderer
{
	const int TILE_LENGTH;

	SpriteAdapter _sprite;
	TextureArray _tileTextureArrays[TileType::NoTile];

	void setTilePosition(const Vector2 & position);
	void setTileTexture(const TileType tileType, int frame);
	void setTileDirection(const Direction4 direction);

public:
	TileRenderer(const int TILE_LENGTH);
	void reflect(Square & square);
	const SpriteAdapter & getSprite() const;
	int getNoFrames(TileType tile) const;
	~TileRenderer();
};
#include "TileRenderer.h"
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "TileType.h"
#include "Square.h"

TileRenderer::TileRenderer(const int TILE_LENGTH)
	: TILE_LENGTH(TILE_LENGTH),
	_sprite(TILE_LENGTH)
{
	const std::string path = "Textures/";
	_tileTextureArrays[TileType::EmptyTile].loadToArrayFromFiles(path + "TVoid");
	_tileTextureArrays[TileType::FloorTile].loadToArrayFromFiles(path + "TFloor");
	_tileTextureArrays[TileType::ObstacleTile].loadToArrayFromFiles(path + "TObstacle");
	_tileTextureArrays[TileType::WallTile].loadToArrayFromFiles(path + "TWall");
}
void TileRenderer::reflect(Square & square)
{
	setTilePosition((square.getPosition() + Vector2(1, 1)) * TILE_LENGTH);
	setTileTexture(square.getTileType(), square.getTileFrame());
	setTileDirection(square.getTileDirection());
}
void TileRenderer::setTilePosition(const Vector2 & position)
{
	_sprite.setPosition(position);
}
void TileRenderer::setTileTexture(const TileType tileType, int frame)
{
	_sprite.setTexture(_tileTextureArrays[tileType].getTexture(frame));
}
void TileRenderer::setTileDirection(const Direction4 direction)
{
	_sprite.setDirection(direction);
}
const SpriteAdapter & TileRenderer::getSprite() const
{
	return _sprite;
}
int TileRenderer::getNoFrames(TileType tile) const
{
	return _tileTextureArrays[tile].getNoFrames();
}
TileRenderer::~TileRenderer()
{}
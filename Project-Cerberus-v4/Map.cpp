#include "header.h"
#include "Map.h"
#include "Vector2.h"
#include "Square.h"
#include <vector>
#include "TileType.h"
#include "Direction4.h"
#include "TileRenderer.h"
#include "TileType.h"
#include "WindowAdapter.h"
#include "LightRenderer.h"

Map::Map(const Vector2 & size, int tileLength)
	: _SIZE(size),
	_tileRenderer(tileLength)
{
	_array = new Square*[_SIZE.y];
	for (int i = 0; i < _SIZE.y; i++)
	{
		_array[i] = new Square[_SIZE.x];
	}
	generateMap();
}
void Map::generateMap()
{
	setAllTilesTo(TileType::FloorTile);
}
void Map::setAllTilesTo(TileType tileType)
{
	for (int y = 0; y < _SIZE.y; y++)
	{
		for (int x = 0; x < _SIZE.x; x++)
		{
			getSquare(x, y).setPosition(x, y);
			getSquare(x, y).setTile(tileType, Direction4::Up, _tileRenderer);
		}
	}
}
const Vector2 & Map::getSize() const
{
	return _SIZE;
}
void Map::setTile(TileType type, const Vector2 & position)
{
	getSquare(position).setTile(type, Direction4::Up, _tileRenderer);
}
TileType Map::getTile(const Vector2 & position) const
{
	if (position.x >= 0 &&
		position.x < _SIZE.x &&
		position.y >= 0 &&
		position.y < _SIZE.y)
	{
		return getSquare(position).getTileType();
	}
	return TileType::NoTile;
}
void Map::setCreature(Creature * creature, const Vector2 & position)
{
	getSquare(position).setCreature(creature);
}
void Map::hurt(const Vector2 & position)
{
	getSquare(position).hurt();
}
const Creature * Map::getCreature(const Vector2 & position) const
{
	return getSquare(position).getCreature();
}
void Map::resetLight()
{
	for (int i = 0; i < _SIZE.y; i++)
	{
		for (int j = 0; j < _SIZE.x; j++)
		{
			getSquare(i, j).resetLight();
		}
	}
}
void Map::setTileToSeen(const Vector2 & position)
{
	getSquare(position).setToSeen();
}
bool Map::getIfSeen(const Vector2 & position)
{
	if (position.x >= 0 &&
		position.x < _SIZE.x &&
		position.y >= 0 &&
		position.y < _SIZE.y)
	{
		return getSquare(position).getLightTile().getIfSeen();
	}
	return true;
}
void Map::draw(WindowAdapter & window)
{
	for (int i = 0; i < _SIZE.y; i++)
	{
		for (int j = 0; j < _SIZE.x; j++)
		{
			_tileRenderer.reflect(getSquare(i, j));
			window.drawIfOnMap(_tileRenderer.getSprite());
		}
	}
}
void Map::drawLight(WindowAdapter & window)
{
	for (int i = 0; i < _SIZE.y; i++)
	{
		for (int j = 0; j < _SIZE.x; j++)
		{
			_lightRenderer.reflect(getSquare(i, j));
			window.drawIfOnMap(_lightRenderer.getSprite());
		}
	}
}
void Map::setTileLightness(const Vector2 & position, int lightness)
{
	if (position.x >= 0 &&
		position.x < _SIZE.x &&
		position.y >= 0 &&
		position.y < _SIZE.y)
	{
		getSquare(position).lightTile(lightness);
	}
}
int Map::getTileLightness(const Vector2 & position) const
{
	if (position.x >= 0 &&
		position.x < _SIZE.x &&
		position.y >= 0 &&
		position.y < _SIZE.y)
	{
		return getSquare(position).getLightTile().getLightness();
	}
	return 255;
}
Square & Map::getSquare(const Vector2 & position) const
{
	assert(position.x >= 0);
	assert(position.x < _SIZE.x);
	assert(position.y >= 0);
	assert(position.y < _SIZE.y);
	return _array[position.y][position.x];
}
Square & Map::getSquare(int x, int y) const
{
	assert(x >= 0);
	assert(x < _SIZE.x);
	assert(y >= 0);
	assert(y < _SIZE.y);
	return _array[y][x];
}
Map::~Map()
{
	for (int i = 0; i < _SIZE.y; i++)
	{
		delete[] _array[i];
	}
	delete[] _array;
}
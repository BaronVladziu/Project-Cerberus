#include "Square.h"
#include "TileRenderer.h"
#include <cassert>

Square::Square()
	: _creature(nullptr)
{}
const Vector2 & Square::getPosition() const
{
	return _position;
}
TileType Square::getTileType() const
{
	return _tile.getType();
}
Direction4 Square::getTileDirection() const
{
	return _tile.getDirection();
}
int Square::getTileFrame()
{
	return _tile.getFrame();
}
void Square::hurt()
{
	if (_creature != nullptr)
	{
		_creature->hurt();
	}
}
CreatureType Square::getCreatureType() const
{
	assert(_creature != nullptr);
	return _creature->getType();
}
Direction4 Square::getCreatureDirection() const
{
	assert(_creature != nullptr);
	return _creature->getActualDirection();
}
int Square::getCreatureFrame()
{
	assert(_creature != nullptr);
	return _creature->getFrame();
}
void Square::setPosition(const Vector2 & position)
{
	_position = position;
}
void Square::setPosition(const int x, const int y)
{
	_position.x = x;
	_position.y = y;
}
void Square::setTile(TileType type, Direction4 direction, const TileRenderer & tileRenderer)
{
	_tile.set(type, direction, tileRenderer.getNoFrames(type));
}
const Creature * Square::getCreature()
{
	return _creature;
}
void Square::setCreature(Creature * creature)
{
	_creature = creature;
}
const LightTile & Square::getLightTile() const
{
	return _lightTile;
}
void Square::resetLight()
{
	_lightTile.reset();
}
void Square::setToSeen()
{
	_lightTile.setToSeen();
}
void Square::setTileLightness(int lightness)
{
	_lightTile.setTileLightness(lightness);
}
Square::~Square()
{}
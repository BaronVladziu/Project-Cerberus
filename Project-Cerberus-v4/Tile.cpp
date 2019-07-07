#include "Tile.h"
#include "TileType.h"
#include "Direction4.h"
#include "Animation.h"

Tile::Tile()
	: _type(TileType::EmptyTile), _direction(Direction4::Down)
{}
void Tile::set(TileType type, Direction4 direction, int noFrames)
{
	assert(direction < Direction4::Center);
	_type = type;
	_direction = direction;
	_animation.setNoFrames(noFrames);
}
TileType Tile::getType() const
{
	return _type;
}
Direction4 Tile::getDirection() const
{
	return _direction;
}
int Tile::getFrame()
{
	return _animation.getFrame();
}
Tile::~Tile()
{}
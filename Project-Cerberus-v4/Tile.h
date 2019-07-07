#pragma once
#include "TileType.h"
#include "Direction4.h"
#include "Animation.h"

class Tile
{
	TileType _type;
	Direction4 _direction;
	Animation _animation;

public:
	Tile();
	void set(TileType type, Direction4 direction, int noFrames);
	TileType getType() const;
	Direction4 getDirection() const;
	int getFrame();
	~Tile();
};
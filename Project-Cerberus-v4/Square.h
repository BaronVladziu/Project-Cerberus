#pragma once
#include "Tile.h"
#include "Vector2.h"
#include "Creature.h"
#include "LightTile.h"

class Square
{
	Vector2 _position;
	Tile _tile;
	Creature * _creature;
	LightTile _lightTile;

public:
	Square();
	const Vector2 & getPosition() const;
	TileType getTileType() const;
	Direction4 getTileDirection() const;
	int getTileFrame();
	void hurt();
	CreatureType getCreatureType() const;
	Direction4 getCreatureDirection() const;
	int getCreatureFrame();
	void setPosition(const Vector2 & position);
	void setPosition(const int x, const int y);
	void setTile(TileType type, Direction4 direction, const TileRenderer & tileRenderer);
	const Creature * getCreature();
	void setCreature(Creature * creature);
	const LightTile & getLightTile() const;
	void resetLight();
	void setToSeen();
	void setTileLightness(int lightness);
	~Square();
};
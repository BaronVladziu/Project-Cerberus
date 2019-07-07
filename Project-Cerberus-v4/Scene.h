#pragma once
#include "Map.h"
#include "Square.h"
#include "Vector2.h"
#include "CreatureScene.h"
#include "EffectScene.h"
#include "LightScene.h"

class Scene
{
	const Vector2 _MAP_SIZE;

	Map _map;
	CreatureScene _creatureScene;
	EffectScene _effectScene;
	LightScene _lightScene;

	bool isFloorOnSquare(const Vector2 & position) const;
	bool isWallOnSquare(const Vector2 & position) const;

public:
	Scene(int tileLength);
	void nextTurn();
	Vector2 getPlayerPosition() const;
	Vector2 getViewCenterPosition();
	void setTile(TileType type, const Vector2 & position);
	void draw(WindowAdapter & window);
	~Scene();
};
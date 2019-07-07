#include "Scene.h"
#include "Map.h"
#include "CreatureRenderer.h"
#include "WindowAdapter.h"

Scene::Scene(int tileLength)
	: _MAP_SIZE(50, 50),
	_map(_MAP_SIZE, tileLength),
	_creatureScene(tileLength),
	_effectScene(tileLength),
	_lightScene(tileLength)
{}
void Scene::nextTurn()
{
	_creatureScene.nextTurn(_map);
	_lightScene.nextTurn(_map);
}
bool Scene::isFloorOnSquare(const Vector2 & position) const
{
	switch (_map.getTile(position))
	{
	case TileType::FloorTile:
		return true;
	default:
		return false;
	}
}
bool Scene::isWallOnSquare(const Vector2 & position) const
{
	switch (_map.getTile(position))
	{
	case TileType::WallTile:
		return true;
	default:
		return false;
	}
}
Vector2 Scene::getPlayerPosition() const
{
	if (_player != nullptr)
	{
		return _player->getPosition();
	}
	else
	{
		return Vector2(-1, -1);
	}
}
Vector2 Scene::getViewCenterPosition()
{
	return getPlayerPosition();
}
void Scene::setTile(TileType type, const Vector2 & position)
{
	_map.setTile(type, position);
}
void Scene::draw(WindowAdapter & window)
{
	_map.draw(window);
	for (Creature & creature : _creatures)
	{
		_creatureRenderer.reflect(creature);
		window.drawIfOnMap(_creatureRenderer.getSprite());
	}
	_effectScene.draw(window);
	_map.drawLight(window);
}
Scene::~Scene()
{}
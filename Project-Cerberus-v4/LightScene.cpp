#include "LightScene.h"
#include "Map.h"

LightScene::LightScene(int tileLength)
	: _LIGHT_SUPRESSING_FACTOR(20),
	_lightRenderer(tileLength)
{
	countLights();
	determineSeenSquares();
}
void LightScene::nextTurn(Map & map)
{
	resetLight();
	countLights();
	determineSeenSquares();
}
void LightScene::resetLight()
{
	_map.resetLight();
}
void LightScene::countLights()
{
	spreadLight(_player->getPosition(), 255);
}
void LightScene::spreadLight(Vector2 position, int lightness)
{
	if (lightness > _map.getTileLightness(position))
	{
		_map.setTileLightness(position, lightness);
		if (isWallOnSquare(position) == false)
		{
			lightness -= _LIGHT_SUPRESSING_FACTOR;
			spreadLight(position + Vector2(1, 0), lightness);
			spreadLight(position + Vector2(-1, 0), lightness);
			spreadLight(position + Vector2(0, 1), lightness);
			spreadLight(position + Vector2(0, -1), lightness);
		}
	}
}
void LightScene::determineSeenSquares()
{
	if (_player != nullptr)
	{
		for (int i = 0; i < _MAP_SIZE.x; i++)
		{
			createLineOfSight(_player->getPosition(), Vector2(i, 0));
			createLineOfSight(_player->getPosition(), Vector2(i, _MAP_SIZE.y - 1));
		}
		for (int i = 0; i < _MAP_SIZE.y; i++)
		{
			createLineOfSight(_player->getPosition(), Vector2(0, i));
			createLineOfSight(_player->getPosition(), Vector2(_MAP_SIZE.x - 1, i));
		}
	}
}
void LightScene::createLineOfSight(Vector2 startPosition, Vector2 endPosition)
{
	Vector2 actualPosition = startPosition;
	if (abs(endPosition.x - startPosition.x) > abs(endPosition.y - startPosition.y))
	{
		float a = abs(float(endPosition.y - startPosition.y) / float(endPosition.x - startPosition.x));
		if (startPosition.x > endPosition.x)
		{
			if (startPosition.y > endPosition.y)
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.y - actualPosition.y) / float(endPosition.x - actualPosition.x)) > a)
					{
						actualPosition.y--;
					}
					else
					{
						actualPosition.x--;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
			else
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.y - actualPosition.y) / float(endPosition.x - actualPosition.x)) > a)
					{
						actualPosition.y++;
					}
					else
					{
						actualPosition.x--;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
		}
		else
		{
			if (startPosition.y > endPosition.y)
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.y - actualPosition.y) / float(endPosition.x - actualPosition.x)) > a)
					{
						actualPosition.y--;
					}
					else
					{
						actualPosition.x++;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
			else
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.y - actualPosition.y) / float(endPosition.x - actualPosition.x)) > a)
					{
						actualPosition.y++;
					}
					else
					{
						actualPosition.x++;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
		}
	}
	else
	{
		float a = abs(float(endPosition.x - startPosition.x) / float(endPosition.y - startPosition.y));
		if (startPosition.x > endPosition.x)
		{
			if (startPosition.y > endPosition.y)
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.x - actualPosition.x) / float(endPosition.y - actualPosition.y)) > a)
					{
						actualPosition.x--;
					}
					else
					{
						actualPosition.y--;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
			else
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.x - actualPosition.x) / float(endPosition.y - actualPosition.y)) > a)
					{
						actualPosition.x--;
					}
					else
					{
						actualPosition.y++;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
		}
		else
		{
			if (startPosition.y > endPosition.y)
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.x - actualPosition.x) / float(endPosition.y - actualPosition.y)) > a)
					{
						actualPosition.x++;
					}
					else
					{
						actualPosition.y--;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
			else
			{
				while (!isWallOnSquare(actualPosition) && actualPosition != endPosition)
				{
					_map.setTileToSeen(actualPosition);
					if (abs(float(endPosition.x - actualPosition.x) / float(endPosition.y - actualPosition.y)) > a)
					{
						actualPosition.x++;
					}
					else
					{
						actualPosition.y++;
					}
				}
				_map.setTileToSeen(actualPosition);
			}
		}
	}
}
LightScene::~LightScene()
{}
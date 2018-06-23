#pragma once
#include "header.h"
#include "LightRenderer.h"

class LightScene
{
	const int _LIGHT_SUPRESSING_FACTOR;

	LightRenderer _lightRenderer;

	void resetLight();
	void determineSeenSquares();
	void createLineOfSight(Vector2 startPosition, Vector2 endPosition);
	void countLights();
	void spreadLight(Vector2 position, int lightness);

public:
	LightScene(int tileLength);
	void nextTurn(Map & map);
	void draw(WindowAdapter & window);
	~LightScene();
};
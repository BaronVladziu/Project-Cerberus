#pragma once
#include "header.h"
#include "Vector2.h"

class CameraMoveFilter
{
	const int _FILTERING_RATIO;

	std::list<sf::Vector2f> _cameraPositions;

	void initializeFilter(float posx, float posy);
	sf::Vector2f countNextPosition();

public:
	CameraMoveFilter();
	sf::Vector2f filterPosition(float posx, float posy);
	sf::Vector2f filterPosition();
	~CameraMoveFilter();
};
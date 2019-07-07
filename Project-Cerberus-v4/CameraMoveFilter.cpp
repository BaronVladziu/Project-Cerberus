#include "CameraMoveFilter.h"
#include "header.h"
#include "Vector2.h"

CameraMoveFilter::CameraMoveFilter()
	: _FILTERING_RATIO(8)
{}
sf::Vector2f CameraMoveFilter::filterPosition(float posx, float posy)
{
	if (_cameraPositions.empty())
	{
		initializeFilter(posx, posy);
	}
	_cameraPositions.pop_front();
	_cameraPositions.push_back(sf::Vector2f(posx, posy));
	return countNextPosition();
}
void CameraMoveFilter::initializeFilter(float posx, float posy)
{
	for (int i = 0; i < _FILTERING_RATIO; i++)
	{
		_cameraPositions.push_back(sf::Vector2f(posx, posy));
	}
}
sf::Vector2f CameraMoveFilter::filterPosition()
{
	return countNextPosition();
}
sf::Vector2f CameraMoveFilter::countNextPosition()
{
	sf::Vector2f nextPos;
	for (std::list<sf::Vector2f>::iterator it = _cameraPositions.begin(); it != _cameraPositions.end(); it++)
	{
		nextPos += *it;
	}
	return (nextPos / float(_FILTERING_RATIO));
}
CameraMoveFilter::~CameraMoveFilter()
{}
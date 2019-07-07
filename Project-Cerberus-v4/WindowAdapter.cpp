#include "WindowAdapter.h"
#include "header.h"
#include "EventType.h"
#include "Vector2.h"
#include "CameraMoveFilter.h"

WindowAdapter::WindowAdapter()
	: _WIDTH(800),
	_HEIGHT(600),
	_TITLE("-Project-Cerberus-v4-Pre-Alpha-"),
	_ZOOM_FACTOR(1.4f),
	_window(sf::VideoMode(_WIDTH, _HEIGHT), _TITLE),
	_mapView(sf::Vector2f(0.f, 0.f), sf::Vector2f(float(_WIDTH), float(_HEIGHT))),
	_hudView(sf::Vector2f(0.f, 0.f), sf::Vector2f(float(_WIDTH), float(_HEIGHT)))
{
	_window.setFramerateLimit(60);
	_window.setVerticalSyncEnabled(true);
	_mapView.zoom(0.5f);
	_hudView.zoom(0.5f);
}
bool WindowAdapter::isOpen() const
{
	return _window.isOpen();
}
Vector2 WindowAdapter::getWindowSize() const
{
	return Vector2(_WIDTH, _HEIGHT);
}
Vector2 WindowAdapter::getMousePosition(const int tileLength) const
{
	sf::Vector2f pos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window), _mapView);
	pos /= float(tileLength);
	pos.x -= 0.5f;
	pos.y -= 0.5f;
	return Vector2(int(pos.x), int(pos.y));
}
EventType WindowAdapter::pollEvent()
{
	return _eventAdapter.pollEvent(_window);
}
void WindowAdapter::setView(float x, float y)
{
	if (x <= 0 || y <= 0)
	{
		_mapView.setCenter(_cameraMoveFilter.filterPosition());
	}
	else
	{
		_mapView.setCenter(_cameraMoveFilter.filterPosition(x, y));
	}
	_window.setView(_mapView);
}
void WindowAdapter::setView(Vector2 center)
{
	setView(float(center.x), float(center.y));
}
void WindowAdapter::resetView()
{
	_window.setView(_hudView);
}
void WindowAdapter::zoomIn()
{
	_mapView.zoom(1.f / _ZOOM_FACTOR);
}
void WindowAdapter::zoomOut()
{
	_mapView.zoom(_ZOOM_FACTOR);
}
void WindowAdapter::clear()
{
	_window.clear();
}
void WindowAdapter::drawIfOnMap(const SpriteAdapter & spriteAdapter)
{
	if (ifCoincidesWithMapView(spriteAdapter))
	{
		drawSprite(spriteAdapter);
	}
}
bool WindowAdapter::ifCoincidesWithMapView(const SpriteAdapter & spriteAdapter) const
{
	sf::FloatRect spriteBounds = spriteAdapter.getDrawableSprite().getGlobalBounds();
	if (spriteBounds.left + spriteBounds.width >= _mapView.getCenter().x - (_mapView.getSize().x/2) &&
		spriteBounds.left <= _mapView.getCenter().x + (_mapView.getSize().x/2) &&
		spriteBounds.top + spriteBounds.height >= _mapView.getCenter().y - (_mapView.getSize().y/2) &&
		spriteBounds.top <= _mapView.getCenter().y + (_mapView.getSize().y/2))
	{
		return true;
	}
	return false;
}
void WindowAdapter::drawSprite(const SpriteAdapter & spriteAdapter)
{
	_window.draw(spriteAdapter.getDrawableSprite());
}
void WindowAdapter::display()
{
	_window.display();
}
void WindowAdapter::close()
{
	_window.close();
}
WindowAdapter::~WindowAdapter()
{}
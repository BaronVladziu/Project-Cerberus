#pragma once
#include "header.h"
#include "EventAdapter.h"
#include "TileRenderer.h"
#include "CreatureRenderer.h"
#include "CameraMoveFilter.h"

class WindowAdapter
{
	const int _WIDTH;
	const int _HEIGHT;
	const sf::String _TITLE;
	const float _ZOOM_FACTOR;

	sf::RenderWindow _window;
	sf::View _mapView;
	CameraMoveFilter _cameraMoveFilter;
	sf::View _hudView;
	EventAdapter _eventAdapter;

	bool ifCoincidesWithMapView(const SpriteAdapter & spriteAdapter) const;

public:
	WindowAdapter();
	bool isOpen() const;
	Vector2 getWindowSize() const;
	Vector2 getMousePosition(const int tileLength) const;
	EventType pollEvent();
	void setView(float x, float y);
	void setView(Vector2 center);
	void resetView();
	void zoomIn();
	void zoomOut();
	void clear();
	void drawIfOnMap(const SpriteAdapter & spriteAdapter);
	void drawSprite(const SpriteAdapter & spriteAdapter);
	void display();
	void close();
	~WindowAdapter();
};
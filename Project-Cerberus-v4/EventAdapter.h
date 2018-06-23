#pragma once
#include "header.h"

class EventAdapter
{
	sf::Event _event;

	EventType translateEvent(const sf::Event & event) const;

public:
	EventAdapter();
	EventType pollEvent(sf::RenderWindow & window);
	~EventAdapter();
};
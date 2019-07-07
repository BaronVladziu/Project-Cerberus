#pragma once
#include "header.h"

class SpriteAdapter
{
	sf::Sprite _sprite;

public:
	SpriteAdapter(int tileLength);
	void setPosition(float x, float y);
	void setPosition(const Vector2 & position);
	Vector2 getPosition() const;
	void setDirection(Direction4 direction);
	void setTexture(const TextureAdapter & texture);
	void setColor(const LightColor & color);
	const sf::Sprite & getDrawableSprite() const;
	~SpriteAdapter();
};
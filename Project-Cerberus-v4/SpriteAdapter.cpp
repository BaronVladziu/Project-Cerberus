#include "SpriteAdapter.h"
#include "TextureAdapter.h"
#include "Direction4.h"
#include "Vector2.h"
#include "LightColor.h"

SpriteAdapter::SpriteAdapter(int tileLength)
{
	_sprite.setOrigin(tileLength * 0.5f, tileLength * 0.5f);
}
void SpriteAdapter::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}
void SpriteAdapter::setPosition(const Vector2 & position)
{
	_sprite.setPosition(float(position.x), float(position.y));
}
Vector2 SpriteAdapter::getPosition() const
{
	return Vector2(int(_sprite.getPosition().x), int(_sprite.getPosition().y));
}
void SpriteAdapter::setDirection(Direction4 direction)
{
	assert(direction < Direction4::Center);
	switch (direction)
	{
	case Direction4::Down:
		_sprite.setRotation(180.f);
		break;
	case Direction4::Left:
		_sprite.setRotation(270.f);
		break;
	case Direction4::Right:
		_sprite.setRotation(90.f);
		break;
	case Direction4::Up:
		_sprite.setRotation(0.f);
		break;
	}
}
void SpriteAdapter::setTexture(const TextureAdapter & texture)
{
	_sprite.setTexture(texture.getSFMLTexture());
}
void SpriteAdapter::setColor(const LightColor & color)
{
	_sprite.setColor(sf::Color(color.red, color.green, color.blue, color.alpha));
}
const sf::Sprite & SpriteAdapter::getDrawableSprite() const
{
	return _sprite;
}
SpriteAdapter::~SpriteAdapter()
{}
#include "SpriteEffect.h"
#include "Vector2.h"
#include "Direction4.h"
#include "Animation.h"
#include "SpriteEffectType.h"

SpriteEffect::SpriteEffect(SpriteEffectType type, Vector2 position, Direction4 direction, int noFrames)
	: _type(type),
	_position(position),
	_direction(direction)
{
	assert(direction < Direction4::Center);
	_animation.setNoFrames(noFrames);
}
bool SpriteEffect::isItTimeToKillMe() const
{
	return _animation.getIfEnded();
}
SpriteEffectType SpriteEffect::getType() const
{
	return _type;
}
Vector2 SpriteEffect::getPosition() const
{
	return _position;
}
Direction4 SpriteEffect::getDirection() const
{
	return _direction;
}
int SpriteEffect::getFrame()
{
	return _animation.getFrame();
}
SpriteEffect::~SpriteEffect()
{}
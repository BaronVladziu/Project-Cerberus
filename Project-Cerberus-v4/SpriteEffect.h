#pragma once
#include "Vector2.h"
#include "Direction4.h"
#include "Animation.h"
#include "SpriteEffectType.h"

class SpriteEffect
{
	SpriteEffectType _type;
	Vector2 _position;
	Direction4 _direction;
	Animation _animation;

public:
	SpriteEffect(SpriteEffectType type, Vector2 _position, Direction4 _direction, int noFrames);
	bool isItTimeToKillMe() const;
	SpriteEffectType getType() const;
	Vector2 getPosition() const;
	Direction4 getDirection() const;
	int getFrame();
	~SpriteEffect();
};
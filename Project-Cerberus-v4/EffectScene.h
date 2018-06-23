#pragma once
#include "header.h"
#include "SpriteEffect.h"
#include "SpriteEffectRenderer.h"

class EffectScene
{
	SpriteEffectRenderer _spriteEffectRenderer;
	std::list<std::unique_ptr<SpriteEffect>> _spriteEffects;

	void killEndedSpriteEffects();
	void addSpriteEffect(SpriteEffectType type, Vector2 position, Direction4 direction);

public:
	EffectScene(int tileLength);
	void draw(WindowAdapter & window);
	~EffectScene();
};
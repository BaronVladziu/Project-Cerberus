#include "EffectScene.h"
#include "header.h"
#include "SpriteEffect.h"
#include "SpriteEffectRenderer.h"
#include "WindowAdapter.h"

EffectScene::EffectScene(int tileLength)
	: _spriteEffectRenderer(tileLength)
{}
void EffectScene::addSpriteEffect(SpriteEffectType type, Vector2 position, Direction4 direction)
{
	_spriteEffects.push_back(std::unique_ptr<SpriteEffect>(new SpriteEffect(type, position, direction, _spriteEffectRenderer.getNoFrames(type))));
}
void EffectScene::killEndedSpriteEffects()
{
	_spriteEffects.remove_if([](std::unique_ptr<SpriteEffect> & spriteEffect) { return spriteEffect->isItTimeToKillMe(); });
}
void EffectScene::draw(WindowAdapter & window)
{
	killEndedSpriteEffects();
	for (std::unique_ptr<SpriteEffect> & spriteEffect : _spriteEffects)
	{
		_spriteEffectRenderer.reflect(*spriteEffect);
		window.drawIfOnMap(_spriteEffectRenderer.getSprite());
	}
}
EffectScene::~EffectScene()
{}
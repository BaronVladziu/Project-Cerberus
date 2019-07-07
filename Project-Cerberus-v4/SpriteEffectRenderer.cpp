#include "SpriteEffectRenderer.h"
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "SpriteEffectType.h"
#include "SpriteEffect.h"

SpriteEffectRenderer::SpriteEffectRenderer(const int TILE_LENGTH)
	: TILE_LENGTH(TILE_LENGTH),
	_sprite(TILE_LENGTH)
{
	const std::string path = "Textures/";
	_effectTextureArrays[SpriteEffectType::SparksSpriteEffect].loadToArrayFromFiles(path + "ESparks");
	_effectTextureArrays[SpriteEffectType::MeleeAttackSpriteEffect].loadToArrayFromFiles(path + "EMeleeAttack");
}
void SpriteEffectRenderer::reflect(SpriteEffect & spriteEffect)
{
	setEffectPosition((spriteEffect.getPosition() + Vector2(1, 1)) * TILE_LENGTH);
	setEffectTexture(spriteEffect.getType(), spriteEffect.getFrame());
	setEffectDirection(spriteEffect.getDirection());
}
void SpriteEffectRenderer::setEffectPosition(const Vector2 & position)
{
	_sprite.setPosition(position);
}
void SpriteEffectRenderer::setEffectTexture(SpriteEffectType spriteEffect, int frame)
{
	_sprite.setTexture(_effectTextureArrays[spriteEffect].getTexture(frame));
}
void SpriteEffectRenderer::setEffectDirection(const Direction4 direction)
{
	_sprite.setDirection(direction);
}
const SpriteAdapter & SpriteEffectRenderer::getSprite() const
{
	return _sprite;
}
int SpriteEffectRenderer::getNoFrames(SpriteEffectType spriteEffect) const
{
	return _effectTextureArrays[spriteEffect].getNoFrames();
}
SpriteEffectRenderer::~SpriteEffectRenderer()
{}
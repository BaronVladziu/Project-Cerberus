#include "CreatureRenderer.h"
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "CreatureType.h"
#include "Square.h"

CreatureRenderer::CreatureRenderer(const int TILE_LENGTH)
	: TILE_LENGTH(TILE_LENGTH),
	_sprite(TILE_LENGTH)
{
	const std::string path = "Textures/";
	_creatureTextureArrays[CreatureType::Player].loadToArrayFromFiles(path + "CSpiderMove");
	_creatureTextureArrays[CreatureType::Zombie].loadToArrayFromFiles(path + "CZombieIdle");
}
void CreatureRenderer::reflect(Creature & creature)
{
	setCreaturePosition((creature.getPosition() + Vector2(1, 1)) * TILE_LENGTH);
	setCreatureTexture(creature.getType(), creature.getFrame());
	setCreatureDirection(creature.getActualDirection());
}
void CreatureRenderer::setCreaturePosition(const Vector2 & position)
{
	_sprite.setPosition(position);
}
void CreatureRenderer::setCreatureTexture(const CreatureType creatureType, int frame)
{
	_sprite.setTexture(_creatureTextureArrays[creatureType].getTexture(frame));
}
void CreatureRenderer::setCreatureDirection(const Direction4 direction)
{
	assert(direction < Direction4::Center);
	_sprite.setDirection(direction);
}
const SpriteAdapter & CreatureRenderer::getSprite() const
{
	return _sprite;
}
int CreatureRenderer::getNoFrames(CreatureType creature) const
{
	return _creatureTextureArrays[creature].getNoFrames();
}
CreatureRenderer::~CreatureRenderer()
{}
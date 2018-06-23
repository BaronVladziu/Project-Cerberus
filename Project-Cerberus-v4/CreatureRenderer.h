#pragma once
#include "SpriteAdapter.h"
#include "TextureArray.h"
#include "CreatureType.h"

class CreatureRenderer
{
	const int TILE_LENGTH;

	SpriteAdapter _sprite;
	TextureArray _creatureTextureArrays[CreatureType::NoCreature];

	void setCreaturePosition(const Vector2 & position);
	void setCreatureTexture(const CreatureType creatureType, int frame);
	void setCreatureDirection(const Direction4 direction);

public:
	CreatureRenderer(const int TILE_LENGTH);
	void reflect(Creature & creature);
	const SpriteAdapter & getSprite() const;
	int getNoFrames(CreatureType creature) const;
	~CreatureRenderer();
};
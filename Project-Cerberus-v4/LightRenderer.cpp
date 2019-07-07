#include "header.h"
#include "LightRenderer.h"
#include "LightTile.h"
#include "SpriteAdapter.h"
#include "Square.h"
#include "LightColor.h"

LightRenderer::LightRenderer(const int TILE_LENGTH)
	: _TILE_LENGTH(TILE_LENGTH),
	_sprite(_TILE_LENGTH),
	_textures("Textures/TVoid")
{
	_sprite.setTexture(_textures.getTexture(0));
}
void LightRenderer::reflect(Square & square)
{
	_sprite.setPosition((square.getPosition() + Vector2(1, 1)) * _TILE_LENGTH);
	LightColor color;
	color.red = 0;
	color.green = 0;
	color.blue = 0;
	int lightness = square.getLightTile().getLightness();
	if (square.getLightTile().getIfSeen() == false || lightness < 20)
	{
		//lightness /= 3; //<---
		lightness = 20;
	}
	color.alpha = 255 - lightness;
	_sprite.setColor(color);
}
const SpriteAdapter & LightRenderer::getSprite() const
{
	return _sprite;
}
LightRenderer::~LightRenderer()
{}
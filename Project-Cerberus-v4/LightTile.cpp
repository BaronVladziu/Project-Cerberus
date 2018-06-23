#include "LightTile.h"
#include "header.h"

LightTile::LightTile()
{
	reset();
}
void LightTile::reset()
{
	_ifSeen = false;
	_lightness = 0;
}
void LightTile::setToSeen()
{
	_ifSeen = true;
}
bool LightTile::getIfSeen() const
{
	return _ifSeen;
}
void LightTile::setTileLightness(int lightness)
{
	assert(lightness >= 0);
	assert(lightness < 256);
	_lightness = lightness;
}
int LightTile::getLightness() const
{
	return _lightness;
}
LightTile::~LightTile()
{}
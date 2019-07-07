#include "HudRenderer.h"
#include "TextureArray.h"
#include "Hud.h"
#include "Vector2.h"
#include "WindowAdapter.h"

HudRenderer::HudRenderer(const Vector2 & screenSize, int tileLength)
	: _hudSize(34, 34),
	_hudInitialPosition(float(_hudSize.x - 20) - float(screenSize.x / 4), float(screenSize.y / 4) - float(_hudSize.y - 4)),
	_chosenMarkerInitialPosition(_hudInitialPosition + Vector2(6, 6)),
	_chosenMarkerNextPositionDistance(29, 0),
	_firstOptionInitialPosition(_chosenMarkerInitialPosition + Vector2(3, 3)),
	_hudTexture("Textures/Hud"),
	_hudSprite(tileLength),
	_chosenMarkerTexture("Textures/AbilityChosen"),
	_chosenMarkerSprite(tileLength),
	_optionSprites{ tileLength }
{
	_hudSprite.setPosition(_hudInitialPosition);
	_chosenMarkerSprite.setPosition(_chosenMarkerInitialPosition);
	_optionTextures[HudOption::MeleeAttackHudOption].loadToArrayFromFiles("Textures/AClaws");
	_optionSprites[HudOption::MeleeAttackHudOption].setPosition(_firstOptionInitialPosition + HudOption::MeleeAttackHudOption * _chosenMarkerNextPositionDistance);
}
int HudRenderer::getNoHudFrames() const
{
	return _hudTexture.getNoFrames();
}
int HudRenderer::getNoOptionFrames(HudOption option) const
{
	assert(option < HudOption::NoHudOption);
	return _optionTextures[option].getNoFrames();
}
int HudRenderer::getNoChosenMarkerFrames() const
{
	return _chosenMarkerTexture.getNoFrames();
}
void HudRenderer::setChosenMarker(HudOption option)
{
	_chosenMarkerSprite.setPosition(_chosenMarkerInitialPosition + (option * _chosenMarkerNextPositionDistance));
}
void HudRenderer::draw(Hud & hud, WindowAdapter & window)
{
	_hudSprite.setTexture(_hudTexture.getTexture(hud.getHudFrame()));
	window.drawSprite(_hudSprite);
	for (int i = 0; i < HudOption::NoHudOption; i++)
	{
		_optionSprites[i].setTexture(_optionTextures[i].getTexture(hud.getOptionFrame(HudOption(i))));
		window.drawSprite(_optionSprites[i]);
	}
	if (hud.getChosenOption() != HudOption::NoHudOption)
	{
		_chosenMarkerSprite.setTexture(_chosenMarkerTexture.getTexture(hud.getChosenMarkerFrame()));
		window.drawSprite(_chosenMarkerSprite);
	}
}
HudRenderer::~HudRenderer()
{}
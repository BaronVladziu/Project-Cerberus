#include "TesterHudRenderer.h"
#include "TextureArray.h"
#include "TesterHud.h"
#include "Vector2.h"
#include "WindowAdapter.h"
#include "TesterHudOption.h"

TesterHudRenderer::TesterHudRenderer(const Vector2 & screenSize, int tileLength)
	: _hudSize(144, 34),
	_hudInitialPosition(float(screenSize.x / 4) - float(_hudSize.x - 4), float(screenSize.y / 4) - float(_hudSize.y - 4)),
	_chosenMarkerInitialPosition(_hudInitialPosition + Vector2(3, 6)),
	_chosenMarkerNextPositionDistance(29, 0),
	_firstOptionInitialPosition(_hudInitialPosition + Vector2(6, 9)),
	_hudTexture("Textures/TesterHud"),
	_hudSprite(tileLength),
	_chosenMarkerTexture("Textures/AbilityChosen"),
	_chosenMarkerSprite(tileLength),
	_optionSprites{ tileLength, tileLength, tileLength, tileLength, tileLength }
{
	_hudSprite.setPosition(_hudInitialPosition);
	_chosenMarkerSprite.setPosition(_chosenMarkerInitialPosition);
	_optionTextures[TesterHudOption::ChangeToFloorTesterHudOption].loadToArrayFromFiles("Textures/TFloor");
	_optionSprites[TesterHudOption::ChangeToFloorTesterHudOption].setPosition(_firstOptionInitialPosition + TesterHudOption::ChangeToFloorTesterHudOption * _chosenMarkerNextPositionDistance);
	_optionTextures[TesterHudOption::ChangeToObstacleTesterHudOption].loadToArrayFromFiles("Textures/TObstacle");
	_optionSprites[TesterHudOption::ChangeToObstacleTesterHudOption].setPosition(_firstOptionInitialPosition + TesterHudOption::ChangeToObstacleTesterHudOption * _chosenMarkerNextPositionDistance);
	_optionTextures[TesterHudOption::ChangeToWallTesterHudOption].loadToArrayFromFiles("Textures/TWall");
	_optionSprites[TesterHudOption::ChangeToWallTesterHudOption].setPosition(_firstOptionInitialPosition + TesterHudOption::ChangeToWallTesterHudOption * _chosenMarkerNextPositionDistance);
	_optionTextures[TesterHudOption::ChangeToVoidTesterHudOption].loadToArrayFromFiles("Textures/TVoid");
	_optionSprites[TesterHudOption::ChangeToVoidTesterHudOption].setPosition(_firstOptionInitialPosition + TesterHudOption::ChangeToVoidTesterHudOption * _chosenMarkerNextPositionDistance);
	_optionTextures[TesterHudOption::CreateZombieTesterHudOption].loadToArrayFromFiles("Textures/CZombieIdle");
	_optionSprites[TesterHudOption::CreateZombieTesterHudOption].setPosition(_firstOptionInitialPosition + TesterHudOption::CreateZombieTesterHudOption * _chosenMarkerNextPositionDistance);
}
int TesterHudRenderer::getNoHudFrames() const
{
	return _hudTexture.getNoFrames();
}
int TesterHudRenderer::getNoOptionFrames(TesterHudOption option) const
{
	assert(option < TesterHudOption::NoTesterHudOption);
	return _optionTextures[option].getNoFrames();
}
int TesterHudRenderer::getNoChosenMarkerFrames() const
{
	return _chosenMarkerTexture.getNoFrames();
}
void TesterHudRenderer::setChosenMarker(TesterHudOption option)
{
	_chosenMarkerSprite.setPosition(_chosenMarkerInitialPosition + (option * _chosenMarkerNextPositionDistance));
}
void TesterHudRenderer::draw(TesterHud & testerHud, WindowAdapter & window)
{
	_hudSprite.setTexture(_hudTexture.getTexture(testerHud.getHudFrame()));
	window.drawSprite(_hudSprite);
	for (int i = 0; i < TesterHudOption::NoTesterHudOption; i++)
	{
		_optionSprites[i].setTexture(_optionTextures[i].getTexture(testerHud.getOptionFrame(TesterHudOption(i))));
		window.drawSprite(_optionSprites[i]);
	}
	if (testerHud.getChosenOption() != TesterHudOption::NoTesterHudOption)
	{
		_chosenMarkerSprite.setTexture(_chosenMarkerTexture.getTexture(testerHud.getChosenMarkerFrame()));
		window.drawSprite(_chosenMarkerSprite);
	}
}
TesterHudRenderer::~TesterHudRenderer()
{}
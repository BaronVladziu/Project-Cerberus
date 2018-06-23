#include "header.h"
#include "TesterHud.h"
#include "Animation.h"
#include "TesterHudRenderer.h"
#include "WindowAdapter.h"

TesterHud::TesterHud(Vector2 screenSize, const int tileLength)
	: _chosenOption(TesterHudOption::NoTesterHudOption),
	_testerHudRenderer(screenSize, tileLength)
{
	_hud.setNoFrames(_testerHudRenderer.getNoHudFrames());
	_chosenMarker.setNoFrames(_testerHudRenderer.getNoChosenMarkerFrames());
	_options[TesterHudOption::ChangeToFloorTesterHudOption].setNoFrames(_testerHudRenderer.getNoOptionFrames(TesterHudOption::ChangeToFloorTesterHudOption));
	_options[TesterHudOption::ChangeToObstacleTesterHudOption].setNoFrames(_testerHudRenderer.getNoOptionFrames(TesterHudOption::ChangeToObstacleTesterHudOption));
	_options[TesterHudOption::ChangeToWallTesterHudOption].setNoFrames(_testerHudRenderer.getNoOptionFrames(TesterHudOption::ChangeToWallTesterHudOption));
	_options[TesterHudOption::ChangeToVoidTesterHudOption].setNoFrames(_testerHudRenderer.getNoOptionFrames(TesterHudOption::ChangeToVoidTesterHudOption));
	_options[TesterHudOption::CreateZombieTesterHudOption].setNoFrames(_testerHudRenderer.getNoOptionFrames(TesterHudOption::CreateZombieTesterHudOption));
}
TesterHudOption TesterHud::getChosenOption() const
{
	return _chosenOption;
}
void TesterHud::chooseOption(TesterHudOption option)
{
	if (_chosenOption == option)
	{
		_chosenOption = TesterHudOption::NoTesterHudOption;
		_testerHudRenderer.setChosenMarker(TesterHudOption::NoTesterHudOption);
	}
	else
	{
		_chosenOption = option;
		_testerHudRenderer.setChosenMarker(option);
	}
}
int TesterHud::getHudFrame()
{
	return _hud.getFrame();
}
int TesterHud::getChosenMarkerFrame()
{
	return _chosenMarker.getFrame();
}
int TesterHud::getOptionFrame(TesterHudOption option)
{
	assert(option < TesterHudOption::NoTesterHudOption);
	return _options[option].getFrame();
}
void TesterHud::draw(WindowAdapter & window)
{
	_testerHudRenderer.draw(*this, window);
}
TesterHud::~TesterHud()
{}
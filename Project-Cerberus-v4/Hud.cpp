#include "Hud.h"
#include "Animation.h"
#include "HudRenderer.h"
#include "WindowAdapter.h"

Hud::Hud(Vector2 screenSize, const int tileLength)
	: _chosenOption(HudOption::NoHudOption),
	_hudRenderer(screenSize, tileLength)
{
	_hud.setNoFrames(_hudRenderer.getNoHudFrames());
	_chosenMarker.setNoFrames(_hudRenderer.getNoChosenMarkerFrames());
	_options[HudOption::MeleeAttackHudOption].setNoFrames(_hudRenderer.getNoOptionFrames(HudOption::MeleeAttackHudOption));
}
HudOption Hud::getChosenOption() const
{
	return _chosenOption;
}
void Hud::chooseOption(HudOption option)
{
	if (_chosenOption == option)
	{
		reset();
	}
	else
	{
		_chosenOption = option;
		_hudRenderer.setChosenMarker(option);
	}
}
void Hud::reset()
{
	_chosenOption = HudOption::NoHudOption;
	_hudRenderer.setChosenMarker(HudOption::NoHudOption);
}
int Hud::getHudFrame()
{
	return _hud.getFrame();
}
int Hud::getChosenMarkerFrame()
{
	return _chosenMarker.getFrame();
}
int Hud::getOptionFrame(HudOption option)
{
	assert(option < HudOption::NoHudOption);
	return _options[option].getFrame();
}
void Hud::draw(WindowAdapter & window)
{
	_hudRenderer.draw(*this, window);
}
Hud::~Hud()
{}
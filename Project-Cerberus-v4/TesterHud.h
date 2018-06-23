#pragma once
#include "Animation.h"
#include "TesterHudRenderer.h"
#include "TesterHudOption.h"

class TesterHud
{
	TesterHudRenderer _testerHudRenderer;
	TesterHudOption _chosenOption;
	Animation _hud;
	Animation _chosenMarker;
	Animation _options[TesterHudOption::NoTesterHudOption];

public:
	TesterHud(Vector2 screenSize, const int tileLength);
	TesterHudOption getChosenOption() const;
	void chooseOption(TesterHudOption option);
	int getHudFrame();
	int getChosenMarkerFrame();
	int getOptionFrame(TesterHudOption option);
	void draw(WindowAdapter & window);
	~TesterHud();
};
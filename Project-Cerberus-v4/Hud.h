#pragma once
#include "Animation.h"
#include "HudRenderer.h"

class Hud
{
	HudRenderer _hudRenderer;
	HudOption _chosenOption;
	Animation _hud;
	Animation _chosenMarker;
	Animation _options[HudOption::NoHudOption];

public:
	Hud(Vector2 screenSize, const int tileLength);
	HudOption getChosenOption() const;
	void chooseOption(HudOption option);
	void reset();
	int getHudFrame();
	int getChosenMarkerFrame();
	int getOptionFrame(HudOption option);
	void draw(WindowAdapter & window);
	~Hud();
};
#pragma once
#include "Scene.h"
#include "WindowAdapter.h"
#include "TesterHud.h"

class Game
{
	const bool _ifTesterMode;
	const int _TILE_LENGTH;

	WindowAdapter _window;
	Scene _scene;
	Hud _hud;
	TesterHud _testerHud;

	void executeEvents();
	void executeEvent(EventType event);
	void writeMousePosition() const;
	void useTesterHudAction();
	void setPlayerOrder(Direction4 direction);
	void nextTurn();
	void drawFrame();

public:
	Game();
	void startLoop();
	~Game();
};
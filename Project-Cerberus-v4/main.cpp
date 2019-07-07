#include "header.h"
#include "Game.h"

int main()
{
	srand(int(time(NULL)));
	Game game;
	game.startLoop();
	return 0;
}
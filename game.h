#ifndef GAME_H
#define GAME_H

#include "header.h"
#include "inputmanager.h"
#include "scene.h"


class Game
{
public:
    static const int BASE_WINDOW_SIZE_X = 800;
    static const int BASE_WINDOW_SIZE_Y = 600;
    static const std::string WINDOW_NAME;

    static const int MS_BETWEEN_FRAMES = 16;

    static const double CAMERA_HEIGHT;

private:
    static Scene _scene;
    static InputManager _inputManager;

private:
    Game();

public:
    static void draw();
    static void handleMouseMove(int x, int y);
    static void handleMouseButtons(int button, int state, int x, int y);
    static void handleKeyPressed(unsigned char key, int x, int y);
    static void handleKeyReleased(unsigned char key, int x, int y);
    static void update(int value);
};

#endif // GAME_H

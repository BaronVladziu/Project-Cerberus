#ifndef GAME_H
#define GAME_H

#include "header.h"
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

private:
    Game();

public:
    static void update(int value);
    static void draw();
};

#endif // GAME_H

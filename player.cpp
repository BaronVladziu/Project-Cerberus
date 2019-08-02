#include "player.h"

Player::Player(Vector2<double> & pos)
    : ColoredRectangle(DrawLayer(DrawLayerType::CreatureObstacle).getDepth(),
                       pos, SIZE, SIZE, Color(1.0, 1.0, 1.0, 1.0)), PhysicalObject(1.0, pos)
{}
Player::Player(double posX, double posY)
    : ColoredRectangle(1, posX, posY, SIZE, SIZE, Color(1.0, 1.0, 1.0, 1.0)), PhysicalObject(1.0, posX, posY)
{}

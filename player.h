#ifndef PLAYER_H
#define PLAYER_H

#include "coloredrectangle.h"
#include "physicalobject.h"


class Player :
        public ColoredRectangle,
        public PhysicalObject
{
private:
    static constexpr double SIZE = 0.5;

public:
    Player(Vector2<double> & pos);
    Player(double posX, double posY);
};

#endif // PLAYER_H

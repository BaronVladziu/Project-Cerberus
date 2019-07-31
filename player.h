#ifndef PLAYER_H
#define PLAYER_H

#include "physicalobject.h"
#include "tile.h"


class Player :
        public PhysicalObject,
        public Tile
{
public:
    Player();
};

#endif // PLAYER_H

#ifndef SCENE_H
#define SCENE_H

#include "map.h"
#include "player.h"


class Scene :
        public Drawable
{
    Map _map;
    Player _player;

public:
    Scene();
    void update();
    void draw() const;
};

#endif // SCENE_H

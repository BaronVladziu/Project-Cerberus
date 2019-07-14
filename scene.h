#ifndef SCENE_H
#define SCENE_H

#include "map.h"


class Scene :
        public Drawable
{
    Map _map;

public:
    Scene();
    void update();
    void draw() const;
};

#endif // SCENE_H

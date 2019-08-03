#ifndef SCENE_H
#define SCENE_H

#include "map.h"
#include "player.h"
#include "sceneobject.h"


class Scene
{
    Map _map;
    Player _player;
    std::list<SceneObject *> _sceneObjects;

public:
    Scene();
    void update();
    void draw() const;
};

#endif // SCENE_H

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
    void draw() const;
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void update();
};

#endif // SCENE_H

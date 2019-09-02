#ifndef MAP_H
#define MAP_H

#include "array2.h"
#include "collider.h"
#include "sceneobject.h"
#include "tile.h"
#include "vector2.h"


class Map
{
    const Vector2<int> _SIZE = Vector2<int>(10, 10);

    Array2<Tile *> _array = Array2<Tile *>(_SIZE);

public:
    Map();
    std::list<SceneObject *> getSceneObjects() const;
    ~Map();
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H

#include "array2.h"
#include "collidable.h"
#include "drawable.h"
#include "tile.h"
#include "vector2.h"


class Map :
        public Collidable,
        public Drawable

{
    const Vector2<int> _SIZE = Vector2<int>(10, 10);

    Array2<Tile *> _array = Array2<Tile *>(_SIZE);

public:
    Map();
    void collide(const Collidable &);
    void draw() const;
    ~Map();
};

#endif // MAP_H

#ifndef TILE_H
#define TILE_H

#include "collidable.h"
#include "drawable.h"
#include "header.h"
#include "tiletype.h"
#include "vector2.h"


class Tile :
        public Collidable,
        public Drawable
{
public:
    static const bool DRAW_BORDERS = true;
    static constexpr double SIZE = 1;

private:
    Vector2<double> _centerPosition;
    TileType _type;

public:
    Tile(TileType type);
    Tile(Vector2<double> & pos, TileType type);
    Tile(double posX, double posY, TileType type);
    void collide(const Collidable &);
    void draw() const;
};

#endif // TILE_H

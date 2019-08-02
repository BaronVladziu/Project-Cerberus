#ifndef TILE_H
#define TILE_H

#include "collidable.h"
#include "coloredrectangle.h"
#include "drawlayer.h"
#include "drawlayertype.h"
#include "header.h"
#include "tiletype.h"
#include "vector2.h"


class Tile :
        public Collidable,
        public ColoredRectangle
{
public:
    static constexpr double SIZE = 1;

private:
    TileType _type;

    void updateColor();

public:
    Tile(TileType type, const DrawLayerType & drawLayerType);
    Tile(Vector2<double> & pos, TileType type, const DrawLayerType & drawLayerType);
    Tile(double posX, double posY, TileType type, const DrawLayerType & drawLayerType);
    void collide(const Collidable &);
    TileType getTileType() const;
    void setTileType(TileType type);
};

#endif // TILE_H

#ifndef TILE_H
#define TILE_H

#include "collider.h"
#include "coloredrectangle.h"
#include "drawlayer.h"
#include "scenelayertype.h"
#include "sceneobject.h"
#include "tiletype.h"
#include "vector2.h"


class Tile :
        public SceneObject
{
public:
    static constexpr double SIZE = 1;

private:
    ColoredRectangle _rectangle;
    TileType _type;

    void updateColor();

public:
    Tile(TileType type, const SceneLayerType & sceneLayerType);
    Tile(Vector2<double> & pos, TileType type, const SceneLayerType & sceneLayerType);
    Tile(double posX, double posY, TileType type, const SceneLayerType & sceneLayerType);
    void draw() const;
    TileType getTileType() const;
    SceneObjectType getType() const;
    void setTileType(TileType type);
    void update();
    virtual ~Tile();
};

#endif // TILE_H

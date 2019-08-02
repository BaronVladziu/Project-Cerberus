#include "tile.h"


Tile::Tile(TileType type, const DrawLayerType & drawLayerType)
    : ColoredRectangle(DrawLayer(drawLayerType).getDepth()), _type(type)
{}
Tile::Tile(Vector2<double> & pos, TileType type, const DrawLayerType & drawLayerType)
    : ColoredRectangle(DrawLayer(drawLayerType).getDepth(), pos, SIZE, SIZE), _type(type)
{}
Tile::Tile(double posX, double posY, TileType type, const DrawLayerType & drawLayerType)
    : ColoredRectangle(DrawLayer(drawLayerType).getDepth(), posX, posY, SIZE, SIZE), _type(type)
{}
void Tile::collide(const Collidable & c) {
    //TODO
}
TileType Tile::getTileType() const {
    return _type;
}
void Tile::setTileType(TileType type) {
    _type = type;
    updateColor();
}

void Tile::updateColor() {
    switch (_type) {
    case Void: {
        ColoredRectangle::setColor(Color(0.f, 0.f, 0.f));
        break;
    }
    case Floor: {
        ColoredRectangle::setColor(Color(0.3f, 0.3f, 0.3f));
        break;
    }
    case Wall: {
        ColoredRectangle::setColor(Color(0.8f, 0.8f, 0.8f));
        break;
    }
    }
}

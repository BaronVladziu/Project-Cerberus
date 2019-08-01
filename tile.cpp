#include "tile.h"


Tile::Tile(TileType type)
    : ColoredRectangle(0.0), _type(type)
{}
Tile::Tile(Vector2<double> & pos, TileType type)
    : ColoredRectangle(0.0, pos, SIZE, SIZE), _type(type)
{}
Tile::Tile(double posX, double posY, TileType type)
    : ColoredRectangle(0.0, posX, posY, SIZE, SIZE), _type(type)
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

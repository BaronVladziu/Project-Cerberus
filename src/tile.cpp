#include "tile.h"


Tile::Tile(TileType type, const SceneLayerType & sceneLayerType)
    : _rectangle(DrawLayer(sceneLayerType, SceneObjectType::TileObject).getDepth()),
      _type(type)
{}
Tile::Tile(Vector2<double> & pos, TileType type, const SceneLayerType & sceneLayerType)
    : _rectangle(DrawLayer(sceneLayerType, SceneObjectType::TileObject).getDepth(),
                 pos, SIZE, SIZE),
      _type(type)
{}
Tile::Tile(double posX, double posY, TileType type, const SceneLayerType & sceneLayerType)
    : _rectangle(DrawLayer(sceneLayerType, SceneObjectType::TileObject).getDepth(),
                 posX, posY, SIZE, SIZE),
      _type(type)
{}
void Tile::draw() const {
    _rectangle.draw();
}
TileType Tile::getTileType() const {
    return _type;
}
SceneObjectType Tile::getType() const {
    return SceneObjectType::TileObject;
}
void Tile::setTileType(TileType type) {
    _type = type;
    updateColor();
}
void Tile::update() {}
Tile::~Tile() {}

void Tile::updateColor() {
    switch (_type) {
    case TileType::VoidTile:
        _rectangle.setColor(Color(0.f, 0.f, 0.f));
        break;
    case TileType::FloorTile:
        _rectangle.setColor(Color(0.3f, 0.3f, 0.3f));
        break;
    case TileType::ObstacleTile:
        _rectangle.setColor(Color(0.3f, 0.3f, 0.3f));
        break;
    case TileType::WallTile:
        _rectangle.setColor(Color(0.8f, 0.8f, 0.8f));
        break;
    }
}

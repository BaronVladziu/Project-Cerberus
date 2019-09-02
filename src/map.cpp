#include "map.h"

Map::Map() {
    for (int j = 0; j < _SIZE.y; j++) {
        for (int i = 0; i < _SIZE.y; i++) {
            _array.get(i, j) = new Tile(i*Tile::SIZE, j*Tile::SIZE,
                                        TileType::VoidTile, SceneLayerType::FloorLayer);
        }
    }
}
std::list<SceneObject *> Map::getSceneObjects() const {
    std::list<SceneObject *> sceneObjects;
    for (int i = 0; i < _array.getSizeX(); i++) {
        for (int j = 0; j < _array.getSizeY(); j++) {
            sceneObjects.push_back(_array.get(i, j));
        }
    }
    return sceneObjects;
}
Map::~Map() {
    for (int i = 0; i < _array.getSizeX(); i++) {
        for (int j = 0; j < _array.getSizeY(); j++) {
            delete _array.get(i, j);
        }
    }
}

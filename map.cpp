#include "map.h"

Map::Map() {
    for (int j = 0; j < _SIZE.y; j++) {
        for (int i = 0; i < _SIZE.y; i++) {
            _array.get(i, j) = new Tile(i*Tile::SIZE, j*Tile::SIZE, TileType::Void);
        }
    }
}

void Map::collide(const Collidable & c) {
    for (int j = 0; j < _SIZE.y; j++) {
        for (int i = 0; i < _SIZE.y; i++) {
            _array.get(i, j)->collide(c);
        }
    }
}

void Map::draw() const {
    for (int j = 0; j < _SIZE.y; j++) {
        for (int i = 0; i < _SIZE.y; i++) {
            _array.get(i, j)->draw();
        }
    }
}

Map::~Map() {}

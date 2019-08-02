#include "drawlayer.h"

DrawLayer::DrawLayer()
    : _type(DrawLayerType::ParticleWall)
{}
DrawLayer::DrawLayer(DrawLayerType type)
    : _type(type)
{}
double DrawLayer::getDepth() const {
    switch (_type) {
    case Background: return 10.0;
    case TileFloor: return 0.0;
    case AuraFloor: return -0.2;
    case ItemFloor: return -0.4;
    case CreatureFloor: return -0.6;
    case ParticleFloor: return -0.8;
    case TileObstacle: return -3.0;
    case AuraObstacle: return -3.2;
    case ItemObstacle: return -3.4;
    case CreatureObstacle: return -3.6;
    case ParticleObstacle: return -3.8;
    case TileWall: return -6.0;
    case AuraWall: return -6.2;
    case ItemWall: return -6.4;
    case CreatureWall: return -6.6;
    case ParticleWall: return -6.8;
    }
}
DrawLayerType DrawLayer::getType() const {
    return _type;
}
void DrawLayer::setType(DrawLayerType type) {
    _type = type;
}

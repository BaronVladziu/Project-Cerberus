#include "drawlayer.h"

DrawLayer::DrawLayer(SceneLayerType layerType, SceneObjectType objectType)
    : _layerType(layerType), _objectType(objectType)
{}
double DrawLayer::getDepth() const {
    double depth;
    switch (_layerType) {
    case BackgroundLayer: depth = 50.0; break;
    case FloorLayer: depth = 0.0; break;
    case ObstacleLayer: depth = -10.0; break;
    case LightingLayer: depth = -11.0; break;
    case WallLayer: depth = -20.0; break;
    }
    switch (_objectType) {
    case TileObject: depth -= 0.0; break;
    case DirtObject: depth -= 0.2; break;
    case ItemObject: depth -= 0.4; break;
    case CreatureObject: depth -= 0.6; break;
    case ParticleObject: depth -= 0.8; break;
    }
    return depth;
}

#ifndef DRAWLAYER_H
#define DRAWLAYER_H

#include "scenelayertype.h"
#include "sceneobjecttype.h"


class DrawLayer
{
private:
    SceneLayerType _layerType;
    SceneObjectType _objectType;

public:
    DrawLayer(SceneLayerType layerType, SceneObjectType objectType);
    double getDepth() const;
};

#endif // DRAWLAYER_H

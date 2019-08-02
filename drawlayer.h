#ifndef DRAWLAYER_H
#define DRAWLAYER_H

#include "drawlayertype.h"


class DrawLayer
{
private:
    DrawLayerType _type;

public:
    DrawLayer();
    DrawLayer(DrawLayerType type);
    double getDepth() const;
    DrawLayerType getType() const;
    void setType(DrawLayerType type);
};

#endif // DRAWLAYER_H

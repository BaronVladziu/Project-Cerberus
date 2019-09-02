#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "sceneobjecttype.h"


class SceneObject
{

public:
    virtual void draw() const = 0;
    virtual SceneObjectType getType() const = 0;
    virtual void update() = 0;
};

#endif // SCENEOBJECT_H

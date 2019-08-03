#ifndef PLAYER_H
#define PLAYER_H

#include "coloredrectangle.h"
#include "drawlayer.h"
#include "physicalobject.h"
#include "scenelayertype.h"
#include "sceneobject.h"


class Player :
        public SceneObject
{
private:
    static constexpr double SIZE = 0.5;

    ColoredRectangle _rectangle;
    PhysicalObject _physicalObject;

public:
    Player(Vector2<double> & pos);
    Player(double posX, double posY);
    void draw() const;
    SceneObjectType getType() const;
    void update();
    virtual ~Player();
};

#endif // PLAYER_H

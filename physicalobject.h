#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include "collidable.h"
#include "vector2.h"


class PhysicalObject :
        public Collidable
{
    double _mass;
    Vector2<double> _centerPosition;
    Vector2<double> _velocity;
    Vector2<double> _acceleration;

public:
    PhysicalObject();
    PhysicalObject(double mass);
    PhysicalObject(double mass,
                   const Vector2<double> & centerPosition = Vector2<double>(0, 0),
                   const Vector2<double> & velocity = Vector2<double>(0, 0),
                   const Vector2<double> & acceleration = Vector2<double>(0, 0));
    PhysicalObject(double mass,
                   double centerPositionX = 0, double centerPositionY = 0,
                   double velocityX = 0, double velocityY = 0,
                   double accelerationX = 0, double accelerationY = 0);

    virtual ~PhysicalObject();
};

#endif // PHYSICALOBJECT_H

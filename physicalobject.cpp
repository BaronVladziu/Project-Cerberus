#include "physicalobject.h"
#include "vector2.h"


PhysicalObject::PhysicalObject()
    : _mass(1)
{}

PhysicalObject::PhysicalObject(double mass)
    : _mass(mass)
{}

PhysicalObject::PhysicalObject(double mass,
                               const Vector2<double> & centerPosition,
                               const Vector2<double> & velocity,
                               const Vector2<double> & acceleration)
    : _mass(mass), _centerPosition(centerPosition),
      _velocity(velocity), _acceleration(acceleration)
{}

PhysicalObject::PhysicalObject(double mass,
                               double centerPositionX, double centerPositionY,
                               double velocityX, double velocityY,
                               double accelerationX, double accelerationY)
    : _mass(mass), _centerPosition(centerPositionX, centerPositionY),
      _velocity(velocityX, velocityY),
      _acceleration(accelerationX, accelerationY)
{}

PhysicalObject::~PhysicalObject() {}

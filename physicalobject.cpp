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
                               const Vector2<double> & force)
    : _mass(mass), _centerPosition(centerPosition),
      _unlimitedVelocity(velocity), _unlimitedForce(force)
{}
PhysicalObject::PhysicalObject(double mass,
                               double centerPositionX, double centerPositionY,
                               double velocityX, double velocityY,
                               double forceX, double forceY)
    : _mass(mass), _centerPosition(centerPositionX, centerPositionY),
      _unlimitedVelocity(velocityX, velocityY),
      _unlimitedForce(forceX, forceY)
{}
void PhysicalObject::addForce(const Force & force) {
    if (force.getVelocityLimit() > 0) {
        _limitedForces.push_back(force);
    } else {
        _unlimitedForce += force.getForce();
    }
}
void PhysicalObject::addForce(const Vector2<double> & force, double velocityLimit) {
    addForce(Force(force, velocityLimit));
}
void PhysicalObject::collide(const Collidable & c) {
    //TODO
}
const Vector2<double> & PhysicalObject::getCenterPosition() const {
    return _centerPosition;
}
double PhysicalObject::getMass() const {
    return _mass;
}
const Vector2<double> PhysicalObject::getVelocity() const {
    return _finalVelocity;
}
void PhysicalObject::update() {
    // Velocities
    _unlimitedVelocity += _unlimitedForce/_mass;
    Vector2<double> _finalVelocity = _unlimitedVelocity;
    for (const Force & force : _limitedForces) {
        _limitedVelocities[force.getVelocityLimit()] += force.getForce()/_mass;
        if (_limitedVelocities[force.getVelocityLimit()].abs() > force.getVelocityLimit()) {
            _limitedVelocities[force.getVelocityLimit()] *= force.getVelocityLimit()/
                    _limitedVelocities[force.getVelocityLimit()].abs();
        }
        _finalVelocity += _limitedVelocities[force.getVelocityLimit()];
    }
    // Position
    _centerPosition += _finalVelocity;
}

PhysicalObject::~PhysicalObject() {}

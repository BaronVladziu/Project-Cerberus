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
        _limitedForces[force.getVelocityLimit()] += force.getForce();
    } else {
        _unlimitedForce += force.getForce();
    }
}
void PhysicalObject::addForce(const Vector2<double> & force, double velocityLimit) {
    addForce(Force(force, velocityLimit));
}
void PhysicalObject::collide(const Collider & c) {
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
    _finalVelocity = _unlimitedVelocity;
    for (const std::pair<const double, Vector2<double>> & force : _limitedForces) {
        _limitedVelocities[force.first] += force.second/_mass;
        if (_limitedVelocities[force.first].abs() > force.first) {
            _limitedVelocities[force.first] *= force.first/
                    _limitedVelocities[force.first].abs();
        }
    }
    for (const std::pair<const double, Vector2<double>> & velocity : _limitedVelocities) {
        _finalVelocity += velocity.second;
    }
    _finalVelocity.print();

    // Position
    _centerPosition += _finalVelocity;

    // Reset forces
    _unlimitedForce = Vector2<double>(0, 0);
    _limitedForces.clear();
}

PhysicalObject::~PhysicalObject() {}

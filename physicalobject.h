#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

#include "collider.h"
#include "force.h"
#include "header.h"
#include "vector2.h"


class PhysicalObject
{
    double _mass;
    Vector2<double> _centerPosition;
    Vector2<double> _unlimitedVelocity;
    std::map<double, Vector2<double>> _limitedVelocities;
    Vector2<double> _finalVelocity;
    Vector2<double> _unlimitedForce;
    std::list<Force> _limitedForces;

public:
    PhysicalObject();
    PhysicalObject(double mass);
    PhysicalObject(double mass,
                   const Vector2<double> & centerPosition = Vector2<double>(0, 0),
                   const Vector2<double> & velocity = Vector2<double>(0, 0),
                   const Vector2<double> & force = Vector2<double>(0, 0));
    PhysicalObject(double mass,
                   double centerPositionX = 0, double centerPositionY = 0,
                   double velocityX = 0, double velocityY = 0,
                   double forceX = 0, double forceY = 0);
    void addForce(const Force & force);
    void addForce(const Vector2<double> & force, double velocityLimit = 0);
    void collide(const Collider &);
    const Vector2<double> & getCenterPosition() const;
    double getMass() const;
    const Vector2<double> getVelocity() const;
    void update();

    virtual ~PhysicalObject();
};

#endif // PHYSICALOBJECT_H

#ifndef FORCE_H
#define FORCE_H

#include "vector2.h"


class Force {

private:
    const Vector2<double> _force = Vector2<double>(0.0, 0.0);
    const double _velocityLimit = 0;

public:
    Force(const Vector2<double> & force)
        : _force(force)
    {}
    Force(const Vector2<double> & force, double velocityLimit)
        : _force(force), _velocityLimit(velocityLimit)
    {}
    const Vector2<double> & getForce() const {
        return _force;
    }
    double getVelocityLimit() const {
        return _velocityLimit;
    }
};

#endif // FORCE_H

#ifndef COLLIDER_H
#define COLLIDER_H

#include "vector2.h"


class Collider
{
    Vector2<double> _centerPosition;
    Vector2<double> _size;

public:
    Collider();
    Collider(const Vector2<double> & centerPosition, const Vector2<double> & size);
    Collider(double centerPosX, double centerPosY, double sizeX, double sizeY);
    void collide(const Collider &);
    ~Collider();
};

#endif // COLLIDER_H

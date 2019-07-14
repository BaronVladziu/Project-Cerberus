#include "collider.h"


Collider::Collider() {}

Collider::Collider(const Vector2<double> & centerPosition,
                   const Vector2<double> & size)
    : _centerPosition(centerPosition), _size(size)
{}

Collider::Collider(double centerPosX, double centerPosY,
                   double sizeX, double sizeY)
    : _centerPosition(centerPosX, centerPosY), _size(sizeX, sizeY)
{}

void Collider::collide(const Collidable &) {
    //TODO
}

Collider::~Collider() {}

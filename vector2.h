#ifndef VECTOR2_H
#define VECTOR2_H

#include "header.h"


template<typename T>
class Vector2
{
public:
    T x;
    T y;

    Vector2<T>() {
        x = 0;
        y = 0;
    }
    Vector2<T>(T x, T y) {
        this->x = x;
        this->y = y;
    }
    Vector2<T>(const Vector2<T> & v) {
        this->x = v.x;
        this->y = v.y;
    }
    Vector2<T> operator-() const {
        return Vector2<T>(-x, -y);
    }
    Vector2<T> & operator+=(const Vector2<T> & v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vector2<T> & operator-=(const Vector2<T> & v) {
        return *this += -v;
    }
    Vector2<T> operator+(const Vector2<T> & v) const {
        return Vector2<T>(*this) += v;
    }
    Vector2<T> operator-(const Vector2<T> & v) const {
        return Vector2<T>(*this) -= v;
    }
    void print() const {
        std::cout << "Point(" << x << "," << y << ")" << std::endl;
    }
};

#endif // VECTOR2_H

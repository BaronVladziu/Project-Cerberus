#ifndef COLOREDRECTANGLE_H
#define COLOREDRECTANGLE_H

#include "color.h"
#include "drawable.h"
#include "vector2.h"


class ColoredRectangle :
        public Drawable
{
public:
    static const bool DRAW_BORDERS = true;

private:
    Vector2<double> _centerPosition;
    Vector2<double> _size = Vector2<double>(1, 1);
    Color _color;

public:
    ColoredRectangle(const Color & color = Color(0.f, 0.f, 0.f));
    ColoredRectangle(Vector2<double> & pos, Vector2<double> & size,
                     const Color & color = Color(0.f, 0.f, 0.f));
    ColoredRectangle(Vector2<double> & pos, double sizeX, double sizeY,
                     const Color & color = Color(0.f, 0.f, 0.f));
    ColoredRectangle(double posX, double posY, Vector2<double> & size,
                     const Color & color = Color(0.f, 0.f, 0.f));
    ColoredRectangle(double posX, double posY, double sizeX, double sizeY,
                     const Color & color = Color(0.f, 0.f, 0.f));
    void draw() const;
    virtual ~ColoredRectangle();
};

#endif // COLOREDRECTANGLE_H

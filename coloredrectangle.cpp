#include "coloredrectangle.h"

ColoredRectangle::ColoredRectangle(const Color & color)
    : _color(color)
{}
ColoredRectangle::ColoredRectangle(Vector2<double> & pos, Vector2<double> & size,
                                   const Color & color)
    : _centerPosition(pos), _size(size), _color(color)
{}
ColoredRectangle::ColoredRectangle(Vector2<double> & pos, double sizeX, double sizeY,
                                   const Color & color)
    : _centerPosition(pos), _size(sizeX, sizeY), _color(color)
{}
ColoredRectangle::ColoredRectangle(double posX, double posY, Vector2<double> & size,
                                   const Color & color)
    : _centerPosition(posX, posY), _size(size), _color(color)
{}
ColoredRectangle::ColoredRectangle(double posX, double posY, double sizeX, double sizeY,
                                   const Color & color)
    : _centerPosition(posX, posY), _size(sizeX, sizeY), _color(color)
{}
void ColoredRectangle::draw() const {
    if (DRAW_BORDERS) {
        //Border
        glBegin(GL_POLYGON);
        glColor4f(1.f - _color.r, 1.f - _color.g, 1.f - _color.b, 1.f);
        glVertex3f(float(_centerPosition.x + _size.x/2),
                   float(_centerPosition.y - _size.y/2), -0.1f);
        glVertex3f(float(_centerPosition.x + _size.x/2),
                   float(_centerPosition.y + _size.y/2), -0.1f);
        glVertex3f(float(_centerPosition.x - _size.x/2),
                   float(_centerPosition.y + _size.y/2), -0.1f);
        glVertex3f(float(_centerPosition.x - _size.x/2),
                   float(_centerPosition.y - _size.y/2), -0.1f);
        glEnd();

        //Center
        glBegin(GL_POLYGON);
        glColor4f(_color.r, _color.g, _color.b, _color.a);
        glVertex3f(float(_centerPosition.x + _size.x*5/11),
                   float(_centerPosition.y - _size.y*5/11), 0.f);
        glVertex3f(float(_centerPosition.x + _size.x*5/11),
                   float(_centerPosition.y + _size.y*5/11), 0.f);
        glVertex3f(float(_centerPosition.x - _size.x*5/11),
                   float(_centerPosition.y + _size.y*5/11), 0.f);
        glVertex3f(float(_centerPosition.x - _size.x*5/11),
                   float(_centerPosition.y - _size.y*5/11), 0.f);
        glEnd();

    } else {
        glBegin(GL_POLYGON);
        glColor4f(_color.r, _color.g, _color.b, _color.a);
        glVertex3f(float(_centerPosition.x + _size.x/2),
                   float(_centerPosition.y - _size.y/2), 0.f);
        glVertex3f(float(_centerPosition.x + _size.x/2),
                   float(_centerPosition.y + _size.y/2), 0.f);
        glVertex3f(float(_centerPosition.x - _size.x/2),
                   float(_centerPosition.y + _size.y/2), 0.f);
        glVertex3f(float(_centerPosition.x - _size.x/2),
                   float(_centerPosition.y - _size.y/2), 0.f);
        glEnd();
    }
}
ColoredRectangle::~ColoredRectangle() {}

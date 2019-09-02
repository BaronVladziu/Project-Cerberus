#include "color.h"

Color::Color() {}
Color::Color(float red, float green, float blue)
    : r(red), g(green), b(blue)
{}
Color::Color(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha)
{}

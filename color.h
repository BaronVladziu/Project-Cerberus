#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    const float r = 0.f;
    const float g = 0.f;
    const float b = 0.f;
    const float a = 1.f;

    Color();
    Color(float red, float green, float blue);
    Color(float red, float green, float blue, float alpha);
};

#endif // COLOR_H

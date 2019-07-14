#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable();
};

#endif // DRAWABLE_H

#ifndef COLLIDABLE_H
#define COLLIDABLE_H

class Collidable {
public:
    virtual void collide(const Collidable &) = 0;
    virtual ~Collidable();
};

#endif // COLLIDABLE_H

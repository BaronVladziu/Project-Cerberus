#ifndef UPDATABLE_H
#define UPDATABLE_H

class Updatable {
public:
    virtual void update() = 0;
    virtual ~Updatable();
};

#endif // UPDATABLE_H

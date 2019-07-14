#include "tile.h"


Tile::Tile(TileType type)
    : _type(type)
{}
Tile::Tile(Vector2<double> & pos, TileType type)
    : _centerPosition(pos), _type(type)
{}
Tile::Tile(double posX, double posY, TileType type)
    : _centerPosition(posX, posY), _type(type)
{}
void Tile::collide(const Collidable & c) {
    //TODO
}
void Tile::draw() const {
    if (DRAW_BORDERS) {
        //Border
        glBegin(GL_POLYGON);
        glColor3f(1.f, 1.f, 1.f);
        glVertex3f(float(_centerPosition.x + SIZE/2),
                   float(_centerPosition.y - SIZE/2), -0.1f);
        glVertex3f(float(_centerPosition.x + SIZE/2),
                   float(_centerPosition.y + SIZE/2), -0.1f);
        glVertex3f(float(_centerPosition.x - SIZE/2),
                   float(_centerPosition.y + SIZE/2), -0.1f);
        glVertex3f(float(_centerPosition.x - SIZE/2),
                   float(_centerPosition.y - SIZE/2), -0.1f);
        glEnd();

        //Center
        glBegin(GL_POLYGON);
        switch (_type) {
        case Void: {
            glColor3f(0.f, 0.f, 0.f);
            break;
        }
        case Floor: {
            glColor3f(0.3f, 0.3f, 0.3f);
            break;
        }
        case Wall: {
            glColor3f(0.8f, 0.8f, 0.8f);
            break;
        }
        }
        glVertex3f(float(_centerPosition.x + SIZE*5/11),
                   float(_centerPosition.y - SIZE*5/11), 0.f);
        glVertex3f(float(_centerPosition.x + SIZE*5/11),
                   float(_centerPosition.y + SIZE*5/11), 0.f);
        glVertex3f(float(_centerPosition.x - SIZE*5/11),
                   float(_centerPosition.y + SIZE*5/11), 0.f);
        glVertex3f(float(_centerPosition.x - SIZE*5/11),
                   float(_centerPosition.y - SIZE*5/11), 0.f);
        glEnd();

    } else {
        glBegin(GL_POLYGON);
        switch (_type) {
        case Void: {
            glColor3f(0.f, 0.f, 0.f);
            break;
        }
        case Floor: {
            glColor3f(0.3f, 0.3f, 0.3f);
            break;
        }
        case Wall: {
            glColor3f(0.8f, 0.8f, 0.8f);
            break;
        }
        }
        glVertex3f(float(_centerPosition.x + SIZE/2),
                   float(_centerPosition.y - SIZE/2), 0.f);
        glVertex3f(float(_centerPosition.x + SIZE/2),
                   float(_centerPosition.y + SIZE/2), 0.f);
        glVertex3f(float(_centerPosition.x - SIZE/2),
                   float(_centerPosition.y + SIZE/2), 0.f);
        glVertex3f(float(_centerPosition.x - SIZE/2),
                   float(_centerPosition.y - SIZE/2), 0.f);
        glEnd();
    }
}

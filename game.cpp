#include "game.h"
#include "header.h"
#include "scene.h"


const std::string Game::WINDOW_NAME = "Project-Cerberus [Pre-Alpha]";
Scene Game::_scene;
const double Game::CAMERA_HEIGHT = 15.0;


// Function for increasing the angle variable smoothly,
// keeps it <=360
// It can also be implemented using the modulo operator.
void Game::update(int value) {
    _scene.update();

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}


void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -CAMERA_HEIGHT);

    // Add an ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    // Add a positioned light
    GLfloat lightColor0[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat lightPos0[] = {4.0, 0.0, 8.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // Draw scene
    _scene.draw();

    glFlush();
    glutSwapBuffers();
}

#include "game.h"

const std::string Game::WINDOW_NAME = "Project-Cerberus [Pre-Alpha]";
Scene Game::_scene;
InputManager Game::_inputManager;
const double Game::CAMERA_HEIGHT = 15.0;

void Game::handleMouseMove(int x, int y) {
    _inputManager.handleMouseMove(
                2*float(x)/glutGet(GLUT_WINDOW_WIDTH) - 1,
                2*float(y)/glutGet(GLUT_WINDOW_HEIGHT) - 1);
}
void Game::handleMouseButtons(int button, int state, int x, int y) {
    _inputManager.handleMouseButtons(button, bool(state),
                                     2*float(x)/glutGet(GLUT_WINDOW_WIDTH) - 1,
                                     2*float(y)/glutGet(GLUT_WINDOW_HEIGHT) - 1);
}
void Game::handleKeyPressed(unsigned char key, int x, int y) {
    _inputManager.handleKeyboardButtons(key, true,
                                        2*float(x)/glutGet(GLUT_WINDOW_WIDTH),
                                        2*float(y)/glutGet(GLUT_WINDOW_HEIGHT));
}
void Game::handleKeyReleased(unsigned char key, int x, int y) {
    _inputManager.handleKeyboardButtons(key, false,
                                        2*float(x)/glutGet(GLUT_WINDOW_WIDTH) - 1,
                                        2*float(y)/glutGet(GLUT_WINDOW_HEIGHT) - 1);
}
void Game::update(int value) {
    if (_inputManager.isKeyPressed(KeyType::Down)) _scene.movePlayerDown();
    if (_inputManager.isKeyPressed(KeyType::Left)) _scene.movePlayerLeft();
    if (_inputManager.isKeyPressed(KeyType::Right)) _scene.movePlayerRight();
    if (_inputManager.isKeyPressed(KeyType::Up)) _scene.movePlayerUp();

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

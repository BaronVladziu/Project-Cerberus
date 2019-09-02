#include "header.h"
#include "game.h"


// Initializes 3D rendering
void initRendering()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        // Set the color of the background
        glClearColor(0.7f, 0.8f, 1.0f, 1.0f);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
}

// Called when the window is resized
void handleResize(int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, double(w) / double(h), 1.0, 200.0);
}

int main(int argc, char **argv)
{    
    //OpenGL init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(Game::BASE_WINDOW_SIZE_X, Game::BASE_WINDOW_SIZE_Y);
    glutCreateWindow(Game::WINDOW_NAME.c_str());
    initRendering();

    //Add OpenGL update functions
    glutDisplayFunc(Game::draw);
    glutReshapeFunc(handleResize);
    glutPassiveMotionFunc(Game::handleMouseMove);
    glutMouseFunc(Game::handleMouseButtons);
    glutKeyboardFunc(Game::handleKeyPressed);
    glutKeyboardUpFunc(Game::handleKeyReleased);

    // Add a timer for the update(...) function
    glutTimerFunc(0, Game::update, 0);

    //Start main loop
    glutMainLoop();
    return 0;
}

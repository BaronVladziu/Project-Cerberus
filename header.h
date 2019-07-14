#ifndef HEADER_H
#define HEADER_H

// basic libraries
#include <iostream>
#include <cassert>

// the GLUT and OpenGL libraries have to be linked correctly
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#endif // HEADER_H

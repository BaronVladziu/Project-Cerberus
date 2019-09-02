cmake_minimum_required(VERSION 2.8)

project(Project-Cerberus)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(library ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

# Source files
file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

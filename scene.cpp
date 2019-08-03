#include "scene.h"

Scene::Scene()
    : _player(0.0, 0.0)
{
    _sceneObjects.push_back(&_player);
    _sceneObjects.merge(_map.getSceneObjects());
}
void Scene::draw() const {
    for (SceneObject * sceneObject : _sceneObjects) {
        sceneObject->draw();
    }
}
void Scene::movePlayerDown() {
    _player.moveDown();
}
void Scene::movePlayerLeft() {
    _player.moveLeft();
}
void Scene::movePlayerRight() {
    _player.moveRight();
}
void Scene::movePlayerUp() {
    _player.moveUp();
}
void Scene::update() {
    for (SceneObject * sceneObject : _sceneObjects) {
        sceneObject->update();
    }
}

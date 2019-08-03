#include "scene.h"

Scene::Scene()
    : _player(0.0, 0.0)
{
    _sceneObjects.push_back(&_player);
    _sceneObjects.merge(_map.getSceneObjects());
}
void Scene::update() {
    for (SceneObject * sceneObject : _sceneObjects) {
        sceneObject->update();
    }
}
void Scene::draw() const {
    for (SceneObject * sceneObject : _sceneObjects) {
        sceneObject->draw();
    }
}

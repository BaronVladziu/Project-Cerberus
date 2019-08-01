#include "scene.h"

Scene::Scene()
    : _player(0.0, 0.0)
{}

void Scene::update() {}

void Scene::draw() const {
    _map.draw();
    _player.draw();
}

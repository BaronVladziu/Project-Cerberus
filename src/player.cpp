#include "player.h"

Player::Player(Vector2<double> & pos)
    : _rectangle(DrawLayer(SceneLayerType::ObstacleLayer,
                           SceneObjectType::CreatureObject).getDepth(),
                       pos, SIZE, SIZE, Color(1.0, 1.0, 1.0, 1.0)),
      _physicalObject(1.0, pos)
{}
Player::Player(double posX, double posY)
    : _rectangle(1, posX, posY, SIZE, SIZE, Color(1.0, 1.0, 1.0, 1.0)),
      _physicalObject(1.0, posX, posY)
{}
void Player::draw() const {
    _rectangle.draw();
}
SceneObjectType Player::getType() const {
    return SceneObjectType::CreatureObject;
}
void Player::moveDown() {
    _physicalObject.addForce(Vector2<double>(0.0, -_acceleration), _maxSpeed);
}
void Player::moveLeft() {
    _physicalObject.addForce(Vector2<double>(-_acceleration, 0.0), _maxSpeed);
}
void Player::moveRight() {
    _physicalObject.addForce(Vector2<double>(_acceleration, 0.0), _maxSpeed);
}
void Player::moveUp() {
    _physicalObject.addForce(Vector2<double>(0.0, _acceleration), _maxSpeed);
}
void Player::update() {
    _physicalObject.update();
    _rectangle.setCenterPosition(_physicalObject.getCenterPosition());
}
Player::~Player() {}

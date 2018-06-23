#include "Creature.h"
#include "CreatureState.h"
#include "Animation.h"
#include "CreatureType.h"
#include "AI.h"

Creature::Creature(CreatureType type, Vector2 position, Direction4 direction, const CreatureRenderer & creatureRenderer)
	: _isDead(false),
	_type(type),
	_position(position),
	_abilities(_type)
{
	assert(direction < Direction4::Center);
	_animation.setNoFrames(creatureRenderer.getNoFrames(type));
	_actualOrder.set(OrderType::NoOrder, direction);
}
void Creature::determineNextOrder()
{
	_nextOrder = _ai.getOrder(*this);
}
void Creature::setNextOrder(OrderType orderType, Direction4 direction)
{
	assert(direction < Direction4::Center);
	if (orderType == OrderType::NoOrder)
	{
		_nextOrder.setToNull();
	}
	else
	{
		_nextOrder.set(orderType, direction);
	}
}
void Creature::setNextOrderToDone()
{
	_actualOrder = _nextOrder;
	_nextOrder.setToNull();
}
void Creature::setAbility(OrderType abilityType, bool ifAvaliable)
{
	_abilities.setIfAvaliable(abilityType, ifAvaliable);
}
bool Creature::isAbilityAvaliable(OrderType abilityType) const
{
	return _abilities.isAvaliable(abilityType);
}
bool Creature::isDead() const
{
	return _isDead;
}
void Creature::hurt()
{
	_isDead = true;
}
CreatureType Creature::getType() const
{
	return _type;
}
Vector2 Creature::getPosition() const
{
	return _position;
}
void Creature::setPosition(Vector2 position)
{
	_position = position;
}
OrderType Creature::getActualOrderType() const
{
	return _actualOrder.getType();
}
Direction4 Creature::getActualDirection() const
{
	return _actualOrder.getDirection();
}
OrderType Creature::getNextOrderType() const
{
	return _nextOrder.getType();
}
Direction4 Creature::getNextDirection() const
{
	return _nextOrder.getDirection();
}
int Creature::getFrame()
{
	return _animation.getFrame();
}
Creature::~Creature()
{}
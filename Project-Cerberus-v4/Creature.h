#pragma once
#include "CreatureState.h"
#include "Animation.h"
#include "CreatureType.h"
#include "CreatureRenderer.h"
#include "Order.h"
#include "Abilities.h"
#include "OrderType.h"
#include "Vector2.h"
#include "AI.h"

class Creature
{
	bool _isDead;
	CreatureType _type;
	Vector2 _position;
	Order _actualOrder;
	Order _nextOrder;
	Abilities _abilities;
	Animation _animation;
	AI _ai;

public:
	Creature(CreatureType type, Vector2 position, Direction4 direction, const CreatureRenderer & creatureRenderer);
	void determineNextOrder();
	void setNextOrder(OrderType orderType, Direction4 direction);
	void setNextOrderToDone();
	void setAbility(OrderType abilityType, bool ifAvaliable);
	bool isAbilityAvaliable(OrderType abilityType) const;
	bool isDead() const;
	void hurt();
	CreatureType getType() const;
	Vector2 getPosition() const;
	void setPosition(Vector2 position);
	OrderType getActualOrderType() const;
	Direction4 getActualDirection() const;
	OrderType getNextOrderType() const;
	Direction4 getNextDirection() const;
	int getFrame();
	virtual ~Creature();
};
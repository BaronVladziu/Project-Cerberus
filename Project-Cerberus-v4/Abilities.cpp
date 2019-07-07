#include "header.h"
#include "Abilities.h"
#include "CreatureType.h"

Abilities::Abilities(CreatureType creatureType)
{
	for (int i = 0; i < OrderType::NoOrder; i++)
	{
		_ifAvaliable[i] = false;
	}

	switch (creatureType)
	{
	case CreatureType::Player:
		setIfAvaliable(OrderType::MoveOrder, true);
		setIfAvaliable(OrderType::MeleeAttackOrder, true);
		break;
	case CreatureType::Zombie:
		setIfAvaliable(OrderType::MoveOrder, true);
		break;
	}
}
bool Abilities::isAvaliable(OrderType orderType) const
{
	assert(orderType >= 0);
	assert(orderType < OrderType::NoOrder);
	return _ifAvaliable[orderType];
}
void Abilities::setIfAvaliable(OrderType orderType, bool ifAvaliable)
{
	assert(orderType >= 0);
	assert(orderType < OrderType::NoOrder);
	_ifAvaliable[orderType] = ifAvaliable;
}
Abilities::~Abilities()
{}
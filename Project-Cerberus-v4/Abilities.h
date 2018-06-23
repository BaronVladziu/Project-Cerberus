#pragma once
#include "OrderType.h"

class Abilities
{
	bool _ifAvaliable[OrderType::NoOrder];

public:
	Abilities(CreatureType creatureType);
	bool isAvaliable(OrderType orderType) const;
	void setIfAvaliable(OrderType orderType, bool ifAvaliable);
	~Abilities();
};
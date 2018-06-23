#pragma once
#include "CreatureState.h"
#include "header.h"

class AI
{
	CreatureState _state;

	void setUnawareZombieOrder(Order & order);
	void setAwareZombieOrder(Order & order);

public:
	AI();
	Order getOrder(const Creature & creature);
	~AI();
};
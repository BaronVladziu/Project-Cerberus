#include "AI.h"
#include "header.h"
#include "Order.h"
#include "CreatureType.h"
#include "CreatureState.h"
#include "Creature.h"

AI::AI()
	: _state(CreatureState::UnawareState)
{}
Order AI::getOrder(const Creature & creature)
{
	Order order;
	switch (creature.getType())
	{
		case CreatureType::Player:
			order.set(creature.getNextOrderType(), creature.getNextDirection());
			break;
		case CreatureType::Zombie:
			if (_state == CreatureState::UnawareState)
			{
				setUnawareZombieOrder(order);
			}
			else
			{
				setAwareZombieOrder(order);
			}
			break;
		default:
			std::cout << "This creature hes no AI yet" << std::endl;
			break;
	}
	return order;
}
void AI::setUnawareZombieOrder(Order & order)
{
	int rollResult = rand() % 10;
	if (rollResult < 4)
	{
		order.set(OrderType::MoveOrder, Direction4(rand() % 4));
	}
}
void AI::setAwareZombieOrder(Order & order)
{
	//TODO
}
AI::~AI()
{}
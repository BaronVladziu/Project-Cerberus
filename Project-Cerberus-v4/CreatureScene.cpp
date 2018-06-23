#include "header.h"
#include "CreatureScene.h"
#include "Vector2.h"
#include "CreatureRenderer.h"
#include "Creature.h"
#include "Map.h"

CreatureScene::CreatureScene(int tileLength)
	: _PLAYER_START_POSITION(1, 1),
	_creatureRenderer(tileLength)
{
	createCreature(CreatureType::Player, _PLAYER_START_POSITION);
}
void CreatureScene::nextTurn(Map & map)
{
	determineNextOrders();
	executeNextOrders();
	hurtCreaturesNotOnFloor();
	cleanKilledCreatures();
}
void CreatureScene::createCreature(CreatureType creature, const Vector2 & position)
{
	_creatures.push_back(Creature(creature, position, Direction4::Up, _creatureRenderer));
	if (creature == CreatureType::Player)
	{
		_player = &_creatures.back();
	}
	_map.setCreature(&_creatures.back(), position);
}
void CreatureScene::determineNextOrders()
{
	for (Creature & creature : _creatures)
	{
		creature.determineNextOrder();
	}
}
void CreatureScene::executeNextOrders()
{
	for (Creature & creature : _creatures)
	{
		if (isCreatureAbleToDoNextOrder(creature))
		{
			executeCratureOrder(creature);
			creature.setNextOrderToDone();
		}
	}
}
bool CreatureScene::isCreatureAbleToDoNextOrder(const Creature & creature) const
{
	if (creature.getNextOrderType() != OrderType::NoOrder)
	{
		if (creature.isAbilityAvaliable(creature.getNextOrderType()) == true)
		{
			return true;
		}
		std::cout << "Creature tried to use unavaliable ability" << std::endl; //<---
	}
	return false;
}
void CreatureScene::executeCratureOrder(Creature & creature)
{
	switch (creature.getNextOrderType())
	{
	case OrderType::MoveOrder:
		if (isFloorOnCreatureMoveWay(creature) == true &&
			isOtherCreatureOnCreatureMoveWay(creature) == false)
		{
			executeCreatureMoveOrder(creature);
		}
		break;
	case OrderType::MeleeAttackOrder:
		executeCreatureMeleeAttackOrder(creature);
		break;
	default:
		std::cout << "This order is not executable yet" << std::endl; //<---
		break;
	}
}
bool CreatureScene::isFloorOnCreatureMoveWay(Creature & creature) const
{
	Vector2 nextPos = creature.getPosition().nextPosition(creature.getNextDirection());
	return (isFloorOnSquare(nextPos));
}
bool CreatureScene::isOtherCreatureOnCreatureMoveWay(Creature & creature) const
{
	Vector2 nextPos = creature.getPosition().nextPosition(creature.getNextDirection());
	if (_map.getCreature(nextPos) != nullptr)
	{
		return true;
	}
	return false;
}
void CreatureScene::executeCreatureMoveOrder(Creature & creature)
{
	Vector2 pos = creature.getPosition();
	_map.setCreature(nullptr, pos);
	pos = countNextPosition(pos, creature.getNextDirection());
	creature.setPosition(pos);
	_map.setCreature(&creature, pos);
}
void CreatureScene::executeCreatureMeleeAttackOrder(Creature & creature)
{
	Vector2 pos = countNextPosition(creature.getPosition(), creature.getNextDirection());
	addSpriteEffect(SpriteEffectType::MeleeAttackSpriteEffect, pos, creature.getNextDirection());
	_map.hurt(pos);
}
void CreatureScene::hurtCreaturesNotOnFloor()
{
	for (Creature & creature : _creatures)
	{
		if (isFloorOnSquare(creature.getPosition()) == false)
		{
			_map.hurt(creature.getPosition());
		}
	}
}
void CreatureScene::cleanKilledCreatures()
{
	for (Creature & creature : _creatures)
	{
		if (creature.isDead())
		{
			_map.setCreature(nullptr, creature.getPosition());
			if (creature.getType() == CreatureType::Player)
			{
				_player = nullptr;
			}
		}
	}
	_creatures.remove_if([](Creature & creature) { return creature.isDead(); });
}
void CreatureScene::setPlayerOrder(OrderType orderType, Direction4 direction)
{
	assert(_player != nullptr);
	assert(direction < Direction4::Center);
	_player->setNextOrder(orderType, direction);
}
CreatureScene::~CreatureScene()
{}
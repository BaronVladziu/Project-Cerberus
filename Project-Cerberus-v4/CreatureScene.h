#pragma once
#include "Vector2.h"
#include "CreatureRenderer.h"

class CreatureScene
{
	const Vector2 _PLAYER_START_POSITION;

	CreatureRenderer _creatureRenderer;
	std::list<Creature> _creatures;
	Creature * _player;

	void createCreature(CreatureType creature, const Vector2 & position);
	void determineNextOrders();
	void executeNextOrders();
	void executeCratureOrder(Creature & creature);
	bool isFloorOnCreatureMoveWay(Creature & creature) const;
	bool isOtherCreatureOnCreatureMoveWay(Creature & creature) const;
	void executeCreatureMoveOrder(Creature & creature);
	void executeCreatureMeleeAttackOrder(Creature & creature);
	bool isCreatureAbleToDoNextOrder(const Creature & creature) const;
	void hurtCreaturesNotOnFloor();
	void cleanKilledCreatures();

public:
	CreatureScene(int tileLength);
	void nextTurn(Map & map);
	void setPlayerOrder(OrderType orderType, Direction4 direction);
	void draw(WindowAdapter & window);
	~CreatureScene();
};
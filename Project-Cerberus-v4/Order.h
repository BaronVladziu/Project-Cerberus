#pragma once
#include "OrderType.h"
#include "Direction4.h"

class Order
{
	OrderType _type;
	Direction4 _direction;

public:
	Order();
	OrderType getType() const;
	Direction4 getDirection() const;
	void set(OrderType type, Direction4 direction);
	void setToNull();
	void operator=(const Order & order);
	~Order();
};
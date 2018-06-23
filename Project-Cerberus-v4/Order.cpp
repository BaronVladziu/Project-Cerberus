#include "header.h"
#include "Order.h"
#include "OrderType.h"
#include "Direction4.h"

Order::Order()
	: _type(OrderType::NoOrder),
	_direction(Direction4::Up)
{}
OrderType Order::getType() const
{
	return _type;
}
Direction4 Order::getDirection() const
{
	return _direction;
}
void Order::set(OrderType type, Direction4 direction)
{
	assert(direction < Direction4::Center);
	_type = type;
	_direction = direction;
}
void Order::setToNull()
{
	_type = OrderType::NoOrder;
}
void Order::operator=(const Order & order)
{
	_type = order.getType();
	_direction = order.getDirection();
}
Order::~Order()
{}
#include "Vector2.h"
#include "Direction4.h"

Vector2::Vector2()
	: x(0), y(0)
{}
Vector2::Vector2(int x, int y)
	: x(x), y(y)
{}
bool operator!=(Vector2 left, Vector2 right)
{
	return (left.x != right.x || left.y != right.y);
}
Vector2 operator+(Vector2 left, Vector2 right)
{
	return Vector2(left.x + right.x, left.y + right.y);
}
Vector2 operator*(Vector2 left, int right)
{
	return Vector2(left.x * right, left.y * right);
}
Vector2 operator*(int left, Vector2 right)
{
	return Vector2(left * right.x, left * right.y);
}
Vector2 Vector2::nextPosition(Direction4 direction) const
{
	Vector2 nextVector = *this;
	switch (direction)
	{
	case Direction4::Down:
		return nextVector + Vector2(0, 1);
	case Direction4::Left:
		return nextVector + Vector2(-1, 0);
	case Direction4::Right:
		return nextVector + Vector2(1, 0);
	case Direction4::Up:
		return nextVector + Vector2(0, -1);
	}
	return nextVector;
}
Vector2::~Vector2()
{}
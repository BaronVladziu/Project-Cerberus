#pragma once
#include "header.h"

class Vector2
{
public:
	int x;
	int y;

	Vector2();
	Vector2(int x, int y);
	friend bool operator!=(Vector2 left, Vector2 right);
	friend Vector2 operator+(Vector2 left, Vector2 right);
	friend Vector2 operator*(Vector2 left, int right);
	friend Vector2 operator*(int left, Vector2 right);
	Vector2 nextPosition(Direction4 direction) const;
	~Vector2();
};
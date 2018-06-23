#pragma once
#include "Vector2.h"
#include "Square.h"
#include "TileRenderer.h"

class Map
{
	const Vector2 _SIZE;

	Square ** _array;
	TileRenderer _tileRenderer;

	void generateMap();
	void setAllTilesTo(TileType tileType);

public:
	Map(const Vector2 & size, int tileLength);
	const Vector2 & getSize() const;
	Square & getSquare(const Vector2 & position) const;
	Square & getSquare(int x, int y) const;
	void draw(WindowAdapter & window);
	~Map();
};
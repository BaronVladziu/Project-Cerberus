#pragma once

class LightTile
{
	bool _ifSeen;
	int _lightness;

public:
	LightTile();
	void reset();
	void setToSeen();
	bool getIfSeen() const;
	void setTileLightness(int lightness);
	int getLightness() const;
	~LightTile();
};
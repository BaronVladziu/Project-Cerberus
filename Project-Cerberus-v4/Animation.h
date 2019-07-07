#pragma once
#include "TextureArray.h"

class Animation
{
	int _NO_FRAMES;
	const int _NO_WAIT_FRAMES;

	int _actualFrame;
	int _waitFrame;
	bool _ifEnded;

public:
	Animation();
	void setNoFrames(int noFrames);
	int getNoFrames() const;
	bool getIfEnded() const;
	int getFrame();
	~Animation();
};
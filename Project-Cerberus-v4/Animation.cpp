#include "Animation.h"
#include "TextureArray.h"

Animation::Animation()
	: _NO_FRAMES(0),
	_NO_WAIT_FRAMES(3),
	_actualFrame(0),
	_waitFrame(_NO_WAIT_FRAMES),
	_ifEnded(true)
{}
void Animation::setNoFrames(int noFrames)
{
	_NO_FRAMES = noFrames;
	_ifEnded = false;
}
int Animation::getNoFrames() const
{
	return _NO_FRAMES;
}
bool Animation::getIfEnded() const
{
	return _ifEnded;
}
int Animation::getFrame()
{
	if (_actualFrame < _NO_FRAMES)
	{
		if (_waitFrame < _NO_WAIT_FRAMES)
		{
			_waitFrame++;
			return _actualFrame;
		}
		else
		{
			_waitFrame = 0;
			_actualFrame++;
			if (_actualFrame == _NO_FRAMES)
			{
				_ifEnded = true;
			}
			return _actualFrame - 1;
		}
	}
	else
	{
		_actualFrame = 0;
		return _actualFrame;
	}
}
Animation::~Animation()
{}
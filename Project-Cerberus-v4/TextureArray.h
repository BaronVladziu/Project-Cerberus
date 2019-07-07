#pragma once
#include "TextureAdapter.h"
#include <list>

class TextureArray
{
	bool _ifTexturesLoaded;
	int _NO_FILES;
	TextureAdapter * _textures;

	int checkNoFiles(const std::string & fileName) const;
	void loadFromFiles(const std::string & fileName);
	bool ifFileExists(const std::string & fileName) const;
	void addTextureFromFile(int textureNr, const std::string & fileName);

public:
	TextureArray();
	TextureArray(const std::string & fileName);
	void loadToArrayFromFiles(const std::string & fileName);
	const TextureAdapter & getTexture(int frame) const;
	int getNoFrames() const;
	~TextureArray();
};
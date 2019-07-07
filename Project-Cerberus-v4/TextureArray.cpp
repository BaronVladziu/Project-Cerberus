#include "TextureArray.h"
#include "TextureAdapter.h"
#include <vector>
#include <fstream>
#include <cassert>

TextureArray::TextureArray()
	: _ifTexturesLoaded(false)
{}
TextureArray::TextureArray(const std::string & fileName)
{
	loadToArrayFromFiles(fileName);
}
void TextureArray::loadToArrayFromFiles(const std::string & fileName)
{
	_NO_FILES = checkNoFiles(fileName);
	loadFromFiles(fileName);
}
int TextureArray::checkNoFiles(const std::string & fileName) const
{
	int noFiles = 0;
	while (ifFileExists(fileName + std::to_string(noFiles) + ".png"))
	{
		noFiles++;
	}
	return noFiles;
}
bool TextureArray::ifFileExists(const std::string & fileName) const
{
	std::ifstream file(fileName);
	return file.good();
}
void TextureArray::loadFromFiles(const std::string & fileName)
{
	_textures = new TextureAdapter[_NO_FILES];
	for (int i = 0; i < _NO_FILES; i++)
	{
		addTextureFromFile(i, fileName + std::to_string(i) + ".png");
	}
	_ifTexturesLoaded = true;
}
void TextureArray::addTextureFromFile(int textureNr, const std::string & fileName)
{
	_textures[textureNr].loadFromFile(fileName);
}
const TextureAdapter & TextureArray::getTexture(int frame) const
{
	assert(_ifTexturesLoaded == true);
	assert(frame >= 0);
	assert(frame < _NO_FILES);
	return _textures[frame];
}
int TextureArray::getNoFrames() const
{
	assert(_ifTexturesLoaded == true);
	return _NO_FILES;
}
TextureArray::~TextureArray()
{
	delete[] _textures;
}
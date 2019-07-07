#include "TextureAdapter.h"

TextureAdapter::TextureAdapter()
{}
TextureAdapter::TextureAdapter(const std::string & fileName)
{
	loadFromFile(fileName);
}
void TextureAdapter::loadFromFile(const std::string & fileName)
{
	_texture.loadFromFile(fileName);
}
const sf::Texture & TextureAdapter::getSFMLTexture() const
{
	return _texture;
}
TextureAdapter::~TextureAdapter()
{}
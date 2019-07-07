#pragma once
#include "header.h"

class TextureAdapter
{
	sf::Texture _texture;

public:
	TextureAdapter();
	TextureAdapter(const std::string & fileName);
	void loadFromFile(const std::string & fileName);
	const sf::Texture & getSFMLTexture() const;
	~TextureAdapter();
};
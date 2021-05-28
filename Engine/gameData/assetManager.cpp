#include <SFML/Graphics.hpp>
#include "assetManager.h"

void assetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		this->_textures[name] = tex;
	}
}

sf::Texture& assetManager::GetTexture(std::string name)
{
	return this->_textures.at(name);
}

void assetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->_fonts[name] = font;
	}
}

sf::Font& assetManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}
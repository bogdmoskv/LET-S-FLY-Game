#include "AccessHandler.h"

	void AccessHandler::loadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AccessHandler::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AccessHandler::loadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AccessHandler::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}


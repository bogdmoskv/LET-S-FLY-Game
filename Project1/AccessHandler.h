#pragma once
#include <map>
#include <SFML/Graphics.hpp>

	class AccessHandler { 
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	public:
		AccessHandler(){}
		~AccessHandler(){}
		void loadTexture(std::string name, std::string fileName); 
		sf::Texture& GetTexture(std::string name);

		void loadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);
	};



#pragma once

#include <SFML/Graphics.hpp>

	class InputHandler 
	{
	public:
		InputHandler(){}
		~InputHandler(){}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	
	};



#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateHandler.h"
#include "AccessHandler.h"
#include "InputHandler.h"

	struct GameData
	{
		StateHandler machine; 
		sf::RenderWindow window;
		AccessHandler access; 
		InputHandler input; 
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
		private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		GameDataRef _data = std::make_shared<GameData>();
		void run();
	
		public:
		Game(int width, int height, std::string title);
	};

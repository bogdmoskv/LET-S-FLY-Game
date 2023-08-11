#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

	class InitialLoadingState :public State 
	{
	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _background;

	public:
		InitialLoadingState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);
	};


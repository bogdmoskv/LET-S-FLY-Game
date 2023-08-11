#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"

	class Flash
	{
	private:
		GameDataRef _data;
		sf::RectangleShape _shape;
		bool _flashOn;

	public:
		Flash(GameDataRef data);
		~Flash();

		void show(float dt);
		void draw();
	};



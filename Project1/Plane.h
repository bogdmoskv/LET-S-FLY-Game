#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

	class Plane
	{
	private:
		GameDataRef _data;
		sf::Sprite _planeSprite;
		sf::Texture _planeTexture;
		sf::Clock _movementClock;

		int _planeState;
		float _rotation;

	public:
		Plane(GameDataRef data);
		void draw();
		void update(float dt);
		void tap();
		sf::Sprite& GetSprite();
	};


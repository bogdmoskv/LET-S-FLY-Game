#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.h"
#include "Obstacle.h"
#include "Plane.h"
#include "PixelCollision.h"
#include "Flash.h"
#include "Score.h"

	class GameState :public State 
	{
	private:
		GameDataRef _data;
		sf::Sprite _background;
		Obstacle* obstacle; 
		Plane* plane;
		sf::Clock clock;
		Flash* flash;
		Score* score;

		int _gameState;
		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;
		sf::SoundBuffer _backgroundSoundBuffer;

		sf::Sound _hitSound;
		sf::Sound _wingSound;
		sf::Sound _pointSound;
		sf::Sound _backgroundSound;
	public:
		GameState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
	};


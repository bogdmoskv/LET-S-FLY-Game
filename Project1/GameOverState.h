#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

	class GameOverState :public State 
	{
	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;

		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;

	public:
		GameOverState(GameDataRef data, int score);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
	};



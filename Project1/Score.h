#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"


	class Score
	{
	private:
		GameDataRef _data;
		sf::Text _scoreText;

	public:
		Score(GameDataRef data);
		void draw();
		void updateScore(int score);
	};



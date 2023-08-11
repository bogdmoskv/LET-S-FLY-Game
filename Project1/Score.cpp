#include "Score.h"
#include <string>


	Score::Score(GameDataRef data) :_data{data}
	{
		_scoreText.setFont(_data->access.GetFont("Flappy Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(50);
		_scoreText.setFillColor(sf::Color(243, 105, 15 , 255));
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);
		_scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 25);
	}

	void Score::draw()
	{
		_data->window.draw(_scoreText);
	}

	void Score::updateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	}



#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include <iostream>
#include "Obstacle.h"
#include "Plane.h"

#include "PixelCollision.h"
#include "GameOverState.h"


	GameState::GameState(GameDataRef data) : _data{ data }
	{
		_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH);
		_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH);
		_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH);
	}

	void GameState::init()
	{
		_hitSound.setBuffer(_hitSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);

		_data->access.loadTexture("Game Background",
			GAME_BACKGROUND_FILEPATH);

		_data->access.loadTexture("Mountain",
			MOUNTAIN_FILEPATH);

		_data->access.loadTexture("Cloud",
			CLOUD_FILEPATH);

		_data->access.loadTexture("Scoring Obstacle",
			SCORING_OBSTACLE_FILEPATH);

		_data->access.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		obstacle = new Obstacle(_data);
		plane = new Plane(_data);
		flash = new Flash(_data);
		score = new Score(_data);

		_background.setTexture(this->_data->access.GetTexture("Game Background"));
		
		_score = 0;
		score->updateScore(_score);

		_gameState = GameStates::eReady;
		_gameState = GameStates::ePlaying; 
		
	}

	void GameState::handleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying; 
					plane->tap();
					_wingSound.play();
				}
			}
		}
	
	}


	void GameState::update(float dt)
	{

		if (GameStates::ePlaying == _gameState)
		{
			obstacle->moveObstacles(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				obstacle->randomiseObstacleOffset();

				obstacle->spawnInvisibleObstacle();
				obstacle->spawnBottomObstacle();
				obstacle->spawnTopObstacle();
				obstacle->spawnScoringObstacle();
				clock.restart();
			}

			plane->update(dt);

			std::vector<sf::Sprite> obstacleSprites = obstacle->GetSprites();
			for (int i = 0; i < obstacleSprites.size(); i++)
			{
				if (PixelPerfectTest(plane->GetSprite(), obstacleSprites.at(i)))
				{
					_gameState = GameStates::eGameOver;
					_hitSound.play();
					clock.restart();
					
				}
			}


			if (GameStates::ePlaying == _gameState)
			{
				std::vector<sf::Sprite>& scoringSprites = obstacle->GetScoringSprites();
				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (PixelPerfectTest(plane->GetSprite(), scoringSprites.at(i)))
					{
						_score++;

						score->updateScore(_score);
						scoringSprites.erase(scoringSprites.begin() + i);
						_pointSound.play();
					}
				}


			}

		}

		if (GameStates::eGameOver == _gameState)
		{
			flash->show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				_data->machine.addState(StateRef(new GameOverState(_data, _score)), true);
			}
		}

	}

	void GameState::draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		obstacle->drawObstacles();
		plane->draw();
		flash->draw();

		score->draw();
		this->_data->window.display();
	}


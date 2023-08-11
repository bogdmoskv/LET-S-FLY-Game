#include "Obstacle.h"
#include <iostream>
#include "DEFINITIONS.h"

Obstacle::Obstacle(GameDataRef data) : _data{ data }
	{
		_landHeight = 0;
		_obstacleSpawnYOffset = 0;
	}

	void Obstacle::spawnBottomObstacle()
	{
		sf::Sprite sprite(this->_data->access.GetTexture("Mountain"));

		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _obstacleSpawnYOffset);

		obstacleSprites.push_back(sprite);
	}

	void Obstacle::spawnTopObstacle()
	{
		sf::Sprite sprite(this->_data->access.GetTexture("Cloud"));

		sprite.setPosition(this->_data->window.getSize().x, -_obstacleSpawnYOffset);

		obstacleSprites.push_back(sprite);
	}

	void Obstacle::spawnInvisibleObstacle()
	{
		sf::Sprite sprite(this->_data->access.GetTexture("Mountain"));

		sprite.setPosition(this->_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		obstacleSprites.push_back(sprite);
	}

	void Obstacle::spawnScoringObstacle()
	{
		sf::Sprite sprite(this->_data->access.GetTexture("Scoring Obstacle"));

		sprite.setPosition(this->_data->window.getSize().x, 0);
		scoringObstacles.push_back(sprite);
	}



	void Obstacle::moveObstacles(float dt)
	{
		for (int i = 0; i < obstacleSprites.size(); i++)
		{
			if (obstacleSprites.at(i).getPosition().x < 0 - obstacleSprites.at(i).getLocalBounds().width)
			{
				obstacleSprites.erase(obstacleSprites.begin() + i);
			}
			else
			{
				sf::Vector2f position = obstacleSprites.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				obstacleSprites.at(i).move(-movement, 0);
			}
		}
		

		for (int i = 0; i < scoringObstacles.size(); i++)
		{
			if (scoringObstacles.at(i).getPosition().x < 0 - scoringObstacles.at(i).getLocalBounds().width)
			{
				scoringObstacles.erase(scoringObstacles.begin() + i);
			}
			else
			{
				sf::Vector2f position = scoringObstacles.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				scoringObstacles.at(i).move(-movement, 0);
			}
		}
	}


	void Obstacle::drawObstacles()
	{
		for (unsigned short int i = 0; i < obstacleSprites.size(); i++)
		{
			this->_data->window.draw(obstacleSprites.at(i));
		}
	}

	void Obstacle::randomiseObstacleOffset()
	{
		_obstacleSpawnYOffset = rand() % (_landHeight -5);
	}

	std::vector<sf::Sprite> &Obstacle::GetSprites()
	{
		return obstacleSprites;
	}


	std::vector<sf::Sprite>& Obstacle::GetScoringSprites()
	{
		return scoringObstacles;
	}


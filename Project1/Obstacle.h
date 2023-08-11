#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "PixelCollision.h"


	class Obstacle
	{
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> obstacleSprites;
		std::vector<sf::Sprite> scoringObstacles;
		int _landHeight;
		int _obstacleSpawnYOffset;
	public:
		Obstacle(GameDataRef data);

		void spawnBottomObstacle();
		void spawnTopObstacle();
		void spawnInvisibleObstacle();
		void spawnScoringObstacle();
		void moveObstacles(float dt);
		void drawObstacles();
		void randomiseObstacleOffset();

		std::vector<sf::Sprite>& GetSprites();
		std::vector<sf::Sprite>& GetScoringSprites();
	};

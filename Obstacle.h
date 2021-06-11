#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "definitions.h"
#include "../ANTS PROJECT/Engine/engine.h"


class Obstacle 
{
public:
	Obstacle(GameDataRef data);

	void drawObstacle();

	void spawnObstacle(float x, float y);


	~Obstacle();

private:
	GameDataRef _data;
	std::vector<sf::Sprite> _obstacleSprite;
	
};


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../definitions.h"
#include "../Engine/engine.h"


class Obstacle 
{
public:
	Obstacle(GameDataRef data);

	void drawObstacle();

	void spawnObstacle(float x, float y);

	~Obstacle();

	std::vector<sf::Sprite> _obstacleSprite;
private:
	GameDataRef _data;
	
};


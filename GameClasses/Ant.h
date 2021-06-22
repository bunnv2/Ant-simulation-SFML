#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <sstream>

#include "definitions.h"
#include "../ANTS PROJECT/Engine/engine.h"
#include "Obstacle.h"
#include "Food.h"
#include "Nest.h"


class Ant {
public:

	Ant(GameDataRef data);

	void drawAnts();
	void spawnAnts(float x, float y);
	void freeRoamAntsMovement(float dt, class Nest* n);

	void collisionWithObstacle(class Obstacle* obstacle);
	void collisionWithFood(class Food* f);

	int foodCounter = 0;

private:

	int direction;

	GameDataRef _data;

	sf::Clock timer;
	sf::Clock foodtimer;

	std::vector<sf::Sprite> antSprites;
	std::vector<int> directions;

	std::vector<int> isHungry;

};

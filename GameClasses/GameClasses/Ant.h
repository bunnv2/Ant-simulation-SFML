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


class Ant {
public:

	Ant(GameDataRef data);

	void drawAnts();
	void spawnAnts(float x, float y);
	void freeRoamAntsMovement(float dt);

	void collisionWithObstacle(class Obstacle* obstacle);
	void collisionWithFood(class Food* f);



private:

	int direction;
	int antIterator = 0;


	GameDataRef _data;

	sf::Clock timer;

	std::vector<sf::Sprite> antSprites;
	std::vector<int> directions;

	//std::vector<std::vector<int>> antDirections; !!!!

	std::vector<int> isHungry;


};

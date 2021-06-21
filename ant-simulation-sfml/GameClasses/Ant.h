#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <sstream>

#include "../definitions.h"
#include "../Engine/engine.h"
#include "Food.h"
#include "Nest.h"


class Ant {
public:

	Ant( GameDataRef data);

	void drawAnts();
	void spawnAnts(float x, float y);
	void freeRoamAntsMovement(float dt, class Nest* n);
	void collisionWithFood(class Food* f);
	void borderCollision(int i);
	void moveInDirection(int i);
	void moveBackToNest(int i);

	void counter();

	int timer;

private:

	int direction;
	int antCounter;

	GameDataRef _data;

	std::vector<sf::Sprite> antSprites;

	std::vector<int> directions;
	std::vector<int> isHungry;

	std::vector<std::vector<int>> antDirections;
	std::vector<float> directionChangeTime;
};
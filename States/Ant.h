#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../definitions.h"
#include "../Engine/engine.h"


class Ant {
public:

	Ant( GameDataRef data);

	void drawAnts();
	void spawnAnts(float x, float y);
	void freeRoamAntsMovement( float dt );

	void chooseDirection();

private:

	int direction;
	bool isHungry = true;

	GameDataRef _data;

	sf::Clock timer;

	std::vector<sf::Sprite> antSprites;
	std::vector<int> directions;

};
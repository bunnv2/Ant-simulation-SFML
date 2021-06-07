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
	void moveAnts( float dt );

	int chooseDirection();

private:

	int direction;
	bool isHungry = true;

	GameDataRef _data;

	std::vector<sf::Sprite> antSprites;

};
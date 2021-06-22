#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../definitions.h"
#include "../Engine/engine.h"
#include "Ant.h"

class Food
{
public:
	Food(GameDataRef data);

	void drawFood();

	float x, y;
	void spawnFood(float x, float y);
	void moveFood(float x, float y, int foodIndex);

	friend class Ant;
private:
	GameDataRef _data;

	bool isEaten = false;

	std::vector<sf::Sprite> _foodSprite;

};


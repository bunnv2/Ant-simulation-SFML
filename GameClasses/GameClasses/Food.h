#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "definitions.h"
#include "../ANTS PROJECT/Engine/engine.h"
#include <iostream>
#include "Ant.h"


class Food
{
public:
	Food(GameDataRef data);

	float x, y;

	void drawFood();

	void spawnFood(float x, float y);

	void moveFood(float x, float y, int foodIndex);

	friend class Ant;

	~Food();

private:
	GameDataRef _data;

	bool isEaten = false;

	std::vector<sf::Sprite> _foodSprite;

};


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../definitions.h"
#include "../Engine/engine.h"
#include <iostream>


class Food
{
public:
	Food(GameDataRef data);

	void drawFood();

	void spawnFood(float x, float y);


	~Food();

private:
	GameDataRef _data;
	std::vector<sf::Sprite> _foodSprite;

};


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "../definitions.h"
#include "../Engine/engine.h"
#include "Ant.h"


class Nest
{
public:
	Nest(GameDataRef data);

	void drawNest();

	void spawnNest(float x, float y);

	~Nest();
	
	friend class Ant;
private:
	GameDataRef _data;

	sf::Sprite _nestSprite;
};

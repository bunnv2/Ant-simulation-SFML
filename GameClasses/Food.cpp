#include "Food.h"
#include "../States/simulationState.h"


Food::Food(GameDataRef data) : _data(data)
{
}




void Food::drawFood()
{
	for (unsigned int i = 0; i < _foodSprite.size(); i++)
	{
		_data->window.draw(_foodSprite.at(i));
	}
}

void Food::spawnFood(float x, float y)
{
	this->x = x;
	this->y = y;

	sf::Sprite sprite(_data->assets.GetTexture("foodTexture"));
	sprite.setScale(sf::Vector2f(0.5, 0.5));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	_foodSprite.push_back(sprite);
}

void Food::moveFood(float x, float y, int foodIndex)
{
	_foodSprite.at(foodIndex).setPosition(x, y);
}


#include "Food.h"
#include "../States/simulationState.h"


Food::Food(GameDataRef data) : _data(data)
{
}




void Food::drawFood() {

	for (unsigned int i = 0; i < _foodSprite.size(); i++)
	{
		_data->window.draw(_foodSprite.at(i));
	}


}

void Food::spawnFood(float x, float y)
{

	sf::Sprite sprite(_data->assets.GetTexture("foodTexture"));
	//sprite.setScale(sf::Vector2f(0.1, 0.1));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	_foodSprite.push_back(sprite);
	
	//std::cout << _foodSprite.size() << std::endl;
	
}





Food::~Food() {

}


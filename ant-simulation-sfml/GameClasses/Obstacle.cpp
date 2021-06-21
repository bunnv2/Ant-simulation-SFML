#include "Obstacle.h"
#include "../States/simulationState.h"


Obstacle::Obstacle(GameDataRef data) : _data(data) 
{
}




void Obstacle::drawObstacle() {

	for (unsigned int i = 0; i < _obstacleSprite.size(); i++)
	{
		_data->window.draw(_obstacleSprite.at(i));
	}
	

}

void Obstacle::spawnObstacle(float x, float y)
{

	sf::Sprite sprite(_data->assets.GetTexture("obstacleTexture"));
	//sprite.setScale(sf::Vector2f(0.1, 0.1));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	_obstacleSprite.push_back(sprite);


	
}





Obstacle::~Obstacle() {

}




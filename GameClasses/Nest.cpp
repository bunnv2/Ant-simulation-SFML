#include "Nest.h"
#include "../States/simulationState.h"


Nest::Nest(GameDataRef data) : _data(data)
{
}




void Nest::drawNest() {

	//for (unsigned int i = 0; i < _nestSprite.size(); i++)
	//{
		//_data->window.draw(_nestSprite.at(i));
	//}
	_data->window.draw(_nestSprite);

}

void Nest::spawnNest(float x, float y)
{
	_nestSprite.setTexture(this->_data->assets.GetTexture("nestTexture"));
	//sf::Sprite sprite(_data->assets.GetTexture("nest"));
	//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	//sprite.setPosition(x, y);

	//_nestSprite.push_back(sprite);

	_nestSprite.setOrigin(_nestSprite.getLocalBounds().width / 2, _nestSprite.getLocalBounds().height / 2);
	_nestSprite.setPosition(x, y);
}





Nest::~Nest() {

}


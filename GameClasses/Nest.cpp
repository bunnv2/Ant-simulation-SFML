#include "Nest.h"
#include "../States/simulationState.h"


Nest::Nest(GameDataRef data) : _data(data)
{
}

void Nest::drawNest()
{
	_data->window.draw(_nestSprite);
}

void Nest::spawnNest(float x, float y)
{
	_nestSprite.setTexture(this->_data->assets.GetTexture("nestTexture"));
	_nestSprite.setOrigin(_nestSprite.getLocalBounds().width / 2, _nestSprite.getLocalBounds().height / 2);
	_nestSprite.setPosition(x, y);

}

Nest::~Nest()
{
}


#include <iostream>
#include <sstream>

#include "initState.h"
#include "../definitions.h"

initState::initState(GameDataRef data) : _data(data)
{
}

void initState::Init()
{
	this->_data->assets.LoadTexture("initBackground", INIT_STATE_BACKGROUND_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("initBackground")); 
}

void initState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) 
			this->_data->window.close();
		}
	}
}

void initState::Update(float dt)
{
}

void initState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);

	this->_data->window.display();
}

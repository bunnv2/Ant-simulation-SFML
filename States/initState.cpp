#include <iostream>
#include <sstream>

#include "initState.h"
#include "menuState.h"
#include "../definitions.h"

initState::initState(GameDataRef data) : _data(data)
{
}

void initState::Init()
{
	this->_data->assets.LoadTexture("init_Background", INIT_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadFont("pixelBit_Font", PIXEL_FONT_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("init_Background")); 
	_initText.setFont(this->_data->assets.GetFont("pixelBit_Font"));

	_initText.setString("pREss <spAcE> To conTinuE...");
	_initText.setCharacterSize(32);
	_initText.setOrigin(sf::Vector2f(_initText.getGlobalBounds().width / 2, _initText.getGlobalBounds().height / 2));
	_initText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - _initText.getCharacterSize()));
	_initText.setFillColor(sf::Color::Color(69, 175, 124)); 
}

void initState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->_data->window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) 
				this->_data->window.close();
			if (event.key.code == sf::Keyboard::Space)
				_data->machine.AddState(StateRef(new menuState(this->_data)));
		}
	}
}





void initState::Update(float dt)
{
	if (_timer.getElapsedTime().asSeconds() > 0.15)
	{
		if ((_timer.getElapsedTime().asSeconds() > 1))
		{
			_initText.setFillColor(sf::Color::Color(0, 0, 0, 0));
			_timer.restart();
		}
		else
		{
			_initText.setFillColor(sf::Color::Color(129, 178, 154));
		}
	}
}

void initState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_initText);

	this->_data->window.display();
}

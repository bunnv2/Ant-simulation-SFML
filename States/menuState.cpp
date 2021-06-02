#include <iostream>
#include <sstream>

#include "menuState.h"
#include "rulesState.h"
#include "simulationState.h"
#include "../definitions.h"

menuState::menuState(GameDataRef data) : _data(data)
{
}

void menuState::Init()
{
	this->_data->assets.LoadTexture("menu_Background", MENU_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadFont("pixelBit_Font", PIXEL_FONT_FILEPATH);

	_start.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_rules.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_exit.setFont(this->_data->assets.GetFont("pixelBit_Font"));

	_background.setTexture(this->_data->assets.GetTexture("menu_Background"));

	_start.setString("START");
	_rules.setString("RULES");
	_exit.setString("EXIT");

	_start.setCharacterSize(65);
	_rules.setCharacterSize(65);
	_exit.setCharacterSize(65);


	_start.setFillColor(sf::Color::Color(244, 241, 222));
	_rules.setFillColor(sf::Color::Color(244, 241, 222));
	_exit.setFillColor(sf::Color::Color(244, 241, 222));

	_start.setPosition(sf::Vector2f(65, 180));
	_rules.setPosition(sf::Vector2f(_start.getPosition().x,_start.getPosition().y + _start.getGlobalBounds().height + 20));
	_exit.setPosition(sf::Vector2f(_rules.getPosition().x + 15, _rules.getPosition().y + _rules.getGlobalBounds().height + 20));
}

void menuState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) // window close
		{
			this->_data->window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) //window close by pressing ESC
				this->_data->window.close();
		}

		if (event.type == sf::Event::MouseMoved) //change color over text with mouse hover
		{

			int x = sf::Mouse::getPosition(this->_data->window).x;
			int y = sf::Mouse::getPosition(this->_data->window).y;

			if (x >= _start.getPosition().x && x <= _start.getPosition().x + _start.getGlobalBounds().width
				&& y >= _start.getPosition().y + 20 && y <= _start.getPosition().y + _start.getCharacterSize())
			{
				_start.setFillColor(sf::Color::Color(61, 64, 91));
			}
			else
			{
				_start.setFillColor(sf::Color::Color(244, 241, 222));
			}

			if (x >= _rules.getPosition().x && x <= _rules.getPosition().x + _rules.getGlobalBounds().width
				&& y >= _rules.getPosition().y + 20 && y <= _rules.getPosition().y + _rules.getCharacterSize())
			{
				_rules.setFillColor(sf::Color::Color(61, 64, 91));
			}
			else
			{
				_rules.setFillColor(sf::Color::Color(244, 241, 222));
			}

			if (x >= _exit.getPosition().x && x <= _exit.getPosition().x + _exit.getGlobalBounds().width
				&& y >= _exit.getPosition().y + 20 && y <= _exit.getPosition().y + _exit.getCharacterSize())
			{
				_exit.setFillColor(sf::Color::Color(61, 64, 91));
			}
			else
			{
				_exit.setFillColor(sf::Color::Color(244, 241, 222));
			}

		}

		if (event.type == sf::Event::MouseButtonPressed)
		{

			int x = sf::Mouse::getPosition(this->_data->window).x;
			int y = sf::Mouse::getPosition(this->_data->window).y;

			if (x >= _exit.getPosition().x && x <= _exit.getPosition().x + _exit.getGlobalBounds().width //closing application by clicking 'EXIT;
				&& y >= _exit.getPosition().y + 20 && y <= _exit.getPosition().y + _exit.getCharacterSize()) 
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					this->_data->window.close();
				}
			}
			else if (x >= _rules.getPosition().x && x <= _rules.getPosition().x + _rules.getGlobalBounds().width //changing state to rules
				&& y >= _rules.getPosition().y + 20 && y <= _rules.getPosition().y + _rules.getCharacterSize())
			{
				std::cout << "rules\n";
				 _data->machine.AddState(StateRef(new rulesState(this->_data)), false);
			}
			else if (x >= _start.getPosition().x && x <= _start.getPosition().x + _start.getGlobalBounds().width //changing state to simulate
				&& y >= _start.getPosition().y + 20 && y <= _start.getPosition().y + _start.getCharacterSize())
			{
				std::cout << "simulate\n";
				 _data->machine.AddState(StateRef(new simulationState(this->_data)), false);
			}
		}
		
	}
}

void menuState::Update(float dt)
{
}

void menuState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_start);
	this->_data->window.draw(this->_rules);
	this->_data->window.draw(this->_exit);

	this->_data->window.display();
}

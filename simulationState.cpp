#include <iostream>
#include <sstream>

#include "menuState.h"
#include "rulesState.h"
#include "simulationState.h"
#include "../definitions.h"




simulationState::simulationState(GameDataRef data) : _data(data)
{
}

void simulationState::Init()
{

	this->_data->assets.LoadFont("pixelBit_Font", PIXEL_FONT_FILEPATH);


	this->_data->assets.LoadTexture("simulation_Background", INIT_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("simulation_help_Button", SIMULATION_STATE_BUTTON_HELP_FILEPATH);
	this->_data->assets.LoadTexture("stop_button", SIMULATION_STATE_BUTTON_STOP_FILEPATH);
	this->_data->assets.LoadTexture("start_button", SIMULATION_STATE_BUTTON_START_FILEPATH);
	this->_data->assets.LoadTexture("simulation_back_Button", SIMULATION_STATE_BUTTON_BACK_FILEPATH);
	this->_data->assets.LoadTexture("simulation_Nest", SIMULATION_STATE_NEST_FILEPATH);
	this->_data->assets.LoadTexture("simulation_Ants", SIMULATION_STATE_ANTS_FILEPATH);
	this->_data->assets.LoadTexture("simulation_Food", SIMULATION_STATE_FOOD_FILEPATH);
	this->_data->assets.LoadTexture("simulation_Obstacle", SIMULATION_STATE_OBSTACLE_FILEPATH);
	this->_data->assets.LoadTexture("obstacle", OBSTACLE_FILEPATH);
	this->_data->assets.LoadTexture("nest", NEST_FILEPATH);
	this->_data->assets.LoadTexture("food", FOOD_FILEPATH);
	

	_background.setTexture(this->_data->assets.GetTexture("simulation_Background"));
	_simulationbackButton.setTexture(this->_data->assets.GetTexture("simulation_back_Button"));
	_stopButton.setTexture(this->_data->assets.GetTexture("stop_button"));
	_startButton.setTexture(this->_data->assets.GetTexture("start_button"));
	_simulationNest.setTexture(this->_data->assets.GetTexture("simulation_Nest"));
	_simulationAnts.setTexture(this->_data->assets.GetTexture("simulation_Ants"));
	_simulationFood.setTexture(this->_data->assets.GetTexture("simulation_Food"));
	_simulationObstacle.setTexture(this->_data->assets.GetTexture("simulation_Obstacle"));
	_simulationhelpButton.setTexture(this->_data->assets.GetTexture("simulation_help_Button"));
	

	_plannerText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_plannerText.setString("plAnnER");
	_plannerText.setCharacterSize(83);
	_plannerText.setFillColor(sf::Color::Color(69, 175, 124));
	_plannerText.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) -(_plannerText.getGlobalBounds().width)/2, 0));



	_simulationbackButton.setPosition(sf::Vector2f(1054, 30));
	_simulationhelpButton.setPosition(sf::Vector2f(50, 30));
	_stopButton.setPosition(sf::Vector2f(600-63, 800));
	_startButton.setPosition(sf::Vector2f(600-63, 700));
	_simulationNest.setPosition(sf::Vector2f((SCREEN_WIDTH / 2), 780));
	_simulationAnts.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 260, 780));
	_simulationFood.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 130, 780));
	_simulationObstacle.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) + 130, 780));
	


	obstacle = new Obstacle(_data);
	nest = new Nest(_data);
	food = new Food(_data);
}

void simulationState::HandleInput()
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



		if (event.type == sf::Event::MouseMoved) //object resize after mouse hover 
		{


			if (sf::Mouse::getPosition(_data->window).x >= _simulationbackButton.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationbackButton.getPosition().x + _simulationbackButton.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationbackButton.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationbackButton.getPosition().y + _simulationbackButton.getGlobalBounds().height)
			{
				_simulationbackButton.setPosition(sf::Vector2f(1047.7, 26.65));
				_simulationbackButton.setScale(sf::Vector2f(1.1, 1.1));
			}
			else
			{
				_simulationbackButton.setPosition(sf::Vector2f(1054, 30));
				_simulationbackButton.setScale(sf::Vector2f(1, 1));
			}

			if (sf::Mouse::getPosition(_data->window).x >= _simulationAnts.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationAnts.getPosition().x + _simulationAnts.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationAnts.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationAnts.getPosition().y + _simulationAnts.getGlobalBounds().height)
			{
				_simulationAnts.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 265, 774.675));
				_simulationAnts.setScale(sf::Vector2f(1.07, 1.07));
			}
			else
			{
				_simulationAnts.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 260, 780));
				_simulationAnts.setScale(sf::Vector2f(1, 1));
			}

			if (sf::Mouse::getPosition(_data->window).x >= _simulationFood.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationFood.getPosition().x + _simulationFood.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationFood.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationFood.getPosition().y + _simulationFood.getGlobalBounds().height)
			{
				_simulationFood.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 135, 774.675));
				_simulationFood.setScale(sf::Vector2f(1.07, 1.07));
			}
			else
			{
				_simulationFood.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 130, 780));
				_simulationFood.setScale(sf::Vector2f(1, 1));
			}

			if (sf::Mouse::getPosition(_data->window).x >= _simulationNest.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationNest.getPosition().x + _simulationNest.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationNest.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationNest.getPosition().y + _simulationNest.getGlobalBounds().height)
			{
				_simulationNest.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - 5, 774.675));
				_simulationNest.setScale(sf::Vector2f(1.07, 1.07));
			}
			else
			{
				_simulationNest.setPosition(sf::Vector2f((SCREEN_WIDTH / 2), 780));
				_simulationNest.setScale(sf::Vector2f(1, 1));
			}

			if (sf::Mouse::getPosition(_data->window).x >= _simulationObstacle.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationObstacle.getPosition().x + _simulationObstacle.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationObstacle.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationObstacle.getPosition().y + _simulationObstacle.getGlobalBounds().height)
			{
				_simulationObstacle.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) + 125, 774.675));
				_simulationObstacle.setScale(sf::Vector2f(1.07, 1.07));
			}
			else
			{
				_simulationObstacle.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) + 130, 780));
				_simulationObstacle.setScale(sf::Vector2f(1, 1));
			}

			if (sf::Mouse::getPosition(_data->window).x >= _simulationhelpButton.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _simulationhelpButton.getPosition().x + _simulationhelpButton.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _simulationhelpButton.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _simulationhelpButton.getPosition().y + _simulationhelpButton.getGlobalBounds().height)
			{
				_simulationhelpButton.setPosition(sf::Vector2f(44.645, 25));
				_simulationhelpButton.setScale(sf::Vector2f(1.1, 1.1));
			}
			else
			{
				_simulationhelpButton.setPosition(sf::Vector2f(50, 30));
				_simulationhelpButton.setScale(sf::Vector2f(1, 1));
			}
			if (sf::Mouse::getPosition(_data->window).x >= _stopButton.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _stopButton.getPosition().x + _stopButton.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _stopButton.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _stopButton.getPosition().y + _stopButton.getGlobalBounds().height)
			{
				_stopButton.setPosition(sf::Vector2f(600 - 63 - 6.3, 800 - 3.35));
				_stopButton.setScale(sf::Vector2f(1.1, 1.1));
			}
			else
			{
				_stopButton.setPosition(sf::Vector2f(600 - 63, 800));
				_stopButton.setScale(sf::Vector2f(1, 1));
			}
			if (sf::Mouse::getPosition(_data->window).x >= _startButton.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _startButton.getPosition().x + _startButton.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _startButton.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _startButton.getPosition().y + _startButton.getGlobalBounds().height)
			{
				_startButton.setPosition(sf::Vector2f(600 - 63 - 6.3, 700 - 3.35));
				_startButton.setScale(sf::Vector2f(1.1, 1.1));
			}
			else
			{
				_startButton.setPosition(sf::Vector2f(600 - 63, 700));
				_startButton.setScale(sf::Vector2f(1, 1));
			}

		}



		if (event.type == sf::Event::MouseButtonPressed) // reactions after button clicking (back, help, start, stop)
		{

			if (_data->input.IsSpriteClicked(_simulationbackButton, sf::Mouse::Left, _data->window))
			{
				this->_data->machine.RemoveState();
			}

			if (_data->input.IsSpriteClicked(_simulationhelpButton, sf::Mouse::Left, _data->window))
			{
				this->_data->machine.AddState(StateRef(new rulesState(this->_data)), false);
			}

			if (_data->input.IsSpriteClicked(_startButton, sf::Mouse::Left, _data->window)) //start simulation
			{
				state = STATES::START;
			}

			if (_data->input.IsSpriteClicked(_stopButton, sf::Mouse::Left, _data->window)) //stop simulation
			{
				state = STATES::PLANNER;
			}

		}




		//reaction after clicking the obstacle button 
		if (obstacle_checked == true)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float x = sf::Mouse::getPosition(_data->window).x;
				float y = sf::Mouse::getPosition(_data->window).y;

				this->obstacle->spawnObstacle(x, y);
				obstacle_checked = false;

			}
		}




		//reaction after clicking the nest button 
		if (nest_checked == true)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float x = sf::Mouse::getPosition(_data->window).x;
				float y = sf::Mouse::getPosition(_data->window).y;

				this->nest->spawnNest(x, y);
				nest_checked = false;

			}
		}




		//reaction after clicking the food button 
		if (food_checked == true)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float x = sf::Mouse::getPosition(_data->window).x;
				float y = sf::Mouse::getPosition(_data->window).y;

				this->food->spawnFood(x, y);
				food_checked1 = true;
				food_checked = false;

			}
		}


		if (food_checked1 == true) {
			if (event.type == sf::Event::MouseMoved)
			{
				float x = sf::Mouse::getPosition(_data->window).x;
				float y = sf::Mouse::getPosition(_data->window).y;

				this->food->spawnFood(x, y);

				food_checked2 = true;
				food_checked = false;
			}
		}


		if (food_checked2 == true)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float x = sf::Mouse::getPosition(_data->window).x;
				float y = sf::Mouse::getPosition(_data->window).y;

				this->food->spawnFood(x, y);
				food_checked1 = false;
				food_checked2 = false;

			}
		}




		//reaction after clicking the obstacle button 
		if (_data->input.IsSpriteClicked(_simulationObstacle, sf::Mouse::Left, _data->window)) //click on obstacle
		{
			obstacle_checked = true;

		}



		//reaction after clicking the nest button 
		if (_data->input.IsSpriteClicked(_simulationNest, sf::Mouse::Left, _data->window)) //click on obstacle
		{
			if (nestButton_checked == true)
			{
				nest_checked = true;
				nestButton_checked = false;
			}


		}


		//reaction after clicking the food button 
		if (_data->input.IsSpriteClicked(_simulationFood, sf::Mouse::Left, _data->window)) //click on obstacle
		{
			food_checked = true;

		}

	}

}





void simulationState::Update(float dt)
{
}





void simulationState::Draw(float dt)
{
	this->_data->window.clear();


	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_simulationbackButton);
	this->_data->window.draw(this->_simulationhelpButton);



	if (state == STATES::PLANNER)
	{
		this->_data->window.draw(this->_simulationbackButton);
		this->_data->window.draw(this->_plannerText);
		this->_data->window.draw(this->_simulationNest);
		this->_data->window.draw(this->_simulationAnts);
		this->_data->window.draw(this->_simulationFood);
		this->_data->window.draw(this->_simulationObstacle);
		this->_data->window.draw(this->_startButton);
		this->obstacle->drawObstacle();
		this->nest->drawNest();
this->food->drawFood();
	}		

	else
	{
		this->_data->window.draw(this->_stopButton);
		this->obstacle->drawObstacle();
		this->nest->drawNest();
		this->food->drawFood();
	}

	
	this->_data->window.display();
}

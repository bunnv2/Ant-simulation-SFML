#include <iostream>
#include <sstream>

#include "menuState.h"
#include "rulesState.h"
#include "../definitions.h"




rulesState::rulesState(GameDataRef data) : _data(data)
{
}

void rulesState::Init()
{
	this->_data->assets.LoadFont("pixelBit_Font", PIXEL_FONT_FILEPATH);

	this->_data->assets.LoadTexture("rules_Background", RULES_STATE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("back_Button", RULES_STATE_BUTTON_BACK_FILEPATH);
	this->_data->assets.LoadTexture("rules_Nest", RULES_STATE_NEST_FILEPATH);
	this->_data->assets.LoadTexture("rules_Ants", RULES_STATE_ANTS_FILEPATH);
	this->_data->assets.LoadTexture("rules_Food", RULES_STATE_FOOD_FILEPATH);
	this->_data->assets.LoadTexture("rules_Obstacle", RULES_STATE_OBSTACLE_FILEPATH);
	this->_data->assets.LoadTexture("rules_Pheromones", RULES_STATE_PHEROMONES_FILEPATH);



	_rulesText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_antText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_pheromonesText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_foodText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_obstacleText.setFont(this->_data->assets.GetFont("pixelBit_Font"));
	_nestText.setFont(this->_data->assets.GetFont("pixelBit_Font"));

	_background.setTexture(this->_data->assets.GetTexture("rules_Background"));
	_backButton.setTexture(this->_data->assets.GetTexture("back_Button"));
	_rulesNest.setTexture(this->_data->assets.GetTexture("rules_Nest"));
	_rulesAnts.setTexture(this->_data->assets.GetTexture("rules_Ants"));
	_rulesFood.setTexture(this->_data->assets.GetTexture("rules_Food"));
	_rulesObstacle.setTexture(this->_data->assets.GetTexture("rules_Obstacle"));
	_rulesPheromones.setTexture(this->_data->assets.GetTexture("rules_Pheromones"));



	_rulesText.setString("THis ApplicATion is ABouT simulATing THe movemenT of AnTs. \n HoveR cursoR oveR icons AT THe BoTTom To see How \n eAcH of THem woRKs.");
	_rulesText.setCharacterSize(37);
	_rulesText.setFillColor(sf::Color::Color(244, 241, 222));
	_rulesText.setPosition(sf::Vector2f(180, 200));

	_antText.setString("THe AnT is THe coRe of THe simulATion. \n THey move in a RAnDom paTTeRn until THey find fooD. \n WHen An Ant finds fooD, iT will TRy to TRAnspoRt iT \n BAck To iTs nesT.");
	_antText.setCharacterSize(37);
	_antText.setFillColor(sf::Color::Color(244, 241, 222));
	_antText.setPosition(sf::Vector2f(180, 200));

	_foodText.setString("FooD is wHAt AnTs ARe seARcHing foR. \n WHen An AnT finDs fooD, iT is TRAnspoRTed BAck To \n THe nesT.");
	_foodText.setCharacterSize(37);
	_foodText.setFillColor(sf::Color::Color(244, 241, 222));
	_foodText.setPosition(sf::Vector2f(180, 200));

	_pheromonesText.setString("WHeneveR THe AnTs ARe wAlking, THey leAve A  \n TRAiT of DiffeRenT pHeRomones. THe colour of THe \n pHeRomone Depends on wHeTHeR An AnT is cuRRenTly \n TRAnspoRTing fooD or seARcHing for iT. \n AnTs woulD follow THose pHeRomone TRAiTs wHicH \n leaD To fooD.");
	_pheromonesText.setCharacterSize(37);
	_pheromonesText.setFillColor(sf::Color::Color(244, 241, 222));
	_pheromonesText.setPosition(sf::Vector2f(180, 200));

	_obstacleText.setString("An obsTAcle. AnTs cAnnot go THRougH THem.");
	_obstacleText.setCharacterSize(37);
	_obstacleText.setFillColor(sf::Color::Color(244, 241, 222));
	_obstacleText.setPosition(sf::Vector2f(180, 200));

	_nestText.setString("THe AnTs' nest. Ants will unloaD \n founD fooD Here.");
	_nestText.setCharacterSize(37);
	_nestText.setFillColor(sf::Color::Color(244, 241, 222));
	_nestText.setPosition(sf::Vector2f(180, 200));


	_backButton.setPosition(sf::Vector2f(1054, 20));
	_rulesNest.setPosition(sf::Vector2f(880, 680));
	_rulesAnts.setPosition(sf::Vector2f(150, 677));
	_rulesFood.setPosition(sf::Vector2f(337, 680));
	_rulesObstacle.setPosition(sf::Vector2f(707, 680));
	_rulesPheromones.setPosition(sf::Vector2f(508, 680));

}

void rulesState::HandleInput()
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


		if (event.type == sf::Event::MouseMoved) //object resize after mouse hover, text change
		{
			bool DisplayRulesText = 1;
			if (sf::Mouse::getPosition(_data->window).x >= _backButton.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _backButton.getPosition().x + _backButton.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _backButton.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _backButton.getPosition().y + _backButton.getGlobalBounds().height)
			{
				_backButton.setPosition(sf::Vector2f(1047.7, 16.65));
				_backButton.setScale(sf::Vector2f(1.1, 1.1));
			}
			else
			{
				_backButton.setPosition(sf::Vector2f(1054, 20));
				_backButton.setScale(sf::Vector2f(1, 1));

			}

			if (sf::Mouse::getPosition(_data->window).x >= _rulesAnts.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _rulesAnts.getPosition().x + _rulesAnts.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _rulesAnts.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _rulesAnts.getPosition().y + _rulesAnts.getGlobalBounds().height)
			{
				_rulesAnts.setPosition(sf::Vector2f(144.505, 672.45));
				_rulesAnts.setScale(sf::Vector2f(1.07, 1.07));
				DisplayRulesText = 0;
				rules = RULES::Ants;
			}
			else
			{
				_rulesAnts.setPosition(sf::Vector2f(150, 677));
				_rulesAnts.setScale(sf::Vector2f(1, 1));

			}

			if (sf::Mouse::getPosition(_data->window).x >= _rulesFood.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _rulesFood.getPosition().x + _rulesFood.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _rulesFood.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _rulesFood.getPosition().y + _rulesFood.getGlobalBounds().height)
			{
				_rulesFood.setPosition(sf::Vector2f(332.24, 676.045));
				_rulesFood.setScale(sf::Vector2f(1.07, 1.07));
				DisplayRulesText = 0;
				rules = RULES::Food;
			}
			else
			{
				_rulesFood.setPosition(sf::Vector2f(337, 680));
				_rulesFood.setScale(sf::Vector2f(1, 1));

			}

			if (sf::Mouse::getPosition(_data->window).x >= _rulesObstacle.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _rulesObstacle.getPosition().x + _rulesObstacle.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _rulesObstacle.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _rulesObstacle.getPosition().y + _rulesObstacle.getGlobalBounds().height)
			{
				_rulesObstacle.setPosition(sf::Vector2f(702.24, 675.765));
				_rulesObstacle.setScale(sf::Vector2f(1.07, 1.07));
				DisplayRulesText = 0;
				rules = RULES::Obstacle;
			}
			else
			{
				_rulesObstacle.setPosition(sf::Vector2f(707, 680));
				_rulesObstacle.setScale(sf::Vector2f(1, 1));

			}

			if (sf::Mouse::getPosition(_data->window).x >= _rulesPheromones.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _rulesPheromones.getPosition().x + _rulesPheromones.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _rulesPheromones.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _rulesPheromones.getPosition().y + _rulesPheromones.getGlobalBounds().height)
			{
				_rulesPheromones.setPosition(sf::Vector2f(502.645, 676.08));
				_rulesPheromones.setScale(sf::Vector2f(1.07, 1.07));
				DisplayRulesText = 0;
				rules = RULES::Pheromones;

			}
			else
			{
				_rulesPheromones.setPosition(sf::Vector2f(508, 680));
				_rulesPheromones.setScale(sf::Vector2f(1, 1));

			}

			if (sf::Mouse::getPosition(_data->window).x >= _rulesNest.getPosition().x && sf::Mouse::getPosition(_data->window).x <= _rulesNest.getPosition().x + _rulesNest.getGlobalBounds().width
				&& sf::Mouse::getPosition(_data->window).y >= _rulesNest.getPosition().y && sf::Mouse::getPosition(_data->window).y <= _rulesNest.getPosition().y + _rulesNest.getGlobalBounds().height)
			{
				_rulesNest.setPosition(sf::Vector2f(873.91, 675.975));
				_rulesNest.setScale(sf::Vector2f(1.07, 1.07));
				DisplayRulesText = 0;
				rules = RULES::Nest;
			}
			else
			{
				_rulesNest.setPosition(sf::Vector2f(880, 680));
				_rulesNest.setScale(sf::Vector2f(1, 1));

			}
			if (DisplayRulesText == 1)
			{
				rules = RULES::Rules;
			}

		}


		if (_data->input.IsSpriteClicked(_backButton, sf::Mouse::Left, _data->window))
		{
			this->_data->machine.RemoveState();
		}
	}
}

void rulesState::Update(float dt)
{
}

void rulesState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_backButton);
	this->_data->window.draw(this->_rulesNest);
	this->_data->window.draw(this->_rulesAnts);
	this->_data->window.draw(this->_rulesFood);
	this->_data->window.draw(this->_rulesObstacle);
	this->_data->window.draw(this->_rulesPheromones);
	if (rules == RULES::Rules)
		this->_data->window.draw(this->_rulesText);
	if (rules == RULES::Ants)
		this->_data->window.draw(this->_antText);
	if (rules == RULES::Food)
		this->_data->window.draw(this->_foodText);
	if (rules == RULES::Pheromones)
		this->_data->window.draw(this->_pheromonesText);
	if (rules == RULES::Obstacle)
		this->_data->window.draw(this->_obstacleText);
	if (rules == RULES::Nest)
		this->_data->window.draw(this->_nestText);

	this->_data->window.display();
}
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"
#include "../GameClasses/Food.h"
#include "../GameClasses/Ant.h"
#include "../GameClasses/Nest.h"
#include "../GameClasses/Obstacle.h"

class simulationState : public state
{
public:
	simulationState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	enum class STATES
	{
		PLANNER = 0,
		START
	}; STATES state = STATES::PLANNER;
	
private:
	GameDataRef _data;

	bool ant_checked = false;
	bool obstacle_checked = false;
	bool nest_checked = false;
	bool food_checked = false;
	bool food_checked1 = false;
	bool food_checked2 = false;
	bool nestButton_checked = true;
	
	sf::Text _plannerText;

	sf::Sprite _antTexture;
	sf::Sprite _foodTexture;
	sf::Sprite _background;
	sf::Sprite _simulationbackButton;
	sf::Sprite _simulationNest;
	sf::Sprite _simulationAnts;
	sf::Sprite _simulationObstacle;
	sf::Sprite _simulationFood;
	sf::Sprite _simulationhelpButton;
	sf::Sprite _stopButton;
	sf::Sprite _startButton;
	
	Ant* ant;
	Food* food;
	Obstacle* obstacle;
	Nest* nest;

};

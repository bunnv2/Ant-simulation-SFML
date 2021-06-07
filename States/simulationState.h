#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ant.h"
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"


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

	bool checked = false;
	
	sf::Text _plannerText;
	sf::Sprite _antTexture;
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

};

#pragma once
#include <SFML/Graphics.hpp>

//#include "Ant.h"
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"
#include "../Engine/gameData/stateMachine.h"


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

	sf::Text _plannerText;

	sf::Sprite _background;
	sf::Sprite _simulationbackButton;
	sf::Sprite _simulationNest;
	sf::Sprite _simulationAnts;
	sf::Sprite _simulationObstacle;
	sf::Sprite _simulationFood;
	sf::Sprite _simulationhelpButton;
	sf::Sprite _startButton;
};

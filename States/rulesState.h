#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"
#include "../Engine/gameData/stateMachine.h"


class rulesState : public state
{
public:
	rulesState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	enum class RULES
	{
		Rules = 0,
		Ants,
		Food,
		Obstacle,
		Nest
	};
	RULES rules = RULES::Rules;


private:
	GameDataRef _data;

	sf::Text _rulesText;
	sf::Text _antText;
	sf::Text _nestText;
	sf::Text _foodText;
	sf::Text _obstacleText;

	sf::Sprite _background;
	sf::Sprite _backButton;
	sf::Sprite _rulesNest;
	sf::Sprite _rulesAnts;
	sf::Sprite _rulesObstacle;
	sf::Sprite _rulesFood;
};
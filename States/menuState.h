#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"

class menuState : public state
{
public:
	menuState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;

	sf::Text _start;
	sf::Text _rules;
	sf::Text _exit;

	sf::Sprite _background;

};
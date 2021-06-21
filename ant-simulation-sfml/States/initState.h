#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/engine.h"
#include "../Engine/gameData/state.h"

class initState : public state
{
public:
	initState(GameDataRef);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::Text _initText;

	sf::Clock _timer;

};
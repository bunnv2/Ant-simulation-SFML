#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "gameData/assetManager.h"
#include "gameData/inputManager.h"
#include "gameData/stateMachine.h"


struct GameData
{
	stateMachine machine;
	sf::RenderWindow window;
	assetManager assets;
	inputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Engine
{
public:
	Engine(int width, int height, std::string title);
private:
	// Updates run at 60 per second.
	const float dt = 1.0f / 60.0f; 

	sf::Clock _clock;

	GameDataRef _data = std::make_shared<GameData>();

	void Run();
};



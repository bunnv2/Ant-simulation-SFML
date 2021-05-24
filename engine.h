#pragma once

#include <SFML/Graphics.hpp>

class Engine
{
private:

	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;


	void initVariable();
	void initWindow();

public:
	// CTORS / DTORS
	Engine();
	virtual ~Engine();

	// ACCESSORS
	const bool running() const;

	// FUNCTIONS
	void pollEvents();
	void update();
	void render();
};

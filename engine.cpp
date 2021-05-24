#include "engine.h"
#include "definitions.h"

// private functions
void Engine::initVariable()
{
	this->window = nullptr;
}

void Engine::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Ant Colony Simulator", sf::Style::Titlebar | sf::Style::Close);
}

// ctors / dtors
Engine::Engine()
{
	this->initVariable();
	this->initWindow();
}

Engine::~Engine()
{
	delete this->window;
}

// accessors
const bool Engine::running() const
{
	return this->window->isOpen();
}

// functions
void Engine::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Engine::update()
{
	this->pollEvents();
}

void Engine::render()
{
	/*
		
		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/
	
	window->clear();

	window->display();
}

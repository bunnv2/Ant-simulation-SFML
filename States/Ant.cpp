#include <iostream>
#include <time.h>
#include <sstream>

#include "Ant.h"

Ant::Ant( GameDataRef data) : _data(data)
{
}

void Ant::drawAnts()
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		_data->window.draw(antSprites.at(i));
	}
}

void Ant::spawnAnts(float x, float y)
{

	sf::Sprite sprite(_data->assets.GetTexture("antTexture"));
	sprite.setScale(sf::Vector2f(0.1, 0.1));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	antSprites.push_back(sprite);
}

void Ant::moveAnts(float dt)
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		sf::Vector2f position = antSprites.at(i).getPosition();
		chooseDirection();
		if (direction == 0) // gora
		{
			for (unsigned int j = 0; j < 300; j++)
			{
				antSprites.at(i).move(0.f, -1.f*dt);
			}
		}
		else if (direction == 1) // dol
		{
			antSprites.at(i).setRotation(180);
			for (unsigned int j = 0; j < 300; j++)
			{
				antSprites.at(i).move(0.f, 1.f * dt);
			}
		}
		else if (direction == 2) // prawo
		{
			antSprites.at(i).setRotation(90);
			for (unsigned int j = 0; j < 300; j++)
			{
				antSprites.at(i).move(1.f* dt, 0.f);
			}

		}
		else if (direction == 3) // lewo
		{
			antSprites.at(i).setRotation(270);
			for (unsigned int j = 0; j < 300; j++)
			{
				antSprites.at(i).move(-1.f*dt, 0.f);
			}
		}

	}
}

int Ant::chooseDirection()
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		direction = rand() % +4; // 0 up 1 up right 2 right 3 down right 4 down 5 down left 6 left 7 up left 

		return direction;
	}
}


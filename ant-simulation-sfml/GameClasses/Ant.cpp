#include "Ant.h"

Ant::Ant(GameDataRef data) : _data(data) {}

void Ant::drawAnts()
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		_data->window.draw(antSprites.at(i));
	}
}

void Ant::spawnAnts(float x, float y)
{

	std::vector <int> vect;

	// setting textures
	sf::Sprite sprite(_data->assets.GetTexture("antTexture"));
	sf::Sprite sprite2(_data->assets.GetTexture("antFoodTexture"));

	sprite2.setScale(sf::Vector2f(0.05, 0.05));
	sprite2.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite2.setPosition(x, y);

	sprite.setScale(sf::Vector2f(0.05, 0.05));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	
	// pushing vectors and starter direction choice
	Ant::direction = rand() % 8;

	isHungry.push_back(0);
	antSprites.push_back(sprite);
	directions.push_back(Ant::direction);
	 
	antDirections.push_back(vect);

	std::cout << direction << " ";	
}

void Ant::freeRoamAntsMovement(float dt, class Nest *n)
{
	for (int i = 0; i < antDirections.size(); i++)
	{
		if (antDirections[i].size() == 0)
		{
			antDirections[i].push_back(directions[i]);
		}

		if (isHungry.at(i) == 0 || isHungry.at(i) == 1) // movement if ant does not find any food
		{
			moveInDirection(i);

			if (timer == 120) // direction change after 2s time
			{
				int buffor;
				buffor = rand() % 3; // some randomizing here..

				if (buffor == 1)
				{
					directions.at(i) -= 1;
					if (directions.at(i) == -1)
					{
						directions.at(i) = 7;
					}
				}
				else if (buffor == 2)
				{
					directions.at(i) += 1;
					if (directions.at(i) == 8)
					{
						directions.at(i) = 0;
					}
				}
				else if (buffor == 0)
				{
					direction = directions.at(i);
				}
				antDirections[i].push_back(directions[i]);
			} 
		} 

		else if (isHungry.at(i) == 2 || isHungry.at(i) == 3) // czas sie rozjezdza kiedy zapisze sie odbicie od jedzenia badz sciany
		{
			moveBackToNest(i);
				
			if (isHungry.at(i) == 2)
			{
				sf::Rect<float> antRect = antSprites.at(i).getGlobalBounds();
				sf::Rect<float> nestRect = n->_nestSprite.getGlobalBounds();

				if (antRect.intersects(nestRect)) // if touched nest, go lurk again
				{
					isHungry[i] = 3;
				}
			}
		}
	}
	
	if (timer == 120) // direction change after 2s time
	{
		timer = 0;

		for (int i = 0; i < antDirections.size(); i++)
		{
			if (isHungry.at(i) == 0) {
				borderCollision(i);
			}

			if (isHungry.at(i) == 1)
			{
				isHungry.at(i) = 2;
			}

			if (isHungry.at(i) == 3)
			{
				isHungry.at(i) = 0;
				antDirections.at(i).erase(antDirections[i].begin(), antDirections[i].end());
				antSprites.at(i).setTexture(_data->assets.GetTexture("antTexture"));
			}

			if (isHungry.at(i) == 2) {
				antDirections[i].pop_back();
			}
		} 
	}

	timer += 1;
}

void Ant::collisionWithFood(Food* f)
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		sf::Rect<float> rect1 = antSprites.at(i).getGlobalBounds();

		for (unsigned int j = 0; j < f->_foodSprite.size(); j++)
		{
			sf::Rect<float> rect2 = f->_foodSprite.at(j).getGlobalBounds();

			if (rect1.intersects(rect2) && isHungry.at(i) == 0)
			{
				isHungry.at(i) = 1;
				f->_foodSprite.erase(f->_foodSprite.begin() + j );
				antSprites.at(i).setTexture(_data->assets.GetTexture("antFoodTexture"));
			}
		}
	}
}

void Ant::borderCollision(int i)
{
	if (antSprites.at(i).getPosition().x <= 0) // if ants try to escape - left side
	{
		if (directions.at(i) == 6)
		{
			directions.at(i) = 2;
			antDirections[i].push_back(2);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 5)
		{
			directions.at(i) = 3;
			antDirections[i].push_back(3);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 7)
		{
			directions.at(i) = 1;
			antDirections[i].push_back(1);
			//std::cout  << antDirections[i].back() << " ";

		}
	}
	else if (antSprites.at(i).getPosition().x >= SCREEN_WIDTH) // if ants try to escape - right side
	{
		if (directions.at(i) == 2)
		{
			directions.at(i) = 6;
			antDirections[i].push_back(6);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 3)
		{
			directions.at(i) = 5;
			antDirections[i].push_back(5);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 1)
		{
			directions.at(i) = 7;
			antDirections[i].push_back(7);
			//std::cout  << antDirections[i].back() << " ";

		}
	}
	else if (antSprites.at(i).getPosition().y <= 0) // if ants try to escape - up side
	{
		if (directions.at(i) == 0)
		{
			directions.at(i) = 4;
			antDirections[i].push_back(4);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 7)
		{
			directions.at(i) = 5;
			antDirections[i].push_back(5);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 1)
		{
			directions.at(i) = 3;
			antDirections[i].push_back(3);
			//std::cout  << antDirections[i].back() << " ";

		}
	}
	else if (antSprites.at(i).getPosition().y >= SCREEN_HEIGHT) // if ants try to escape - up side
	{
		if (directions.at(i) == 4)
		{
			directions.at(i) = 0;
			antDirections[i].push_back(0);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 5)
		{
			directions.at(i) = 1;
			antDirections[i].push_back(1);
			//std::cout  << antDirections[i].back() << " ";

		}
		else if (directions.at(i) == 3)
		{
			directions.at(i) = 1;
			antDirections[i].push_back(1);
			//std::cout  << antDirections[i].back() << " ";

		}
	}
}

void Ant::moveInDirection(int i)
{
	std::cout << "in " << directions[i] << "\n";

	if (directions.at(i) == 0) // up
	{
		antSprites.at(i).setRotation(0);
		antSprites.at(i).move(0.f, -1.f);
	}
	else if (directions.at(i) == 1) // right-up
	{
		antSprites.at(i).setRotation(45);
		antSprites.at(i).move(1.f, -1.f);
	}
	else if (directions.at(i) == 2) // right
	{
		antSprites.at(i).setRotation(90);
		antSprites.at(i).move(1.f, 0.f);
	}
	else if (directions.at(i) == 3) // right-down
	{
		antSprites.at(i).setRotation(135);
		antSprites.at(i).move(1.f, 1.f);
	}
	else if (directions.at(i) == 4) // down
	{
		antSprites.at(i).setRotation(180);
		antSprites.at(i).move(0.f, 1.f);
	}
	else if (directions.at(i) == 5) // left-down
	{
		antSprites.at(i).setRotation(225);
		antSprites.at(i).move(-1.f, 1.f);
	}
	else if (directions.at(i) == 6) // left
	{
		antSprites.at(i).setRotation(270);
		antSprites.at(i).move(-1.f, 0.f);
	}

	else if (directions.at(i) == 7) // left-up
	{
		antSprites.at(i).setRotation(315);
		antSprites.at(i).move(-1.f, -1.f);
	}
}

void Ant::moveBackToNest(int i)
{
	if (antDirections[i].size() == 0)
	{
		std::cout << "taki chuj " << antDirections[i].back() << " / " << isHungry.at(i) << "\n";
	}

	if (antDirections[i].back() == 0) // if up go down
	{
		antSprites.at(i).setRotation(180);
		antSprites.at(i).move(0.f, 1.f);
	}
	else if (antDirections[i].back() == 1) // if right-up, go left-down
	{
		antSprites.at(i).setRotation(225);
		antSprites.at(i).move(-1.f, 1.f);
	}
	else if (antDirections[i].back() == 2) // if right, go left
	{
		antSprites.at(i).setRotation(270);
		antSprites.at(i).move(-1.f, 0.f);
	}
	else if (antDirections[i].back() == 3) // if right-down, go left up
	{
		antSprites.at(i).setRotation(315);
		antSprites.at(i).move(-1.f, -1.f);
	}
	else if (antDirections[i].back() == 4) // if down, go up
	{
		antSprites.at(i).setRotation(0);
		antSprites.at(i).move(0.f, -1.f);
	}
	else if (antDirections[i].back() == 5) // if left-down, go right up
	{
		antSprites.at(i).setRotation(45);
		antSprites.at(i).move(1.f, -1.f);
	}
	else if (antDirections[i].back() == 6) // if left, go right
	{
		antSprites.at(i).setRotation(90);
		antSprites.at(i).move(1.f, 0.f);
	}

	else if (antDirections[i].back() == 7) // if left-up, go right, down
	{
		antSprites.at(i).setRotation(135);
		antSprites.at(i).move(1.f, 1.f);
	}
}

void Ant::counter()
{
	std::cout << std::endl << std::endl << std::endl;
	for (int i = 0; i < antDirections.size(); i++)
	{
		if (isHungry[i] == 0)
		{
			std::cout << "\nANT " << i << std::endl;
			for (int j = 0; j < antDirections[i].size(); j++)
			{
				std::cout << antDirections[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}





#include "Ant.h"

Ant::Ant(GameDataRef data) : _data(data)
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
	sf::Sprite sprite2(_data->assets.GetTexture("antFoodTexture"));

	sprite2.setScale(sf::Vector2f(0.05, 0.05));
	sprite2.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite2.setPosition(x, y);

	sprite.setScale(sf::Vector2f(0.05, 0.05));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(x, y);

	Ant::direction = rand() % +8;

	antSprites.push_back(sprite);
	directions.push_back(Ant::direction);
	isHungry.push_back(0);
	
}

void Ant::freeRoamAntsMovement(float dt, class Nest* n)
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		if (isHungry.at(i) == 0) // movement if ant does not find any food
		{
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

			if (antSprites.at(i).getPosition().x == 0) // if ants try to escape - left side
			{
				if (directions.at(i) == 6)
				{
					directions.at(i) = 2;
				}
				else if (directions.at(i) == 5)
				{
					directions.at(i) = 3;
				}
				else if (directions.at(i) == 7)
				{
					directions.at(i) = 1;
				}
			}
			else if (antSprites.at(i).getPosition().x == SCREEN_WIDTH) // if ants try to escape - right side
			{
				if (directions.at(i) == 2)
				{
					directions.at(i) = 6;
				}
				else if (directions.at(i) == 3)
				{
					directions.at(i) = 5;
				}
				else if (directions.at(i) == 1)
				{
					directions.at(i) = 7;
				}
			}
			else if (antSprites.at(i).getPosition().y == 0) // if ants try to escape - up side
			{
				if (directions.at(i) == 0)
				{
					directions.at(i) = 4;
				}
				else if (directions.at(i) == 7)
				{
					directions.at(i) = 5;
				}
				else if (directions.at(i) == 1)
				{
					directions.at(i) = 3;
				}
			}
			else if (antSprites.at(i).getPosition().y == SCREEN_HEIGHT) // if ants try to escape - up side
			{
				if (directions.at(i) == 4)
				{
					directions.at(i) = 0;
				}
				else if (directions.at(i) == 5)
				{
					directions.at(i) = 1;
				}
				else if (directions.at(i) == 3)
				{
					directions.at(i) = 1;
				}
			}

			if (timer.getElapsedTime().asSeconds() > 2) // direction change after 2s time
			{
				for (int j = 0; j < antSprites.size(); j++)
				{
					int buffor;
					buffor = rand() % +3; // some randomizing here..

					if (buffor == 1)
					{
						directions.at(j) -= 1;
						if (directions.at(j) == -1)
						{
							directions.at(j) = 7;
						}
					}
					else if (buffor == 2)
					{
						directions.at(j) += 1;
						if (directions.at(j) == 8)
						{
							directions.at(j) = 0;
						}
					}
					else if (buffor == 0)
					{
						directions.at(j) = directions.at(j);
					}

				}
				timer.restart();
			}
		}
		else if (isHungry.at(i) == 1) 
		{
			sf::Rect<float> rect1 = antSprites.at(i).getGlobalBounds();
			sf::Rect<float> rect2 = n->_nestSprite.getGlobalBounds();

			if (rect1.intersects(rect2)) // if touched nest, go lurk again
			{
				foodCounter++;
				isHungry.at(i) = 0;
				antSprites.at(i).setTexture(_data->assets.GetTexture("antTexture"));

				if (directions.at(i) == 6)
					{
						directions.at(i) = 2;
					}

					else if (directions.at(i) == 5)
					{
						directions.at(i) = 1;
					}

					else if (directions.at(i) == 7)
					{
						directions.at(i) = 3;
					}
				
					else if (directions.at(i) == 2)
					{
						directions.at(i) = 6;
					}

					else if (directions.at(i) == 3)
					{
						directions.at(i) = 7;
					}

					else if (directions.at(i) == 1)
					{
						directions.at(i) = 5;
					}
				
					else if (directions.at(i) == 0)
					{
						directions.at(i) = 4;
					}
					
					else if (directions.at(i) == 4)
					{
						directions.at(i) = 0;
					}

			}
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

					if (antSprites.at(i).getPosition().x == 0) // if ants try to escape - left side
					{
						if (directions.at(i) == 6)
						{
							directions.at(i) = 2;
						}
						else if (directions.at(i) == 5)
						{
							directions.at(i) = 3;
						}
						else if (directions.at(i) == 7)
						{
							directions.at(i) = 1;
						}
					}
					else if (antSprites.at(i).getPosition().x == SCREEN_WIDTH) // if ants try to escape - right side
					{
						if (directions.at(i) == 2)
						{
							directions.at(i) = 6;
						}
						else if (directions.at(i) == 3)
						{
							directions.at(i) = 5;
						}
						else if (directions.at(i) == 1)
						{
							directions.at(i) = 7;
						}
					}
					else if (antSprites.at(i).getPosition().y == 0) // if ants try to escape - up side
					{
						if (directions.at(i) == 0)
						{
							directions.at(i) = 4;
						}
						else if (directions.at(i) == 7)
						{
							directions.at(i) = 5;
						}
						else if (directions.at(i) == 1)
						{
							directions.at(i) = 3;
						}
					}
					else if (antSprites.at(i).getPosition().y == SCREEN_HEIGHT) // if ants try to escape - up side
					{
						if (directions.at(i) == 4)
						{
							directions.at(i) = 0;
						}
						else if (directions.at(i) == 5)
						{
							directions.at(i) = 1;
						}
						else if (directions.at(i) == 3)
						{
							directions.at(i) = 1;
						}
					}

					if (timer.getElapsedTime().asSeconds() > 2) // direction change after 2s time
					{
						for (int j = 0; j < antSprites.size(); j++)
						{
							int buffor;
							buffor = rand() % +3; // some randomizing here..

							if (buffor == 1)
							{
								directions.at(j) -= 1;
								if (directions.at(j) == -1)
								{
									directions.at(j) = 7;
								}
							}
							else if (buffor == 2)
							{
								directions.at(j) += 1;
								if (directions.at(j) == 8)
								{
									directions.at(j) = 0;
								}
							}
							else if (buffor == 0)
							{
								directions.at(j) = directions.at(j);
							}
						}
						timer.restart();
			
			}

		}

	}
}




void Ant::collisionWithObstacle(Obstacle* obstacle)
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		sf::Rect<float> rect1 = antSprites.at(i).getGlobalBounds();
		for (unsigned int j = 0; j < obstacle->_obstacleSprite.size(); j++)
		{
			
			sf::Rect<float> rect2 = obstacle->_obstacleSprite.at(j).getGlobalBounds();

			if (rect1.intersects(rect2)) 
			{
				
					if (directions.at(i) == 6)
					{
						directions.at(i) = 2;
					}

					else if (directions.at(i) == 5)
					{
						directions.at(i) = 1;
					}

					else if (directions.at(i) == 7)
					{
						directions.at(i) = 3;
					}
				
					else if (directions.at(i) == 2)
					{
						directions.at(i) = 6;
					}

					else if (directions.at(i) == 3)
					{
						directions.at(i) = 7;
					}

					else if (directions.at(i) == 1)
					{
						directions.at(i) = 5;
					}
				
					else if (directions.at(i) == 0)
					{
						directions.at(i) = 4;
					}
					
					else if (directions.at(i) == 4)
					{
						directions.at(i) = 0;
					}
					
			}
		}
	}
}





void Ant::collisionWithFood(Food* f)
{
	for (unsigned int i = 0; i < antSprites.size(); i++)
	{
		if (isHungry.at(i) == 0) 
		{
		sf::Rect<float> rect1 = antSprites.at(i).getGlobalBounds();
		sf::Vector2f position = antSprites.at(i).getPosition();

		for (unsigned int j = 0; j < f->_foodSprite.size(); j++)
		{
			sf::Rect<float> rect2 = f->_foodSprite.at(j).getGlobalBounds();

			if (rect1.intersects(rect2))
			{
				isHungry.at(i) = 1;
				f->_foodSprite.erase(f->_foodSprite.begin() + j);
				antSprites.at(i).setTexture(_data->assets.GetTexture("antFoodTexture"));
			}
		}
		}
	}
}





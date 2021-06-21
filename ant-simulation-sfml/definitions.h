#pragma once
#include "SFML/Graphics.hpp"
/*
	here are all the definitions we are using, f.e.
		- file paths
		- global variables (like screen width/height)
		etc..

*/

//VARIABLES
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

const int cellSize = 5;
const int gridWidth = SCREEN_WIDTH / cellSize;
const int gridHeight = SCREEN_HEIGHT / cellSize;
const int cellNumber = gridWidth * gridHeight;


//BACKGROUNDS
#define INIT_STATE_BACKGROUND_FILEPATH "res/initStateBackground.png"
#define MENU_STATE_BACKGROUND_FILEPATH "res/menuStateBackground.png"
#define RULES_STATE_BACKGROUND_FILEPATH "res/rulesbackground.png"
#define SIMULATION_STATE_BACKGROUND_FILEPATH "res/SimulationPlannerBackground.png"

//BUTTONS
#define RULES_STATE_BUTTON_BACK_FILEPATH "res/rulesBackButton.png"
#define RULES_STATE_NEST_FILEPATH "res/rulesNest.png"
#define RULES_STATE_OBSTACLE_FILEPATH "res/rulesObstacle.png"
#define RULES_STATE_FOOD_FILEPATH "res/rulesFood.png"
#define RULES_STATE_ANTS_FILEPATH "res/rulesAnts.png"
#define RULES_STATE_PHEROMONES_FILEPATH "res/rulesPheromones.png"

#define SIMULATION_STATE_BUTTON_BACK_FILEPATH "res/SimulationBackButton.png"
#define SIMULATION_STATE_NEST_FILEPATH "res/SimulationNest.png"
#define SIMULATION_STATE_OBSTACLE_FILEPATH "res/SimulationObstacle.png"
#define SIMULATION_STATE_FOOD_FILEPATH "res/SimulationFood.png"
#define SIMULATION_STATE_ANTS_FILEPATH "res/SimulationAnts.png"
#define SIMULATION_STATE_BUTTON_HELP_FILEPATH "res/SimulationHelpButton.png"
#define SIMULATION_STATE_BUTTON_START_FILEPATH "res/SimulationStartButton.png"
#define SIMULATION_STATE_BUTTON_STOP_FILEPATH "res/SimulationStopButton.png"

//FONTS
#define PIXEL_FONT_FILEPATH "res/PixelBit.ttf"

//IN-GAME TEXTURES
#define ANT_TEXTURE_FILEPATH "res/ant.png"
#define ANT_FOOD_TEXTURE_FILEPATH "res/antWithFood.png"
#define FOOD_TEXTURE_FILEPATH "res/food.png"
#define OBSTACLE_TEXTURE_FILEPATH "res/obstacle.png"
#define NEST_TEXTURE_FILEPATH "res/nest.png"



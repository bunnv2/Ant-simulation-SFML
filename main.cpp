#include "definitions.h"
#include "Engine/engine.h"

int main()
{
    srand(time(NULL));

    //initialize game engine
    Engine hello_world(SCREEN_WIDTH, SCREEN_HEIGHT, "Ant Colony Simulation");

    return 0;
}

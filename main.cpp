#include "engine.h"

int main()
{

    //init game engine
    Engine engine;

    //app loop
    while (engine.running())
    {
        //Update
        engine.update();

        //Render
        engine.render();
    }

    return 0;
}

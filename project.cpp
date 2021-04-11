// apps/Projet/project.cpp
#include<Grapic.h>
#include"utility.h"

using namespace grapic;


int main(int , char**)
{
    srand(time(NULL));
    bool stop = false;
    World my_world;
    world_init(my_world);
    winInit("Fire in a Forest",my_world.DIMW,my_world.DIMW);
    backgroundColor(255,200,100);
    float t_now;
    float t_before = 0;

    int x = rand()%my_world.size;
    int y = rand()%my_world.size;

    my_world.blocks[x][y].type = 2;
    my_world.blocks[x][y].onfire = true;

    //setKeyboardRepeatMode(true);

    while(!stop)
    {
        winClear();
        t_now = elapsedTime();
        world_draw(my_world);
        setrain(my_world);
        if (t_now - t_before > 0.5f)
        {
            world_update(my_world);
            t_before = t_now;
        }
        stop = winDisplay();
    }
    
    winQuit();
    return 0;
}

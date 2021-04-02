// apps/Projet/project.cpp
#include<Grapic.h>
#include"utility.h"

using namespace grapic;


int main(int , char**)
{
    bool stop = false;
    World my_world;
    world_init(my_world);
    winInit("Fire in a Forest",my_world.DIMW,my_world.DIMW);
    backgroundColor(255,200,100);
    srand(time(NULL));

    int x = rand()%my_world.size;
    int y = rand()%my_world.size;

    my_world.blocks[x][y].type = 2;
    my_world.blocks[x][y].onfire = true;

    while(!stop)
    {
        winClear();
        world_draw(my_world);
        delay(1000);
        world_update(my_world);
        stop = winDisplay();
    }
    
    winQuit();
    return 0;
}

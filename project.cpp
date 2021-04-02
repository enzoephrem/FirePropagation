// apps/Projet/project.cpp
#include<Grapic.h>
#include"utility.h"

using namespace grapic;
 
int const DIMW = 500;


int main(int , char**)
{
    bool stop = false;
    winInit("Fire in a Forest",DIMW,DIMW);
    backgroundColor(255,200,100);
    srand(time(NULL));

    World my_world;
    world_init(my_world, DIMW);

    while(!stop)
    {
        winClear();
        world_draw(my_world);
        stop = winDisplay();
    }
    
    winQuit();
    return 0;
}

// cd build/macosx ; make -f project.make ; ../../bin/project 
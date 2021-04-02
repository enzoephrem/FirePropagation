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
    
    while(!stop)
    {
        winClear();
        color(255, 255, 100);
        print(DIMW/2, DIMW/2, "test6");
        stop = winDisplay();
    }
    
    winQuit();
    return 0;
}

// cd build/macosx ; make -f project.make ; ../../bin/project 
//
//  utility.cpp
//  project
//
//  Created by Enzo Ephrem on 20/03/2021.
//

#include "utility.h"
#include <math.h>


// functions for Color

Color make_color(unsigned char r, unsigned char g, unsigned char b)
{
    Color c = {r,g,b};
    return c;
}

// functions for block

void setrain(block& cell)
{
    cell.israining = true;
}

void setfire(block& cell)
{
    if (cell.type == 2) cell.onfire = true;
}

int check_neighbors(block& b)
{
    int answer = 0;
    //  answer = 1 if neighbor on fire
    // return 1 if one of the neighbors at least is on fire, return 0 if none on fire
    return answer;
}


// functions for World

void world_init(World& w)
{
}

void world_draw(World w)
{
}

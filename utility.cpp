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

    w.size = 100;
    w.forest_nb = 0.5 * w.size;

    for (int i = 0; i < w.size; i++)
    {
        for (int j = 0; j < w.size; j++)
        {
            w.blocks[i][j].x1 = j * w.DIMW/w.size;
            w.blocks[i][j].x2 = w.blocks[i][j].x1 + w.DIMW/w.size;
            w.blocks[i][j].y1 = i * w.DIMW/w.size;
            w.blocks[i][j].y2 = w.blocks[i][j].y1 + w.DIMW/w.size;
            w.blocks[i][j].israining = false;
            w.blocks[i][j].onfire = false;
            w.blocks[i][j].type = 0;
        }
    }

    

}

void world_draw(World w)
{
}

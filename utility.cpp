//
//  utility.cpp
//  project
//
//  Created by Enzo Ephrem on 20/03/2021.
//

#include "utility.h"
#include<Grapic.h>
#include <math.h>
#include<cmath>

using namespace grapic;

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

void world_init(World& w, int DIMW)
{
    int tmp_x, tmp_y;
    w.size = 50;
    w.forest_nb = round(0.5 * w.size*w.size);
    w.DIMW = DIMW;

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

    for (int i = 0; i < w.forest_nb; i++)
    {
        do
        {
            tmp_x = rand() % w.size;
            tmp_y = rand() % w.size;
        }while(w.blocks[tmp_x][tmp_y].type != 0);
        w.blocks[tmp_x][tmp_y].type = 2;
    }

}

void world_draw(World w)
{
    for (int i = 0; i < w.size; i++)
    {
        for (int j = 0; j < w.size; j++)
        {
            switch(w.blocks[i][j].type)
            {
                case 0:
                    color(255, 255, 255); // empty -> white
                    break;
                case 1:
                    color(45, 45, 45); // ash -> grey
                case 2:
                    if (w.blocks[i][j].onfire) color(255, 0, 0); // forest on fire -> red
                    else color(0, 255, 0); // forest not on fire -> green 
            }
            rectangleFill(w.blocks[i][j].x1, w.blocks[i][j].y1, w.blocks[i][j].x2, w.blocks[i][j].y2);
        }
    }
}

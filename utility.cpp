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

int const DIMW = 500;
int const token = 0;
int const nX[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int const nY[8] =  {0, 0, -1, 1, 1, -1, 1, -1};

// functions for Color

Color make_color(unsigned char r, unsigned char g, unsigned char b)
{
    Color c = {r,g,b};
    return c;
}

Color operator+(Color a, Color b)
{
    Color r;
    r.r = a.r + b.r;
    r.g = a.g + b.g;
    r.b = a.b + b.b;
    return r;
}

Color operator*(float a, Color b)
{
    Color r;
    r.r = a * b.r;
    r.g = a * b.g;
    r.b = a * b.b;
    return r;
}

Color interpolation_color(Color c1, Color c2, float T)
{
    Color res;
    res = (T * c1) + ((1-T) * c2);
    return res;
}

// functions for block

// functions for World


void setrain(World& w)
{
    int x, y;
    mousePos(x, y);
    if (isMousePressed(SDL_BUTTON_LEFT))
    {
        int index_i, index_j;
        index_j = x /(w.DIMW/w.size);
        index_i = y /(w.DIMW/w.size);
        w.blocks[index_i][index_j].israining = true;
        for (int k = 0; k < 8; k++)
        {
            if (index_i - nX[k] >= 0 && index_i - nX[k] < w.size && index_j - nY[k] >= 0 && index_j - nY[k] < w.size)
            {
                w.blocks[index_i - nX[k]][index_j - nY[k]].israining = true;
            }
        }
    }
}

void world_init(World& w)
{
    int tmp_x, tmp_y;
    w.size = 50;
    w.forest_nb = round(0.7 * w.size*w.size);
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
            w.blocks[i][j].fireToken = 0;
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
    Color intercolor;
    for (int i = 0; i < w.size; i++)
    {
        for (int j = 0; j < w.size; j++)
        {
            if(w.blocks[i][j].israining)
            {
                switch(w.blocks[i][j].type)
                {
                    case 0:
                        intercolor = make_color(255, 255, 255); // empty -> white
                        break;
                    case 1:
                        intercolor = make_color(45, 45, 45); // ash -> grey
                        break;
                    case 2:
                        if (w.blocks[i][j].onfire) intercolor = make_color(255, 0, 0); // forest on fire -> red
                        else intercolor = make_color(0, 255, 0); // forest not on fire -> green 
                        break;
                }
                intercolor = interpolation_color(intercolor, make_color(0, 0, 255), 0.3);

                color(intercolor.r, intercolor.g, intercolor.b);
            }
            else
            {
                switch(w.blocks[i][j].type)
                {
                    case 0:
                        color(255, 255, 255); // empty -> white
                        break;
                    case 1:
                        color(45, 45, 45); // ash -> grey
                        break;
                    case 2:
                        if (w.blocks[i][j].onfire) color(255, 0, 0); // forest on fire -> red
                        else color(0, 255, 0); // forest not on fire -> green 
                        break;
                }
            }
            rectangleFill(w.blocks[i][j].x1, w.blocks[i][j].y1, w.blocks[i][j].x2, w.blocks[i][j].y2);
        }
    }
}

void world_update(World& w)
{
    World new_world = w;
    int x,y, prob;

    for (int i = 0; i < w.size; i++)
    {
        for (int j = 0; j < w.size; j++)
        {

            switch (w.blocks[i][j].type)
            {
                case 2:
                    if (w.blocks[i][j].onfire)
                    {
                        new_world.blocks[i][j].onfire = false;
                        new_world.blocks[i][j].type = w.blocks[i][j].type - 1;
                    }
                    else
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            if (i - nX[k] >= 0 && i - nX[k] < w.size && j - nY[k] >= 0 && j - nY[k] < w.size)
                            {
                                if (w.blocks[i-nX[k]][j-nY[k]].onfire)
                                {
                                    new_world.blocks[i][j].onfire = true;
                                    if (w.blocks[i-nX[k]][j-nY[k]].israining) new_world.blocks[i][j].fireToken = w.blocks[i-nX[k]][j-nY[k]].fireToken + 1;
                                    else new_world.blocks[i][j].fireToken = 0;
                                    if (new_world.blocks[i][j].fireToken > 3)
                                    {
                                        new_world.blocks[i][j].onfire = false;
                                        new_world.blocks[i][j].type = w.blocks[i][j].type - 1; 
                                    }
                                }
                            }
                        }
                    }
                    break;
                
                case 1:
                    new_world.blocks[i][j].type = w.blocks[i][j].type - 1;
                    new_world.blocks[i][j].fireToken = 0;
                    break;
                case 0:
                    break;
            }
        }
    }
    w = new_world;
}

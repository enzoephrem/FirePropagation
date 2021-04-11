//
//  utility.hpp
//  project
//
//  Created by Enzo Ephrem on 20/03/2021.
//

#ifndef utility_h
#define utility_h

#include <stdio.h>

int const MAX = 100;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// -------------------------Color-------------------------------
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Color entity representing an r value, g value and b value
struct Color
{
    int r, g, b;
};

// create a Color structure
Color make_color(unsigned char r, unsigned char g, unsigned char b);
Color operator+(Color a, Color b);
Color operator*(float a, Color b);
Color interpolation_color(Color c1, Color c2);


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// -------------------------Block-------------------------------
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// a block representing a cell in the World
struct block
{
    float x1, x2, y1, y2; // coordinates of the block
    bool israining; // israining=True if raining, False if not
    int type; // 0 for empty, 1 for ash, 2 for forest
    bool onfire; // if type=2 and on fire onfire=True else False
    int fireToken; // if onfire have a token to track the cell
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// -------------------------World-------------------------------
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct World
{
    int DIMW;
    int size;
    int forest_nb;
    block blocks[MAX][MAX];
};

void setrain(World& w);
void world_init(World& w);
void world_draw(World w);
void world_update(World& w);
void humidity_draw(World w);
void humidity_update(World& w);

#endif

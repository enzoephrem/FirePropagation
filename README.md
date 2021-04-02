My project will consiste on a simple World divided in smaller cells, that will each have a type,
- 0: empty
- 1: ash
- 2: forest

Empty being a cell that hypothetically and visually don't change (white color), ash the successor of a forest on fire (grey color) and forest a cell that can catch fire (any other cell can't catch fire) (green color), a forest on fire will be a state in wich a forest can be in (red color).

The concept of the program is to simulate with various factors and events the propagation of a wild fire in a forest.
Assuming that the fire will be passed to a nearby forest cell if one of it's four adjacent cells is on fire:

```diff


            time: t         | empty  |+forest |+forest |+forest |
                            | -fire  |+forest | empty  |+forest | 
                            |+forest |+forest | forest | empty  |
                            |+forest |+forest | forest |+forest |
                            | empty  |+forest |  fire  |+forest |
                            |+forest |+forest |+forest |+forest |
                            |+forest |+forest |+forest | empty  |
            
            time: t+1       | empty  |+forest |+forest |+forest |
                            |  #ash  | -fire  | empty  |+forest | 
                            | -fire  |+forest |+forest | empty  |
                            |+forest |+forest | -fire  |+forest |
                            | empty  | -fire  |  ash   | -fire  |
                            |+forest |+forest | -fire  |+forest |
                            |+forest |+forest | forest | empty  |
```


In the process of the propagation of the fire will come in a factor/event of *Rain* controled by a user click wich will slow down and/or turn off fires depending on how much time it has been under the rain. *Rain* will be similar to *Fire*, it will be a state in wich a block can be. But *Rain* here can be applied to whatever the type of the Block is, *Fire* can only be a state to a forest type block.


With each block having different types and states, for each of the blocks in a world we will have to look at it's neighbours to predict the next type it will have.

First of all, let's begin by initializing the World having **size** number of block with **forest_nb** of forest (in a kind of way that is the density of the World) and obviously **size**-**forest_nb** of empty blocks. The initialization will be at random.


Let's initialize the size of the world **size** (here 50), the number of forest **nb_forest** (around a density of 50%) and DIMW the size of the window.

```
void world_init(World& w, int DIMW)
{
    int tmp_x, tmp_y;
    w.size = 50;
    w.forest_nb = round(0.5 * w.size*w.size);
    w.DIMW = DIMW;

```

Then with a simple itteration through every block we will initialize them to its corresponding coordinates. And have every attribute initialized to false and 0 respectivly for *israining*/*onfire* and type.

```
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
```

Now that we have all blocks empty and not on fire and with no rain, let's add the forst type blocks. Picking randomly a block from the World till it's empty and changing it's type to 2 and this **forest_nb** times.
```
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
```


 

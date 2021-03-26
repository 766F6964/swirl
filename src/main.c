#include <stdio.h>
#include <stdlib.h>
#include "../deps/dotdotdot/src/grid.h"

int main(int argc, char** argv)
{   
    grid* g = grid_new(100,100);

    grid_free(g);
    return 0;
}

void generate_galaxy(int grid_width, int grid_height)
{

}
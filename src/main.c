#include <stdio.h>
#include <stdlib.h>
#include "particle.h"
#include "../deps/dotdotdot/src/grid.h"
#include "../deps/dotdotdot/src/renderer.h"

// References: https://github.com/iSach/nbody-c

int main(int argc, char** argv)
{
    int width = 100;
    int height = 100;
    
    grid *g = grid_new(width, height);
    renderer_new(g);

    while (1)
    {
        grid_clear(g);
        grid_draw_border(g, 1);
        renderer_update(g);
    }

    return 0;
}

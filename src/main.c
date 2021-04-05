#include <stdio.h>
#include <stdlib.h>
#include "particle.h"
#include "nparticle.h"
#include "../deps/dotdotdot/src/grid.h"
#include "../deps/dotdotdot/src/renderer.h"

// References: https://github.com/iSach/nbody-c

int main(int argc, char** argv)
{
    int width = 100;
    int height = 100;
    
    double time_max = 100;
    double time_delta = 0.1; 

    nparticle* np = nparticle_generate_random(10);

    for (double i = 0.0; i < time_max; i += time_delta)
    {
        // Compute particle position, velocity & forces etc
        nparticle_simulate_bruteforce(np, time_delta);

        // Render particles to grid
    
    }

    nparticle_free(np);

    /*
    grid *g = grid_new(width, height);
    renderer_new(g);

    while (1)
    {
        grid_clear(g);
        grid_draw_border(g, 1);
        renderer_update(g);
    }
    */

    return 0;
}

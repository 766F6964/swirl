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

    nparticle* np = nparticle_generate_random(10, width, height);

    grid *g = grid_new(width, height);
    renderer_new(g);

    while (1)
    {
        grid_clear(g);
        
        for (double i = 0.0; i < time_max; i += time_delta)
        {
            // Compute particle position, velocity & forces etc
            nparticle_simulate_bruteforce(np, time_delta);

            // Render particles to grid
            grid_clear(g);

            for (int j = 0; j < np->n; j++)
            {
                int pos_x = (int)np->particles[j]->pos_x;
                int pos_y = (int)np->particles[j]->pos_y;

                //printf("%i %i\n", pos_x, pos_y);
                if(pos_x < width && pos_y < height)
                    grid_set_pixel(g, pos_x, pos_y);
            }
            //printf("------------\n");
        }

        renderer_update(g);
    }

    nparticle_free(np);

    return 0;
}

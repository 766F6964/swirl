#include <stdio.h>
#include <stdlib.h>
#include "particle.h"
#include "nparticle.h"
#include "../deps/dotdotdot/src/grid.h"
#include "../deps/dotdotdot/src/renderer.h"
#include "../deps/log/src/log.h"

// References: https://github.com/iSach/nbody-c

int main(int argc, char **argv) {
    // Initialize the logger
    log_use_time_prefix(false);
    log_use_short_prefix(true);
    log_use_colored_prefix(false);
    log_set_mode(LOGFILE);
    log_set_filename("errors.log");

    int width = 180;
    int height = 180;

    double time_max = 100;
    double time_delta = 0.1;

    //nparticle* np = nparticle_generate_random(30, width, height);
    nparticle *np = nparticle_generate_from_file("galaxy1.txt");

    grid *g = grid_new(width, height);
    renderer_new(g);

    while (1) {
        grid_clear(g);

        for (double i = 0.0; i < time_max; i += time_delta) {
            // Clear previous drawn frame
            grid_clear(g);

            // Draw border
            grid_draw_border(g, 1);

            // Compute particle position, velocity & forces etc
            nparticle_simulate_bruteforce(np, time_delta);

            // Render particles to grid
            for (int j = 0; j < np->n; j++) {

                // Clamp coordinates to grid width and height
                int pos_x = (((int) np->particles[j]->pos_x + np->radius) /
                             (2 * np->radius) * (double) width);
                int pos_y = (((height - (int) np->particles[j]->pos_y) + np->radius) /
                             (2 * np->radius) * (double) height);

                if (pos_x < width && pos_x > 0 && pos_y < height && pos_y > 0) {
                    grid_set_pixel(g, pos_x, pos_y);
                }
            }

            // Draw changes to screen
            renderer_update(g);
        }

        renderer_update(g);
    }

    nparticle_free(np);

    return 0;
}

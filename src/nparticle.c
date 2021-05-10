#include "nparticle.h"
#include "particle.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../deps/log/src/log.h"

nparticle *nparticle_generate_random(int n, int grid_width, int grid_height)
{
    nparticle *nparticle = malloc(sizeof(nparticle));
    if (nparticle == NULL) return NULL;

    particle **particles = malloc(sizeof(nparticle) * n);
    if (particles == NULL) return NULL;

    double mass_blackhole = 10e34;
    double mass_star = 5e08;
    double radius_star = 10;

    nparticle->radius = radius_star;
    nparticle->n = n;
    nparticle->particles = particles;
    //nparticle->bhtree = NULL:

    // Create black hole (particle with high mass)
    particles[0] = particle_create(mass_blackhole, grid_width / 2, grid_height / 2, 0, 0);

    // Initialize random
    srand(time(NULL));

    // Create stars (particles with low mass)
    for (int i = 0; i < n; i++)
    {
        // Choose random position for the stars
        //double rx = ((double)rand() / (double)RAND_MAX * 2 * radius_star - radius_star);
        //double ry = ((double)rand() / (double)RAND_MAX * 2 * radius_star - radius_star);
        double rx = (double)(rand() % grid_width);
		double ry = (double)(rand() % grid_height);

        // Set velocity perpindicular to black hole, to ensure an orbit around the black hole
        double vx = - (ry/rx); // 1.0;
		double vy = 1.0;
        double br = 1.0 - 2.0 * (rand() % 2);
		double rnv =  br * ((double)rand() / (double)RAND_MAX * 2 * radius_star) / (5 * sqrt(vx * vx + vy * vy)); // 1;
		
		vx = rnv * vx;
		vy = rnv * vy;
		
        // Create star particle
		particles[i] = particle_create(mass_star, rx, ry, vx, vy);
    }

    return nparticle;
}

void nparticle_simulate_bruteforce(nparticle* p, double dt)
{
    int n = p->n;

    // Update forces between particles
    for (int i = 0; i < n; i++)
    {
        particle_reset_forces(p->particles[i]);
        for (int j = 0; j < n; j++)
        {
            if(i != j)
            {
                particle_compute_forces(p->particles[i], p->particles[j]);
            }
        }

    }

    // Update particles
    for (int i = 0; i < n; i++)
    {
        particle_update_position(p->particles[i], dt);
    }
}

void nparticle_free(nparticle *np)
{
    for (int i = 0; i < np->n; i++)
    {
        free(np->particles[i]);
    }
    free(np);
}
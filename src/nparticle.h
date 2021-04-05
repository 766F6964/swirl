#ifndef NPARTICLE_H
#define NPARTICLE_H

#include "particle.h"

typedef struct
{
    particle **particles;
    int n; // Amount of particles
    double radius;

} nparticle;

nparticle *nparticle_generate_random(int n, int grid_width, int grid_height);
void nparticle_simulate_bruteforce(nparticle* p, double dt);


void nparticle_free(nparticle *np);

#endif
#ifndef NPARTICLE_H
#define NPARTICLE_H

#include "particle.h"

typedef struct
{
    particle **particles;
    int n; // Amount of particles

} n_particle;

n_particle *nparticle_generate_random(int n);
void nparticle_free(n_particle *np);

#endif
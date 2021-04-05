#ifndef NPARTICLE_H
#define NPARTICLE_H

#include "particle.h"

typedef struct
{
    particle **particles;
    int n; // Amount of particles
    double radius;

} nparticle;

nparticle *nparticle_generate_random(int n);
void nparticle_free(nparticle *np);

#endif
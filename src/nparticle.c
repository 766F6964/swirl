#include "nparticle.h"
#include "particle.h"
#include <stdlib.h>

n_particle *nparticle_generate_random(int n)
{
    n_particle *particles = malloc(sizeof(n_particle));
    particles **particles = malloc(sizeof(n_particle));
    return NULL;
}

void nparticle_free(n_particle *np)
{
    for (int i = 0; i < np->n; i++)
    {
        free(np->particles[i]);
    }
    free(np);
}
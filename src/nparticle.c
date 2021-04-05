#include "nparticle.h"
#include "particle.h"
#include <stdlib.h>

nparticle *nparticle_generate_random(int n)
{
    nparticle *nparticle = malloc(sizeof(nparticle));
    particle **particles = malloc(sizeof(nparticle) * n);

    nparticle->radius = 5e08;
    nparticle->n = n;
    nparticle->particles = particles;

    return nparticle;
}

void nparticle_free(nparticle *np)
{
    for (int i = 0; i < np->n; i++)
    {
        free(np->particles[i]);
    }
    free(np);
}
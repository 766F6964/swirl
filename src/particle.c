#include "particle.h"
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

particle *particle_create(double mass, double px, double py, double vx, double vy)
{
    particle *p = malloc(sizeof(particle));
    p->mass = mass;
    p->pos_x = px;
    p->pos_y = py;
    p->vel_x = vx;
    p->vel_x = vy;
    return p;
}

particle *particle_copy(particle *p)
{
    return particle_create(p->mass, p->pos_x, p->pos_y, p->vel_x, p->vel_y);
}

void particle_free(particle *p)
{
    free(p);
}

double particle_get_mass(particle *p)
{
    return p->mass;
}

double particle_get_pos_x(particle *p)
{
    return p->pos_x;
}

double particle_get_pos_y(particle *p)
{
    return p->pos_y;
}

double particle_get_vel_x(particle *p)
{
    return p->vel_x;
}

double particle_get_vel_y(particle *p)
{
    return p->vel_x;
}

double particle_get_distance(particle *p1, particle *p2)
{
    double dx = p1->pos_x - p2->pos_x;
    double dy = p1->pos_y - p2->pos_y;
    return sqrt(dx * dx + dy * dy);
}
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

void particle_compute_forces(particle *p1, particle *p2)
{
    double G = 6.67e-11;    // Gravational constant
    double EPS = 3E4;       // Softening parameter
    double dx = p2->pos_x - p1->pos_x;
    double dy = p2->pos_y - p1->pos_y;
    double dist = sqrt(dx * dx + dy * dy);
    double F = (G * p1->mass * p2->mass) / (dist * dist + EPS * EPS);
    p1->force_x += F * dx / dist;
    p1->force_y += F * dy / dist;
}

void particle_reset_forces(particle *p)
{  
    p->force_x = 0.0;
    p->force_y = 0.0;
}

void particle_update_position(particle *p, double time_delta)
{
    p->vel_x += time_delta * p->force_x / p->mass;
    p->vel_y += time_delta * p->force_y / p->mass;
    p->pos_x += time_delta * p->vel_x;
    p->pos_y += time_delta * p->vel_y;
}

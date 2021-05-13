#ifndef GALAXYGEN_H
#define GALAXYGEN_H

#include "nparticle.h"

double* get_particle_random_position(int radius, double center_x, double center_y);
double* get_particle_perpendicular_velocity(int radius, double rx, double ry);

void generate_galaxy(int n, int radius, double x_center, double y_center, double mass_star, double mass_bh);

double calculate_perpindicular_velocity();


#endif
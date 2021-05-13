#include "galaxygen.h"
#include "nparticle.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double* get_particle_random_position(int radius, double center_x, double center_y)
{
    double rx = 2.0, ry = 2.0;
    while (rx * rx + ry * ry > 1)
    {
        rx = 2 * (double)rand() / RAND_MAX - 1;
        ry = 2 * (double)rand() / RAND_MAX - 1;
    }
    double rand_x = center_x + radius * rx;
    double rand_y = center_y + radius * ry;

    double* coords = malloc(sizeof(double) * 2);
    coords[0] = rand_x;
    coords[1] = rand_y;
    
    return coords;
}

double* get_particle_perpendicular_velocity(int radius, double rx, double ry)
{
    double vx = -(ry/rx);
    double vy = 1.0;

    double br = 1.0 - 2.0 * (rand() % 2);
	double rnv =  br * ((double)rand() / (double)RAND_MAX * 2 * radius) / (5 * sqrt(vx * vx + vy * vy)); // is radius right here or should it be planet radius?
    
    double* vel = malloc(sizeof(double) * 2);
    vel[0] = (rnv * vx);
    vel[1] = (rnv * vy);

    return vel;
}


void generate_galaxy(int n, int radius, double x_center, double y_center, double mass_star, double mass_bh) 
{
    FILE *fhandle = fopen("galaxy_gen.txt", "w");
    //int radius_star = 10;
    fprintf(fhandle, "%d\n", n);
    fprintf(fhandle, "%d\n", radius);

    y_center = 0;
    y_center = 0;

    for (int x = 0; x < n; x++)
    {
        double* coords = get_particle_random_position(radius, x_center, y_center);
        double* vels = get_particle_perpendicular_velocity(radius, coords[0], coords[1]);

        if(x == 0)
            fprintf(fhandle, "%.5e %.5e %.5e %.5e %.5e\n", x_center, y_center, (double)0, (double)0, mass_bh);
        else{
            // The problem is the perpendicular motion ... They dont point to the orbit correctly
            fprintf(fhandle, "%.5e %.5e %.5e %.5e %.5e\n", coords[0], coords[1], vels[0], vels[1], mass_star); 
        }
        free(vels);
    }
    fclose(fhandle);
}



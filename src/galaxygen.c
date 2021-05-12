#include "galaxygen.h"
#include "nparticle.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void generate_galaxy(int n, int radius, double x_center, double y_center, double mass_star, double mass_bh) 
{
    FILE *fhandle = fopen("galaxy_gen.txt", "w");
    int radius_star = 10;
    fprintf(fhandle, "%d\n", n);
    fprintf(fhandle, "%d\n", radius);

    for (int x = 0; x < n; x++)
    {
        double rx = 2.0, ry = 2.0;
        while (rx * rx + ry * ry > 1)
        {
            rx = 2 * (double)rand() / RAND_MAX - 1;
            ry = 2 * (double)rand() / RAND_MAX - 1;
        }
        double rand_x = x_center + radius * rx;
        double rand_y = y_center + radius * ry;
        
        double vx = - (ry/rx);
        double vy = 1.0;
        double br = 1.0 - 2.0 * (rand() % 2);
		double rnv =  br * ((double)rand() / (double)RAND_MAX * 2 * radius_star) / (5 * sqrt(vx * vx + vy * vy)); // 1;
		
		vx = (rnv * vx) * 100000;
		vy = (rnv * vy) * 100000;

        if(x == 0)
            fprintf(fhandle, "%lf %lf %lf %lf %lf\n", x_center, y_center, 0, 0, mass_bh);
        else
            fprintf(fhandle, "%lf %lf %lf %lf %lf\n", rand_x, rand_y, vx, vy, mass_star);
    }
    fclose(fhandle);
}



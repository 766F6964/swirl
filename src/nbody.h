#ifndef NBODY_H
#define NBODY_H

typedef struct{
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double mass;
} particle;

void compute_particle_forces();
void compute_particle_acceleration();
void update_particles();

#endif
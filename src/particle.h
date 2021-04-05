#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct{
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double force_x;
    double force_y;
    double mass;
} particle;

particle *particle_create(double mass, double px, double py, double vx, double vy);
particle *particle_copy(particle *p);
void particle_free(particle *p);

double particle_get_mass(particle *p);
double particle_get_pos_x(particle *p);
double particle_get_pos_y(particle *p);
double particle_get_vel_x(particle *p);
double particle_get_vel_y(particle *p);
double particle_get_distance(particle *p1, particle *p2);

void particle_compute_forces(particle *p1, particle *p2);
void particle_reset_forces(particle *p);
void particle_update_position(particle *p, double time_delta);

//void init_bodies(int n);
//void compute_particle_forces();
//void compute_particle_acceleration();
//void update_particles();

#endif
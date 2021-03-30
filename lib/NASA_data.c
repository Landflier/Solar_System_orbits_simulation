//
// Created by vasil on 2/15/21.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Stellar_body_struct.h"
#include "Hamiltonian.h"
#include "Vector_operations.h"

void Read_Nasa_txt_file(int N, Stellar_body* Solar_System){
    FILE* nasa_data_compiled;
    nasa_data_compiled = fopen("../data/Planets_NASA/Solar_system_bodies.txt", "r"); // progam is run from /bin
    long double p[3];
    long double q[3];
    long double mass;
    int i=0;

    if(nasa_data_compiled == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while( fscanf(nasa_data_compiled, "%Le, %Le, %Le, %Le, %Le, %Le, %Le "
            , &q[0], &q[1], &q[2], &p[0], &p[1], &p[2], &mass) != EOF )
    {
        memcpy(&p , Vector_Scalar(mass, p), sizeof(p));
        memcpy(&Solar_System[i].p, &p, sizeof(Solar_System[i].p));
        memcpy(&Solar_System[i].q, &q, sizeof(Solar_System[i].q));
        Solar_System[i].mass = mass;
        i++;
        //printf("%Le\t\t%Le\t\t%Le\t\t%Le\t\t%Le\t\t%Le\t\t%Le\n", q[0], q[1] ,q[2], p[0] , p[1] , p[2], mass );
    }

    fclose(nasa_data_compiled);
}

void Write_Solar_System_iteration(int N, Stellar_body* Solar_System, FILE *simulation_file) {

    if (simulation_file == NULL) {
        printf("Error opening simulation file\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        fprintf(simulation_file, "%Le, %Le, %Le, %Le, %Le, %Le\n",
                Solar_System[i].q[0], Solar_System[i].q[1],Solar_System[i].q[2],
                Solar_System[i].p[0]/Solar_System[i].mass, Solar_System[i].p[1]/Solar_System[i].mass, Solar_System[i].p[2]/Solar_System[i].mass);
    }

}

void Write_System_Variables(int N, Stellar_body* Solar_System, FILE *simulation_file) {

    if (simulation_file == NULL) {
        printf("Error opening system variables file\n");
        exit(1);
    }
    static long double center_of_m[3], angular_mom[3];
    long double ham_of_system;
    memcpy(&center_of_m, center_of_mass(N,Solar_System), sizeof(center_of_m));
    memcpy(&angular_mom, angular_momentum(N,Solar_System), sizeof(angular_mom));
    ham_of_system = Hamiltonian(N, Solar_System);

    for (int i = 0; i < N; i++) {
        fprintf(simulation_file, "%Le, %Le, %Le, %Le, %Le, %Le, %Le\n",
                center_of_m[0], center_of_m[1], center_of_m[2],
                angular_mom[0], angular_mom[1], angular_mom[2],
                ham_of_system);
    }

}

void reset_simulation_file(char *filepath){

    FILE* simulation_file;
    simulation_file = fopen(filepath, "w"); // progam is run from /bin
    fclose(simulation_file);

}
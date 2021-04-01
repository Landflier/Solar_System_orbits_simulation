#include "lib/Stellar_body_struct.h"
#include "lib/Vector_operations.h"
#include "lib/Hamiltonian.h"
#include "lib/Runge_Kutta_second_order.h"
#include "lib/NASA_data.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void print_current_system(int N, Stellar_body System[N]){
    printf("Current Solar System data: \n");
    for (int i=0; i<N; i++){
        printf ("%Le %Le %Le %Le %Le %Le \n",
                System[i].q[0], System[i].q[1], System[i].q[2],
                System[i].p[0], System[i].p[1], System[i].p[2]);

    }
}

int main() {
    int N=10; // number of objects
    Stellar_body Objects[N];

    Read_Nasa_txt_file(N,Objects);


    long double k= 3; // k is in units of days
    int years= 5000;
    int Total_Number_of_steps = years * 365 / k;
    //int Total_Number_of_steps = 5000;




    char *human_readable_results = "../data/Simulation_Results/planets_p_q_human_readable.txt";
    char *python_results = "../data/Simulation_Results/planets_p_q_python.txt";
    char *system_variables = "../data/Simulation_Results/system_variables_python.txt";

    reset_simulation_file(human_readable_results);
    reset_simulation_file(python_results);
    reset_simulation_file(system_variables);

    FILE *simulation_file, *simulation_file_python, *system_variables_python;
    //simulation_file = fopen(human_readable_results, "a"); // progam is run from /bin
    simulation_file_python = fopen(python_results, "a");
    system_variables_python = fopen(system_variables, "a");

    Stellar_body  New_Object[N]; // updating solar system
    for (int i=0; i<N; i++){
        New_Object[i].mass = Objects[i].mass;
    }
    printf("Starting system data: \n");
    print_current_system(N,Objects);

    //Write the value of k at the start of system_variables
    fprintf(system_variables_python, " %Le \n ", k);

    for (int iteration_number = 0 ; iteration_number < Total_Number_of_steps ; iteration_number++ ){

        for (int i=0; i<N; i++){
            memcpy(&New_Object[i].q, update_q_i(k,i,N,Objects), sizeof (New_Object[i].q));
            memcpy(&New_Object[i].p, update_p_i(k,i,N,Objects), sizeof (New_Object[i].p));
            //printf ("New p_i is : [%Le %Le %Le] \n", New_Object[i].p[0], New_Object[i].p[1], New_Object[i].p[2]);

        }
            memcpy(&Objects, &New_Object, sizeof (Objects)); //update system

        Write_System_Variables(N,Objects, system_variables_python, total_mass);

        //Write_Solar_System_iteration(N,Objects, simulation_file);
        //fprintf(simulation_file, "\n"); // delimeter charecter between simulations for human readable

        Write_Solar_System_iteration(N,Objects, simulation_file_python);

    }

    fclose(simulation_file_python);
    //fclose(simulation_file);
    fclose(system_variables_python);

return 0;
}

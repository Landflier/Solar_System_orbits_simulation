//
// Created by vasil on 2/15/21.
//
#include "Stellar_body_struct.h"
#include "Vector_operations.h"
#include<math.h>
#include<stdio.h>

#include<string.h>

long double Converted_G (){
    long double  G = 6.67408 * pow (10, -11); // m3 kg-1 s-2
    double au = 149597870700; // m
    double day = 86400; // s
    return  G / pow(au,3) * pow(day,2); // 1 au= 149597870.700 km, 1 day= 86400.0 s
    // convert grav constant to au,day unit system

}

// Kin and Pot energy are long double if they become too large
long double Kinetic_Energy (int N, Stellar_body Solar_system_object[N]){
    long double Kin_En=0;
    for(int n=0 ; n<N ; n++){
            /* test print for kinetic energy of object
                   printf("Kinetic energy of object %i is %Le \n", n, pow (Vector_Length(Solar_system_object[n].p),2) / Solar_system_object[n].mass))));
            */
            Kin_En +=  pow (Vector_Length(Solar_system_object[n].p),2) / Solar_system_object[n].mass;
    }
return Kin_En / 2;
}

long double Potential_Energy (int N, Stellar_body Solar_system_object[N]) {
    long double Pot_En = 0;
    for (int i = 0; i < N; i++) { // loop through all pairs of objects to compute pot energy
                                  // note V(i,j) = V(j,i)
                                  // therefore looping though ordered (i,j) tuples only
        for (int j = i + 1; j < N; j++) {
            /* test print for potential between pairs
            printf("Potential energy between %i and %i is %f \n", i, j, Solar_system_object[i].mass * Solar_system_object[j].mass /
                                                                      (Vector_Length(Vector_Subtract(Solar_system_object[i].q, Solar_system_object[j].q))));
            */
             Pot_En += Solar_system_object[i].mass * Solar_system_object[j].mass /
                      (Vector_Length(Vector_Subtract(Solar_system_object[i].q, Solar_system_object[j].q)));
        }
    }
    return  -Converted_G() * Pot_En;
}
long double Hamiltonian (int N, Stellar_body Solar_System_object[N]){
    return Potential_Energy(N, Solar_System_object) + Kinetic_Energy(N, Solar_System_object);
}


// -dH/dq_i , which requires the whole system to calculate
long double* f_i(int N, Stellar_body Object[N] /* notation difference because long equations */ , int i /* index for which object */, Stellar_body Ref_point){
    static long double p_i_derivative[3];
    static long double distance_vector[3];
    p_i_derivative[0] = 0; p_i_derivative[1] = 0; p_i_derivative[2] = 0; // needed explicit intialization, because of static type
    distance_vector[0] = 0; distance_vector[1] = 0; distance_vector[2] = 0; // needed explicit intialization, because of static type
    for (int j=0; j < i; j++){
        memcpy( &distance_vector, Vector_Subtract(Object[j].q, Ref_point.q), sizeof(distance_vector));
        memcpy( &p_i_derivative,
                           Vector_Add(p_i_derivative,
                                      Vector_Scalar( Ref_point.mass * Object[j].mass / pow(Vector_Length(distance_vector),3), distance_vector)),
                                      sizeof(p_i_derivative));
    }
    for (int j=i+1; j < N; j++){
        memcpy( &distance_vector, Vector_Subtract(Object[j].q, Ref_point.q), sizeof(distance_vector));
        memcpy( &p_i_derivative,
                           Vector_Add(p_i_derivative,
                                      Vector_Scalar( Ref_point.mass * Object[j].mass / pow(Vector_Length(distance_vector),3), distance_vector)),
                sizeof (p_i_derivative));
    }
    return Vector_Scalar(Converted_G(), p_i_derivative );
}

// dH/dp_i , which requires the whole system to calculate
long double* g_i( Stellar_body Solar_System_object){
    return Vector_Scalar(1/Solar_System_object.mass, Solar_System_object.p);
}

long double* center_of_mass (int N, Stellar_body Solar_System[N]){
    static long double c_of_mass[3];
    c_of_mass[0] = 0 ; c_of_mass[1] = 0 ; c_of_mass[2] = 0 ;
    for (int j = 0; j < N ; j++){
        memcpy (&c_of_mass,
                Vector_Add(c_of_mass, Vector_Scalar(Solar_System[j].mass, Solar_System[j].q)),
                sizeof(c_of_mass));
    }
    return c_of_mass;
}

long double* angular_momentum (int N, Stellar_body Solar_System[N]){
    static long double L_of_system[3];
    L_of_system[0] = 0; L_of_system[1] = 0; L_of_system[2] = 0;
    for (int j = 0; j < N ; j++){
        memcpy (&L_of_system,
                Vector_Add(L_of_system, Vector_Cross(Solar_System[j].q ,Solar_System[j].p)),
                sizeof(L_of_system));
    }
    return L_of_system;
}



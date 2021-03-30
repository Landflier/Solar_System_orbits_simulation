//
// Created by vasil on 2/15/21.
//

#ifndef SYSTEME_SOLAIRE_HAMILTONIAN_H
#define SYSTEME_SOLAIRE_HAMILTONIAN_H

long double Converted_G ();
long double Kinetic_Energy (int N, Stellar_body Solar_system_object[N]);
long double Potential_Energy (int N, Stellar_body Solar_system_object[N]);
long double Hamiltonian (int N, Stellar_body Solar_System_object[N]);

// Partial derivatives of Hamiltonian
long double* f_i(int N, Stellar_body Solar_System_object[N], int i, Stellar_body Ref_point);
long double* g_i( Stellar_body Solar_System_object);

// System angular momentum and center of mass
long double* center_of_mass (int N, Stellar_body Solar_System[N]);
long double* angular_momentum (int N, Stellar_body Solar_System[N]);

#endif //SYSTEME_SOLAIRE_HAMILTONIAN_H

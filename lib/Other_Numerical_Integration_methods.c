//
// Created by vasil on 4/1/21.
//
//
// Created by vasil on 2/15/21.
//

#include "Stellar_body_struct.h"
#include "Hamiltonian.h"
#include "Vector_operations.h"

#include<stdio.h>
#include<string.h>

long double* Euler_symplectic_update_p_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N]){
    static long double new_p_i[3];
    new_p_i[0] = 0; new_p_i[1] = 0; new_p_i[2] = 0; //reset new_p_i everytime the function is called


    Stellar_body Ref_point;

    memcpy(&Ref_point, &Object[i], sizeof (Ref_point));

    memcpy(&new_p_i,
           Vector_Add(Object[i].p,
                      Vector_Scalar(k, f_i(N, Object, i, Ref_point)))
                      ,sizeof(new_p_i));
    return new_p_i;

}

long double* Euler_symplectic_update_q_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N], long double p_i_plus_one[3]){
    static long double new_q_i[3];
    new_q_i[0] = 0; new_q_i[1] = 0; new_q_i[2] = 0; //reset new_p_i everytime the function is called

    Stellar_body Ref_point;

    memcpy(&Ref_point, &Object[i], sizeof (Ref_point));
    memcpy(&Ref_point.p, p_i_plus_one, sizeof (Ref_point.p)); // pass p_i_plus_one as argument, so as not to comupte two times

    memcpy(&new_q_i,
           Vector_Add(Object[i].q,
                      Vector_Scalar(k,g_i(Ref_point))),
           sizeof(new_q_i) );

    return new_q_i;
}







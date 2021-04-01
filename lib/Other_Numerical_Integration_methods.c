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

long double* Euler_update_p_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N]){
    static long double new_p_i[3];
    new_p_i[0] = 0; new_p_i[1] = 0; new_p_i[2] = 0; //reset new_p_i everytime the function is called
    long double f_i_old[3] = {0,0,0};
    long double first_f_i_input[3] = {0,0,0};
    long double second_f_i_input[3] = {0,0,0};

    Stellar_body Ref_point;

    memcpy(&Ref_point, &Object[i], sizeof (Ref_point));

    memcpy(&f_i_old, f_i(N,Object,i, Ref_point), sizeof (f_i_old));
    memcpy(&first_f_i_input, Vector_Add(Object[i].q, Vector_Scalar(k, g_i(Object[i]))), sizeof (first_f_i_input));
    memcpy(&second_f_i_input, Vector_Add(Object[i].p, Vector_Scalar(k, f_i(N,Object,i, Object[i]))), sizeof (second_f_i_input));

    memcpy(&Ref_point.q, first_f_i_input, sizeof (Ref_point.q)); //update position to compute derivative at
    memcpy(&Ref_point.p, second_f_i_input, sizeof (Ref_point.p)); //update momentum to compute derivative at
/*    printf("System for which new momentum is calculated:\n ");
    for(int i = 0; i < N; i++) {
        printf("%i: %Le %Le %Le %Le %Le %Le \n", i, Object[i].q[0], Object[i].q[1], Object[i].q[2],
                                          Object[i].p[0], Object[i].p[1], Object[i].p[2]);
    }
    printf ("\n");*/
    memcpy(&new_p_i,
           Vector_Add(Object[i].p, Vector_Scalar(k/2,
                                                 Vector_Add(f_i_old, f_i(N,Object,i, Ref_point)))),
           sizeof(new_p_i));
    return new_p_i;

}

long double* Euler_update_q_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N]){
    static long double new_q_i[3];
    new_q_i[0] = 0; new_q_i[1] = 0; new_q_i[2] = 0; //reset new_p_i everytime the function is called
    long double g_i_old[3] = {0,0,0};
    long double first_g_i_input[3] = {0,0,0};
    long double second_g_i_input[3] = {0,0,0};

    Stellar_body Ref_point;

    memcpy(&Ref_point, &Object[i], sizeof (Ref_point));


    memcpy(&g_i_old, g_i(Object[i]), sizeof (g_i_old));
    memcpy(&first_g_i_input, Vector_Add(Object[i].q, Vector_Scalar(k, g_i(Object[i]))), sizeof (first_g_i_input));
    memcpy(&second_g_i_input, Vector_Add(Object[i].p, Vector_Scalar(k, f_i(N,Object,i,Ref_point))), sizeof (second_g_i_input));

    memcpy(&Ref_point.q, first_g_i_input, sizeof (Ref_point.q)); //update position to compute derivative at
    memcpy(&Ref_point.p, second_g_i_input, sizeof (Ref_point.p)); //update momentum to compute derivative at

    memcpy(&new_q_i,
           Vector_Add(Object[i].q, Vector_Scalar(k/2,
                                                 Vector_Add(g_i_old, g_i(Ref_point)))),
           sizeof(new_q_i) );

    return new_q_i;
}



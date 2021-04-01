//
// Created by vasil on 4/1/21.
//

#ifndef SOLAR_SYSTEM_REBASED_OTHER_NUMERICAL_INTEGRATION_METHODS_H
#define SOLAR_SYSTEM_REBASED_OTHER_NUMERICAL_INTEGRATION_METHODS_H
long double* Euler_symplectic_update_p_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N]);
long double* Euler_symplectic_update_q_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N], long double p_i_plus_one[3]);
#endif //SOLAR_SYSTEM_REBASED_OTHER_NUMERICAL_INTEGRATION_METHODS_H

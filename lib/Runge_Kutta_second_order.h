//
// Created by vasil on 2/15/21.
//

#ifndef SYSTEME_SOLAIRE_RUNGE_KUTTA_SECOND_ORDER_H
#define SYSTEME_SOLAIRE_RUNGE_KUTTA_SECOND_ORDER_H
long double* update_p_i(long double k, int i, int N, Stellar_body Solar_system_object[N]);
long double* update_q_i(long double k /*R-K step*/ , int i, int N, Stellar_body Object[N]);


#endif //SYSTEME_SOLAIRE_RUNGE_KUTTA_SECOND_ORDER_H

//
// Created by vasil on 2/15/21.
//

#ifndef SYSTEME_SOLAIRE_VECTOR_OPERATIONS_H
#define SYSTEME_SOLAIRE_VECTOR_OPERATIONS_H

long double* Vector_Add (long double *vector_one, long double *vector_two);
long double* Vector_Subtract (long double *vector_one, long double *vector_two);
long double* Vector_Scalar (long double A, long double *vector);
long double Vector_Dot (long double *vector_one, long double *vector_two);
long double* Vector_Cross (long double *vector_one, long double *vector_two);
long double Vector_Length (long double *vector);

#endif //SYSTEME_SOLAIRE_VECTOR_OPERATIONS_H

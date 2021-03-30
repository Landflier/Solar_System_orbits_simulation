//
// Created by vasil on 2/15/21.
//
#include <stdio.h>
#include <math.h>

long double Vector_Dot (long double *vector_one, long double *vector_two){
   return (vector_one[0]*vector_two[0] + vector_one[1]*vector_two[1] + vector_one[2]*vector_two[2]);
}


long double* Vector_Cross (long double *vector_one, long double *vector_two){
    static long double cross_vector[3];
    cross_vector[0] = vector_one[1]*vector_two[2] - vector_one[2]*vector_two[1];
    cross_vector[1] = vector_one[2]*vector_two[0] - vector_one[0]*vector_two[2];
    cross_vector[2] = vector_one[0]*vector_two[1] - vector_one[1]*vector_two[0];
    return cross_vector;
}

long double* Vector_Subtract (long double *vector_one, long double *vector_two){
    static long double difference_vector[3];
    difference_vector[0] = vector_one[0] - vector_two[0];
    difference_vector[1] = vector_one[1] - vector_two[1];
    difference_vector[2] = vector_one[2] - vector_two[2];
    return difference_vector;
}

long double* Vector_Scalar ( long double A, long double *vector){
    static long double scaled_vector[3];
    scaled_vector[0] = A * vector[0];
    scaled_vector[1] = A * vector[1];
    scaled_vector[2] = A * vector[2];
    return scaled_vector;
}

long double* Vector_Add (long double *vector_one, long double *vector_two){
    static long double sum_vector[3];
    sum_vector[0] = vector_one[0] +vector_two[0];
    sum_vector[1] = vector_one[1] +vector_two[1];
    sum_vector[2] = vector_one[2] +vector_two[2];
    return sum_vector;
}


long double Vector_Length (long double *vector){
    return sqrt(pow(vector[0],2)+ pow(vector[1],2)+pow(vector[2],2) );
}

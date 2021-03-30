//
// Created by vasil on 2/15/21.
//

#ifndef SYSTEME_SOLAIRE_NASA_DATA_H
#define SYSTEME_SOLAIRE_NASA_DATA_H

typedef struct Stellar_body{
    long double q[3]; // position vector
    long double p[3]; // momentum vector
    long double mass;
}Stellar_body;

#endif //SYSTEME_SOLAIRE_NASA_DATA_H

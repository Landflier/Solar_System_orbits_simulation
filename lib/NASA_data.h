//
// Created by vasil on 2/15/21.
//

#ifndef SYSTEME_SOLAIRE_NASA_DATA_H
#define SYSTEME_SOLAIRE_NASA_DATA_H
void reset_simulation_file(char *filepath);
void Read_Nasa_txt_file(int N, Stellar_body* Solar_System);
void Write_Solar_System_iteration(int N, Stellar_body* Solar_System);
void Write_System_Variables(int N, Stellar_body* Solar_System, FILE *simulation_file);

#endif //SYSTEME_SOLAIRE_NASA_DATA_H

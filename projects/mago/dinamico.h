#ifndef DINAMICO_H
#define DINAMICO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>


int **alocaMatriz(int, int);
void inicializaMatriz(int **, int, int, FILE *);
void desalocarMatriz(int **, int);
void visualizarMatriz(int **, int, int);


#endif
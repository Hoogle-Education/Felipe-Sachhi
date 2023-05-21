#ifndef TABULEIRO_H
#define TABULEIRO_H
#define MAX_N 10010

#include "dinamico.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct pos
{
  int i;
  int j;
} Pos;

int min(int a, int b);
int max(int a, int b);
void feedback(Pos *atual, Pos *destino);
int vida_minima(int **matriz, int **dp, Pos *atual, Pos *destino, int R, int C);
int agrupar_caminho(int valor_atual, int casoVertical, int casoHorizontal);

#endif
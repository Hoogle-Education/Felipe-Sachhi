#ifndef TABULEIRO_H
#define TABULEIRO_H

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
int vida_minima(int **matriz, Pos *atual, Pos *destino);

#endif
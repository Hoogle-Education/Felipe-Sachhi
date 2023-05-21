#include <stdio.h>
#include <stdbool.h>
#include "dinamico.h"
#include "tabuleiro.h"

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

void feedback(Pos *atual, Pos *destino)
{
  printf("Atual: (%d, %d)\n", atual->i, atual->j);
  printf("Destino: (%d, %d)\n", destino->i, destino->j);
}

int agrupar_caminho(int valor_atual, int casoVertical, int casoHorizontal)
{
  int menorCaso = min(casoHorizontal, casoVertical);
  // printf("hort: %d | vert: %d | menor: %d | ", casoHorizontal, casoVertical, menorCaso);
  int result;

  if (valor_atual >= 0) // * OK
  {
    int best = menorCaso - valor_atual;
    result = max(best, 1);
  }
  else // * testar
  {
    result = abs(valor_atual) + menorCaso;
  }

  // printf("result = %d\n", result);
  return result;
}

int vida_minima(int **matriz, int **dp, Pos *atual, Pos *destino, int R, int C)
{
  // printf("Pos [%d, %d] - ", atual->i, atual->j);
  int valor_atual = matriz[atual->i][atual->j];
  Pos *proximo = (Pos *)malloc(sizeof(Pos));
  int casoVertical = INT_MAX, casoHorizontal = INT_MAX;

  // * caso nao dinamico
  if (dp[atual->i][atual->j] != INT_MAX)
  {
    // printf("Caso ja calculado\n");
    return dp[atual->i][atual->j];
  }

  // printf("Calculando...\n");

  // * caso base: valor_atual individual * OK
  if (atual->i == destino->i && atual->j == destino->j) // true and true
  {
    int minimo = min(valor_atual, 0);
    return dp[atual->i][atual->j] = abs(minimo) + 1;
  }

  // * caso recursivo 1: caso linha
  if (atual->j < destino->j) // se nao for o fim horizontal
  {                          // anda horizontalmente para direita
    proximo->i = atual->i;
    proximo->j = atual->j + 1;

    casoHorizontal = vida_minima(matriz, dp, proximo, destino, R, C);
  }

  // * caso recursivo 2: caso coluna
  if (atual->i < destino->i) //  se nao for o fim vertical
  {                          // anda verticalmente para baixo
    proximo->i = atual->i + 1;
    proximo->j = atual->j;

    casoVertical = vida_minima(matriz, dp, proximo, destino, R, C);
  }

  free(proximo);

  // * operacao recursiva
  int result = agrupar_caminho(valor_atual, casoVertical, casoHorizontal);
  dp[atual->i][atual->j] = result;
  return result;
}
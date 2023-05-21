#include "dinamico.h"

// Funcao que aloca a matriz
int **alocaMatriz(int R, int C)
{
    int **matriz;
    matriz = (int **)malloc((R) * sizeof(int *));
    for (int i = 0; i < R; i++)
    {
        matriz[i] = (int *)malloc((C) * sizeof(int));
    }
    return matriz;
}

// aloca matriz com valor nas celulas
int **alocaMatrizComValor(int R, int C, int V)
{
    int **matriz = alocaMatriz(R, C);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz[i][j] = V;
        }
    }

    return matriz;
}

// Visualizar matriz
void visualizarMatriz(int **matriz, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Funcao que inicializa a matriz
void inicializaMatriz(int **matriz, int R, int C, FILE *arquivo)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }
}

// Desaloca
void desalocarMatriz(int **matriz, int R)
{
    for (int i = 0; i < R; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

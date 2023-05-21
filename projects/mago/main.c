#include "dinamico.h"
#include "tabuleiro.h"

int main()
{
    int R, C, result;
    FILE *arquivo = NULL;
    arquivo = fopen("input.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de texto\n");
        return -1;
    }

    fscanf(arquivo, "%d %d", &R, &C);

    int **matriz = alocaMatriz(R, C);
    int **dp = alocaMatrizComValor(MAX_N, MAX_N, INT_MAX);
    inicializaMatriz(matriz, R, C, arquivo);

    // visualizarMatriz(matriz, R, C);

    Pos *origem = (Pos *)malloc(sizeof(Pos));
    Pos *destino = (Pos *)malloc(sizeof(Pos));

    origem->i = 0;
    origem->j = 0;
    destino->i = R - 1;
    destino->j = C - 1;

    result = vida_minima(matriz, dp, origem, destino, R, C);

    printf("RESULTADO = %d\n", result);

    // desalocarMatriz(auxiliar, R);
    desalocarMatriz(matriz, R);
    free(origem);
    free(destino);
    return 0;
}

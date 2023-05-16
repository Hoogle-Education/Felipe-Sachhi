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
    inicializaMatriz(matriz, R, C, arquivo);

    visualizarMatriz(matriz, R, C);

    Pos *origem, *destino;
    origem->i = 0;
    origem->j = 0;
    destino->i = R - 1;
    destino->j = C - 1;

    int resultado = vida_minima(matriz, origem, destino);
    puts("**********");
    puts("**********");
    printf("RESULTADO = %d", resultado);
    puts("**********");
    puts("**********");

    desalocarMatriz(matriz, R);
    // desalocarMatriz(auxiliar, R);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include "dinamico.h"
#include "tabuleiro.h"

int min(int a, int b)
{
  if (a == NULL && b == NULL)
    return NULL;
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  return a < b ? a : b;
}

int max(int a, int b)
{
  if (a == NULL && b == NULL)
    return NULL;
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  return a > b ? a : b;
}

int vida_minima(int **matriz, Pos *atual, Pos *destino)
{
  puts("****");

  bool fimHorizontal = atual->i == destino->i;
  bool fimVertical = atual->j == destino->j;
  int celula = matriz[atual->i][atual->j];
  int casoVertical = NULL, casoHorizontal = NULL;
  Pos *proximo;

  puts("-------------------------");
  printf("ATUAL (i = %d, j = %d)\n", atual->i, atual->j);
  visualizarMatriz(matriz, atual->i, atual->j);
  puts("-------------------------");

  // * caso base: celula individual
  if (fimHorizontal && fimVertical) // true and true
  {
    return abs(min(celula, 0)) + 1;
  }

  // * caso base: caso linha
  if (!fimHorizontal) // true and false
  {                   // anda horizontalmente para direita
    proximo->i = atual->i;
    proximo->j = atual->j + 1;

    casoHorizontal = vida_minima(matriz, proximo, destino);
  }

  // * caso base: caso coluna
  if (!fimVertical) //  false and true
  {                 // anda verticalmente para baixo
    proximo->i = atual->i + 1;
    proximo->j = atual->j;

    casoVertical = vida_minima(matriz, proximo, destino);
  }

  int melhorCaso = min(casoHorizontal, casoVertical);

  if (celula >= 0)
  {
    return max(melhorCaso - celula, 1);
  }
  else
  {
    return max(abs(celula), melhorCaso) + 1;
  }
}

// int guloso(int **matriz, int R, int C)
// {
//   int i = 0, j = 0;
//   int caminho = matriz[i][j];
//   // no melhor caso, ou seja, pegando caminhos que apenas tenham poções de energia, a vida mínima necessária é 1
//   int initial_life = 1;

//   // Verifica se i ou j chegaram aos extremos da funcao
//   for (; j != C - 1 || i != R - 1;)
//   {
//     if (j == C - 1)
//     {
//       // Caso em que j chegou em seu limite das dimensões da matriz, e a partir de agora os movimentos possíveis são somente para baixo
//       i++;
//     }
//     else if (i == R - 1)
//     {
//       // Caso em que i chegou em seu limite das dimensões da matriz, e a partir de agora os movimentos possíveis são somente para a direita
//       j++;
//     }
//     else if (matriz[i + 1][j] > matriz[i][j + 1])
//     {
//       // Verificação se o elemento a direita da posição atual é maior do que o elemento abaixo
//       i++;
//     }
//     else
//     {
//       // Caso a condição anterior tenha falhado, então o elemento abaixo da posição atual é maior do que o elemento à direita
//       j++;
//     }
//     // O maior valor escolhido anteriormente será somado à variável caminho
//     caminho += matriz[i][j];
//     // Caso o valor do caminho percorrido chegue a 0 ou menor, então tirando a diferença entre a vida inicial e o caminho percorrido, terá a vida inicial
//     // necessária para se chegar à posição atual.
//     // A variável caminho é zerada, pois neste momento já se sabe a vida inicial necessária para chegar nessa posição, e este raciocínio será realizada
//     // até que chegue no artefado desejado
//     if (caminho <= 0)
//     {
//       initial_life = initial_life - caminho;
//       caminho = 0;
//     }
//     matriz[i][j] = -1;
//   }
//   return initial_life;
// }
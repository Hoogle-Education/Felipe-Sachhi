#include <stdio.h>
#include <stdbool.h>
#define MAXN 10010

// TODO: buscar um alvo no vetor
// 1. se houver retorna posição
// 2 senão retorna -1

void main()
{
  int num, values[MAXN];

  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &values);
    printf("%d\n", values);
  }
}

int sequencial_search(int alvo, int values[])
{
  for (int i = 0; i < MAXN; i++)
  {
    if (values[i] == alvo)
    {
      return i;
    }
  }

  return -1;
}

// f(n) = n + 1 O(n)

// n + log n
// f(n) = n ^ 2 + 3n + 5 O(n ^ 2)

// 5
// 1 3 4 5 8

// binary search
// meio = (0 + 4)/2 = 2
// elemento_meio = 4
// elemento_meio < alvo
// inicio = meio + 1

// meio = (3 + 4)/2 = 3
// elemento_meio = 5
// elemento_meio < alvo
// inicio = meio + 1

// meio (4 + 4) / 2 = 4
// elemento_meio = 7
// elemento_meio == alvo
// retorno meio

// tam = 6, alvo = 5
// 2 5 1 3 7 6
// 2 1 3 5 6 7

// segmentation fault
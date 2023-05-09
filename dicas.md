# Dicas e Problemas recorrentes

## Vetores, Matrizes e problemas de borda

Problemas de borda acontecem quando em um vetor acessamos a posição `n+1` ou `n-1`, ou até alguma quantidade maior em relação a posição atual, pois não sabemos se ela excede o vetor.

### Estratégias

1. Tomar cuidado e validar
2. Borda falsa com valor absurdo

Ao invés de fazer um xadrez 8x8, vai um 10x10 com bordas ao redor.

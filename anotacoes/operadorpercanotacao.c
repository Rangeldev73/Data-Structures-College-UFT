/*
=============================================================================
                     ANOTAÇÃO: OPERADOR DE MÓDULO (%)
=============================================================================
Regra de Ouro: Sempre que o número da esquerda for menor que o da direita,
               o resto da divisão será o próprio número da esquerda.
-----------------------------------------------------------------------------

Exemplo prático: 1 % 4 = 1
--------------------------
Na divisão de números inteiros, quando você divide um número menor por um 
número maior, o resultado (quociente) é 0 e o resto é o próprio número menor.

Passo a passo da conta:
  1. Quantas vezes o 4 cabe dentro do 1? Nenhuma vez (0 vezes).
  2. Quanto sobra? Sobra o próprio 1 inteiro que não pôde ser dividido.

Matematicamente:
  1 = (4 * 0) + 1

Outros exemplos para fixar:
  - 8  % 40  = 8
  - 2  % 10  = 2
  - 39 % 40  = 39
=============================================================================
*/

#include <stdio.h>

int main() {
    // Exemplo 1: O caso da fila circular que você estava calculando
    int head = 0;
    int max_elementos = 4;
    
    // Simulando o avanço do ponteiro tail (0 + 1) % 4
    int tail_atual = 0;
    int proximo_tail = (tail_atual + 1) % max_elementos;
    
    printf("--- SIMULACAO FILA CIRCULAR ---\n");
    printf("Posicao atual do tail: %d\n", tail_atual);
    printf("Proxima posicao calculada ((0 + 1) %% 4): %d\n\n", proximo_tail);

    // Exemplo 2: O teste do 8 % 40
    int a = 8;
    int b = 40;
    int resto = a % b;

    printf("--- OUTROS TESTES COM NUMERO MENOR %% NUMERO MAIOR ---\n");
    printf("Resultado de %d %% %d = %d\n", a, b, resto);
    printf("Resultado de 2 %% 10  = %d\n", 2 % 10);
    printf("Resultado de 39 %% 40 = %d\n", 39 % 40);

    return 0;
}

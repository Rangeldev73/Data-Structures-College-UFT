#include <stdio.h>

/*
===============================================================================
                       GUIA PRÁTICO DA NOTAÇÃO BIG O
===============================================================================
Para descobrir a complexidade, conte quantas vezes o computador trabalha 
conforme o volume de dados (n) aumenta. Foque sempre no PIOR CENÁRIO.
-------------------------------------------------------------------------------
*/

// 1. O(1) – COMPLEXIDADE CONSTANTE
// O tempo é SEMPRE o mesmo. Não importa se a array tem 1 item ou 1 milhão.
int exemplo_o1(int arr[], int tamanho) {
    if (tamanho > 0) {
        return arr[0]; // O(1) - Vai direto na memória e pega o primeiro item
    }
    return -1;
}

// 2. O(n) – COMPLEXIDADE LINEAR
// O trabalho cresce proporcionalmente ao número de itens (n).
// Se os dados dobram, o tempo de execução dobra.
int exemplo_on(int arr[], int n, int alvo) {
    // Um único laço (for) que percorre a array do início ao fim
    for (int i = 0; i < n; i++) { // Roda 'n' vezes
        if (arr[i] == alvo) {
            return 1; // Encontrou
        }
    }
    return 0; // No pior caso, olhou a array toda: O(n)
}

// 3. O(n²) – COMPLEXIDADE QUADRÁTICA
// O trabalho cresce de forma explosiva. Loops aninhados (um dentro do outro).
void exemplo_on2(int arr[], int n) {
    // Para cada elemento, visitamos todos os outros elementos de novo
    for (int i = 0; i < n; i++) {       // Roda n vezes
        for (int j = 0; j < n; j++) {   // Roda n vezes para CADA 'i'
            printf("Comparando %d com %d\n", arr[i], arr[j]); // Total: n * n = O(n²)
        }
    }
}

// 4. O(log n) – COMPLEXIDADE LOGARÍTMICA
// O mais eficiente para grandes volumes. A cada passo, o problema é 
// dividido pela metade (ex: busca binária ou divisões sucessivas).
int exemplo_ologn(int n) {
    int passos = 0;
    while (n > 1) {
        n = n / 2; // Divide o problema por 2 a cada rodada
        passos++;
    }
    return passos; // O número de passos cresce muito devagar: O(log n)
}

/*
===============================================================================
                    REGRAS DE OURO PARA O "OLHÔMETRO"
===============================================================================
1. Linhas simples (somas, prints, atribuições): Vale O(1).
2. Um loop simples de 0 até n: Vale O(n).
3. Loops aninhados: Multiplique-os (n * n = O(n²)).
4. Loops que dividem/multiplicam o índice por 2: Vale O(log n).
5. Ignore as constantes: O(2n + 5) vira apenas O(n). Só o termo maior importa!
===============================================================================
*/

int main() {
    int meus_dados[] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("--- Testando O(1) ---\n");
    printf("Primeiro item: %d\n", exemplo_o1(meus_dados, n));

    printf("\n--- Testando O(log n) ---\n");
    printf("Divisoes para o numero 64: %d\n", exemplo_ologn(64));

    return 0;
}

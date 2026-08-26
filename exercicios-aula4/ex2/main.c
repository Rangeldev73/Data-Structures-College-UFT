#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main() {
    printf("=== TESTANDO TAD CONJUNTO ===\n\n");

    Conj* c1 = conj_create();
    Conj* c2 = conj_create();

    printf("1. Teste de Conjunto Vazio:\n");
    printf("c1: ");
    conj_print(c1);
    printf("c1 esta vazio? %s\n\n", conj_empty(c1) ? "Sim" : "Nao");

    printf("2. Inserindo elementos em c1 (10, 20, 30):\n");
    conj_insert(c1, 10);
    conj_insert(c1, 20);
    conj_insert(c1, 30);
    conj_insert(c1, 20);
    printf("c1: ");
    conj_print(c1);
    printf("\n");

    printf("Inserindo elementos em c2 (20, 30, 40, 50):\n");
    conj_insert(c2, 20);
    conj_insert(c2, 30);
    conj_insert(c2, 40);
    conj_insert(c2, 50);
    printf("c2: ");
    conj_print(c2);
    printf("\n");

    printf("3. Informacoes de c1:\n");
    printf("Tamanho: %d\n", conj_getsize(c1));
    printf("Maior valor: %d\n", getmaior(c1));
    printf("Menor valor: %d\n\n", getmenor(c1));

    printf("4. Intersecao (c1 cap c2):\n");
    Conj* c_inter = conj_intersection(c1, c2);
    printf("c_inter: ");
    conj_print(c_inter);
    printf("\n");

    printf("5. Diferenca (c1 - c2):\n");
    Conj* c_diff = conj_difference(c1, c2);
    printf("c_diff: ");
    conj_print(c_diff);
    printf("\n");

    printf("6. Uniao (c1 U c2):\n");
    Conj* c_union = conj_union(c1, c2);
    printf("c_union: ");
    conj_print(c_union);
    printf("\n");

    printf("7. Teste de Igualdade:\n");
    printf("c1 e c2 sao iguais? %s\n", conj_iguais(c1, c2) ? "Sim" : "Nao");
    
    Conj* c3 = conj_create();
    conj_insert(c3, 30);
    conj_insert(c3, 10);
    conj_insert(c3, 20);
    printf("c3: ");
    conj_print(c3);
    printf("c1 e c3 sao iguais? %s\n\n", conj_iguais(c1, c3) ? "Sim" : "Nao");

    printf("8. Removendo elemento 20 de c1:\n");
    conj_remove(c1, 20);
    printf("c1 apos remocao: ");
    conj_print(c1);
    printf("\n");

    free(c1);
    free(c2);
    free(c3);
    free(c_inter);
    free(c_diff);
    free(c_union);

    printf("=== TODOS OS TESTES CONCLUIDOS COM SUCESSO! ===\n");

    return 0;
}
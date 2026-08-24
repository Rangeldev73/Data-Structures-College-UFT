#include "pilha.h"
#include <stdio.h>

int main(){
    Pilha p;
    pilha_inicializar(&p);
    pilha_empilhar(&p,10);
    pilha_empilhar(&p,20);
    pilha_empilhar(&p,30);
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    pilha_empilhar(&p, 40);
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    pilha_destruir(&p);
    return 0;
}
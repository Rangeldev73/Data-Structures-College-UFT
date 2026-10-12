#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;


int lista_tamanho(Lista *l) {
    int t = 0;
    No* a = l->inicio;
    while(a) {
        t++;
        a=a->proximo;
    }
    return t;
}
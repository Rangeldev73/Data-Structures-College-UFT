#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

int lista_somar(Lista *l) {
    int s = 0;
    No* a = l->inicio;
    while(a) {
        s+=a->valor;
        a=a->proximo;
    }
    return s;
}
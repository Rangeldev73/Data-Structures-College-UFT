#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void pilha_inicializar(Pilha *p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha *p) {
    return p->topo == NULL;
}

void pilha_empilhar(Pilha *p, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pilha_desempilhar(Pilha *p) {
    if (pilha_vazia(p)) return -1;
    No *aux = p->topo;
    int v = aux->valor;
    p->topo = p->topo->proximo;
    free(aux);
    return v;
}

void pilha_destruir(Pilha *p) {
    while (!pilha_vazia(p)) {
        pilha_desempilhar(p);
    }
}

int eh_palindromo(int v[], int n) {
    Pilha p;
    pilha_inicializar(&p);

    for (int i = 0; i < n; i++) {
        pilha_empilhar(&p, v[i]);
    }

    int palindromo = 1;
    for (int i = 0; i < n; i++) {
        int topo = pilha_desempilhar(&p);
        if (topo != v[i]) {
            palindromo = 0; 
            break;          
        }
    }

    pilha_destruir(&p);

    return palindromo;
}
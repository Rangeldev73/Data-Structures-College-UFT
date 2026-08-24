#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *proximo;
};

void pilha_inicializar(Pilha *p){
    p->topo=NULL;
}

int pilha_vazia(Pilha *p){
    return p->topo == NULL;
}

void pilha_empilhar(Pilha *p, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pilha_desempilhar(Pilha *p){
    if(pilha_vazia(p)){
        printf("Erro pilha vazia\n");
        return -1;
    }
    No *aux = p->topo;
    p->topo = p->topo->proximo;
    int valor = aux->valor;
    free(aux);
    return valor;
}

void pilha_destruir(Pilha *p){
    while(p->topo!=NULL){
        No *aux = p->topo;
        p->topo = p->topo->proximo;
        free(aux);
    }
}
#ifndef PILHA_H
#define PILHA_H

typedef struct No No; 
typedef struct {
    No *topo;
} Pilha;

void pilha_inicializar(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_empilhar(Pilha *p, int valor);
int pilha_desempilhar(Pilha *p);
void pilha_destruir(Pilha *p);

#endif
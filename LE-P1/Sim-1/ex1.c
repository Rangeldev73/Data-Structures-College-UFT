#include <stdbool.h>
#include <stdlib.h>

typedef struct _no {
    char acao;
    struct _no *prox;
} No;

typedef struct {
    No *topo;
    unsigned int qtd;
} Pilha;

bool Pilha_push(Pilha* p, char acao) {
    No* novo = malloc(sizeof(No));
    if (!novo) return false;
    
    novo->acao = acao;
    novo->prox = p->topo; 
    p->topo = novo;      
    p->qtd++;
    return true;
}

bool Pilha_pop(Pilha *p, char *pacao) {
    if (p->qtd == 0 || p->topo == NULL) return false; 

    No* aux = p->topo;
    *pacao = aux->acao;      
    p->topo = p->topo->prox; 
    
    free(aux);
    p->qtd--;
    return true;
}

void Pilha_destruir(Pilha *p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* proximo = atual->prox; 
        free(atual);               
        atual = proximo;
    }
    p->topo = NULL;
    p->qtd = 0;
    free(p);
}
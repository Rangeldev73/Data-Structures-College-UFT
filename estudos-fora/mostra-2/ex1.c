#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila {
    int valor;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void fila_inicializar(Fila *f) {
    f->inicio = f->fim = NULL;
}

int fila_vazia(Fila *f) {
    return f->inicio == NULL;
}

void enfileirar(Fila *f, int valor) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int desenfileirar(Fila *f) {
    if (fila_vazia(f)) return -1;
    NoFila *aux = f->inicio;
    int v = aux->valor;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    free(aux);
    return v;
}

void fila_imprimir(Fila *f) {
    NoFila *atual = f->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

typedef struct NoPilha {
    int valor;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void pilha_inicializar(Pilha *p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha *p) {
    return p->topo == NULL;
}

void pilha_empilhar(Pilha *p, int valor) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pilha_desempilhar(Pilha *p) {
    if (pilha_vazia(p)) return -1;
    NoPilha *aux = p->topo;
    int v = aux->valor;
    p->topo = p->topo->proximo;
    free(aux);
    return v;
}

void inverter_fila(Fila *f) {
    Pilha p;
    pilha_inicializar(&p);

    while (!fila_vazia(f)) {
        pilha_empilhar(&p, desenfileirar(f));
    }

    while (!pilha_vazia(&p)) {
        enfileirar(f, pilha_desempilhar(&p));
    }
}

int main() {
    Fila f;
    fila_inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    printf("Fila original:  ");
    fila_imprimir(&f);

    inverter_fila(&f);

    printf("Fila invertida: ");
    fila_imprimir(&f); 

    return 0;
}
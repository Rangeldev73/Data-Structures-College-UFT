#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

typedef struct {
    Fila preferencial;
    Fila comum;
} SistemaAtendimento;

void sistema_inicializar(SistemaAtendimento *s) {
    s->preferencial.inicio = s->preferencial.fim = NULL;
    s->comum.inicio = s->comum.fim = NULL;
}

void enfileirar(SistemaAtendimento *s, int valor, int eh_preferencial) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    Fila *f = eh_preferencial ? &(s->preferencial) : &(s->comum);

    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int atender_proximo(SistemaAtendimento *s) {
    Fila *f = NULL;

    if (s->preferencial.inicio != NULL) {
        f = &(s->preferencial);
    } else if (s->comum.inicio != NULL) {
        f = &(s->comum);
    } else {
        printf("Fila vazia!\n");
        return -1;
    }

    No *aux = f->inicio;
    int valor = aux->valor;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(aux);
    return valor;
}
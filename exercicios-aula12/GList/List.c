#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _no {
    void* info;      
    struct _no *prox;
} TNo;

struct _list {
    TNo* inicio;
    size_t data_size; 
    void (*print)(void*);
};

List* List_create(size_t data_size, void (*print)(void*)) {
    List* nova = malloc(sizeof(List));
    if(nova != NULL) {
        nova->inicio = NULL;
        nova->data_size = data_size;
        nova->print = print;
    }
    return nova;
}

bool List_insert_end(List* lista, void* info) {
    if(!lista||!info) return false;

    TNo* novo = malloc(sizeof(TNo));
    if(!novo) return false;

    novo->info = malloc(lista->data_size);
    if(!novo->info) {
        free(novo);
        return false;
    }

    memcpy(novo->info, info, lista->data_size);
    novo->prox = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        TNo* aux = lista->inicio;
        while(aux->prox) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return true;
}

bool List_insert_begin(List* lista, void* info) {
    if(!lista||!info) return false;

    TNo* novo = malloc(sizeof(TNo));
    if(!novo) return false;

    novo->info = malloc(lista->data_size);
    if(!novo->info) {
        free(novo);
        return false;
    }

    memcpy(novo->info, info, lista->data_size);
    novo->prox = lista->inicio;
    lista->inicio = novo;
    return true;
}

void List_print(List* lista) {
    if(lista != NULL) {
        TNo* aux = lista->inicio;
        while (aux != NULL) {
            lista->print(aux->info);
            aux = aux->prox;
        }
        putchar('\n');
    }
}

void List_destroy(List* lista) {
    if (lista == NULL) return;

    TNo* aux = lista->inicio;
    while(aux) {
        TNo* temp = aux;
        aux = aux->prox;
        free(temp->info);
        free(temp);       
    }
    free(lista);       
}
#include "DList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *ant;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    TNo* fim;
};

List* List_create() {
    List* l = malloc(sizeof(List));
    if(l) {
        l->fim=NULL;
        l->inicio=NULL;
    }
    return l;
}

bool List_Insert_Begin(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->ant=NULL;
    n->prox=l->inicio;
    if(l->inicio) l->inicio->ant=n;
    else l->fim=n;
    l->inicio=n;
    return true;
}

bool List_Insert_End(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->ant=l->fim;
    n->prox=NULL;

    if(l->fim) l->fim->prox=n;
    else l->inicio=n;

    l->fim=n;
    return true;
}

void List_print(List* l) {
    if(!l) return;
    TNo* aux = l->inicio;
    while(aux!=NULL) {
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

void List_reverse_print(List* l) {
    if(!l) return;
    TNo* aux = l->fim;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->ant;
    }
    putchar('\n');
}
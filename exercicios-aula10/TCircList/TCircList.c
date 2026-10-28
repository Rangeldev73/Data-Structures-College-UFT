#include "TCircList.h"
#include<stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
};

TCList* TCList_create() {
    TCList* l = malloc(sizeof(TCList));
    if(l) l->inicio=NULL;
    return l;
}

bool TCList_insert(TCList* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    if(!l->inicio) {
        l->inicio=n;
        n->prox=n;
    }
    else {
        TNo* aux = l->inicio;
        while(aux->prox!=l->inicio) aux=aux->prox;
        aux->prox=n;
        n->prox=l->inicio;
    }
    return true;
}

void TCList_print(TCList* l) {
    TNo* aux = l->inicio;
    if(aux!=NULL)
        do{
            printf("%d->", aux->info);
            aux = aux->prox;
        }while(aux!=l->inicio);
    putchar('\n');
}
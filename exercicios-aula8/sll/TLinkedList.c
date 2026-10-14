#include <stdlib.h>
#include "TLinkedList.h"
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no* prox;
}TNo;

struct _list {
    TNo* head;
};

List* SList_create() {
    List* l = malloc(sizeof(List));
    if(l) l->head=NULL;
    return l;
}

bool SList_Insert_Begin(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->prox=NULL;
    if(l->head!=NULL) n->prox = l->head;
    l->head = n;
    return true;
}

void Slist_Print(List* l) {
    if(l) {
        TNo* aux = l->head;
        while(aux) {
            printf("%d, ", aux->info);
            aux = aux->prox;
        }
        putchar('\n');
    }
}
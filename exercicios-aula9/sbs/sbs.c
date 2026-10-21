#include <stdlib.h>
#include "sbs.h"
#include <stdio.h>

typedef struct _no {
    int qty;
    int c;
    struct _no* next;
}TNo;

struct _list {
    TNo* head;
};

List* SList_create() {
    List* l = malloc(sizeof(List));
    if(l) l->head=NULL;
    return l;
}

bool Slist_Insert_End(List* l, int qty, int c) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->qty=qty;
    n->c=c;
    n->next=NULL;
    if(!l->head) l->head = n;
    else {
        TNo* aux = l->head;
        while(aux->next) {
            aux = aux->next;
        }
        aux->next = n;
    }
    return true;
}

int SList_Size(List* l) {
    if(!l) return 0;
    int count = 0;
    TNo* aux = l->head;
    while(aux) {
        count++;
        aux = aux->next;
    }
    return count;
}

void Slist_Print_SBS(List* l) {
    if(!l) return;
    printf("%d\n", SList_Size(l));
    TNo* aux = l->head;
    while(aux) {
        printf("%d %d\n",aux->qty,aux->c);
        aux=aux->next;
    }
}

void SList_destroy(List* l) {
    if(l) {
        TNo* aux = l->head;
        while(aux) {
            l->head=aux->next;
            free(aux);
            aux=l->head;
        }
        free(l);
    }
}
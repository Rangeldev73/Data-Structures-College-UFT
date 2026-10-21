#include <stdlib.h>
#include "TLinkedList.h"
#include <stdio.h>

typedef struct _no {
    int info;
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

bool SList_Insert_Begin(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->next=NULL;
    if(l->head!=NULL) n->next = l->head;
    l->head = n;
    return true;
}

bool Slist_Insert_end(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->next=NULL;
    if(!l->head) l->head=n;
    else {
        TNo* aux = l->head;
        while(aux->next) {
            aux = aux->next;
        }
        aux->next = n;
    }
    return true;
}

bool Slist_Insert_ordered(List* l, int v) {
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->next=NULL;
    if(!l->head || l->head->info>=v) {
        n->next = l->head;
        l->head = n;
        return true;
    }
    TNo* prev = l->head;
    TNo* curr = l->head->next;
    while(curr && curr->info<v) {
        prev=curr;
        curr=curr->next;
    }
    n->next=curr;
    prev->next=n;
    return true;
}

bool Slist_Search_n_Destroy(List* l, int v) {
    if(!l||!l->head) return false;
    if(l->head->info==v) {
        TNo* aux = l->head;
        l->head=aux->next;
        free(aux);
        return true;
    }
    TNo* prev = l->head;
    TNo* curr = l->head->next;
    while(curr && curr->info!=v) {
        prev=curr;
        curr=curr->next;
    }
    if(!curr) return false;
    prev->next=curr->next;
    free(curr);
    return true;
}

void Slist_Print(List* l) {
    if(l) {
        TNo* aux = l->head;
        while(aux) {
            printf("%d, ", aux->info);
            aux = aux->next;
        }
        putchar('\n');
    }
}

void SList_destroy(List* l) {
    if(l) {
        TNo* aux = l->head;
        while(aux) {
            TNo* t = aux->next;
            free(aux);
            aux = t;
        }
        free(l);
    }
}
#include "TSortedList.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct _no{
    int info;
    struct _no *prox;
    struct _no *skip;
}TNo;

struct _list{
    TNo* inicio;
};

TSLinkedList* TSLinkedList_create(){
    TSLinkedList* nova = malloc(sizeof(TSLinkedList));
    if (nova!=NULL){
        nova->inicio = NULL;
    } return nova;
}

bool TSLinkedList_insert(TSLinkedList* l, int v){
    if(!l) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->prox=NULL;
    n->skip=NULL;
    if(!l->inicio||l->inicio->info>=v) {
        n->prox=l->inicio;
        l->inicio=n;
    }
    else {
        TNo* ant = l->inicio;
        while(ant->prox && ant->prox->info<v) ant = ant->prox;
        n->prox = ant->prox;
        ant->prox = n;
    }
    return true;
}

bool TSLinkedList_Set_Skip(TSLinkedList* l, int s) {
    if(!l) return false;
    TNo* curr = l->inicio;
    while(curr) {
        TNo* aux = curr;
        int skips = s;
        while(aux&&skips>0) {
            aux=aux->prox;
            skips--;
        }
        curr->skip = aux;
        curr=curr->prox;
    }
    return true;
}

bool TSLinkedList_search(TSLinkedList* l, int v) {
    if(!l) return false;
    TNo* aux = l->inicio;
    while(aux) {
        if(aux->info==v) return true;
        if(aux->skip&&aux->skip->info<=v) aux=aux->skip;
        else aux=aux->prox;
    }
    return false;
}

void TSLinkedList_print(TSLinkedList* lista){
    if(lista != NULL)
    {
        TNo* aux = lista->inicio;
        while(aux != NULL){
            printf("(%d, %p)->", aux->info, aux->prox);
            aux = aux->prox;
        }
        putchar('\n');
    }
}
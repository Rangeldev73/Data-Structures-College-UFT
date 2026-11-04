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

List* List_from_string(char* str) {
    List* l = List_create();
    if(!l) return NULL;
    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        int digit = str[i] - '0';
        List_Insert_End(l, digit);
    }
    return l;
}

List* List_sum(List* l1, List* l2) {
    if(!l1 || !l2) return NULL;

    List* result_list = List_create();
    if(!result_list) return NULL;

    TNo* aux1 = l1->fim;
    TNo* aux2 = l2->fim;
    int vai_um = 0;
    while(aux1!=NULL || aux2!=NULL || vai_um > 0) {
        int soma= vai_um;
        if(aux1!=NULL) {
            soma+=aux1->info;
            aux1 = aux1->ant;
        }
        if(aux2!=NULL) {
            soma+=aux2->info;
            aux2=aux2->ant;
        }
        vai_um = soma/10;
        int final_digit = soma %10;
        List_Insert_Begin(result_list, final_digit); 
    }
    return result_list;
}

void List_print_bigint(List* l) {
    if(!l) return;
    TNo* aux = l->inicio;
    while(aux != NULL) {
        printf("%d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
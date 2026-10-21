#include "dstack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int info;
    struct _no* next;
}TNo;

struct _stack {
    TNo* top;
};

Stack* Stack_create() {
    Stack* s = malloc(sizeof(Stack));
    if(s) s->top=NULL;
    return s;
}

bool Stack_push(Stack* s, int v) {
    if(!s) return false;
    TNo* n = malloc(sizeof(TNo));
    if(!n) return false;
    n->info=v;
    n->next=NULL;
    if(s->top) n->next = s->top;
    s->top = n;
    return true;
}

bool Stack_pop(Stack* s, int* v) {
    if(!s||!v) return false;
    if(!s->top) return false;
    TNo* aux = s->top;
    *v = aux->info;
    s->top = aux->next;
    free(aux);
    return true;
}

bool Stack_head(Stack* s, int* v) {
    if(!s||!v) return false;
    if(!s->top) return false;
    *v = s->top->info;
    return true;
}

void Stack_destroy(Stack* s) {
    if (!s) return;
    TNo* aux = s->top;
    while(aux) {
        s->top = aux->next;
        free(aux);
        aux = s->top;
    }
    free(s);
}


unsigned int Stack_qty(Stack* s) {
    if(!s) return 0;
    TNo* aux = s->top;
    int c=0;
    while(aux) {
        c++;
        aux=aux->next;
    }
    return c;
}
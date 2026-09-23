#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#define MAX 100

struct _stack{
    int data[MAX];
    int qtd;
};

Stack* Stack_create(){
    Stack* s = malloc(sizeof(Stack));
    if(s!=NULL){
        s->qtd = 0;
    }
    return s;
}

bool Stack_empty(Stack* s){
    return s->qtd==0;
}

bool Stack_is_full(Stack* s){
    return s->qtd==MAX;
}

bool Stack_push(Stack* s, int x){
    if(s!=NULL && !Stack_is_full(s)){
        s->data[s->qtd] = x;
        s->qtd++;
        return true;
    }
    return false;
}

bool Stack_pop(Stack* s, int* t){
    if(s!=NULL && !Stack_empty(s)){
        *t = s->data[s->qtd-1];
        s->qtd--;
        return true;
    }
    return false;
}

void Stack_destroy(Stack* s){
    free(s);
}

int Stack_getSize(Stack* s){
    if(s!=NULL) return s->qtd;
    return 0;
}
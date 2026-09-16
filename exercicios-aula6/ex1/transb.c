#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "transb.h"

struct _trans {
    PixED* dados;
    int head;
    int tail;
    unsigned int qtd;
    int capacidade;
};

Trans* Trans_create(int c) {
    if(c <= 0) return NULL; 

    Trans* t = (Trans*) malloc(sizeof(Trans));
    if(t){
        t->dados = (PixED*) malloc(c * sizeof(PixED));
        
        if(!t->dados){
            free(t);
            return NULL;
        }

        t->head = 0;
        t->tail = 0;
        t->qtd = 0;
        t->capacidade = c;
    }
    return t;
}

void Trans_destroy(Trans* f){
    if(f){
        free(f->dados);
        free(f);
    }
}

bool Trans_empty(Trans* f){
    if(!f) return true;
    return f->qtd==0;
}

bool Trans_full(Trans* f){
    if(!f) return false;
    return f->qtd==f->capacidade;
}

bool Trans_enqueue(Trans* f, PixED p){
    if(!f||Trans_full(f)) return false;
    f->dados[f->tail] = p;
    f->tail = (f->tail+1) % f->capacidade;
    f->qtd++;
    return true;
}

bool Trans_dequeue(Trans* f, PixED* p){
    if(!f||!p||Trans_empty(f)) return false;
    *p = f->dados[f->head];
    f->head = (f->head+1) % f->capacidade;
    f->qtd--;
    return true;
}

unsigned int getSize(Trans* f){
    return f ? f->qtd : 0;
}

void Trans_process(Trans* f){
    if(!f||Trans_empty(f)) return;

    PixED p;
    while(!Trans_empty(f)){
        Trans_dequeue(f,&p);
        printf("(%d, %d, %.2f),", p.id_orig, p.id_dest, p.valor);
    }
    printf("\n");
}
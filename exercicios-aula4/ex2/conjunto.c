#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#define MAX 100

struct _conj{
    int qtd;
    int dados[MAX];
};

Conj* conj_create(){
    Conj* novo = malloc(sizeof(Conj));
    if (novo != NULL) {novo->qtd = 0;}
    return novo;
}

int conj_empty(Conj* c){
    if(c!=NULL){
        return c->qtd==0;
    }
    return -1;
}

void conj_print(Conj* c){
    if(c==NULL){
        printf("Erro de alocacao!\n");
        return;
    }
    if (conj_empty(c)) {
        printf("vazio \n");
        return;
    }
    printf("{ ");
    for (int i = 0; i < c->qtd; i++) {
        printf("%d", c->dados[i]);
        if (i < c->qtd - 1) {
            printf(", ");
        }
    }
    printf(" } (%d elementos)\n", c->qtd);
}

void conj_insert(Conj* c, int v){
    if(c==NULL){
        printf("Erro de alocacao!\n");
        return;
    }
    if(c->qtd==MAX){
        printf("Erro, conjunto cheio!\n");
        return;
    }
    for(int i=0;i<c->qtd;i++){
        if(c->dados[i]==v){
            printf("Elemento já existente no conjunto!\n");
            return;
        }
    }
    c->dados[c->qtd] = v;
    c->qtd++;
    printf("Operação feita com sucesso!\n"); 
}

void conj_remove(Conj* c, int v){
    if(c == NULL){
        printf("Erro de alocacao!\n");
        return;
    }
    if(conj_empty(c)){
        printf("Erro lista vazia!\n");
        return;
    }
    for(int i=0;i<c->qtd;i++){
        if(c->dados[i] == v){
            c->dados[i] = c->dados[c->qtd - 1]; 
            c->qtd--;
            printf("Operacao feita com sucesso!\n");
            return;
        }
    }

    printf("Valor nao encontrado!\n");
}

Conj* conj_intersection(Conj* c1,Conj* c2){
    if(c1==NULL||c2==NULL){
        printf("Erro de alocacao!\n");
        return NULL;
    }
    Conj* c3 = conj_create();
    if(c3==NULL){
        printf("Erro de alocacao!\n");
        return NULL;
    }

    for(int i=0;i<c1->qtd;i++){
        for(int j = 0; j < c2->qtd; j++){
            if(c1->dados[i] == c2->dados[j]){
                conj_insert(c3, c1->dados[i]);
                break; 
            }
        }
    }

    return c3;
}

Conj* conj_difference(Conj* c1,Conj* c2){
    if(c1==NULL||c2==NULL){
        printf("Erro de alocacao!\n");
        return NULL;
    }
    Conj* c3 = conj_create();
    if(c3==NULL){
        printf("Erro de alocacao!\n");
        return NULL;
    }
    for(int i=0;i<c1->qtd;i++){
        int foundi=-1;
        for(int j=0;j<c2->qtd;j++){
            if(c1->dados[i] == c2->dados[j]){
                foundi=j;
                break;
            }
        }
        if(foundi==-1){
            conj_insert(c3,c1->dados[i]);
        }
    }
    return c3;
}

Conj* conj_union(Conj* c1, Conj* c2){
    if(c1 == NULL || c2 == NULL){
        printf("Erro: Conjunto invalido!\n");
        return NULL;
    }
    Conj* c3 = conj_create();
    if(c3 == NULL){
        printf("Erro de alocacao!\n");
        return NULL;
    }
    for(int i = 0; i < c1->qtd; i++){
        conj_insert(c3, c1->dados[i]);
    }
    for(int i = 0; i < c2->qtd; i++){
        conj_insert(c3, c2->dados[i]);
    }
    return c3;
}

int getmaior(Conj* c){
    if(c==NULL){
        printf("Erro: Conjunto invalido!\n");
        return -1;
    }
    if(conj_empty(c)){
        printf("Erro lista vazia!\n");
        return -1;
    }
    int n = c->dados[0];
    for(int i=1;i<c->qtd;i++){
        if(c->dados[i]>n){n=c->dados[i];}
    }
    return n;
}

int getmenor(Conj* c){
    if(c==NULL){
        printf("Erro: Conjunto invalido!\n");
        return -1;
    }
    if(c->qtd==0){
        printf("Erro lista vazia!\n");
        return -1;
    }
    int n = c->dados[0];
    for(int i=1;i<c->qtd;i++){
        if(c->dados[i]<n){n=c->dados[i];}
    }
    return n;
}

int conj_iguais(Conj* c1,Conj* c2){
    if(c1 == NULL || c2 == NULL){
        printf("Erro: Conjunto invalido!\n");
        return 0;
    }
    if(c1->qtd!=c2->qtd){
        return 0;
    }
    for(int i=0;i<c1->qtd;i++){
        int exists=0;
        for(int j=0;j<c2->qtd;j++){
            if(c1->dados[i]==c2->dados[j]){
                exists=1;
                break;
            }
        }
        if(!exists){
            return 0;
        }
    }
    return 1;
}

int conj_getsize(Conj* c){
    if(c!=NULL){
        return c->qtd;
    }
    return -1;
}
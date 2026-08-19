#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>

struct _ponto {
    float x, y;
}; 

Ponto* Ponto_create(float x, float y) {
    Ponto* novo = (Ponto*) malloc(sizeof(Ponto));
    if (novo != NULL) {
        novo->x = x; 
        novo->y = y; 
    }
    return novo; 
}

void Ponto_print(Ponto* ponto) {
    if (ponto != NULL) {
        printf("X: %.2f | Y: %.2f\n", ponto->x, ponto->y);
    }
}

void Ponto_delete(Ponto* ponto){
    if (ponto!=NULL){
        free(ponto);
    }
}

void Ponto_copia(Ponto* ponto,float *x,float *y){
    if (ponto!=NULL&&x!=NULL&&y!=NULL){
        *x=ponto->x;
        *y=ponto->y;
    }
}

void Ponto_modifica(Ponto* ponto,float x,float y){
    if (ponto!=NULL){
        ponto->x=x;
        ponto->y=y;
    }
}

float Pontos_distancia(Ponto* p1,Ponto* p2){
    if (p1!=NULL&&p2!=NULL){
        float x1=p1->x;
        float y1=p1->y;
        float x2=p2->x;
        float y2=p2->y;
        float x = pow((x1-x2),2);
        float y = pow((y1-y2),2);
        return sqrt(x+y);
    }
    return -1;
}
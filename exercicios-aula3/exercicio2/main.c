#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    Ponto* p1 = Ponto_create(10, 20);
    Ponto* p2 = Ponto_create(-5, -3);
    float x=0,y=0;

    Ponto_print(p1);
    Ponto_print(p2);

    printf("x: %.2f | y: %.2f\n", x,y);

    Ponto_copia(p1,&x,&y);
    
    printf("x: %.2f | y: %.2f\n", x,y);

    Ponto_print(p2);

    Ponto_modifica(p2,3,8);

    Ponto_print(p2);

    float r = Pontos_distancia(p1,p2);
    printf("Distancia entre pontos: %.2f\n", r);

    Ponto_delete(p1);
    Ponto_delete(p2);

    return 0;
}
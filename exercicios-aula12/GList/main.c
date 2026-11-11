#include "List.h"
#include <stdio.h>

void print_float(void* info) {
    float* pf = (float*) info;
    printf("[%0.2f]->", *pf);
}

void print_int(void* info) {
    int* pi = (int*) info;
    printf("[%d]->", *pi);
}

int main() {
    List* lista = List_create(sizeof(float), print_float);

    float V[] = {1.4f, 1.6f, 1.9f};
    List_insert_end(lista, &V[0]);
    List_insert_end(lista, &V[1]);
    List_insert_end(lista, &V[2]);

    printf("Lista inicial (valores copiados):\n");
    List_print(lista); 

    V[0] = 10.5f;

    printf("\nApos alterar V[0] para 10.5 na main:\n");
    List_print(lista);

    List_destroy(lista);
    return 0;
}
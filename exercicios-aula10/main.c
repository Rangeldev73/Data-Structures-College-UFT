#include "TSortedList.h"
#include <stdio.h>
int main(){
    int V[] = {4, 2, 3, 5, 4}, i;
    TSLinkedList* lista = TSLinkedList_create();
    for(i=0; i<5; i++){
        if (!TSLinkedList_insert(lista, V[i]))
            printf("Erro ao inserir V[%i]=%i\n", i, V[i]);
    }
    TSLinkedList_print(lista);
    return 0;
}
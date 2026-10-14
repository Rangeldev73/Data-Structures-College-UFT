#include "dstack.h"
#include <stdio.h>

int main(){
    //Exemplo de uso da pilha
    Stack* stack = Stack_create();
    Stack_push(stack, 1);
    Stack_push(stack, 2);
    Stack_push(stack, 3);

    int temp;
    Stack_head(stack, &temp);
    printf("O elemento do topo atual é: %d\n", temp);
    //Aqui remove os elementos
    while(Stack_pop(stack, &temp))
        printf("Valor removido: %d, Qtde atual na pilha: %u\n", temp, Stack_qty(stack));
    
    Stack_destroy(stack);
    return 0;
}
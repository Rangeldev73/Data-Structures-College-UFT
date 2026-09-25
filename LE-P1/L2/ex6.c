#include "../stack/stack.h"
#include <stdbool.h>
#include <string.h>

bool ex5(Stack* s, Stack* s2) {
    if(!s||!s2) return false;
    Stack* aux = Stack_create();
    if(!aux) return false;
    int n;
    while(Stack_pop(s,&n)) {
        Stack_push(aux, n);
    }
    while(Stack_pop(aux,&n)) {
        Stack_push(s,n);
        Stack_push(s2,n);
    }
    Stack_destroy(aux);
    return true;
}
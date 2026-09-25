#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ex5(Stack* s1, Stack* s2) {
    if(!s1||!s2) return false;
    if(Stack_getSize(s1)!=Stack_getSize(s2)) return false;
    Stack* aux1 = Stack_create();
    Stack* aux2 = Stack_create();
    if (!aux1 || !aux2) {
        if (aux1) Stack_destroy(aux1);
        if (aux2) Stack_destroy(aux2);
        return false;
    }
    bool equals = true;
    int v1,v2;
    while(Stack_pop(s1,&v1)&&Stack_pop(s2,&v2)) {
        Stack_push(aux1,v1);
        Stack_push(aux2, v2);

        if(v1!=v2) {
            equals=false;
            break;
        }
    }
    while (Stack_pop(aux1, &v1)) Stack_push(s1, v1);
    while (Stack_pop(aux2, &v2)) Stack_push(s2, v2);

    Stack_destroy(aux1);
    Stack_destroy(aux2);
    return equals;
}
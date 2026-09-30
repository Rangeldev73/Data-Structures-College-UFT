#include "../../stack/stack.h"

void ex11(Stack* s1, Stack* s2) {
    if(!s1||!s2) return;
    Stack* saux = Stack_create();
    if(!saux) return;
    int n;
    while(!Stack_empty(s1)) {
        Stack_pop(s1,&n);
        Stack_push(saux,n);
    }
    while(!Stack_empty(saux)) {
    Stack_pop(saux, &n);
    Stack_push(s1, n);
    Stack_push(s2, n);
    }
    Stack_destroy(saux);
}
#include "../stack/stack.h"
#include <stdbool.h>
#include <stdio.h>

void ex1(int n) {
    Stack* s = Stack_create();
    if(!s) return;
    int r;
    if(n==0) Stack_push(s,n);
    else {
        while(n>0) {
        r = n%2;
        n = n/2;
        Stack_push(s,r);
        }
    }
    while(Stack_pop(s,&r)) {
        printf("%d",r);
    }
    putchar('\n');
    Stack_destroy(s);
}
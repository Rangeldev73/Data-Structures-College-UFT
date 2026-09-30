#include "../../stack/stack.h"

void ex19(Stack* s, int x) {
    if(!s) return;
    int n;
    while(Stack_pop(s,&n)) {
        if(n==x) {
            break;
        }
    }
}
#include "../../stack/stack.h"
#include <stdbool.h>

bool ex9(char sent[]) {
    if(!sent) return false;
    Stack* s = Stack_create();
    if(!s) return false;
    for(int i=0;sent[i]!='\0';i++) {
        Stack_push(s,sent[i]);
    }
    int c;
    for(int i=0;sent[i]!='\0';i++) {
        Stack_pop(s,&c);
        if((char)c!=sent[i]) {
            Stack_destroy(s);
            return false;
        }
    }
    Stack_destroy(s);
    return true;
}
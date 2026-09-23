#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ex2(char sent[]) {
    if(!sent) return false;
    Stack* s = Stack_create();
    if(!s) return false;
    for(int i=0;sent[i]!='\0';i++) {
        Stack_push(s,sent[i]);
    }
    int c,i=0;
    bool palin=true;
    while(Stack_pop(s,&c)) {
        if((char)c!=sent[i]) {
            palin=false;
            break;
        }
        i++;
    }
    Stack_destroy(s);
    return palin;
}
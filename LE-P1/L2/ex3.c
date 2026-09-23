#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int ex3(char sent[]) {
    if(!sent) return false;
    Stack* s = Stack_create();
    if(!s) return false;
    for(int i=0;sent[i]!='\0';i++) {
        if(sent[i]=='('||sent[i]=='{'||sent[i]=='[') {
            Stack_push(s, sent[i]);
        }
        else if(sent[i]==')'||sent[i]=='}'||sent[i]==']') {
            if(Stack_empty(s)) {
                Stack_destroy(s);
                return false;
            }
            int top;
            Stack_pop(s,&top);
            if((sent[i]==')'&&top!='(')||(sent[i]=='}'&&top!='{')||(sent[i]==']'&&top!='[')) {
                Stack_destroy(s);
                return false;
            }
        }
    }
    bool valid = Stack_empty(s);
    Stack_destroy(s);
    return valid;
}
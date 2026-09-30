#include "../../stack/stack.h"
#include <stdio.h>
#include <string.h>

void ex5() {
    Stack* s = Stack_create();
    if(!s) return;
    char sentence[1024];
    fgets(sentence,1024,stdin);
    int aux;
    for(int i=0;sentence[i]!='\0';i++) {
        if(sentence[i]!=' '&&sentence[i]!='.') {
            Stack_push(s,sentence[i]);
        }
        else {
            while(Stack_pop(s, &aux)) {
                printf("%c",(char)aux);
            }
            if(sentence[i]==' ') {
                printf(" ");
            }
            else if(sentence[i]=='.') {
                printf(".");
                break;
            }
        }
    }
    Stack_destroy(s);
}
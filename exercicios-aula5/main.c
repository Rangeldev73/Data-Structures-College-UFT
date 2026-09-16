#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack/stack.h"
#define MAX 10

int main(){

    Stack* principal = Stack_create();
    Stack* secundaria = Stack_create();

    char comando;
    int id;

    while(scanf(" %c %d",&comando,&id)==2){
        if(comando=='0'&&id==0){
            break;
        }

        if(comando=='i'){
            if(getSize(principal)==MAX){
                printf("overflow\n");
            }
            else{
                Stack_push(principal, id);
            }
        }
        else if(comando=='r'){

            bool found=false;
            int catual;
            while(!Stack_empty(principal)){
                Stack_pop(principal,&catual);
                printf("%d, ", catual);
                if(catual==id){
                    found=true;
                    break;
                }
                else {
                    Stack_push(secundaria, catual);
                }
            }
            if(!found){
                printf("underflow\n");
            }
            else{
                printf("\n");
            }

            while(!Stack_empty(secundaria)){
                Stack_pop(secundaria,&catual);
                Stack_push(principal, catual);
            }
        }
    }
    Stack_destroy(principal);
    Stack_destroy(secundaria);
    return 0;
}
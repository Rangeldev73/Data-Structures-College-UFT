#include "../../stack/stack.h"
#include "../../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ex3() {
    Queue* eq = Queue_create();
    Queue* oq = Queue_create();
    Stack* s = Stack_create();
    if(!eq||!oq||!s) return; 
    int n;
    do {
        printf("Insira o numero('0'sai): ");
        scanf("%d",&n);
        if(n!=0) {
            if(n%2==0) Queue_enqueue(eq,n);
            else Queue_enqueue(oq,n);
        }
    }while(n!=0);
    bool odd_turn = true;
    while(!Queue_empty(oq)||!Queue_empty(eq)) {
        bool took = false;
        if((odd_turn && !Queue_empty(oq))||Queue_empty(eq)) {
            Queue_dequeue(oq, &n);
            took = true;
            odd_turn = false; 
        } 
        else if(!Queue_empty(eq)) {
            Queue_dequeue(eq, &n);
            took = true;
            odd_turn = true;
        }

        if(took) {
            if(n>0) Stack_push(s,n);
            else {
                if(!Stack_empty(s)) {
                    Stack_pop(s, &n);
                }
            }
        }
    }

    while(Stack_pop(s,&n)) {
        printf("%d ",n);
    }
    putchar('\n');

    Queue_destroy(eq);
    Queue_destroy(oq);
    Stack_destroy(s);
}
//1-odd
//2-even
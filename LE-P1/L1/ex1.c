#include "../queue/queue.h"
#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>

bool ex1(Queue* q) {
    if(!q) return false;
    Stack* s = Stack_create();
    if (!s) return false;
    int n;
    while(Queue_dequeue(q,&n)) {
        Stack_push(s,n);
    }
    while(Stack_pop(s,&n)){
        Queue_enqueue(q,n);
    }
    Stack_destroy(s);
    return true;
}
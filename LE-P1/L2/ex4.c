#include "../stack/stack.h"
#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ex4(Stack* s) {
    if(!s) return false;
    Queue* q = Queue_create();
    if(!q) return false;
    int n;
    while(Stack_pop(s,&n)) {
        Queue_enqueue(q,n);
    }
    while(Queue_dequeue(q,&n)) {
        Stack_push(s,n);
    }
    Queue_destroy(q);
    return true;
}
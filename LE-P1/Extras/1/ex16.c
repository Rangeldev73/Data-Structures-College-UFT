#include "../../queue/queue.h"
#include "../../stack/stack.h"

void ex16(Queue* q) {
    if(!q) return;
    Stack* s = Stack_create();
    if(!s) return;
    int n;
    while(Queue_dequeue(q,&n)) Stack_push(s,n);
    while(Stack_pop(s,&n)) Queue_enqueue(q,n);
    Stack_destroy(s);
    return;
}
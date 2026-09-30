#include "../../stack/stack.h"
#include "../../queue/queue.h"

void ex8(Stack* s) {
    if(!s) return;
    Queue* q = Queue_create();
    if(!q) return;
    int v;
    while(!Stack_empty(s)) {
        Stack_pop(s, &v);
        Queue_enqueue(q, v);
    }
    while(!Queue_empty(q)) {
        Queue_dequeue(q, &v);
        Stack_push(s, v);
    }
    Queue_destroy(q);
}
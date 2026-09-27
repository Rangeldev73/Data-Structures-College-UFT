#include "../stack/stack.h"
#include "../queue/queue.h"
#include <stdbool.h>

bool ex8(Queue* q, Stack* es) {
    if(!q||!es) return false;
    int n;
    while(Queue_dequeue(q,&n)) {
        Stack_push(es,n);
    }
    while(Stack_pop(es,&n)) {
        Queue_enqueue(q,n);
    }
    return true;
}

//1234
//4321
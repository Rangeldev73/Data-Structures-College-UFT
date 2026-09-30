#include "../../queue/queue.h"
#include <stdlib.h>

Queue* ex10(Queue* q1, Queue* q2) {
    if(!q1||!q2) return NULL;
    Queue* nq = Queue_create();
    if(!nq) return NULL;
    int n;
    while(!Queue_empty(q1)&&(!Queue_empty(q2))) {
        Queue_dequeue(q1,&n);
        Queue_enqueue(nq,n);

        Queue_dequeue(q2,&n);
        Queue_enqueue(nq,n);
    }
    while(!Queue_empty(q1)) {
        Queue_dequeue(q1,&n);
        Queue_enqueue(nq,n);
    }

    while(!Queue_empty(q2)) {
        Queue_dequeue(q2,&n);
        Queue_enqueue(nq,n);
    }

    return nq;
}
#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

Queue* ex9(Queue* q1, Queue* q2) {
    Queue* fq = Queue_create();
    if(!q1||!q2||!fq){
        if(fq) Queue_destroy(fq);
        return NULL;
    }

    bool q1_turn = true;
    int n;
   while (!Queue_empty(q1) && !Queue_empty(q2)) {
        Queue_dequeue(q1, &n);
        Queue_enqueue(fq, n);

        Queue_dequeue(q2, &n);
        Queue_enqueue(fq, n);
    }
    while (Queue_dequeue(q1, &n)) {
        Queue_enqueue(fq, n);
    }
    while (Queue_dequeue(q2, &n)) {
        Queue_enqueue(fq, n);
    }

    return fq;
}
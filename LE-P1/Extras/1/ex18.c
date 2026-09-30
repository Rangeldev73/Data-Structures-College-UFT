#include "../../queue/queue.h"
#include <stdio.h>

void ex16(Queue* q) {
    if(!q) return;
    Queue* qaux = Queue_create();
    if(!qaux) return;
    int n;
    while(Queue_dequeue(q,&n)) {
        Queue_enqueue(qaux,n);
        printf("%d",n);
    }
    putchar('\n');
    while(Queue_dequeue(qaux,&n)) {
        Queue_enqueue(q,n);
    }
    Queue_destroy(qaux);
}
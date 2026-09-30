#include "../../queue/queue.h"
#include <stdlib.h>

Queue* ex12(Queue* q1, Queue* q2) {
    if(!q1||!q2) return NULL;
    int n;
    while(Queue_dequeue(q2,&n)) {
        Queue_enqueue(q1,n);
    }
    return q1;
}
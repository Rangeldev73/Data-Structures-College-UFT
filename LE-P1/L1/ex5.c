#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

Queue* ex5(Queue* q1,Queue* q2) {
    if(!q1||!q2) return NULL;
    int n;
    while(Queue_dequeue(q2,&n)) {
        Queue_enqueue(q1,n);
    }
    return q1;
}
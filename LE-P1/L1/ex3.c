#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

bool ex3(Queue* q1,Queue* q2, Queue* q3) {
    if(!q1||!q2||!q3) return false;
    int v1,v2;
    bool has_v1 = Queue_dequeue(q1,&v1);
    bool has_v2 = Queue_dequeue(q2,&v2);

    while(has_v1 && has_v2) {
        if(v1<=v2) {
            Queue_enqueue(q3,v1);
            has_v1 = Queue_dequeue(q1,&v1);
        }
        else{
            Queue_enqueue(q3,v2);
            has_v2 = Queue_dequeue(q2,&v2);
        }
    }

    while(has_v1){
        Queue_enqueue(q3,v1);
        has_v1 = Queue_dequeue(q1,&v1);
    }

    while(has_v2){
        Queue_enqueue(q3,v2);
        has_v2 = Queue_dequeue(q2,&v2);
    }

    return true;
}
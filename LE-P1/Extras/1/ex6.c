#include "../../queue/queue.h"
#include <stdbool.h>

bool ex6(Queue* q1, Queue* q2, Queue* nq) {
    if(!q1||!q2||!nq) return false;
    int v1, v2;
    bool has1 = false, has2 = false;
    while(1) {
        if(!has1 && !Queue_empty(q1)) { Queue_dequeue(q1,&v1); has1 = true; }
        if(!has2 && !Queue_empty(q2)) { Queue_dequeue(q2,&v2); has2 = true; }
        
        if(has1 && has2) {
            if(v1 <= v2) { Queue_enqueue(nq,v1); has1 = false; }
            else { Queue_enqueue(nq,v2); has2 = false; }
        }
        else if(has1) { Queue_enqueue(nq,v1); has1 = false; }
        else if(has2) { Queue_enqueue(nq,v2); has2 = false; }
        else break;
    }
    return true;
}
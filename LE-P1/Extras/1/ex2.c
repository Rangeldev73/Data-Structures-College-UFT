#include "../../queue/queue.h"

void ex2(Queue* q) {
    if(!q) return;
    int os = Queue_getSize(q);
    int n;
    for(int i=0;i<os;i++) {
        Queue_dequeue(q,&n);
        if(n>=0) Queue_enqueue(q,n); 
    }
}
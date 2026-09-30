#include "../../queue/queue.h"

int ex15(Queue* q) {
    if(!q) return -1;
    Queue* qaux = Queue_create();
    if(!qaux) return -1;
    int ec=0,n;
    while(Queue_dequeue(q,&n)) {
        Queue_enqueue(qaux,n);
        if((n%2)==0) ec++;
    }
    while(Queue_dequeue(qaux,&n)) Queue_enqueue(q,n);
    Queue_destroy(qaux);
    return ec;
}
#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

int ex7(Queue* q) {
    if(!q) return -1;
    int n,ci=0;
    unsigned int os = Queue_getSize(q);
    for(int i=0;i<os;i++) {
        Queue_dequeue(q,&n);

        if(n%2!=0) ci++;

        Queue_enqueue(q,n);
    }
    return ci;
}
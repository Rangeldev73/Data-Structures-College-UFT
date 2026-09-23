#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

bool ex4(Queue* q) {
    if(!q) return false;
    int n;
    int s = Queue_getSize(q);
    for(int i=0;i<s;i++) {
        Queue_dequeue(q,&n);
        printf("%d->",n);
        Queue_enqueue(q,n);
    }
    putchar('\n');
    return true;
}
#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>

bool ex2(Queue* q) {
    if(!q) return false;
    int n,s=Queue_getSize(q);
    for(int i=0;i<s;i++){
        Queue_dequeue(q,&n);
        if(n>=0) Queue_enqueue(q,n);
    }
    return true;
}
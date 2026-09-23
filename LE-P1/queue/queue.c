#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#define MAX 10

struct _queue{
    int data[MAX];
    unsigned int qtd, head, tail;
};

Queue* Queue_create(){
    Queue* q = malloc(sizeof(Queue));
    if(q){
        q->qtd=0;
        q->head=0;
        q->tail=0;
    }
    return q;
}

bool Queue_empty(Queue* q){
    if(q) return q->qtd==0;
    return true;
}

bool Queue_full(Queue* q){
    if(q) return q->qtd==MAX;
    return true;
}

bool Queue_enqueue(Queue* q, int v){
    if(!q||Queue_full(q)) return false;
    q->data[q->tail] = v;
    q->tail = (q->tail+1) % MAX;
    q->qtd++;
    return true;
}

bool Queue_dequeue(Queue* q, int* t){
    if(!q||!t||Queue_empty(q)) return false;
    *t = q->data[q->head];
    q->head = (q->head+1) % MAX;
    q->qtd--;
    return true;
}

unsigned int Queue_getSize(Queue* q){
    return q ? q->qtd : 0;
}

void Queue_destroy(Queue* q){
    free(q);
}
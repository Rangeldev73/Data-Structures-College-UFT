#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct _queue Queue;

struct _queue {
    int data[MAX];
    unsigned int qtd, head, tail;
};

bool Queue_peek(Queue* q, int* val) {
    if(!q||!val||q->qtd == 0) return false;
    *val = q->data[q->head];
    return true;
}

int Queue_count_occurrences(Queue* q, int val) {
    if(!q || q->qtd == 0) return 0;
    int c = 0;
    int voltas = 0; 
    for(int i = q->head; voltas < q->qtd; i = (i + 1) % MAX) {
        if(q->data[i] == val) {
            c++;
        }
        voltas++;
    }
    return c;
}

Queue* Queue_merge(Queue* q1, Queue* q2) {
    if (!q1 || !q2) return NULL;
    int tq = q1->qtd + q2->qtd;
    if (tq > MAX) return NULL;
    Queue* qaux = malloc(sizeof(Queue));
    if (!qaux) return NULL;
    
    qaux->qtd = 0;
    qaux->head = 0;
    qaux->tail = 0;
    
    for (int i = 0; i < q1->qtd; i++) {
        int idx = (q1->head + i) % MAX;
        qaux->data[qaux->tail] = q1->data[idx];
        qaux->tail = (qaux->tail + 1) % MAX;
        qaux->qtd++;
    }
    
    for (int i = 0; i < q2->qtd; i++) {
        int idx = (q2->head + i) % MAX;
        qaux->data[qaux->tail] = q2->data[idx];
        qaux->tail = (qaux->tail + 1) % MAX;
        qaux->qtd++;
    }
    
    return qaux;
}
#define MAX 10
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int data[MAX];
    int qtd;
} Stack;

typedef struct
{
    Stack* data[MAX];
    unsigned int qtd, head, tail;
} StackQueue;

// normal int Stack
Stack* Stack_create() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s) s->qtd = 0; 
    return s;
}

bool Stack_push(Stack* s, int n) {
    if (!s || s->qtd == MAX) return false;
    s->data[s->qtd++] = n;
    return true;
}

bool Stack_pop(Stack* s, int* n) {
    if (!s || !n || s->qtd == 0) return false;
    *n = s->data[--s->qtd];
    return true;
}

// Stack Queue
StackQueue* SQ_create() {
    StackQueue* sq = (StackQueue*) malloc(sizeof(StackQueue));
    if (sq) {
        sq->head = 0;
        sq->tail = 0;
        sq->qtd = 0;
    }
    return sq;
}

bool SQ_enqueue(StackQueue* sq, Stack* s) {
    if (!s || !sq || sq->qtd == MAX) return false;
    sq->data[sq->tail] = s;
    sq->tail = (sq->tail + 1) % MAX;
    sq->qtd++;
    return true;
}

bool SQ_dequeue(StackQueue* sq, Stack** s) {
    if (!sq || !s || sq->qtd == 0) return false;
    *s = sq->data[sq->head];
    sq->head = (sq->head + 1) % MAX;
    sq->qtd--;
    return true;
}
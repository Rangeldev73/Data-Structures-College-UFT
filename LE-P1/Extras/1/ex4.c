#include "../../stack/stack.h"
#include "../../queue/queue.h"

void transfere_fila_para_pilha(Queue* q, Stack* s) {
    if(!q||!s) return;
    Stack* saux = Stack_create();
    if(!saux) return;
    int n;
    while(Queue_dequeue(q,&n)) {
        Stack_push(saux,n);
    }
    while(Stack_pop(saux,&n)) {
        Stack_push(s,n);
    }
    Stack_destroy(saux);
}

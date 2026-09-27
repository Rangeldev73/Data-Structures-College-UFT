#include "../stack/stack.h"
#include "../queue/queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ex7() {
    Queue* fi = Queue_create(); 
    Queue* fp = Queue_create(); 
    Stack* p  = Stack_create(); 

    if (!fi || !fp || !p) {
        if (fi) Queue_destroy(fi);
        if (fp) Queue_destroy(fp);
        if (p)  Stack_destroy(p);
        return;
    }
    int n;
    do {
        printf("Insira um numero ('0' finaliza): ");
        scanf("%d", &n);

        if (n != 0) {
            if (n % 2 == 0) {
                Queue_enqueue(fp, n);
            } else {
                Queue_enqueue(fi, n);
            }
        }
    } while (n != 0);

    bool vez_impar = true;

    while (!Queue_empty(fi) || !Queue_empty(fp)) {
        int elem;
        bool retirou = false;

        if (vez_impar) {
            if (!Queue_empty(fi)) {
                Queue_dequeue(fi, &elem);
                retirou = true;
            }
        } else {
            if (!Queue_empty(fp)) {
                Queue_dequeue(fp, &elem);
                retirou = true;
            }
        }

        if (retirou) {
            if (elem > 0) {
                Stack_push(p, elem);
            } else {
                int temp;
                Stack_pop(p, &temp);
            }
        }

        vez_impar = !vez_impar;
    }

    printf("\nConteudo final da Pilha (do topo para a base):\n");
    int val;
    while (Stack_pop(p, &val)) {
        printf("%d ", val);
    }
    printf("\n");

    Queue_destroy(fi);
    Queue_destroy(fp);
    Stack_destroy(p);
}
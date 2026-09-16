#include <stdio.h>
#include <stdlib.h>
#include "transb.h"

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Trans* fila = Trans_create(n);
    if (!fila) return 1;

    PixED p;
    while (scanf("%d %d %f", &p.id_orig, &p.id_dest, &p.valor) == 3) {
        
        if (p.id_orig == 0 && p.id_dest == 0) {
            Trans_process(fila);
            break;
        }

        if (Trans_full(fila)) {
            Trans_process(fila);
        }

        Trans_enqueue(fila, p);
    }

    Trans_destroy(fila);
    return 0;
}
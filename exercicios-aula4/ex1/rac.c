#include <stdio.h>
#include <stdlib.h>
#include "rac.h"

struct _rac{
    int n,d;
};

Rac* create(int n, int d){
    if(d == 0) return NULL; 
    Rac* rac = (Rac*) malloc(sizeof(Rac));
    if(rac != NULL){
        rac->n = n;
        rac->d = d;
    }
    return rac;
}

Rac* soma(Rac* r1, Rac* r2){
    if(r1 == NULL || r2 == NULL) return NULL;

    int d = r1->d * r2->d;
    int n = (r1->n * r2->d) + (r2->n * r1->d);

    return create(n, d);
}

Rac* multiplica(Rac* r1, Rac* r2){
    if(r1 == NULL || r2 == NULL) return NULL;
    int d = r1->d * r2->d;
    int n = r1->n * r2->n;
    return create(n, d);
}

int iguais(Rac* r1, Rac* r2){
    if(r1 == NULL || r2 == NULL) return 0;

    if(r1->n * r2->d == r2->n * r1->d){
        return 1;
    }
    return 0;
}
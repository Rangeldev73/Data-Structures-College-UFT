#include <stdio.h>
#include <stdlib.h>
#include "rac.h"

int main(){

    Rac* r1 = create(1, 2);
    Rac* r2 = create(2, 4); 
    Rac* r3 = create(3, 4); 
    
    Rac* r_invalido = create(5, 0); 

    if (r_invalido == NULL) {
        printf("Teste Denominador Zero: OK (Tentativa de criar fração com denominador 0 bloqueada)\n\n");
    }

    Rac* r_soma = soma(r1, r3);
    printf("Resultado da Soma (1/2 + 3/4): criado com sucesso.\n");

    Rac* r_mult = multiplica(r1, r3);
    printf("Resultado da Multiplicacao (1/2 * 3/4): criado com sucesso.\n\n");

    printf("--- Testes de Igualdade ---\n");
    
    if (iguais(r1, r2)) {
        printf("r1 (1/2) e r2 (2/4) sao IGUAIS -> OK\n");
    } else {
        printf("r1 (1/2) e r2 (2/4) sao DIFERENTES\n");
    }

    if (iguais(r1, r3)) {
        printf("r1 (1/2) e r3 (3/4) sao IGUAIS\n");
    } else {
        printf("r1 (1/2) e r3 (3/4) sao DIFERENTES -> OK\n");
    }

    return 0;
}
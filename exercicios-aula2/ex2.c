#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v;
    
    v = malloc(3 * sizeof(int));
    if (v == NULL) return 1; 

    printf("--- Primeiro Bloco (Tamanho 3) ---\n");
    for(int i = 0; i < 3; i++){
        v[i] = i * 10;
        printf("v[%d]: %d\n", i, v[i]); 
    }

    int *temp = realloc(v, 5 * sizeof(int));
    if (temp == NULL) {
        free(v); 
        return 1;
    }
    v = temp;

    printf("\n--- Segundo Bloco (Tamanho 5) ---\n");
    for(int i = 0; i < 5; i++){
        v[i] = i * 10; 
        printf("v[%d]: %d\n", i, v[i]);
    }

    free(v);
    return 0;
}

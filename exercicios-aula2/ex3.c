#include <stdio.h>
#include <stdlib.h>

int main(){
    int **M, n, m;
    
    printf("Insira n e m: ");
    if (scanf("%d %d", &n, &m) != 2) return 1; 

    M = malloc(n * sizeof(int*));
    
    if (M == NULL) {
        printf("Erro: Memoria cheia ao alocar a matriz!\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        M[i] = calloc(m, sizeof(int));

        if(M[i] == NULL){
            printf("Erro: Memoria cheia ao alocar a linha %d!\n", i);
            
            for(int j = 0; j < i; j++) {
                free(M[j]);
            }
            free(M);
            return 1;
        }
    }

    printf("Matriz %dx%d alocada e zerada com sucesso!\n", n, m);

    for(int i = 0; i < n; i++) {
        free(M[i]); 
    }
    free(M); 
    return 0;
}

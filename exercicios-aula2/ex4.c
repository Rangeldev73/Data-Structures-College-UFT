#include<stdio.h>
#include<stdlib.h>

int main(){
    int **M, i;
    unsigned int n, m;
    puts("Digite as dimensoes da matriz: ");
    scanf("%d %d", &n, &m);

    M = (int**) malloc(n*sizeof(int*));
    if (M!= NULL){
        for(i=0; i< n; i++){
            M[i] = (int*) calloc(m, sizeof(int));
            if(M[i] == NULL)
                return printf("ERRO: ao alocar o vetor %d", i);
        }
    }
    return 0;
}
#include <stdio.h>

int busca_binaria(int v[], int n, int chave);

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10},n=10,chave;

    printf("Insira o a chave (1a10): ");
    scanf("%d",&chave);

    int r = busca_binaria(v,n,chave);
    if(r!=-1) printf("Elemento %d encontrado no indice: %d\n", chave, r);
    else printf("Elemento %d nao encontrado no vetor.\n", chave);
    return 0;
}

int busca_binaria(int v[], int n, int chave){
    int inicio=0,fim=n-1;

     while(inicio <= fim){
        int meio=(inicio+fim)/2;

        if(v[meio] == chave){
            return meio;
        }
        if(chave < v[meio]){
            fim = meio - 1;
        } 
        else{
            inicio = meio + 1;
        }
     }
    return -1;
}
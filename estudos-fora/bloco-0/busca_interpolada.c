#include <stdio.h>

int busca_interpolada(int v[], int n, int chave);

int main(){
    int v[10] = {1,2,3,4,5,6,7,8,9,10},n=10,chave;

    printf("Insira o a chave (1a10): ");
    scanf("%d",&chave);

    int r = busca_interpolada(v,n,chave);
    if(r!=-1) printf("Elemento %d encontrado no indice: %d\n", chave, r);
    else printf("Elemento %d nao encontrado no vetor.\n", chave);
    return 0;
}

int busca_interpolada(int v[], int n, int chave){
    int inicio=0,fim=n-1,pos;

    while(inicio <= fim && chave >= v[inicio] && chave <= v[fim]){
        if(v[fim] == v[inicio]){
            if (v[inicio] == chave) return inicio;
            break;
        }
        pos = inicio + ((chave - v[inicio]) * (fim - inicio)) / (v[fim] - v[inicio]);
        if(v[pos] == chave){
            return pos;
        }
        if(v[pos] < chave){
            inicio = pos + 1;
        }
        else{
            fim = pos - 1;
        }
    }
    return -1;
}
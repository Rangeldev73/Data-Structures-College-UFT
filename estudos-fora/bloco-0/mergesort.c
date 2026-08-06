#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim);
void merge_sort(int v[], int inicio, int fim);

int main(){
    int v[10] = {5, 2, 9, 1, 5, 6,9,3,9,10};
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
    merge_sort(v,0,9);
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
}

void merge(int v[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esq[n1],dir[n2];

    for(int i = 0; i < n1; i++) esq[i] = v[inicio + i];
    for(int j = 0; j < n2; j++) dir[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while(i < n1 && j < n2){
        if(esq[i] <= dir[j]){
            v[k] = esq[i];
            i++;
        }
        else{
            v[k] = dir[j];
            j++;
        }
        k++;
    }
    while(i < n1) { v[k] = esq[i]; i++; k++; }
    while(j < n2) { v[k] = dir[j]; j++; k++; }
}

void merge_sort(int v[], int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}
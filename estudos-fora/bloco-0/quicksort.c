#include <stdio.h>

int particiona(int v[], int inicio, int fim);
void quick_sort(int v[], int inicio, int fim);

int main(){
    int v[10] = {5, 2, 9, 1, 5, 6,9,3,9,10};
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
    quick_sort(v,0,9);
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    return 0;
}

int particiona(int v[], int inicio, int fim){
    int pivo = v[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){
        if(v[j] < pivo){
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

void quick_sort(int v[], int inicio, int fim){
    if(inicio < fim){
        int p = particiona(v,inicio,fim);
        quick_sort(v,inicio,p-1);
        quick_sort(v,p+1,fim);
    }
}
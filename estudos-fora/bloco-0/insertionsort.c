#include <stdio.h>

void insertion_sort(int v[], int n);

int main(){
    int v[10] = {5, 2, 9, 1, 5, 6,9,3,9,10},n=10;
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
    insertion_sort(v,n);
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
}

void insertion_sort(int v[], int n){
    for(int i = 1; i < n; i++){
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}
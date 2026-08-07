#include <stdio.h>

void bubble_sort(int v[], int n);

int main(){
    int v[10] = {5, 2, 9, 1, 5, 6,9,3,9,10},n=10;
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
    bubble_sort(v,n);
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    return 0;
}

void bubble_sort(int v[], int n){
    for(int i=0;i<n-1;i++){
        int trocou = 0;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                trocou = 1;
            }
        }
        if(trocou == 0) break;
    }
}
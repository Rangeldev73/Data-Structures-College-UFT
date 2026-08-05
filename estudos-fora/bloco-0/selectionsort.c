#include <stdio.h>

void selection_sort(int v[], int n);

int main(){
    int v[10] = {5, 2, 9, 1, 5, 6,9,3,9,10},n=10;
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
    printf("\n");
    selection_sort(v,n);
    for(int i=0;i<10;i++){
        printf("%d-",v[i]);
    }
}

void selection_sort(int v[], int n){
    for(int i = 0; i < n - 1; i++){
        int imenor = i;
        for(int j = i +1; j < n;j++){
            if(v[j]<v[imenor]){
                imenor=j;
            }
        }
        int temp = v[i];
        v[i] = v[imenor];
        v[imenor] = temp;
    }
}
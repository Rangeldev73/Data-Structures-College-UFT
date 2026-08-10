#include <stdio.h>

int main(){
    int v[50];
    for(int i=0;i<50;i++){
        v[i]=(i+5*i)%(i+1);
    }
    for(int i=0;i<50;i++){
        printf("%d-",v[i]);
    }
    return 0;
}
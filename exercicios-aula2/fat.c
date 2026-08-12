#include <stdio.h>

int fat(int);

int main(){
    int n;
    printf("Insira n: ");
    scanf("%d",&n);
    printf("%d",fat(n));
    return 0;;
}

int fat(int n){
    if(n<=1){
        return 1;
    }
    else{
        return n*fat(n-1);
    }
}
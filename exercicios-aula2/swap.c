#include <stdio.h>

void swap(int *a,int *b);

int main(){
    int a,b;
    printf("Insira a: ");
    scanf("%d",&a);
    printf("Insira b: ");
    scanf("%d",&b);
    printf("A:%d e B:%d\n",a,b);
    swap(&a,&b);
    printf("A:%d e B:%d\n",a,b);
    return 0;
}

void swap(int *a, int *b){
    int aux = (*a);
    (*a)=(*b);
    (*b)=aux;
}
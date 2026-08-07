#include <stdio.h>

void trocar(int *a, int *b);

int main(){
    int a,b;
    printf("Insira a: ");
    scanf("%d",&a);
    printf("Insira b: ");
    scanf("%d",&b);
    printf("A:%d e B:%d\n",a,b);
    trocar(&a,&b);
    printf("A:%d e B:%d\n",a,b);
    return 0;
}

void trocar(int *a, int *b){
    int temp = (*a);
    (*a)=(*b);
    (*b)=temp;
}
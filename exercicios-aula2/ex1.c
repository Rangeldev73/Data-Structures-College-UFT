#include <stdio.h>
#include <stdlib.h>

int main(){
    float *p1,*p2;
    p1= malloc(sizeof(float));
    *p1=10;
    p2=p1;
    printf("*p1 = %f, *p2 = %f\n",*p1,*p2);
    p1= malloc(sizeof(float));
    puts("Digite um float: ");
    scanf("%f",p1);
    printf("*p1 = %f, *p2 = %f\n",*p1,*p2);
    //desperdiçando memoria pois com essa tera 3 endereços de memoria para duas variaveis
    //correcao :
    //free(p2);
    p2= malloc(sizeof(float));
    *p2=20;
    return 0;
}
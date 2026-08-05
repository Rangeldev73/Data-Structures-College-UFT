#include <stdio.h>

int main(){
    int v1[10]={0};
    int i,n;
    for(i=0;i<10;i++){
        printf("Insira o numero %d\n",i+1);
        scanf("%d",&v1[i]);
    }
    printf("Insira N\n");
    scanf("%d",&n);
    for(i=0;i<10;i++){
        if((v1[i]%n)==0){
           printf("%d\n",v1[i]);
        }
    }
}
#include <stdio.h>

int soma_diagonal_principal(int m[3][3]);

int main(){
    int m[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Insira linha %d coluna %d: ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
    int r=soma_diagonal_principal(m);
    printf("Resultado: %d\n", r);
    return 0;
}

int soma_diagonal_principal(int m[3][3]){
    return m[0][0]+m[1][1]+m[2][2];
}
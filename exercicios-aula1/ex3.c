#include <stdio.h>

int main(){
    int v[10];
    int iatual = 0;
    int numero_valido;

    printf("Digite 10 numeros exclusivos:\n");

    for(int i = 0; i < 10; i++){
        printf("Digite o numero para a posicao %d: ", i);
        scanf("%d", &v[i]);

        numero_valido = 1; 

        for(int j = 0; j < i; j++){
            if(v[i] == v[j]){
                numero_valido = 0; 
                break; 
            }
        }

        if(numero_valido == 0){
            printf("Numero ja digitado! Tente outro.\n");
            i--; 
        }
    }

    printf("\nVetor final:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
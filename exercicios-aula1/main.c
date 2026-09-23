#include <stdio.h>
#include <string.h> 

int main() {
    char nome[50];

    printf("Digite seu nome completo: ");
    
    if (fgets(nome, sizeof(nome), stdin) != NULL) {
        
        
        nome[strcspn(nome, "\n")] = '\0';

        printf("Ola, %s! Seja bem-vindo.\n", nome);
    } else {
        printf("Erro ao ler a entrada.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} ListaCircular;

void lista_inicializar(ListaCircular *l);
int lista_vazia(ListaCircular *l);
void lista_inserir_fim(ListaCircular *l, int valor);
void lista_imprimir(ListaCircular *l);
void lista_remover(ListaCircular *l, int valor);

int main(){
    ListaCircular l;
    lista_inicializar(&l);

    printf("--- TESTE DE REMOCAO NA LISTA CIRCULAR ---\n\n");

    lista_inserir_fim(&l, 10);
    lista_inserir_fim(&l, 20);
    lista_inserir_fim(&l, 30);

    printf("Lista atual: ");
    lista_imprimir(&l);
    printf("\n");

    printf("Removendo 10 (inicio)...\n");
    lista_remover(&l, 10);
    printf("Imprimir: ");
    lista_imprimir(&l); 
    printf("\n");

    printf("Removendo 30 (fim)...\n");
    lista_remover(&l, 30);
    printf("Imprimir: ");
    lista_imprimir(&l); 
    printf("\n");

    printf("Removendo 20 (unico elemento restante)...\n");
    lista_remover(&l, 20);
    printf("Imprimir: ");
    lista_imprimir(&l); 

    return 0;
}

void lista_inicializar(ListaCircular *l){
    l->inicio=NULL;
}

int lista_vazia(ListaCircular *l){
    return l->inicio==NULL;
}

void lista_inserir_fim(ListaCircular *l, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor=valor;

    if(lista_vazia(l)){
        novo->proximo=novo;
        l->inicio=novo;
        return;
    }

    No *atual = l->inicio;
    while(atual->proximo!=l->inicio){
        atual = atual->proximo;
    }

    atual->proximo=novo;
    novo->proximo=l->inicio;
}


void lista_imprimir(ListaCircular *l) {
    if (lista_vazia(l)) {
        printf("Lista vazia\n");
        return;
    }
    No *atual = l->inicio;
    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    } while (atual != l->inicio); 
    printf("(volta ao inicio)\n");
}

void lista_remover(ListaCircular *l, int valor) {
    if (lista_vazia(l)) {
        printf("Erro: lista vazia\n");
        return;
    }

    if (l->inicio->valor == valor) {
        if (l->inicio->proximo == l->inicio) {
            free(l->inicio);
            l->inicio = NULL;
            return;
        }

        No *ultimo = l->inicio;
        while (ultimo->proximo != l->inicio) {
            ultimo = ultimo->proximo;
        }

        No *temp = l->inicio;            
        l->inicio = l->inicio->proximo;  
        ultimo->proximo = l->inicio;     
        free(temp);                      
        return;
    }

    No *anterior = l->inicio;
    No *atual = l->inicio->proximo;

    while (atual != l->inicio) {
        if (atual->valor == valor) {
            anterior->proximo = atual->proximo; 
            free(atual);                     
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Erro: valor %d nao encontrado\n", valor);
}
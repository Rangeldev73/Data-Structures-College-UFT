#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} Lista;

void lista_inicializar(Lista *l);
int lista_vazia(Lista *l);
void lista_inserir_inicio(Lista *l, int valor);
void lista_inserir_fim(Lista *l, int valor);
void lista_imprimir(Lista *l);
int lista_remover(Lista *l, int valor);

int main(){
    Lista l;
    lista_inicializar(&l);

    printf("--- TESTE DE REMOÇÃO NA LISTA ENCADEADA ---\n\n");

    lista_inserir_fim(&l, 5);
    lista_inserir_fim(&l, 10);
    lista_inserir_fim(&l, 20);
    lista_inserir_fim(&l, 30);

    printf("Lista atual: ");
    lista_imprimir(&l);
    printf("\n");

    printf("Removendo 5 (inicio)...\n");
    lista_remover(&l, 5);
    printf("Imprimir: ");
    lista_imprimir(&l); 
    printf("\n");

    printf("Removendo 20 (meio)...\n");
    lista_remover(&l, 20);
    printf("Imprimir: ");
    lista_imprimir(&l); 
    printf("\n");

    printf("Tentando remover 99 (nao existe):\n");
    lista_remover(&l, 99);

    return 0;
}

void lista_inicializar(Lista *l){
    l->inicio=NULL;
}

int lista_vazia(Lista *l){
    return l->inicio == NULL;
}

void lista_inserir_inicio(Lista *l, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor=valor;
    novo->proximo=l->inicio;
    l->inicio=novo;
}

void lista_inserir_fim(Lista *l, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor=valor;
    novo->proximo=NULL;

    if(lista_vazia(l)){
        l->inicio = novo;
        return;
    }

    No *atual = l->inicio;
    while(atual->proximo!=NULL){
        atual = atual->proximo;
    }
    atual->proximo=novo;
}

void lista_imprimir(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int lista_remover(Lista *l, int valor){
    if(lista_vazia(l)){
        printf("Erro: lista vazia\n");
        return 0;
    }

    if(l->inicio->valor==valor){
        No *aux = l->inicio;
        l->inicio = aux->proximo;
        free(aux);
        return 1;
    }

    No *anterior = l->inicio;
    No *atual = l->inicio->proximo;

    while(atual!=NULL && atual->valor!=valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual==NULL){
        printf("Erro: valor nao encontrado\n");
        return 0;
    }

    anterior->proximo = atual->proximo;
    free(atual);
    return 1;
}
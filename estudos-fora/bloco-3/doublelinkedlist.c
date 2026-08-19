#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaDupla;

void lista_inicializar(ListaDupla *l);
int lista_vazia(ListaDupla *l);
void lista_inserir_fim(ListaDupla *l, int valor);
void lista_imprimir(ListaDupla *l);
int lista_remover(ListaDupla *l, int valor);
void lista_imprimir_reversa(ListaDupla *l);

int main(){
    ListaDupla l;
    lista_inicializar(&l);

    printf("--- TESTE DA LISTA DUPLAMENTE ENCADEADA ---\n\n");

    lista_inserir_fim(&l, 10);
    lista_inserir_fim(&l, 20);
    lista_inserir_fim(&l, 30);
    lista_inserir_fim(&l, 40);

    printf("Lista inicial:\n");
    lista_imprimir(&l);

    printf("Impressao reversa (bonus):\n");
    lista_imprimir_reversa(&l);
    printf("\n");

    printf("Removendo 10 (inicio)...\n");
    lista_remover(&l, 10);

    printf("Removendo 40 (fim)...\n");
    lista_remover(&l, 40);

    printf("\nLista apos remocao do 10 e 40:\n");
    lista_imprimir(&l);

    printf("Impressao reversa atualizada:\n");
    lista_imprimir_reversa(&l);
    printf("\n");

    printf("Tentando remover 99:\n");
    lista_remover(&l, 99);

    return 0;
}

void lista_inicializar(ListaDupla *l){
    l->inicio=NULL;
    l->fim=NULL;
}

int lista_vazia(ListaDupla *l){
    return l->inicio==NULL;
}

void lista_inserir_fim(ListaDupla *l, int valor){
    No *novo = malloc(sizeof(No));
    novo->valor=valor;
    novo->proximo=NULL;

    if(lista_vazia(l)){
        novo->anterior=NULL;
        l->inicio=novo;
        l->fim=novo;
        return;
    }

    novo->anterior=l->fim;
    l->fim->proximo = novo;
    l->fim=novo;
}

void lista_imprimir(ListaDupla *l){
    No *atual=l->inicio;
    while(atual!=NULL){
        printf("%d<->",atual->valor);
        atual=atual->proximo;
    }
    printf("NULL\n");
}

int lista_remover(ListaDupla *l, int valor){
    if (lista_vazia(l)) {
        printf("Erro: lista vazia\n");
        return 0;
    }

    No *atual = l->inicio;
    while(atual!=NULL && atual->valor!=valor){
        atual=atual->proximo;
    }

    if (atual == NULL) {
        printf("Erro: valor nao encontrado\n");
        return 0;
    }

    if(atual->anterior!=NULL){
        atual->anterior->proximo=atual->proximo;
    }
    else{
        l->inicio=atual->proximo;
    }

    if(atual->proximo!=NULL){
        atual->proximo->anterior=atual->anterior;
    }
    else{
        l->fim = atual->anterior;
    }

    free(atual);
    return 1;
}

void lista_imprimir_reversa(ListaDupla *l){
    No *atual=l->fim;
    while(atual!=NULL){
        printf("%d<->",atual->valor);
        atual=atual->anterior;
    }
    printf("NULL\n");
}
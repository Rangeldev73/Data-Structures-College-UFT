#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;

void fila_inicializar(Fila *f);
int fila_vazia(Fila *f);
void fila_enfileirar(Fila *f, int valor);
int fila_desenfileirar(Fila *f);
void fila_destruir(Fila *f);

int main(){
    Fila f;
    fila_inicializar(&f);

    printf("--- TESTE DA FILA DINAMICA ---\n\n");

    fila_enfileirar(&f, 10);
    fila_enfileirar(&f, 20);
    fila_enfileirar(&f, 30);

    printf("Desenfileirado: %d (esperado: 10)\n", fila_desenfileirar(&f));

    fila_enfileirar(&f, 40);

    printf("Desenfileirado: %d (esperado: 20)\n", fila_desenfileirar(&f));
    printf("Desenfileirado: %d (esperado: 30)\n", fila_desenfileirar(&f));
    printf("Desenfileirado: %d (esperado: 40)\n", fila_desenfileirar(&f));

    printf("Desenfileirado: %d (esperado: Erro e retorno -1)\n", fila_desenfileirar(&f));

    fila_enfileirar(&f, 50);

    printf("Desenfileirado: %d (esperado: 50)\n", fila_desenfileirar(&f));

    fila_destruir(&f);
    return 0;
}

void fila_inicializar(Fila *f){
    f->inicio=NULL;
    f->fim=NULL;
}

int fila_vazia(Fila *f){
    return f->inicio==NULL;
}

void fila_enfileirar(Fila *f, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo; 
        f->fim = novo;   
    } else {
        f->fim->proximo = novo; 
        f->fim = novo;     
    }
}

int fila_desenfileirar(Fila *f){
    if(fila_vazia(f)){
        printf("Erro: fila vazia\n");
        return -1;
    }
    No *aux = f->inicio;
    int valor=aux->valor;
   f->inicio=aux->proximo;
   if(f->inicio==NULL){
    f->fim=NULL;
   }
   free(aux);
    return valor;
}

void fila_destruir(Fila *f){
    while(f->inicio!=NULL){
        No *aux = f->inicio;
        f->inicio=aux->proximo;
        free(aux);
    }
    f->fim=NULL;
}
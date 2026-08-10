#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int total; 
} Fila;

void fila_inicializar(Fila *f);
int fila_vazia(Fila *f);
int fila_cheia(Fila *f);
void fila_enfileirar(Fila *f, int valor);
int fila_desenfileirar(Fila *f);

int main(){
    Fila f;
    fila_inicializar(&f);

    printf("--- TESTE DA FILA CIRCULAR ---\n\n");

    fila_enfileirar(&f, 10);
    fila_enfileirar(&f, 20);
    fila_enfileirar(&f, 30);

    printf("Desenfileirado: %d (esperado: 10)\n", fila_desenfileirar(&f));

    fila_enfileirar(&f, 40);

    printf("Desenfileirado: %d (esperado: 20)\n", fila_desenfileirar(&f));
    printf("Desenfileirado: %d (esperado: 30)\n", fila_desenfileirar(&f));
    printf("Desenfileirado: %d (esperado: 40)\n", fila_desenfileirar(&f));

    printf("Desenfileirado: %d (esperado: Erro e retorno -1)\n", fila_desenfileirar(&f));

    return 0;
}

void fila_inicializar(Fila *f){
    f->inicio=0;
    f->fim=0;
    f->total=0;
}

int fila_vazia(Fila *f){
    return f->total==0;
}

int fila_cheia(Fila *f){
    return f->total==MAX;
}

void fila_enfileirar(Fila *f, int valor){
    if(fila_cheia(f)){
        printf("Erro: fila cheia\n");
        return;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

int fila_desenfileirar(Fila *f){
    if(fila_vazia(f)){
        printf("Erro: fila vazia\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX; 
    f->total--;
    return valor;
}
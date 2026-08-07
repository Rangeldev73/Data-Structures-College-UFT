#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo; 
} Pilha;

void pilha_inicializar(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void pilha_empilhar(Pilha *p, int valor);
int pilha_desempilhar(Pilha *p);

int main(){
    Pilha p;
    pilha_inicializar(&p);
    pilha_empilhar(&p,10);
    pilha_empilhar(&p,20);
    pilha_empilhar(&p,30);
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    pilha_empilhar(&p, 40);
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    printf("Desempilhado: %d\n", pilha_desempilhar(&p));
    return 0;
}

void pilha_inicializar(Pilha *p){
    p->topo = -1;
}

int pilha_vazia(Pilha *p){
    return p->topo == -1;
}

int pilha_cheia(Pilha *p){
    return p->topo == MAX - 1;
}

void pilha_empilhar(Pilha *p, int valor){
    if(pilha_cheia(p)){
        printf("Erro pilha cheia\n");
        return;
    }
    p->topo++;
    p->dados[p->topo]=valor;
}

int pilha_desempilhar(Pilha *p){
    if(pilha_vazia(p)){
        printf("Erro pilha vazia\n");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}
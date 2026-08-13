#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int total;
} ListaOrdenada;

void lista_inicializar(ListaOrdenada *l);
int lista_vazia(ListaOrdenada *l);
void lista_inserir(ListaOrdenada *l, int valor);
int lista_buscar(ListaOrdenada *l, int valor);
int lista_remover(ListaOrdenada *l, int valor);

int main() {
    ListaOrdenada l;
    lista_inicializar(&l);

    printf("--- TESTE DA LISTA SEQUENCIAL ORDENADA ---\n\n");

    lista_inserir(&l, 50);
    lista_inserir(&l, 20);
    lista_inserir(&l, 80);
    lista_inserir(&l, 10);
    lista_inserir(&l, 30);

    printf("Lista apos insercoes (esperado: 10, 20, 30, 50, 80):\n");
    for (int i = 0; i < l.total; i++) {
        printf("%d ", l.dados[i]);
    }
    printf("\n\n");

    printf("Buscar 30: posicao %d (esperado: 2)\n", lista_buscar(&l, 30));

    printf("Buscar 99: posicao %d (esperado: -1)\n\n", lista_buscar(&l, 99));

    printf("Removendo 20...\n");
    lista_remover(&l, 20);

    printf("Lista apos remover 20 (esperado: 10, 30, 50, 80):\n");
    for (int i = 0; i < l.total; i++) {
        printf("%d ", l.dados[i]);
    }
    printf("\n\n");
    
    printf("Tentando remover 99:\n");
    lista_remover(&l, 99);

    return 0;
}

void lista_inicializar(ListaOrdenada *l){
    l->total=0;
}

int lista_vazia(ListaOrdenada *l){
    return l->total == 0;
}

void lista_inserir(ListaOrdenada *l, int valor){
    if(l->total==MAX){
        printf("Erro: lista cheia\n");
        return;
    }
    int i = l->total - 1;
    while(i>=0 && l->dados[i] > valor){
        l->dados[i+1] = l->dados[i];
        i--;
    }
    l->dados[i+1] = valor;
    l->total++;
}

int lista_buscar(ListaOrdenada *l, int valor){
    for(int i=0;i<l->total;i++){
        if(l->dados[i]==valor) return i;
    }
    return -1;
}

int lista_remover(ListaOrdenada *l, int valor){
    int pos = lista_buscar(l,valor);
    if(pos==-1){
        printf("Erro: valor nao encontrado\n");
        return 0;
    }
    for(int i=pos;i<l->total-1;i++){
        l->dados[i] = l->dados[i+1];
    }
    l->total--;
    return 1;
}
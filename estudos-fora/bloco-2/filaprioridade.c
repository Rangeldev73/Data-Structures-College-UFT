#include <stdio.h>
#define MAX 100

typedef struct {
    int valor;
    int prioridade; 
} Item;

typedef struct {
    Item dados[MAX];
    int total;
} FilaPrioridade;

void fp_inicializar(FilaPrioridade *f);
int fp_vazia(FilaPrioridade *f);
void fp_inserir(FilaPrioridade *f, int valor, int prioridade);
int fp_remover(FilaPrioridade *f);

int main(){
    FilaPrioridade f;
    fp_inicializar(&f);

    printf("--- TESTE DA FILA DE PRIORIDADE ---\n\n");

    fp_inserir(&f, 100, 2);
    fp_inserir(&f, 200, 5);
    fp_inserir(&f, 300, 1);
    fp_inserir(&f, 400, 8);

    printf("Removido: %d (esperado: 400 - prio 8)\n", fp_remover(&f));
    printf("Removido: %d (esperado: 200 - prio 5)\n", fp_remover(&f));
    printf("Removido: %d (esperado: 100 - prio 2)\n", fp_remover(&f));
    printf("Removido: %d (esperado: 300 - prio 1)\n", fp_remover(&f));

    return 0;
}

void fp_inicializar(FilaPrioridade *f){
    f->total=0;
}

int fp_vazia(FilaPrioridade *f){
    return f->total==0;
}

void fp_inserir(FilaPrioridade *f, int valor, int prioridade){
    if(f->total==MAX){
        printf("Erro: fila cheia\n");
        return;
    }
    int i=f->total-1;

    while(i >= 0 && f->dados[i].prioridade < prioridade){
        f->dados[i+1] = f->dados[i];
        i--;
    }
    f->dados[i+1].valor=valor;
    f->dados[i+1].prioridade=prioridade;
    f->total++;
}

int fp_remover(FilaPrioridade *f){
    if(fp_vazia(f)){
        printf("Erro: fila vazia\n");
        return -1;
    }
    int valor = f->dados[0].valor;

    for(int i=0;i<f->total-1;i++){
        f->dados[i] = f->dados[i+1];
    }
    f->total--;
    return valor;
}
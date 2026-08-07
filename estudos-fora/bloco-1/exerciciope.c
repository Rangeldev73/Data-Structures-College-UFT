#include <stdio.h>
#define MAX 100

typedef struct {
    char dados[MAX];
    int topo; 
} Pilha;

void pilha_inicializar(Pilha *p);
int pilha_vazia(Pilha *p);
int pilha_cheia(Pilha *p);
void pilha_empilhar(Pilha *p, char valor);
char pilha_desempilhar(Pilha *p);
int esta_balanceado(char *expressao);

int main(){
    printf("Resultado: %d\n", esta_balanceado("(a+[b*c])"));
    printf("Resultado: %d\n", esta_balanceado("(a+[b*c)]"));
    printf("Resultado: %d\n", esta_balanceado("(a+b"));
    printf("Resultado: %d\n", esta_balanceado("a+b)"));
    printf("Resultado: %d\n", esta_balanceado("[(a+b)*{c-d}]"));
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

void pilha_empilhar(Pilha *p, char valor){
    if(pilha_cheia(p)){
        printf("Erro pilha cheia\n");
        return;
    }
    p->topo++;
    p->dados[p->topo]=valor;
}

char pilha_desempilhar(Pilha *p){
    if(pilha_vazia(p)){
        printf("Erro pilha vazia\n");
        return '\0';
    }
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

int esta_balanceado(char *expressao){
    Pilha p;
    pilha_inicializar(&p);
    for(int i = 0; expressao[i] != '\0'; i++){
        char c = expressao[i];
        if(c == '(' || c == '[' || c == '{'){
            pilha_empilhar(&p,c);
        }       
        else if(c == ')' || c == ']' || c == '}'){
            if(pilha_vazia(&p)){
                return 0;
            }
            char topo = pilha_desempilhar(&p);
            if (c == ')' && topo != '(') return 0;
            if (c == ']' && topo != '[') return 0;
            if (c == '}' && topo != '{') return 0;
        }
    }
    return pilha_vazia(&p);
}
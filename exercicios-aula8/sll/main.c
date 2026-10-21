#include "TLinkedList.h"
#include <stdio.h>

int main() {
    printf("==========================================\n");
    printf("       TESTANDO A LISTA ENCADEADA        \n");
    printf("==========================================\n");

    // 1. Criando e testando inserção comum
    List* lista_comum = SList_create();
    printf("Inserindo no inicio: 50, 40\n");
    SList_Insert_Begin(lista_comum, 50);
    SList_Insert_Begin(lista_comum, 40);
    
    printf("Inserindo no fim: 60, 70\n");
    Slist_Insert_end(lista_comum, 60);
    Slist_Insert_end(lista_comum, 70);
    
    printf("Lista Comum Atual: ");
    Slist_Print(lista_comum);
    SList_destroy(lista_comum);
    printf("\n");

    // 2. Testando a inserção ordenada (O foco principal)
    List* lista_ordenada = SList_create();
    printf("Inserindo de forma desordenada no codigo:\n");
    printf("-> Inserindo 25\n"); Slist_Insert_ordered(lista_ordenada, 25);
    printf("-> Inserindo 10\n"); Slist_Insert_ordered(lista_ordenada, 10);
    printf("-> Inserindo 40\n"); Slist_Insert_ordered(lista_ordenada, 40);
    printf("-> Inserindo 5\n");  Slist_Insert_ordered(lista_ordenada, 5);
    printf("-> Inserindo 30\n"); Slist_Insert_ordered(lista_ordenada, 30);

    printf("\nResultado Final (Deve estar em ordem crescente):\n");
    printf("Lista Ordenada: ");
    Slist_Print(lista_ordenada);

    SList_destroy(lista_ordenada);
    printf("Lista liberada com sucesso!\n");
    printf("==========================================\n");

    return 0;
}
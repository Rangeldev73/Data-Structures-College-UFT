#ifndef STACK
#define STACK
#include <stdbool.h>

typedef struct _stack Stack;

Stack* Stack_create();
/**
 * Tenta a inserção de um inteiro em uma stack.
 * @param Stack* ponteiro para uma stack instanciada
 * @param int inteiro a ser inserido na Stack
 * @return bool informando do sucesso da operação
 */
bool Stack_push(Stack*, int);
/**
 * Tenta a remoção do topo da Stack.
 * @param Stack* ponteiro para uma stack instanciada
 * @param int* ponteiro para o valor do topo
 * @return bool informando do sucesso da operação
 */
bool Stack_pop(Stack*, int*);
/**
 * Libera os recursos da pilha.
 * @param Stack* ponteiro para uma stack instanciada
 */
void Stack_destroy(Stack*);
/**
 * Consulta se a pilha está vazia.
 * @param Stack* ponteiro para uma stack instanciada
 */
bool Stack_empty(Stack*);
/**
 * Consulta se a pilha está cheia.
 * @param Stack* ponteiro para uma stack instanciada
 */
bool Stack_is_full(Stack*);
/**
 * Retorna o tamanho da pilha.
 * @param Stack* ponteiro para uma stack instanciada
 */
int getSize(Stack*);
#endif
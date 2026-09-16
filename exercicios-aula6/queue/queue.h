#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct _queue Queue;

Queue* Queue_create();
/**
 * Checa se a Queue está vazia.
 * @param Queue* instância da Queue
 * @return bool informando se está vazia.
 */
bool Queue_empty(Queue*);
/**
 * Checa se a Queue está cheia.
 * @param Queue* instância da Queue
 * @return bool informando se está cheia.
 */
bool Queue_full(Queue*);
/**
 * Tenta inserir um elemnento em uma Queue.
 * @param Queue* ponteiro para uma queue instanciada
 * @param int inteiro a ser inserido na Queue
 * @return bool informando do sucesso da operação.
 */
bool Queue_enqueue(Queue*, int);
/**
* Tenta remover um elemnento em uma Queue.
* @param Queue* ponteiro para uma queue instanciada
* @param int  ponteiro para variável inteira que receberá o valor removido da Queue
* @return bool informando do sucesso da operação.
*/
bool Queue_dequeue(Queue*, int*);
/**
 * Retorna a quantidade de elementos atualmente na Queue
 * @param Queue* instância da Queue
 * @return unsigned int : Quantidade de elementos presentes na Queue.
 */
unsigned int getSize(Queue*);
#endif
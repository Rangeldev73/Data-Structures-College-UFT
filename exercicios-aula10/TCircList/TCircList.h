#ifndef TCLIST_H
#define TCLIST_H
#include <stdbool.h>
/**
TAD Lista circular simplesmente encadeada.
*/
typedef struct _list TCList;
/**
 * Cria instâncias da TCList;
 */
TCList* TCList_create();
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TCList_insert_end(TCList*, int);

bool TCList_insert_begin(TCList*, int);
/**
 * Imprime a lista do início para o fim.
 */
void TCList_print(TCList*);
#endif
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h> 

typedef struct _list List;

List* List_create(size_t data_size, void (*fp)(void*));

bool List_insert_begin(List* lista, void* info);
bool List_insert_end(List* lista, void* info);
void List_print(List* lista);
void List_destroy(List* lista); 
#endif
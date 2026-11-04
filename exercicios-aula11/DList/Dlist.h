#ifndef DLIST_H
#define DLIST_H
#include <stdbool.h>

typedef struct _list List;

List* List_create();
bool List_Insert_Begin(List*, int);
bool List_Insert_End(List*, int);
void List_print(List*);
void List_reverse_print(List*);

#endif

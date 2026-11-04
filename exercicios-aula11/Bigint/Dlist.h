#ifndef DLIST_H
#define DLIST_H
#include <stdbool.h>

typedef struct _list List;

List* List_create();
bool List_Insert_Begin(List*, int);
bool List_Insert_End(List*, int);
void List_print(List*);
void List_reverse_print(List*);

List* List_from_string(char* str);
List* List_sum(List* l1, List* l2);
void List_print_bigint(List* l);

#endif

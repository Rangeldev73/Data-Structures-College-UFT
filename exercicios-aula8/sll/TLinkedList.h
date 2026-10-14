#ifndef SLIST_H
#define SLIST_H
#include <stdbool.h>

typedef struct _list List;

List* SList_create();

bool SList_Insert_Begin(List*, int);

void Slist_Print(List*);
#endif
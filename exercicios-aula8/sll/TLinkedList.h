#ifndef SLIST_H
#define SLIST_H
#include <stdbool.h>

typedef struct _list List;

List* SList_create();

bool SList_Insert_Begin(List*, int);

bool Slist_Insert_end(List*, int);

bool Slist_Insert_ordered(List*, int);

bool Slist_Search_n_Destroy(List*, int);

void Slist_Print(List*);

void SList_destroy(List*);
#endif
#ifndef SBS_H
#define SBS_H
#include <stdbool.h>

typedef struct _list List;

List* SList_create();
bool Slist_Insert_End(List*, int, int);
int SList_Size(List*);
void Slist_Print_SBS(List*);
void SList_destroy(List*);

#endif
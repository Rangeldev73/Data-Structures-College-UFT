#include "TLinkedList.h"
#include <stdio.h>

int main() {
    int v[] = {1,2,3,4,5};
    List* l = SList_create();
    for(int i=0;i<5;i++) {
        if(!SList_Insert_Begin(l,v[i])) printf("Error inserting v[%i]=%i\n", i, v[i]);
    }
    Slist_Print(l);
    return 0;
}
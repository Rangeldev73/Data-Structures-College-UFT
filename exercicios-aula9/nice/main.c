#include <stdio.h>
#include <stdlib.h>
#include "nice.h"

int main() {
    List* solution = SList_create();
    int number;
    
    scanf("%d", &number);
    
    Slist_Insert_end(solution, number);
    int current = number;
    
    while(current >= 10) {
        List* digits = SList_create();
        int temp = current;
        
        while(temp > 0) {
            SList_Insert_Begin(digits, temp % 10);
            temp /= 10;
        }
        
        current = Slist_Nice(digits);
        SList_destroy(digits);
        Slist_Insert_end(solution, current);
    }
    
    Slist_Print(solution);
    
    if(current == 1) printf("bacana\n"); 
    else printf("non-bacana\n");

    
    SList_destroy(solution);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sbs.h"

int main() {
    char str[10002]; 
    if(fgets(str, sizeof(str), stdin) == NULL) return 0;
    int len = strlen(str);
       
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    if(len == 0) return 0;

    List* sbs_list = SList_create();

    int i = 0;
    while(i < len) {
        char current_char = str[i];
        int run_length = 0;

        while(i < len && str[i] == current_char) {
            run_length++;
            i++;
        }

        int binary_value = current_char - '0';

        Slist_Insert_End(sbs_list, run_length, binary_value);
    }

    Slist_Print_SBS(sbs_list);

    SList_destroy(sbs_list);

    return 0;
}
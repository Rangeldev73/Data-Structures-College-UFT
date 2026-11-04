#include "Dlist.h"
#include <stdio.h>
#include <string.h>
int main() {
    char str1[4096];
    char str2[4096];
    fgets(str1,4096,stdin);
    fgets(str2,4096,stdin);

    List* number1 = List_from_string(str1);
    List* number2 = List_from_string(str2);

    List* result = List_sum(number1, number2);
    List_print_bigint(result);
    return 0;
}
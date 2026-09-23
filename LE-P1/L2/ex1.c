#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ex1(Stack* s, char sent[]) {
    if (!s || !sent) return false;
    int c;

    for (int i = 0; sent[i] != '\0'; i++) {
        if (sent[i] != ' ' && sent[i] != '.') {
            Stack_push(s, sent[i]);
        }
        else {
            while (Stack_pop(s, &c)) {
                printf("%c", (char)c);
            }
            if (sent[i] == ' ') {
                printf(" ");
            } 
            else if (sent[i] == '.') {
                printf(".");
                break;
            }
        }
    }
    while (Stack_pop(s, &c)) {
        printf("%c", (char)c);
    }
    printf("\n");
    return true;
}
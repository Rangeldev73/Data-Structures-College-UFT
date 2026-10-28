#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        TCList* l = TCList_create();

        for(int i = 1; i <= n; i++) {
            TCList_insert(l, i);
        }
        int winner = TCList_resolve_edmundo(l, m);
        printf("%d\n", winner);
    }
    return 0;
}
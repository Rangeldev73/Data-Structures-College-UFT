#include "BankAccount.h"
#include <stdio.h>

int main() {
    BankAccount* a1 = BA_create(21,"name", 8291);
    BankAccount* a2 = BA_create(41,"oeke", 843);

    BA_deposit(a1,200);
    BA_withdraw(a2,20);

    BA_transfer(a1,a2,5032);

    printf("Final balance of name account: %.2f\n", BA_getB(a1));
    printf("Final balance of oeke account: %.2f\n", BA_getB(a2));
    BA_free(a1);
    BA_free(a2);
    return 0;
}
#include "BankAccount.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _bankaccount {
    int an;
    char name[41];
    float balance;
};

BankAccount* BA_create(int an, char* name, float bal) {
    if(!name) return NULL;
    BankAccount* ba = malloc(sizeof(BankAccount));
    if(!ba) return NULL;
    ba->an = an;
    strncpy(ba->name, name, 40);
    ba->name[40] = '\0';
    ba->balance = bal;
    return ba;
}

bool BA_deposit(BankAccount* b, float val) {
    if(!b) return false;
    if(val<=0) return false;
    b->balance+=val;
    return true;
}

bool BA_withdraw(BankAccount* b, float val) {
    if(!b) return false;
    if(val<=0||b->balance<val) return false;
    b->balance-=val;
    return true;
}

float BA_getB(BankAccount* b) {
    if(!b) return -1;
    return b->balance;
}

bool BA_transfer(BankAccount* b1, BankAccount* b2, float val) {
    if(!b1||!b2) return false;
    if(val<=0) return false;
    if(!BA_withdraw(b1,val)) return false;
    BA_deposit(b2,val);
    return true;
}

void BA_free(BankAccount* b) {
    free(b);
}
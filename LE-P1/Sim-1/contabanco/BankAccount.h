#ifndef BANKACOUNT_H
#define BANKACOUNT_H
#include <stdbool.h>

typedef struct _bankaccount BankAccount;

BankAccount* BA_create(int an, char* name, float b);
bool BA_deposit(BankAccount* b, float val);
bool BA_withdraw(BankAccount* b, float val);
float BA_getB(BankAccount* b);
bool BA_transfer(BankAccount* b1, BankAccount* b2, float val);
void BA_free(BankAccount* b);
#endif
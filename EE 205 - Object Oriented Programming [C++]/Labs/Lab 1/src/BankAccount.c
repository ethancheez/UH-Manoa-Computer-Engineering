#include "BankAccount.h"
#include <stdio.h>

struct BankAccount {
    double balance;
    double last_withdrawl;
    double last_deposit;
};

/*
 * Implement the definitions for the
 * functions involving BankAccount from BankAccount.h here,
 *
 * Make sure to produce comments that look like this!
 * (Try to copy the formatting.)
 *
 * For BankAccount_construct() and BankAccount_destroy(),
 * if you do not remember malloc() and free(), review them
 * by creating a toy program.
 */

BankAccount* BankAccount_construct(double balance) {
    struct BankAccount *a = (struct BankAccount*) malloc(sizeof(struct BankAccount));
    a -> balance = balance;
    a -> last_withdrawl = 0;
    a -> last_deposit = 0;
    return a;
}

void BankAccount_destroy(BankAccount* ba) {
    free(ba);
}

int BankAccount_deposit(BankAccount* ba, double amount) {
    ba -> balance += amount;
    ba -> last_deposit = amount;
    return ba -> balance;
}

int BankAccount_withdraw(BankAccount* ba, double amount) {
    ba -> balance -= amount;
    ba -> last_withdrawl = amount;
    return ba -> balance;
}

double BankAccount_get_balance(BankAccount* ba) {
    return ba -> balance;
}

double BankAccount_get_last_deposit(BankAccount* ba) {
    return ba -> last_deposit;
}

double BankAccount_get_last_withdrawal(BankAccount* ba) {
    return ba -> last_withdrawl;
}

/*
int main() {

    double lastDeposit = 0;

    struct BankAccount *a = BankAccount_construct(1000);
    BankAccount_deposit(a, 50);
    printf("Last Deposit: %lf\n", BankAccount_get_last_deposit(a));
    printf("%lf\n", a -> balance);
    
    
    
    BankAccount_destroy(a);
    
}
*/ 



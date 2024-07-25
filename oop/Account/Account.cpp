#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

void Account::deposit(double amount) {
    if (amount < 0) {
        throw IllegalBalanceException();
    } else {
        balance += amount;
    }
}

void Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
    } else {
        throw InsufficientFundsException();
    }
}

double Account::get_balance() const {
    return balance;
}

void Account::print(std::ostream &os) const{
    os << "Account: " << name << " with balance: " << balance; 
}
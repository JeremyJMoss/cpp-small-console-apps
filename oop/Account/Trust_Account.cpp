#include "Trust_Account.h"
#include "InsufficientFundsException.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
    : Savings_Account(name, balance, interest_rate), number_of_withdrawals{0}{};

void Trust_Account::deposit(double amount){
    if (amount > 5000){
        amount += 50;
    }
    Savings_Account::deposit(amount);
}

void Trust_Account::withdraw(double amount){
    if (this->number_of_withdrawals > 3 || amount / this->get_balance() >= 0.2){
        throw InsufficientFundsException();
    }
    Savings_Account::withdraw(amount);
    this->number_of_withdrawals++;
}

void Trust_Account::print(std::ostream &os) const{
    os << "Trust Account: " << name << " with balance: " << balance << " interest rate: " << int_rate << " number of withdrawals: " << number_of_withdrawals; 
}


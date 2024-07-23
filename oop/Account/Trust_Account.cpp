#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double interest_rate)
    : Savings_Account(name, balance, interest_rate), number_of_withdrawals{0}{};

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

bool Trust_Account::deposit(double amount){
    if (amount > 5000){
        amount += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if (this->number_of_withdrawals > 3 || amount / this->get_balance() >= 0.2){
        return false;
    }
    if (Savings_Account::withdraw(amount)){
        this->number_of_withdrawals++;
        return true;
    }
    return false;
}


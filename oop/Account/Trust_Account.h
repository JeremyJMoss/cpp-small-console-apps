#pragma once
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
    protected:
        int number_of_withdrawals;
    public:
        Trust_Account(std::string name = "Unnamed Account", double balance = 0.0, double interest_rate = 0.0);
        bool deposit(double amount);
        bool withdraw(double amount);
};
#pragma once
#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
    public:
        Checking_Account(std::string name = "Unnamed Account", double balance = 0.0);
        bool withdraw(double amount);
};
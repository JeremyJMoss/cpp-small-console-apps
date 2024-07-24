#pragma once
#include "Account.h"

class Savings_Account: public Account {
    protected:
        double int_rate;
    public:
        Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double int_rate = 0.0);    
        virtual ~Savings_Account() = default;
        virtual bool deposit(double amount) override;
        virtual void print(std::ostream &os) const override;
};


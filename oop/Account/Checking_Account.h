#pragma once
#include "Account.h"

class Checking_Account: public Account {
    public:
        Checking_Account(std::string name = "Unnamed Account", double balance = 0.0);
        virtual ~Checking_Account() = default; 
        virtual bool withdraw(double amount) override;
        virtual void print(std::ostream &os) const override;
};
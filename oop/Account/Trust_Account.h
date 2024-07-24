#pragma once
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    protected:
        int number_of_withdrawals;
    public:
        Trust_Account(std::string name = "Unnamed Account", double balance = 0.0, double interest_rate = 0.0);
        virtual ~Trust_Account() = default;
        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        virtual void print(std::ostream &os) const override;
};
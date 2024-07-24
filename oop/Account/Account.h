#pragma once
#include "I_Printable.h"
#include <iostream>
#include <string>

class Account: public I_Printable{
    protected:
        std::string name;
        double balance;
    public:
        Account(std::string name = "Unnamed Account", double balance = 0.0);
        virtual ~Account() = default;
        virtual bool deposit(double amount);
        virtual bool withdraw(double amount);
        double get_balance() const;
        void print(std::ostream &os) const override;
};
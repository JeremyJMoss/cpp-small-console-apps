#include <iostream>
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

void display(const std::vector<Account*> &accounts) {
    std::cout << "\n=== Accounts ==========================================" << std::endl;
    for (const auto acc: accounts) 
        std::cout << *acc << std::endl;
}

void deposit(std::vector<Account*> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto acc:accounts)  {
        try{
            acc->deposit(amount);
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        }
        catch(IllegalBalanceException &ex){
            std::cout << ex.what() << std::endl;;
        }
    }
}

void withdraw(std::vector<Account*> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto acc:accounts)  {
        try{
            acc->withdraw(amount);
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        } 
        catch (InsufficientFundsException &ex){
            std::cout << ex.what() << std::endl;
        }
    } 
}
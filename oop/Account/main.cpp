#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    
    // Savings 

    vector<Account*> sav_accounts;
    Account *savings_acc1 = new Savings_Account();
    Account *savings_acc2 = new Savings_Account("Superman");
    Account *savings_acc3 = new Savings_Account("Batman", 2000);
    Account *savings_acc4 = new Savings_Account("Wonderwoman", 5000, 5.0);
    sav_accounts.push_back(savings_acc1);
    sav_accounts.push_back(savings_acc2);
    sav_accounts.push_back(savings_acc3);
    sav_accounts.push_back(savings_acc4);

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    delete savings_acc1;
    delete savings_acc2;
    delete savings_acc3;
    delete savings_acc4;

    // Checking 

    Account *check_acc1 = new Checking_Account();
    Account *check_acc2 = new Checking_Account("Superman");
    Account *check_acc3 = new Checking_Account("Batman", 2000);
    Account *check_acc4 = new Checking_Account("Wonderwoman", 5000);
    
    vector<Account*> check_accounts;
    check_accounts.push_back(check_acc1);
    check_accounts.push_back(check_acc2);
    check_accounts.push_back(check_acc3);
    check_accounts.push_back(check_acc4);

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    delete check_acc1;
    delete check_acc2;
    delete check_acc3;
    delete check_acc4;

    // Trust 

    Account *trust_acc1 = new Trust_Account();
    Account *trust_acc2 = new Trust_Account("Superman");
    Account *trust_acc3 = new Trust_Account("Batman", 2000);
    Account *trust_acc4 = new Trust_Account("Wonderwoman", 5000, 5.0);
    
    vector<Account*> trust_accounts;
    trust_accounts.push_back(trust_acc1);
    trust_accounts.push_back(trust_acc2);
    trust_accounts.push_back(trust_acc3);
    trust_accounts.push_back(trust_acc4);

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 2000);

    delete trust_acc1;
    delete trust_acc2;
    delete trust_acc3;
    delete trust_acc4;

    return 0;
}


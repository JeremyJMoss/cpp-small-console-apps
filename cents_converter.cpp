#include <iostream>

void cent_breakdown(int cents);

int main() {
    std::cout << "Please enter the amount of cents to be converted: ";
    int cents;
    std::cin >> cents;
    cent_breakdown(cents);

    return 0;
}

void cent_breakdown(int cents){
    const int dollar = 100;
    const int quarter = 25;
    const int dime = 10;
    const int nickel = 5;

    int dollars = cents / dollar;
    int leftover = cents % dollar;
    int quarters = leftover / quarter;
    leftover %= quarter;
    int dimes = leftover / dime;
    leftover %= dime;
    int nickels = leftover / nickel;
    leftover %= nickel;
    int pennies = leftover;

    std::cout << "dollars: " << dollars << std::endl;
    std::cout << "quarters: " << quarters << std::endl;
    std::cout << "dimes: " << dimes << std::endl;
    std::cout << "nickels: " << nickels << std::endl;
    std::cout << "pennies: " << pennies << std::endl;
}
#include <iostream>
#include <iomanip>

double a_penny_doubled_everyday(int, double = 0.01);

int main() {
    int days = 25;
    double total_amount = a_penny_doubled_everyday(days);
    std::cout <<  "If I start with a penny and doubled it every day for " << days << " days, I will have $" << std::setprecision(10) << total_amount << std::endl;
    return 0;
}

double a_penny_doubled_everyday(int number_of_days, double amount) {
    if (number_of_days == 1){
        return amount;
    }
    return a_penny_doubled_everyday(number_of_days - 1, (amount * 2));
}

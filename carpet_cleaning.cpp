#include <iostream>

int main() {
    const float sm_room_charge = 25.0f;
    const float lg_room_charge = 35.0f;
    const float sales_tax = 0.06f;
    const int days_valid = 30;
    int amount_large;
    int amount_small;

    std::cout << "Frank's Carpet Cleaning Service\n";
    std::cout << "How many small rooms would you like cleaned: ";
    std::cin >> amount_small;
    std::cout << "How many large rooms would you like cleaned: ";
    std::cin >> amount_large;
    float cost = amount_small * sm_room_charge + amount_large * lg_room_charge;
    float tax = cost * sales_tax;
    std::cout << "\nEstimate for carpet cleaning service" << std::endl;
    std::cout << "Number of small rooms: " << amount_small << std::endl;
    std::cout << "Number of large rooms: " << amount_large << std::endl;
    std::cout << "Price per small room: $" << sm_room_charge << std::endl;
    std::cout << "Price per large room: $" << lg_room_charge << std::endl;
    std::cout << "Cost: $" << cost << std::endl;
    std::cout << "Tax: $" << tax << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Total estimate: $" << cost + tax << std::endl;
    std::cout << "This estimate is valid for " << days_valid << " days" << std::endl;
    
    return 0;
}
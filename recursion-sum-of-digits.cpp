#include <iostream>
#include <string>

int sum_of_digits(int n);

int main(){
    std::cout << sum_of_digits(1234) << std::endl;
    return 0;
}

int sum_of_digits(int n) {
    
    if (n / 10 == 0){
        return n;
    }
    
    return n % 10 + sum_of_digits(n / 10);
}
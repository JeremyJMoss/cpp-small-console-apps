#include <iostream>

int factorial(int num);

int main(){
    std::cout << factorial(7) << std::endl;
    return 0;
}

int factorial(int num){
    if (num == 0){
        return 1;
    }
    return num * factorial(num - 1);
}
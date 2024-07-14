#include <iostream>

int fibernacci(int num);

int main(){
    std::cout << fibernacci(40) << std::endl;
    return 0;
}

int fibernacci(int num){
    if (num <= 1){
        return num;
    }
    return fibernacci(num -1) + fibernacci(num - 2);
}


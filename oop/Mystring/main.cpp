#include <iostream>
#include "Mystring.h"

int main(){
    Mystring word("Hello");
    std::cout << word.get_str() << std::endl;
    Mystring multiplied = word * 3;
    std::cout << multiplied.get_str() << std::endl;
    multiplied += word;
    std::cout << multiplied.get_str() << std::endl;
    Mystring more_multiplied = multiplied + word;
    std::cout << more_multiplied.get_str() << std::endl;
    Mystring lower = -more_multiplied;
    std::cout << lower.get_str() << std::endl;
    if (more_multiplied == lower){
        std::cout << "equal" << std::endl;
    } else { 
        std::cout << "not equal" << std::endl;
    }
    lower *= 2;
    std::cout << lower.get_str() << std::endl;
    return 0;
}
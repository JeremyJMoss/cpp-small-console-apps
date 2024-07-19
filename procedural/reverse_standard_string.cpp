#include <iostream>
#include <string>

std::string reverse_standard_string(const std::string &str);

int main(){
    std::string input = "Hello, World!";
    std::string reversed = reverse_standard_string(input);
    std::cout << reversed << std::endl;
    return 0;
}

std::string reverse_standard_string(const std::string &str) {
    std::string reversed;
    // Write your code below this line 
    for (int i = 0; i < str.length(); i++){
        reversed.push_back(str.at(str.length() - 1 - i));
    }
    // Write your code abocve this line
    return reversed;
}
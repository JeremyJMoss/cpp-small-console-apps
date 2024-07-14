#include <iostream>
#include <string>
#include <limits>

int main(){
    std::string alphabet = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string cipher_key = {"TzmUkVxDoBiNHsQRgfJEvOhKpMnlZtLAwbqjYPcWuyCdSXreFGaI"}; 
    
    std::string type {};
    std::string input {};
     std::string extracted_string {};

    std::cout << "Would you like to encrypt or decrypt? e for encrypt d for decrypt: ";
    std::cin >> type;
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "What would you like to ";
    if (type == "e" || type == "E"){
        std::cout << "encrypt? ";
    } else if(type == "d" || type == "D"){
        std::cout << "decrypt? ";
    }

    std::getline(std::cin, input);

    if (type == "e" || type == "E"){
        for (std::size_t i = 0; i < input.length(); i++){
            std::size_t index = alphabet.find(input[i]);
            if (index != std::string::npos){
                extracted_string += cipher_key[index];
            } else {
                extracted_string += input[i];
            }
        }
    } else if(type == "d" || type == "D"){
        for (std::size_t i = 0; i < input.length(); i++){
            std::size_t index = cipher_key.find(input[i]);
            if (index != std::string::npos){
                extracted_string += alphabet[index];
            } else {
                extracted_string += input[i];
            }
        }
    }

    std::cout << extracted_string << std::endl;

    return 0;
}
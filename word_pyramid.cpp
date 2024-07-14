#include <iostream>
#include <string>

int main(){

    std::string input {};
    std::cin >> input;
    
    for (std::size_t i = 0; i < input.length(); i++){
        int j = input.length() - 1;
        bool reverse = true;
        while(j < input.length()){
            if (i >= j){
                std::cout << input[j];
            }
            else {
                std::cout << " ";
            }
            if (j == 0){
                reverse = false;
            }

            reverse ? j-- : j++;
        }
        std::cout << std::endl;
    }

    return 0; 
}

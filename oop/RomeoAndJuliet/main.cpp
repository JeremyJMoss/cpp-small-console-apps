#include <iostream>
#include <fstream>

int main() {
    std::fstream in_file {"romeoandjuliet.txt"};
    if (!in_file){
        std::cerr << "Error opening file";
        return 1;
    }
    std::string substring;
    std::cout << "Enter the substring to search for: ";
    std::cin >> substring;
    
    std::string word;
    int word_count = 0;
    int matched_words = 0;
    while(in_file >> word){
        word_count++;
        //jump out if word is not as long as the substring specified
        if (word.length() < substring.length()){
            continue;
        }

        for (std::size_t i = 0; i <= word.length() - substring.length(); ++i) {
            std::size_t j;
            for (j = 0; j < substring.length(); ++j) {
                if (word[i + j] != substring[j]) {
                    break;
                }
            }
            // if made it through inner loop then substring must have matched to the word
            if (j == substring.length()) {
                matched_words++;
                break;
            }
        }
    }
    in_file.close();
    
    std::cout << word_count << " words were searched..." << std::endl;
    std::cout << "The substring " << substring << " was found " << matched_words << " times" << std::endl;
    std::cout << std::endl;
    return 0;
}


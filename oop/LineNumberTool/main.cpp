#include <iostream>
#include <fstream>

int main() {
    std::ofstream out_file {"romeoandjulietwithlinenumbers.txt"};
    std::ifstream in_file {"romeoandjuliet.txt"};
    if (!in_file){
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    if (!out_file){
        std::cerr << "Error opening or creating output file." << std::endl;
        return 1;
    }
    std::string line;
    int count = 1;
    while (std::getline(in_file, line)){
        out_file << count++ << " " << line << std::endl; 
    }
    
    return 0;
}
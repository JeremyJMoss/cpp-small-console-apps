#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

void print_header(int column_width) {
     std::cout << std::setw(column_width) << std::left << "Student"
              << std::setw(column_width / 2) << std::right << "Score" << std::endl
              << std::setw(column_width + 0.5 * column_width) << std::setfill('-') << "" << std::endl;
}

void print_footer(double average, int column_width){
    std::cout << std::left << std::setw(column_width) << std::setfill(' ') << "Average score" 
              << std::right << std::setw(column_width / 2) << std::setprecision(1) << std::fixed <<  average << std::endl << std::endl;
}

int get_result(const std::string &response, const std::string &answers){
    int score = 0;
    for (std::size_t i = 0; i < answers.length(); i++){
        if (response[i] == answers[i]){
            score++;
        }
    }
    return score;
}

double get_average(const std::vector<int> &scores){
    int sum = 0;
    for (int score: scores){
        sum += score;
    }
    double average = static_cast<double>(sum) / scores.size();
    return average;
}

int main(){
    std::fstream in_file {"responses.txt"};
    if (!in_file){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string correct_answers;
    std::getline(in_file, correct_answers);

    int column_width = 16;

    print_header(column_width);

    std::string student;
    std::string answers;
    std::vector<int> scores{};
    while(in_file >> student >> answers){
        std::cout << std::setfill(' ') << std::setw(column_width) << std::left << student;
        int score = get_result(answers, correct_answers);
        std::cout << std::setw(column_width / 2) << std::right << score << std::endl;
        scores.push_back(score);
    }
    std::cout << std::setw(column_width + 0.5 * column_width) << std::setfill('-') << "" << std::endl << std::endl;
    double average = get_average(scores);
    
    print_footer(average, column_width);

    in_file.close();
    return 0;
}
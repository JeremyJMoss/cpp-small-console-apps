#include <iostream>
#include <memory>
#include <vector>
#include "Test.h"

auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);


int main(){
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

auto make(){
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num){
    for (std::size_t i = 0; i < num; i++){
        std::cout << "Enter data point [" << i+1 << "]: ";
        int data_point;
        std::cin >> data_point;
        vec.push_back(std::make_shared<Test>(data_point));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec){
    std::cout << "\nDisplaying vector data" << std::endl;
    std::cout << "====================" << std::endl;
    for (std::size_t i = 0; i < vec.size(); i++){
        std::cout << vec.at(i)->get_data() << std::endl;
    }
    std::cout << "====================" << std::endl;
}
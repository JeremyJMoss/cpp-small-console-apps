#include <iostream>
#include <vector>

void displayMenu();
void printList(const std::vector<std::size_t> &list);
void addToList(std::vector<std::size_t> &list);
void displayMean(const std::vector<std::size_t> &list);
void displayElement(const std::vector<std::size_t> &list, std::string type);

int main(){
    char input;
    std::vector<std::size_t> list;
    
    while(input != 'q' && input != 'Q'){
        displayMenu();    
        std::cin >> input;

        switch (input){
            case 'q':
            case 'Q':
                std::cout << "Goodbye" << std::endl;
                break;
            case 'P':
            case 'p':
                printList(list);
                break;
            case 'a':
            case 'A':
                addToList(list);
                break;
            case 'm':
            case 'M':
                displayMean(list);
                break;
            case 's':
            case 'S':
                displayElement(list, "smallest");
                break;
            case 'L':
            case 'l':
                displayElement(list, "largest");
                break;
            default:
                std::cout << "Unknown selection, please try again" << std::endl;
        }
    }
    
    return 0;
}

void displayMenu() {
    std::cout << "\nP - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "Q = Quit" << std::endl;
    std::cout << "\n\nEnter your choice: ";   
}

void printList(const std::vector<std::size_t> &list){
    if (list.size() == 0){
        std::cout << "[] - the list is empty" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (std::size_t num: list){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

void addToList(std::vector<std::size_t> &list){
    std::size_t newNum;
    std::cout << "Enter a number to add to the list: ";
    std::cin >> newNum;

    list.push_back(newNum);

    std::cout << newNum << " added" << std::endl;
}

void displayMean(const std::vector<std::size_t> &list){
    std::size_t size = list.size();
    double mean = 0;
    if (size != 0){
        std::size_t total = 0;
        for (std::size_t num : list){
            total += num;
        }
        mean = (double) total / size;
    }
    if (mean <= 0){
        std::cout << "Unable to calculate the mean - no data" << std::endl;
    } else {
        std::cout << "The mean is " << mean << std::endl;
    }
}

void displayElement(const std::vector<std::size_t> &list, std::string type){
    if (list.size() == 0){
        std::cout << "Unable to determine the " << type << " number - list is empty" << std::endl;
    }
    std::size_t element = list.at(0);
    if (type == "smallest"){
        for (std::size_t i = 1; i < list.size(); i++){
            if (list.at(i) < element){
                element = list.at(i);
            }
        }    
    }
    else if (type == "largest"){
        for (std::size_t i = 1; i < list.size(); i++){
            if (list.at(i) > element){
                element = list.at(i);
            }
        }
    }
    std::cout << "The " << type << " number is " << element << std::endl;
}
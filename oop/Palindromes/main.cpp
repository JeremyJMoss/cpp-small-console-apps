#include <iostream>
#include <deque>

bool is_palindrome(const std::string &s);

int main(){
    std::cout << is_palindrome("Hello");
    std::cout << is_palindrome("racecar");
    std::cout << is_palindrome("Racecar");
    std::cout << is_palindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!");
    return 0;
}

bool is_palindrome(const std::string &s){
    std::deque<char> d {};
    for (char c : s){
        if (!std::isalpha(c)){
            continue;
        }
        d.push_back(std::toupper(c));
    }
    for (int i = 0; i < (d.size() / 2); i++){
        if (d.back() != d.front()){
            return false;
        }
        d.pop_front();
        d.pop_back();
    }
    return true;
}
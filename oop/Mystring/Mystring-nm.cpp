#include <iostream>
#include <cstring>
#include "Mystring-nm.h"

Mystring::Mystring() : str(nullptr){
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char* initial) : str(nullptr) {
    if (initial == nullptr){
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(initial) + 1];
        std::strcpy(str, initial);
    }
}

Mystring::Mystring(const Mystring &source) : str(nullptr) {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) : str(source.str) {
    source.str = nullptr;
}

Mystring::~Mystring(){
    delete [] str;
}

Mystring Mystring::operator=(const Mystring &rhs){
    if (this == &rhs){
        return *this;
    }
    delete [] this->str;
    this->str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

Mystring Mystring::operator=(Mystring &&rhs){
    if (this == &rhs){
        return *this;
    }
    delete [] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring operator-(const Mystring &obj){
    char * buff = new char[std::strlen(obj.str) + 1];
    for (std::size_t i = 0; i < std::strlen(obj.str); i++){
        *(buff + i) = std::tolower(*(obj.str + i));
    }
    Mystring return_value(buff);
    delete[] buff;
    return return_value;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return !(lhs == rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str) == -1);
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str) == 1);
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring return_value(buff);
    delete [] buff;
    return return_value;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs){
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring &lhs, const int num){
    char* buff = new char[(std::strlen(lhs.str) * num) + 1];
    Mystring return_value(buff);
    for (int i = 0; i < num; i++){
        return_value += lhs;
    }
    delete[] buff;
    return return_value;
}

Mystring &operator*=(Mystring &lhs, const int num){
    lhs = lhs * num;
    return lhs;
}

const char* Mystring::get_str() const {
    return this->str;
}
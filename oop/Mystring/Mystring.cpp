#include <iostream>
#include <cstring>
#include "Mystring.h"

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

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(this->str) + 1];
    for (std::size_t i = 0; i < std::strlen(this->str); i++){
        *(buff + i) = std::tolower(*(this->str + i));
    }
    Mystring return_value(buff);
    delete [] buff;
    return return_value;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return !(this == &rhs);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == -1);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 1);
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char* buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring return_value(buff);
    delete [] buff;
    return return_value;
}

Mystring &Mystring::operator+=(const Mystring &rhs){
    *this = *this + rhs;
    return *this;
}

Mystring Mystring::operator*(const int num) const {
    char* buff = new char[(std::strlen(this->str)* num) + 1];
    Mystring return_value(buff);
    for (int i = 0; i < num; i++){
        return_value += *this;
    }
    delete [] buff;
    return return_value;
}

Mystring &Mystring::operator*=(const int num) {
    *this = *this * num;
    return *this;
}

const char* Mystring::get_str() const{
    return this->str;
}
#pragma once
#include <iostream>

class Mystring {
    friend Mystring operator-(const Mystring &obj);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, const int num);
    friend Mystring &operator*=(Mystring &lhs, const int num);

    private:
        char* str;
    public:
        Mystring(); // No-args constructor
        Mystring(const char *initial); //Overloaded constructor
        Mystring(const Mystring &source); //Copy constructor
        Mystring(Mystring &&source); //Move constructor
        ~Mystring();
        Mystring operator=(const Mystring &rhs);
        Mystring operator=(Mystring &&rhs);
        const char* get_str() const;
};

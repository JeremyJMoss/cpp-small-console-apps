#pragma once
#include <iostream>

class Mystring{
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
        Mystring operator-() const;
        bool operator==(const Mystring &rhs) const;
        bool operator!=(const Mystring &rhs) const;
        bool operator<(const Mystring &rhs) const;
        bool operator>(const Mystring &rhs) const;
        Mystring operator+(const Mystring &rhs) const;
        Mystring &operator+=(const Mystring &rhs);
        Mystring operator*(const int num) const;
        Mystring &operator*=(const int num);
        const char* get_str() const;
};
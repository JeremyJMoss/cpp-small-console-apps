#pragma once
#include <iostream>
#include <exception>

class InsufficientFundsException: public std::exception{
    public:
        InsufficientFundsException() = default;
        ~InsufficientFundsException() = default;
        const char* what() const noexcept override;
};
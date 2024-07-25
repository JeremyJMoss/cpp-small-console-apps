#include "IllegalBalanceException.h"

const char* IllegalBalanceException::what() const noexcept{
    return "Balance cannot be negative";
}
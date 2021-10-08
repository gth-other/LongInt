#include "LongInt.hpp"


LongInt LongInt::_factorial_tree(LongInt number_first, const LongInt& number_second) {
    if (number_first > number_second) {
        return 1;
    }
    if (number_first == number_second) {
        return number_first;
    }
    if (number_second - number_first == 1) {
        return number_first * number_second;
    }
    LongInt tmp = (number_first + number_second) / 2;
    return LongInt::_factorial_tree(number_first, tmp) * LongInt::_factorial_tree(tmp + 1, number_second);
}
LongInt LongInt::factorial(LongInt number) {
    if (number < 1) {
        throw "Fatal error. The factorial calculation from the specified number is not possible. The specified number is less than or equal to zero.";
    }
    if (number == 1 or number == 2) {
        return number;
    }
    return _factorial_tree(2, number);
}
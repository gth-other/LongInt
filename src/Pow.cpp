#include "LongInt.hpp"


LongInt LongInt::pow(LongInt number_first, LongInt number_second) {
    if (number_first == 0 and number_second == 0) {
        throw "Fatal error. Exponentiation is not possible. Cannot raise zero to zero degree.";
    }
    if (number_second < 0) {
        throw "Fatal error. Exponentiation is not possible. Specified number is less than zero.";
    }
    LongInt result = 1;
    while (number_second != 0) {
        if (even(number_second)) {
            number_second = number_second / 2;
            number_first = number_first * number_first;
        }
        else {
            number_second = number_second - 1;
            result = result * number_first;
        }
    }
    return result;
}
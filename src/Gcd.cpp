#include "LongInt.hpp"


LongInt LongInt::gcd(LongInt number_first, LongInt number_second) {
    if (number_first == 0 and number_second == 0) {
        throw "Fatal error. Counting the greatest common divisor is not possible. Both numbers are zero.";
    }
    number_first._sign = true;
    number_second._sign = true;
    if (number_first == 0) {
        return number_second;
    }
    if (number_second == 0) {
        return number_first;
    }
    while (number_first != 0 and number_second != 0) {
        if (number_first > number_second) {
            number_first = number_first % number_second;
        }
        else {
            number_second = number_second % number_first;
        }
    }
    return number_first + number_second;
}
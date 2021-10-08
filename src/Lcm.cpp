#include "LongInt.hpp"


LongInt LongInt::lcm(LongInt number_first, LongInt number_second) {
    if (number_first == 0 or number_second == 0) {
        throw "Fatal error. Calculating the least common multiple is not possible. One of the numbers is zero.";
    }
    number_first._sign = true;
    number_second._sign = true;
    return number_first * number_second / LongInt::gcd(number_first, number_second);
}
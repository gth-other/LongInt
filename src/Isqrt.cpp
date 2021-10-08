#include "LongInt.hpp"


LongInt LongInt::isqrt(const LongInt& number) {
    if (!number._sign) {
        throw "Fatal error. Calculating an integer square root is not possible. The square root of the specified number does not exist.";
    }
    if (number == 0) {
        return number;
    }
    LongInt left = 1;
    LongInt right = number / 2 + 1;
    LongInt middle;
    LongInt result;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (middle * middle <= number) {
            left = middle + 1;
            result = middle;
        }
        else {
            right = middle - 1;
        }
    }
    return result;
}
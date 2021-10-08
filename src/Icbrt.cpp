#include "LongInt.hpp"


LongInt LongInt::icbrt(LongInt number) {
    if (number == 0) {
        return number;
    }
    bool result_natural = number._sign;
    number._sign = true;
    LongInt left = 1;
    LongInt right = number / 2 + 1;
    LongInt middle;
    LongInt result;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (middle * middle * middle <= number) {
            left = middle + 1;
            result = middle;
        }
        else {
            right = middle - 1;
        }
    }
    result._sign = result_natural;
    return result;
}
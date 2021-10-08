#include "LongInt.hpp"


LongInt operator +(LongInt number_first, LongInt number_second) {
    if (number_first._sign and !number_second._sign) {
        number_second._sign = true;
        return number_first - number_second;
    }
    if (!number_first._sign and number_second._sign) {
        number_first._sign = true;
        return number_second - number_first;
    }
    if (!number_first._sign and !number_second._sign) {
        number_second._sign = true;
    }
    if (number_first._digits.size() > number_second._digits.size()) {
        number_second = LongInt::_shift_right(number_second, number_first._digits.size() - number_second._digits.size());
    }
    else {
        number_first = LongInt::_shift_right(number_first, number_second._digits.size() - number_first._digits.size());
    }
    int sum;
    int in_mind = 0;
    for (long long numbers_position = number_first._digits.size() - 1; numbers_position >= 0; numbers_position = numbers_position - 1) {
        sum = number_first._digits[numbers_position] + number_second._digits[numbers_position] + in_mind;
        in_mind = sum / LongInt::_base;
        number_first._digits[numbers_position] = sum % LongInt::_base;
    }
    if (in_mind != 0) {
        number_first._digits.insert(number_first._digits.begin(), in_mind);
    }
    return number_first;
}
LongInt LongInt::operator +=(LongInt number) {
    return *this = *this + std::move(number);
}
LongInt LongInt::operator ++() {
    return *this = *this + 1;
}
LongInt LongInt::operator ++(int) {
    *this = *this + 1;
    return *this = *this - 1;
}
#include "LongInt.hpp"


LongInt operator -(LongInt number_first, LongInt number_second) {
    if (number_first._sign and !number_second._sign) {
        number_second._sign = true;
        return number_first + number_second;
    }
    if (!number_first._sign and number_second._sign) {
        number_first._sign = true;
        LongInt tmp = number_first + number_second;
        tmp._sign = false;
        return tmp;
    }
    if (!number_first._sign and !number_second._sign) {
        number_first._sign = true;
        number_second._sign = true;
        LongInt tmp;
        tmp = number_first;
        number_first = number_second;
        number_second = tmp;
    }
    if (number_first < number_second) {
        LongInt tmp = number_first;
        number_first = number_second;
        number_second = tmp;
        number_first._sign = false;
    }
    number_second = LongInt::_shift_right(number_second, number_first._digits.size() - number_second._digits.size());
    int different;
    for (long long numbers_position1 = number_first._digits.size() - 1; numbers_position1 >= 0; numbers_position1 = numbers_position1 - 1) {
        different = number_first._digits[numbers_position1] - number_second._digits[numbers_position1];
        if (different >= 0) {
            number_first._digits[numbers_position1] = different;
        }
        else {
            number_first._digits[numbers_position1] = different + LongInt::_base;
            for (long long numbers_position2 = numbers_position1 - 1; true; numbers_position2 = numbers_position2 - 1) {
                if (number_first._digits[numbers_position2] == 0) {
                    number_first._digits[numbers_position2] = LongInt::_base - 1;
                }
                else {
                    number_first._digits[numbers_position2] = number_first._digits[numbers_position2] - 1;
                    break;
                }
            }
        }
    }
    return LongInt::_zeroes_leading_remove(number_first);
}
LongInt LongInt::operator -=(LongInt number) {
    return *this = *this - std::move(number);
}
LongInt LongInt::operator --() {
    return *this = *this - 1;
}
LongInt LongInt::operator --(int) {
    *this = *this - 1;
    return *this = *this + 1;
}
#include "LongInt.hpp"


LongInt LongInt::_zeroes_leading_remove(LongInt number) {
    long long zeroes_leading_border = number._digits.size() - 1;
    for (long long i = 0; i < number._digits.size() - 1; i = i + 1) {
        if (number._digits[i] != 0) {
            zeroes_leading_border = i;
            break;
        }
    }
    number._digits.erase(number._digits.begin(), number._digits.begin() + zeroes_leading_border);
    return number;
}
LongInt LongInt::_shift_right(LongInt number, long long shift_power) {
    number._digits.reserve(shift_power);
    for (long long i = 0; i < shift_power; i = i + 1) {
        number._digits.insert(number._digits.begin(), 0);
    }
    return number;
}
LongInt LongInt::_shift_left(LongInt number, long long shift_power) {
    if (number == 0) {
        return number;
    }
    number._digits.resize(number._digits.size() + shift_power);
    return number;
}
LongInt LongInt::abs(LongInt number_first) {
    number_first._sign = true;
    return number_first;
}
bool LongInt::even(LongInt number) {
    if (number._digits.back() % 2 == 0) {
        return true;
    }
    return false;
}
bool LongInt::odd(LongInt number) {
    return !LongInt::even(std::move(number));
}
long long LongInt::size(LongInt number) {
    return (((long long)number._digits.size() - (long long)1) * (long long)_base_length) + (long long)std::to_string(number._digits.front()).size();
}
LongInt LongInt::max(LongInt number_first, LongInt number_second) {
    if (number_first > number_second) {
        return number_first;
    }
    return number_second;
}
LongInt LongInt::min(LongInt number_first, LongInt number_second) {
    if (number_first < number_second) {
        return number_first;
    }
    return number_second;
}
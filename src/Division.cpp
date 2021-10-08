#include "LongInt.hpp"


LongInt operator /(LongInt number_first, LongInt number_second) {
    if (number_second == 0) {
        throw "Fatal error. Whole division is not possible. Zero is specified as the divisor.";
    }
    if (number_second._digits.size() == 1) {
        int number_second_integer = number_second._digits[0];
        int in_mind = 0;
        long long composition;
        for (long long i = 0; i < number_first._digits.size(); i = i + 1) {
            composition = (long long)number_first._digits[i] + (long long)in_mind * (long long)LongInt::_base;
            number_first._digits[i] = composition / number_second_integer;
            in_mind = composition % number_second_integer;
        }
        number_first._sign = (number_first._sign == number_second._sign);
        return LongInt::_zeroes_leading_remove(number_first);
    }
    LongInt result;
    result._sign = (number_first._sign == number_second._sign);
    LongInt number_first_part;
    number_first._sign = true;
    number_second._sign = true;
    if (number_first < number_second) {
        return 0;
    }
    result._digits.resize(0);
    number_first_part._digits.resize(0);
    int quotient;
    int left;
    int middle;
    int right;
    LongInt tmp;
    for (long long number_first_position = 0; number_first_position < number_first._digits.size(); number_first_position = number_first_position + 1) {
        number_first_part._digits.push_back(number_first._digits[number_first_position]);
        quotient = 0;
        left = 0;
        right = LongInt::_base;
        while (left <= right) {
            middle = (left + right) / 2;
            tmp = number_second * middle;
            if (tmp <= number_first_part) {
                quotient = middle;
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        number_first_part = number_first_part - (number_second * quotient);
        if (!result._digits.empty() or quotient != 0) {
            result._digits.push_back(quotient);
        }
        if (number_first_part == 0) {
            number_first_part._digits.resize(0);
        }
    }
    return result;
}
LongInt LongInt::operator /=(LongInt number) {
    return *this = *this / std::move(number);
}
LongInt operator %(LongInt number_first, LongInt number_second) {
    if (number_second == 0) {
        throw "Fatal error. It is not possible to get the remainder of the division. Zero is specified as the divisor.";
    }
    if (number_second._digits.size() == 1) {
        int number_second_integer = number_second._digits[0];
        int in_mind = 0;
        long long composition;
        for (long long i = 0; i < number_first._digits.size(); i = i + 1) {
            composition = (long long)number_first._digits[i] + (long long)in_mind * (long long)LongInt::_base;
            number_first._digits[i] = composition / number_second_integer;
            in_mind = composition % number_second_integer;
        }
        return in_mind;
    }
    LongInt number_first_part;
    number_first._sign = true;
    number_second._sign = true;
    if (number_first < number_second) {
        return number_first;
    }
    number_first_part._digits.resize(0);
    int quotient;
    int left;
    int middle;
    int right;
    LongInt tmp;
    for (long long number_first_position = 0; number_first_position < number_first._digits.size(); number_first_position = number_first_position + 1) {
        number_first_part._digits.push_back(number_first._digits[number_first_position]);
        quotient = 0;
        left = 0;
        right = LongInt::_base;
        while (left <= right) {
            middle = (left + right) / 2;
            tmp = number_second * middle;
            if (tmp <= number_first_part) {
                quotient = middle;
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        number_first_part = number_first_part - (number_second * quotient);
        if (number_first_part == 0) {
            number_first_part._digits.resize(0);
        }
    }
    if (number_first_part._digits.empty()) {
        return 0;
    }
    return number_first_part;
}
LongInt LongInt::operator %=(LongInt number) {
    return *this = *this % std::move(number);
}
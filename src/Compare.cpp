#include <algorithm>
#include "LongInt.hpp"


bool operator ==(LongInt number_first, LongInt number_second) {
    if (number_first._sign != number_second._sign) {
        return false;
    }
    if (number_first._digits.size() != number_second._digits.size()) {
        return false;
    }
    for (long long numbers_position = 0; numbers_position < number_first._digits.size(); numbers_position = numbers_position + 1) {
        if (number_first._digits[numbers_position] != number_second._digits[numbers_position]) {
            return false;
        }
    }
    return true;
}
bool operator !=(LongInt number_first, LongInt number_second) {
    return !(std::move(number_first) == std::move(number_second));
}
bool operator >(LongInt number_first, LongInt number_second) {
    if (number_first == number_second) {
        return false;
    }
    if (number_first._sign and !number_second._sign) {
        return true;
    }
    if (!number_first._sign and number_second._sign) {
        return false;
    }
    if (!number_first._sign and !number_second._sign) {
        number_first._sign = true;
        number_second._sign = true;
        return !(number_first > number_second);
    }
    if (number_first._digits.size() > number_second._digits.size()) {
        return true;
    }
    if (number_first._digits.size() < number_second._digits.size()) {
        return false;
    }
    return !(std::lexicographical_compare(number_first._digits.begin(), number_first._digits.end(), number_second._digits.begin(), number_second._digits.end()));
}
bool operator <(const LongInt& number_first, const LongInt& number_second) {
    if (number_first != number_second and !(number_first > number_second)) {
        return true;
    }
    return false;
}
bool operator >=(const LongInt& number_first, const LongInt& number_second) {
    if (number_first > number_second or number_first == number_second) {
        return true;
    }
    return false;
}
bool operator <=(const LongInt& number_first, const LongInt& number_second) {
    if (number_first < number_second or number_first == number_second) {
        return true;
    }
    return false;
}
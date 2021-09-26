#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>
#include <future>
#include "LongInt.hpp"


std::vector<int> LongInt::_string_convert_to_vector(const std::string& string) {
    std::vector<int> result;
    if (string.size() % _base_length == 0) {
        result.resize(string.size() / _base_length);
    }
    else {
        result.resize(string.size() / _base_length + 1);
    }
    for (long long string_position = string.size() - 1, result_position = result.size() - 1; string_position >= 0; string_position = string_position - _base_length, result_position = result_position - 1) {
        if ((string_position + 1) - _base_length <= 0) {
            result[result_position] = std::stoi(string.substr(0, (string_position + 1)));
        }
        else {
            result[result_position] = std::stoi(string.substr((string_position + 1) - _base_length, _base_length));
        }
    }
    return result;
}
LongInt::LongInt() {
    _digits.resize(1);
    _sign = true;
}
LongInt::LongInt(std::string string) {
    if (string.empty() or (string.size() == 1 and string[0] == '-')) {
        throw "Fatal error. Type creation is impossible. String does not contain number.";
    }
    if (string[0] == '-') {
        string.erase(string.begin() + 0);
        _sign = false;
    }
    else {
        _sign = true;
    }
    for (long long i = 0; i < string.size(); i = i + 1) {
        if (string[i] < 48 or string[i] > 57) {
            throw "Fatal error. Type creation is impossible. String contain unknown characters.";
        }
    }
    while (string.size() != 1 and string[0] == '0') {
        string.erase(string.begin() + 0);
    }
    _digits = LongInt::_string_convert_to_vector(string);
}
LongInt::LongInt(signed int number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin() + 0);
        _sign = false;
    }
    else {
        _sign = true;
    }
    _digits = LongInt::_string_convert_to_vector(string);
}
LongInt::LongInt(unsigned int number) {
    _sign = true;
    _digits = LongInt::_string_convert_to_vector(std::to_string(number));
}
LongInt::LongInt(signed long number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin() + 0);
        _sign = false;
    }
    else {
        _sign = true;
    }
    _digits = LongInt::_string_convert_to_vector(string);
}
LongInt::LongInt(unsigned long number) {
    _sign = true;
    _digits = LongInt::_string_convert_to_vector(std::to_string(number));
}
LongInt::LongInt(signed long long number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin() + 0);
        _sign = false;
    }
    else {
        _sign = true;
    }
    _digits = LongInt::_string_convert_to_vector(string);
}
LongInt::LongInt(unsigned long long number) {
    _sign = true;
    _digits = LongInt::_string_convert_to_vector(std::to_string(number));
}
std::string LongInt::to_string(LongInt number) {
    if (number._digits.size() == 1 and number._digits[0] == 0) {
        return "0";
    }
    std::string result;
    if (!number._sign) {
        result.append("-");
    }
    result.reserve(number._digits.size() * (_base_length - 1));
    std::string tmp;
    result.append(std::to_string(number._digits[0]));
    for (long long i = 1; i < number._digits.size(); i = i + 1) {
        tmp = std::to_string(number._digits[i]);
        tmp.reserve(_base_length - tmp.size());
        while (tmp.size() < _base_length) {
            tmp.insert(tmp.begin() + 0, '0');
        }
        result.append(tmp);
    }
    return result;
}
std::ostream& operator <<(std::ostream& ostream, const LongInt& number) {
    std::string string = LongInt::to_string(number);
    for (long long i = 0; i < string.size(); i = i + 1) {
        ostream.put(string[i]);
    }
    return ostream;
}
LongInt LongInt::_zeroes_leading_remove(LongInt number) {
    long long zeroes_leading_border = number._digits.size() - 1;
    for (long long i = 0; i < number._digits.size() - 1; i = i + 1) {
        if (number._digits[i] != 0) {
            zeroes_leading_border = i;
            break;
        }
    }
    number._digits.erase(number._digits.begin() + 0, number._digits.begin() + zeroes_leading_border);
    return number;
}
LongInt LongInt::_shift_right(LongInt number, long long shift_power) {
    number._digits.reserve(shift_power);
    for (long long i = 0; i < shift_power; i = i + 1) {
        number._digits.insert(number._digits.begin() + 0, 0);
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
    if (number._digits[number._digits.size() - 1] % 2 == 0) {
        return true;
    }
    return false;
}
bool LongInt::odd(LongInt number) {
    return !LongInt::even(std::move(number));
}
long long LongInt::size(LongInt number) {
    return (((long long)number._digits.size() - (long long)1) * (long long)_base_length) + (long long)std::to_string(number._digits[0]).size();
}
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
        number_first._digits.insert(number_first._digits.begin() + 0, in_mind);
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
LongInt LongInt::_multiply_karatsuba(LongInt number_first, LongInt number_second, bool iteration_thirst) {
    if (std::min(number_first._digits.size(), number_second._digits.size()) <= _length_maximum_for_default_multiply) {
        number_first = LongInt::_zeroes_leading_remove(number_first);
        number_second = LongInt::_zeroes_leading_remove(number_second);
        LongInt result;
        result._digits.resize(number_first._digits.size() + number_second._digits.size());
        long long composition;
        for (long long number_first_position = number_first._digits.size() - 1; number_first_position >= 0; number_first_position = number_first_position - 1) {
            for (long long number_second_position = number_second._digits.size() - 1; number_second_position >= 0; number_second_position = number_second_position - 1) {
                composition = (long long)number_first._digits[number_first_position] * (long long)number_second._digits[number_second_position] + result._digits[number_first_position + number_second_position + 1];
                result._digits[number_first_position + number_second_position + 1] = composition % LongInt::_base;
                result._digits[number_first_position + number_second_position + 1 - 1] = result._digits[number_first_position + number_second_position + 1 - 1] + (composition / LongInt::_base);
            }
        }
        return LongInt::_zeroes_leading_remove(result);
    }
    if (number_first._digits.size() % 2 != 0) {
        number_first._digits.insert(number_first._digits.begin() + 0, 0);
    }
    if (number_second._digits.size() % 2 != 0) {
        number_second._digits.insert(number_second._digits.begin() + 0, 0);
    }
    if (number_first._digits.size() > number_second._digits.size()) {
        number_second = LongInt::_shift_right(number_second, number_first._digits.size() - number_second._digits.size());
    }
    else {
        number_first = LongInt::_shift_right(number_first, number_second._digits.size() - number_first._digits.size());
    }
    long long numbers_size = number_first._digits.size();
    long long numbers_part_size = numbers_size / 2;
    LongInt number_first_part_left;
    LongInt number_first_part_right;
    LongInt number_second_part_left;
    LongInt number_second_part_right;
    number_first_part_left._digits.resize(numbers_part_size);
    number_first_part_right._digits.resize(numbers_part_size);
    number_second_part_left._digits.resize(numbers_part_size);
    number_second_part_right._digits.resize(numbers_part_size);
    std::copy(number_first._digits.begin() + 0, number_first._digits.begin() + numbers_part_size, number_first_part_left._digits.begin() + 0);
    std::copy(number_second._digits.begin() + 0, number_second._digits.begin() + numbers_part_size, number_second_part_left._digits.begin() + 0);
    std::copy(number_first._digits.begin() + numbers_part_size, number_first._digits.begin() + numbers_size, number_first_part_right._digits.begin() + 0);
    std::copy(number_second._digits.begin() + numbers_part_size, number_second._digits.begin() + numbers_size, number_second_part_right._digits.begin() + 0);
    LongInt product_first;
    LongInt product_second;
    LongInt product_third;
    if (iteration_thirst) {
        auto thread_first = std::async(LongInt::_multiply_karatsuba, number_first_part_left, number_second_part_left, false);
        auto thread_second = std::async(LongInt::_multiply_karatsuba, number_first_part_right, number_second_part_right, false);
        product_third = LongInt::_multiply_karatsuba(LongInt::_zeroes_leading_remove(number_first_part_left) + LongInt::_zeroes_leading_remove(number_first_part_right), LongInt::_zeroes_leading_remove(number_second_part_left) + LongInt::_zeroes_leading_remove(number_second_part_right), false);
        product_first = thread_first.get();
        product_second = thread_second.get();
    }
    else {
        product_first = LongInt::_multiply_karatsuba(number_first_part_left, number_second_part_left, false);
        product_second = LongInt::_multiply_karatsuba(number_first_part_right, number_second_part_right, false);
        product_third = LongInt::_multiply_karatsuba(LongInt::_zeroes_leading_remove(number_first_part_left) + LongInt::_zeroes_leading_remove(number_first_part_right), LongInt::_zeroes_leading_remove(number_second_part_left) + LongInt::_zeroes_leading_remove(number_second_part_right), false);
    }
    return LongInt::_shift_left(product_first, numbers_size) + LongInt::_shift_left(product_third - product_first - product_second, numbers_part_size) + product_second;
}
LongInt operator *(const LongInt& number_first, const LongInt& number_second) {
    LongInt result = LongInt::_multiply_karatsuba(number_first, number_second, true);
    result._sign = (number_first._sign == number_second._sign);
    return result;
}
LongInt LongInt::operator *=(const LongInt& number) {
    return *this = *this * number;
}
LongInt operator /(LongInt number_first, LongInt number_second) {
    if (number_second == 0) {
        throw "Fatal error. Division whole is impossible. Attempt to divide by zero.";
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
        throw "Fatal error. Division remainder calculation is impossible. Attempt to divide by zero.";
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
LongInt LongInt::pow(LongInt number_first, LongInt number_second) {
    if (number_first == 0 and number_second == 0) {
        throw "Fatal error. Pow calculation is impossible. It is impossible to raise zero to zero degree.";
    }
    if (number_second < 0) {
        throw "Fatal error. Pow calculation is impossible. This class only support whole numbers, so erection to negative degree is impossible.";
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
LongInt LongInt::_factorial_tree(LongInt number_first, const LongInt& number_second) {
    if (number_first > number_second) {
        return 1;
    }
    if (number_first == number_second) {
        return number_first;
    }
    if (number_second - number_first == 1) {
        return number_first * number_second;
    }
    LongInt tmp = (number_first + number_second) / 2;
    return LongInt::_factorial_tree(number_first, tmp) * LongInt::_factorial_tree(tmp + 1, number_second);
}
LongInt LongInt::factorial(LongInt number) {
    if (number < 1) {
        throw "Fatal error. Factorial calculation is impossible. Factorial is defined only for natural numbers.";
    }
    if (number == 1 or number == 2) {
        return number;
    }
    return _factorial_tree(2, number);
}
LongInt LongInt::gcd(LongInt number_first, LongInt number_second) {
    if (number_first == 0 and number_second == 0) {
        throw "Fatal error. Gcd calculation is impossible. Both numbers are zeros.";
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
LongInt LongInt::lcm(LongInt number_first, LongInt number_second) {
    if (number_first == 0 or number_second == 0) {
        throw "Fatal error. Lcm calculation is impossible. One of the numbers is zero.";
    }
    number_first._sign = true;
    number_second._sign = true;
    return number_first * number_second / LongInt::gcd(number_first, number_second);
}
LongInt LongInt::isqrt(const LongInt& number) {
    if (!number._sign) {
        throw "Fatal error. Isqrt calculation is impossible. Isqrt operation over negative numbers has no result.";
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
LongInt LongInt::random(long long number_length) {
    if (number_length < 1) {
        throw "Fatal error. Random number generation is impossible. Number length must be natural.";
    }
    LongInt result;
    result._digits.resize(0);
    std::random_device random_device;
    std::mt19937 mersenne(random_device());
    int tmp = 0;
    if (number_length % _base_length == 0) {
        while (tmp == 0 or std::to_string(tmp).size() != _base_length) {
            tmp = mersenne() % _base;
        }
        result._digits.push_back(tmp);
        number_length = number_length - _base_length;
    }
    else {
        while (tmp == 0 or std::to_string(tmp).size() != number_length % _base_length) {
            tmp = mersenne() % (unsigned int)std::pow(10, number_length % _base_length);
        }
        result._digits.push_back(tmp);
        number_length = number_length - (number_length % _base_length);
    }
    result._digits.reserve(number_length / _base_length);
    while (number_length != 0) {
        result._digits.push_back(mersenne() % _base);
        number_length = number_length - _base_length;
    }
    return result;
}
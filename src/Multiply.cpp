#include <future>
#include "LongInt.hpp"


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
                result._digits[number_first_position + number_second_position] = result._digits[number_first_position + number_second_position] + (composition / LongInt::_base);
            }
        }
        return LongInt::_zeroes_leading_remove(result);
    }
    if (number_first._digits.size() % 2 != 0) {
        number_first._digits.insert(number_first._digits.begin(), 0);
    }
    if (number_second._digits.size() % 2 != 0) {
        number_second._digits.insert(number_second._digits.begin(), 0);
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
    std::copy(number_first._digits.begin(), number_first._digits.begin() + numbers_part_size, number_first_part_left._digits.begin());
    std::copy(number_second._digits.begin(), number_second._digits.begin() + numbers_part_size, number_second_part_left._digits.begin());
    std::copy(number_first._digits.begin() + numbers_part_size, number_first._digits.begin() + numbers_size, number_first_part_right._digits.begin());
    std::copy(number_second._digits.begin() + numbers_part_size, number_second._digits.begin() + numbers_size, number_second_part_right._digits.begin());
    LongInt product_first;
    LongInt product_second;
    LongInt product_third;
    if (iteration_thirst and std::thread::hardware_concurrency() >= 3) {
        auto thread_first = std::async(LongInt::_multiply_karatsuba, number_first_part_left, number_second_part_left, false);
        auto thread_second = std::async(LongInt::_multiply_karatsuba, number_first_part_right, number_second_part_right, false);
        product_third = LongInt::_multiply_karatsuba(LongInt::_zeroes_leading_remove(number_first_part_left) + LongInt::_zeroes_leading_remove(number_first_part_right), LongInt::_zeroes_leading_remove(number_second_part_left) + LongInt::_zeroes_leading_remove(number_second_part_right), false);
        product_first = thread_first.get();
        product_second = thread_second.get();
    }
    else if (iteration_thirst and std::thread::hardware_concurrency() == 2) {
        auto thread_first = std::async(LongInt::_multiply_karatsuba, number_first_part_left, number_second_part_left, false);
        product_second = LongInt::_multiply_karatsuba(number_first_part_right, number_second_part_right, false);
        product_third = LongInt::_multiply_karatsuba(LongInt::_zeroes_leading_remove(number_first_part_left) + LongInt::_zeroes_leading_remove(number_first_part_right), LongInt::_zeroes_leading_remove(number_second_part_left) + LongInt::_zeroes_leading_remove(number_second_part_right), false);
        product_first = thread_first.get();
    }
    else {
        product_first = LongInt::_multiply_karatsuba(number_first_part_left, number_second_part_left, false);
        product_second = LongInt::_multiply_karatsuba(number_first_part_right, number_second_part_right, false);
        product_third = LongInt::_multiply_karatsuba(LongInt::_zeroes_leading_remove(number_first_part_left) + LongInt::_zeroes_leading_remove(number_first_part_right), LongInt::_zeroes_leading_remove(number_second_part_left) + LongInt::_zeroes_leading_remove(number_second_part_right), false);
    }
    return LongInt::_shift_left(product_first, numbers_size) + LongInt::_shift_left(product_third - (product_first + product_second), numbers_part_size) + product_second;
}
LongInt operator *(const LongInt& number_first, const LongInt& number_second) {
    LongInt result = LongInt::_multiply_karatsuba(number_first, number_second, true);
    result._sign = (number_first._sign == number_second._sign);
    return result;
}
LongInt LongInt::operator *=(const LongInt& number) {
    return *this = *this * number;
}
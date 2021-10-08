#include <random>
#include <cmath>
#include "LongInt.hpp"


LongInt LongInt::random(long long number_length) {
    if (number_length < 1) {
        throw "Fatal error. Random number generation is not possible. Specified length is less than or equal to zero.";
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
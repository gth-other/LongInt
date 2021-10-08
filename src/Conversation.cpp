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
            result[result_position] = std::stoi(string.substr(0, string_position + 1));
        }
        else {
            result[result_position] = std::stoi(string.substr(string_position - _base_length + 1, _base_length));
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
        throw "Fatal error. Cannot create type. String does not contain a number.";
    }
    if (string.front() == '-') {
        string.erase(string.begin());
        _sign = false;
    }
    else {
        _sign = true;
    }
    for (long long i = 0; i < string.size(); i = i + 1) {
        if (string[i] < 48 or string[i] > 57) {
            throw "Fatal error. Cannot create type. String contains unknown characters.";
        }
    }
    while (string.size() != 1 and string.front() == '0') {
        string.erase(string.begin());
    }
    _digits = LongInt::_string_convert_to_vector(string);
}
LongInt::LongInt(signed int number) {
    std::string string = std::to_string(number);
    if (string.front() == '-') {
        string.erase(string.begin());
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
    if (string.front() == '-') {
        string.erase(string.begin());
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
    if (string.front() == '-') {
        string.erase(string.begin());
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
    if (number._digits.size() == 1 and number._digits.front() == 0) {
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
            tmp.insert(tmp.begin(), '0');
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
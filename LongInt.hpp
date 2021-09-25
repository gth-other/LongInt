#include <iostream>
#include <vector>


class LongInt {
public:
    LongInt();
    LongInt(std::string string);
    LongInt(signed int number);
    LongInt(unsigned int number);
    LongInt(signed long number);
    LongInt(unsigned long number);
    LongInt(signed long long number);
    LongInt(unsigned long long number);
    static std::string to_string(LongInt number);
    friend std::ostream& operator <<(std::ostream& ostream, const LongInt& number);
    static LongInt abs(LongInt number_first);
    static bool even(LongInt number);
    static bool odd(LongInt number);
    friend bool operator ==(LongInt number_first, LongInt number_second);
    friend bool operator !=(LongInt number_first, LongInt number_second);
    friend bool operator >(LongInt number_first, LongInt number_second);
    friend bool operator <(const LongInt& number_first, const LongInt& number_second);
    friend bool operator >=(const LongInt& number_first, const LongInt& number_second);
    friend bool operator <=(const LongInt& number_first, const LongInt& number_second);
    static LongInt max(LongInt number_first, LongInt number_second);
    static LongInt min(LongInt number_first, LongInt number_second);
    friend LongInt operator +(LongInt number_first, LongInt number_second);
    LongInt operator +=(LongInt number);
    LongInt operator ++();
    LongInt operator ++(int);
    friend LongInt operator -(LongInt number_first, LongInt number_second);
    LongInt operator -=(LongInt number);
    LongInt operator --();
    LongInt operator --(int);
    friend LongInt operator *(const LongInt& number_first, const LongInt& number_second);
    LongInt operator *=(const LongInt& number);
    friend LongInt operator /(LongInt number_first, LongInt number_second);
    LongInt operator /=(LongInt number);
    friend LongInt operator %(LongInt number_first, LongInt number_second);
    LongInt operator %=(LongInt number);
    static LongInt pow(LongInt number_first, LongInt number_second);
    static LongInt factorial(LongInt number);
    static LongInt gcd(LongInt number_first, LongInt number_second);
    static LongInt lcm(LongInt number_first, LongInt number_second);
    static LongInt isqrt(const LongInt& number);
    static LongInt icbrt(LongInt number);
    static LongInt random(long long number_length);
private:
    std::vector<int> _digits;
    bool _sign;
    static const int _base = 1000000000;
    static const int _base_length = 9;
    static const int _length_maximum_for_default_multiply = 256;
    static std::vector<int> _string_convert_to_vector(const std::string& string);
    static LongInt _zeroes_leading_remove(LongInt number);
    static LongInt _shift_right(LongInt number, long long shift_power);
    static LongInt _shift_left(LongInt number, long long shift_power);
    static LongInt _multiply_karatsuba(LongInt number_first, LongInt number_second, bool iteration_thirst);
    static LongInt _factorial_tree(LongInt number_first, const LongInt& number_second);
};
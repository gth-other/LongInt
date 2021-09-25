#include <iostream>
#include <chrono>
#include "LongInt.hpp"


int main() {
    std::string number_first_string;
    std::string number_second_string;
    std::string action;
    LongInt number_first;
    LongInt number_second;
    long double time_start;
    long double time_end;
    LongInt result_longint;
    bool result_bool;
    char result_char;
    std::cout << "1| Сложение двух целых чисел." << std::endl;
    std::cout << "2| Вычитание из целого числа целое число." << std::endl;
    std::cout << "3| Умножение двух целых чисел." << std::endl;
    std::cout << "4| Деление нацело двух целых чисел." << std::endl;
    std::cout << "5| Получения остатка от деления двух целых чисел." << std::endl;
    std::cout << "6| Возведение целого числа в целую неотрицательную степень." << std::endl;
    std::cout << "7| Подсчет факториала от натурального числа." << std::endl;
    std::cout << "8| Подсчет НОД двух целых чисел." << std::endl;
    std::cout << "9| Подсчет НОК двух целых чисел." << std::endl;
    std::cout << "10| Получение модуля целого числа." << std::endl;
    std::cout << "11| Быстрая проверка целого числа на четность." << std::endl;
    std::cout << "12| Быстрая проверка целого числа на нечетность." << std::endl;
    std::cout << "13| Получение максимального из двух целых чисел." << std::endl;
    std::cout << "14| Получение минимального из двух целых чисел." << std::endl;
    std::cout << "15| Извлечение целого квадратного корня из целого неотрицательного числа." << std::endl;
    std::cout << "16| Извлечение целого кубического корня из целого числа." << std::endl;
    std::cout << "17| Генерация натурального псевдослучайного числа натуральной длины." << std::endl;
    std::cout << "18| Выход." << std::endl;
    for (; ;) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Выберите операцию: ";
        getline(std::cin, action);
        if (action == "1") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = number_first + number_second;
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "2") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = number_first - number_second;
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "3") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = number_first * number_second;
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "4") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = number_first / number_second;
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "5") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = number_first % number_second;
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "6") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = LongInt::pow(number_first, number_second);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "7") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_longint = LongInt::factorial(number_first);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "8") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = LongInt::gcd(number_first, number_second);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "9") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = LongInt::lcm(number_first, number_second);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "10") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_longint = LongInt::abs(number_first);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "11") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_bool = LongInt::even(number_first);
            std::cout << "Результат: " << result_bool << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "12") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_bool = LongInt::odd(number_first);
            std::cout << "Результат: " << result_bool << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "13") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = LongInt::max(number_first, number_second);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "14") {
            std::cout << "Введите первое число: ";
            getline(std::cin, number_first_string);
            std::cout << "Введите второе число: ";
            getline(std::cin, number_second_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            number_second = number_second_string;
            result_longint = LongInt::min(number_first, number_second);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "15") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_longint = LongInt::isqrt(number_first);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "16") {
            std::cout << "Введите число: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            number_first = number_first_string;
            result_longint = LongInt::icbrt(number_first);
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "17") {
            std::cout << "Введите число [оно должно помещаться в стандартные целочисленные типы]: ";
            getline(std::cin, number_first_string);
            time_start = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            result_longint = LongInt::random(std::stoi(number_first_string));
            std::cout << "Результат: " << result_longint << "." << std::endl;
            time_end = std::chrono::high_resolution_clock::now().time_since_epoch().count();
            std::cout << "Затрачено времени [с учетом затрат на конвертацию типов и вывод]: " << (time_end - time_start) / 1000000000 << " секунд(а/ы)." << std::endl;
        }
        else if (action == "18") {
            break;
        }
        else {
            std::cout << "Неизвестный номер команды. Введите число от 1 до 18." << std::endl;
        }
    }
    return 0;
}
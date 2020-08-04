#include <iostream>
#include <string>

#include "utility.h"

void utility::enter_and_exit() {
    std::cout << "\nPress any key to exit. ";
    /* std::cin.clear(); */
    /* std::cin.ignore(); */
    std::string wait;
    std::getline(std::cin, wait);
}

std::string utility::insert_commas(double number) {
    std::string s_number{std::to_string((long)number)};
    int length{(int)s_number.length()};

    int count{0};
    for (int i{length - 1}; i >= 0; i--) {
        if (count < 2) {
            count++;
            continue;
        } else {
            if (i != 0) s_number.insert(i, ",");
            count = 0;
            length = s_number.length();
        }
    }
    return s_number;
}

bool utility::is_int(std::string input) {
    int length{(int)input.size()};

    for (int i{0}; i < length; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

bool utility::is_double(std::string input) {
    int length{(int)input.size()};
    int dotcount = 0;

    if (input == ".") {
        return false;
    }

    for (int i{0}; i < length; i++) {
        if (input[i] == '.') {
            dotcount += 1;
            if (dotcount > 1) {
                return false;
            }
        } else if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

int utility::get_int() {
    std::string input;
    std::getline(std::cin, input);

    while (!is_int(input)) {
        std::cout << "Bad input! Please enter an integer: ";
        std::getline(std::cin, input);
    }
    return std::stod(input.c_str());
}

double utility::get_double() {
    std::string input;
    std::getline(std::cin, input);

    while (!is_double(input)) {
        std::cout << "Bad input! Please enter a floating point number: ";
        std::getline(std::cin, input);
    }
    return std::stod(input);
}

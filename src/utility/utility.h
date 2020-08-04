#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

namespace utility {

void enter_and_exit();
std::string insert_commas(double number);

bool is_int(std::string input);
bool is_double(std::string input);
int get_int();
double get_double();

}  // namespace utility

#endif /* ifndef UTILITY_H */

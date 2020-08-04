#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

namespace utility {

void enter_and_exit();
std::string insert_commas(double number);

bool is_int(const std::string &input);
bool is_double(const std::string &input);
void get_int(int &number);
void get_double(double &number);

}  // namespace utility

#endif /* ifndef UTILITY_H */

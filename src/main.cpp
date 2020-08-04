#include <iomanip>
#include <iostream>

#include "utility.h"
#include "fund.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    constexpr double tax_rate  = 0.25;
    constexpr double inflation = 0.03;
    /* constexpr double fees      = 0.005; */
    /* constexpr double fees      = 0.00007; */
    constexpr double fees      = 0.002;

    Fund fund(tax_rate,inflation,fees);
    fund.set_parameters();

    fund.set_years();
    fund.calculate_complex_fortune();

    fund.display_fortune();
    utility::enter_and_exit();

    return 0;
}

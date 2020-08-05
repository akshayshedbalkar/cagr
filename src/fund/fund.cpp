#include <cmath>
#include <iostream>

#include "fund.h"
#include "utility.h"

Fund::Fund() : years{0}, capital{0}, annual_return{0}, cumulative_return{0}, tax_rate{0}, inflation{0}, fees{0}, fortune{0}, increments{0} {
    greeting(0, 0, 0);
}

Fund::Fund(const double tax_rate, const double inflation, const double fees) : years{0}, capital{0}, annual_return{0}, cumulative_return{0}, tax_rate{tax_rate}, inflation{inflation}, fees{fees}, fortune{0}, increments{0} {
    greeting(tax_rate, inflation, fees);
}

void Fund::greeting(const double tax_rate, const double inflation, const double fees) {
    std::cout << "\nHello!\n\n";
    std::cout << "Setting capital gains tax to " << tax_rate * 100 << "%\n";
    std::cout << "Setting inflation rate to " << inflation * 100 << "%\n";
    std::cout << "Setting fees (transaction costs + account fees) to " << fees * 100 << "%\n\n";
}

void Fund::set_increments() {
    std::cout << "How much to reinvest yearly? (0 for none): ";
    utility::get_double(increments);
}

void Fund::set_parameters() {
    set_capital();
    set_current_return();
    set_years();
    annual_return = calculate_return();

    std::cout << "\nAnnual return is: " << annual_return * 100 << "%\n";
    annual_return -= inflation;
    std::cout << "Annual return adjusted for inflation is: " << annual_return * 100 << "%\n";
    annual_return -= fees;
    std::cout << "Annual return after fees and inflation is: " << annual_return * 100 << "%\n\n";
}

void Fund::set_capital() {
    std::cout << "Enter capital: ";
    utility::get_double(capital);
}

void Fund::set_current_return() {
    std::cout << "Enter current cumulative return: ";
    utility::get_double(cumulative_return);
    cumulative_return /= 100;
}

void Fund::set_years() {
    if (annual_return == 0) {
        std::cout << "Enter number of years already invested: ";
        utility::get_double(years);
    } else {
        std::cout << "Enter number of years to invest: ";
        utility::get_double(years);
        set_increments();
    }
}

void Fund::reset_annual_return() {
    annual_return = 0;
}

double Fund::calculate_return() {
    return std::pow((1 + cumulative_return), (1.0 / years)) - 1;
}

double Fund::calculate_differential_fortune(double number) {
    if (!number) return 0;

    double ex{0}, value{0};
    ex = std::pow((1 + number), years);
    value = (capital * ex) + (increments * ((ex - 1) / number));
    return value;
}

double Fund::calculate_complex_fortune() {
    fortune = calculate_differential_fortune(annual_return);
    return fortune;
}

double Fund::calculate_taxes() {
    double profit{fortune - capital - (increments * years)};
    return (profit * 0.25);
}

void Fund::display_fortune() {
    double taxes{calculate_taxes()};
    double fortune_after_taxes{fortune - taxes};
    double cost_of_fees{calculate_differential_fortune(annual_return + fees) - fortune};

    std::cout << "\nFortune after fees, taxes and adjusting for inflation is: $" << utility::insert_commas(fortune_after_taxes) << "\n";
    if (fortune) {
        std::cout << "Amount lost to taxes: $" << utility::insert_commas(taxes) << " or " << taxes * 100 / fortune << "%\n";
        std::cout << "Amount lost to fees: $" << utility::insert_commas(cost_of_fees) << " or " << cost_of_fees * 100 / fortune << "%\n";
    }
}

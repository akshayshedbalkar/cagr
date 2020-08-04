#ifndef FUND_H
#define FUND_H

class Fund {
   private:
    double years;
    double capital;

    double annual_return;
    double cumulative_return;

    double tax_rate;
    double inflation;
    double fees;

    double increments;
    double fortune;

   public:
    Fund();
    Fund(const double tax_rate, const double inflation, const double fees);

    void set_parameters();
    void set_capital();
    void set_current_return();
    void set_years();
    void set_increments();

    void reset_annual_return();

    double calculate_return();
    double calculate_taxes();

    double calculate_complex_fortune();
    double calculate_differential_fortune(double number);

    void display_fortune();
    void greeting(const double tax_rate, const double inflation, const double fees);
};

#endif /* ifndef FUND_H */

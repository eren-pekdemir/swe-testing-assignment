#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stdexcept>

class Calculator {
public:
    Calculator();

    /* Return the sum of two numbers. */
    double add(double a, double b) const;

    /* Return the difference of two numbers. */
    double subtract(double a, double b) const;

    /* Return the product of two numbers. */
    double multiply(double a, double b) const;

    double divide(double a, double b) const;

    double calculate(double a, char op, double b);

    /* Reset the calculator state to initial values. */
    void clear();

    /* Get the current stored value. */
    double getCurrentValue() const;

    /* Get the current display string. */
    std::string getDisplayValue() const;

private:
    double currentValue;
    std::string displayValue;
};

#endif // CALCULATOR_H

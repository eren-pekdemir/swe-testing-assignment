#include "QuickCalc.h"
#include <sstream>
#include <cmath>

Calculator::Calculator() : currentValue(0.0), displayValue("0") {}

double Calculator::add(double a, double b) const {
    return a + b;
}

double Calculator::subtract(double a, double b) const {
    return a - b;
}

double Calculator::multiply(double a, double b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    if (b == 0.0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return a / b;
}

double Calculator::calculate(double a, char op, double b) {
    double result;

    switch (op) {
    case '+': result = add(a, b);      break;
    case '-': result = subtract(a, b);  break;
    case '*': result = multiply(a, b);  break;
    case '/': result = divide(a, b);    break;
    default:
        throw std::invalid_argument(std::string("Invalid operator: ") + op);
    }

    currentValue = result;

    return result;
}

void Calculator::clear() {
    currentValue = 0.0;
    displayValue = "0";
}

double Calculator::getCurrentValue() const {
    return currentValue;
}

std::string Calculator::getDisplayValue() const {
    return displayValue;
}
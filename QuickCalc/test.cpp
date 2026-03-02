/**
 * Quick-Calc Test Suite
 * Simple test runner without external frameworks.
 * All unit and integration tests in a single file.
 */

#include <iostream>
#include <string>
#include <cmath>
#include "QuickCalc.h"

int totalTests = 0;
int passedTests = 0;

/**
 * Simple assertion helper: prints PASS or FAIL for each test.
 */
void check(const std::string& testName, bool condition) {
    totalTests++;
    if (condition) {
        passedTests++;
        std::cout << "  [PASS] " << testName << std::endl;
    }
    else {
        std::cout << "  [FAIL] " << testName << std::endl;
    }
}

// ── Unit Tests ──────────────────────────────────────────

void testAddPositiveNumbers() {
    Calculator calc;
    check("Add positive numbers (5+3=8)", calc.add(5, 3) == 8);
}

void testAddNegativeNumbers() {
    Calculator calc;
    check("Add negative numbers (-4+-6=-10)", calc.add(-4, -6) == -10);
}

void testSubtractPositiveNumbers() {
    Calculator calc;
    check("Subtract positive numbers (10-4=6)", calc.subtract(10, 4) == 6);
}

void testSubtractResultingNegative() {
    Calculator calc;
    check("Subtract resulting negative (3-10=-7)", calc.subtract(3, 10) == -7);
}

void testMultiplyPositiveNumbers() {
    Calculator calc;
    check("Multiply positive numbers (6*7=42)", calc.multiply(6, 7) == 42);
}

void testMultiplyByZero() {
    Calculator calc;
    check("Multiply by zero (99*0=0)", calc.multiply(99, 0) == 0);
}

void testDividePositiveNumbers() {
    Calculator calc;
    check("Divide positive numbers (10/2=5)", calc.divide(10, 2) == 5.0);
}

void testDivideByZero() {
    Calculator calc;
    bool threw = false;
    try {
        calc.divide(10, 0);
    }
    catch (const std::invalid_argument&) {
        threw = true;
    }
    check("Divide by zero throws exception", threw);
}

void testDivideDecimalNumbers() {
    Calculator calc;
    double result = calc.divide(7.5, 2.5);
    check("Divide decimal numbers (7.5/2.5=3.0)", std::abs(result - 3.0) < 0.0001);
}

void testMultiplyLargeNumbers() {
    Calculator calc;
    check("Multiply large numbers (1M*1M=1T)", calc.multiply(1000000, 1000000) == 1e12);
}



// ── Main ────────────────────────────────────────────────

int main() {
    std::cout << "\n==============================" << std::endl;
    std::cout << "  Quick-Calc Test Suite" << std::endl;
    std::cout << "==============================\n" << std::endl;

    std::cout << "[Unit Tests]" << std::endl;
    testAddPositiveNumbers();
    testAddNegativeNumbers();
    testSubtractPositiveNumbers();
    testSubtractResultingNegative();
    testMultiplyPositiveNumbers();
    testMultiplyByZero();
    testDividePositiveNumbers();
    testDivideByZero();
    testDivideDecimalNumbers();
    testMultiplyLargeNumbers();

    std::cout << "\n==============================" << std::endl;
    std::cout << "  Result: " << passedTests << "/" << totalTests << " passed" << std::endl;
    std::cout << "==============================\n" << std::endl;

    return (passedTests == totalTests) ? 0 : 1;
}
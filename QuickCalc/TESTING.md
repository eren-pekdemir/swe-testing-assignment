# Testing Strategy — Quick-Calc

## What We Tested

- All four arithmetic operations (add, subtract, multiply, divide) individually
- Edge cases: division by zero, negative numbers, decimals, large numbers, multiply by zero
- Full calculation workflows: `calculate()` updating state and display correctly
- `clear()` resetting everything after a calculation
- Invalid operator handling (throwing exception)

## What We Did NOT Test

- Non-functional aspects : performance, security, usability 

---

### The Testing Pyramid

Our suite has **10 unit tests**  and **2 integration tests** . This matches the pyramid: many small, fast unit tests at the base and fewer integration tests above.

### Black-Box vs White-Box Testing

Unit tests use a **white-box** approach — we knew `divide()` checks `if (b == 0.0)` internally, so we wrote a test targeting that exact branch. Integration tests use a **black-box** approach — we call `calculate(5, '+', 3)` and only check the observable outputs (return value, `getCurrentValue()`, `getDisplayValue()`) without caring about internal details.

### Functional vs Non-Functional Testing

All 12 tests are **functional** — they check "given this input, is the output correct?". We did **not** test non-functional aspects like execution speed, memory usage, or usability because they are irrelevant for a simple calculator.

### Regression Testing

If someone changes the code in the future, running `ctest` will immediately show if anything broke. For example, if the division-by-zero guard is accidentally removed, `testDivideByZero` will fail. In a real project, this would run automatically in a CI/CD pipeline on every push.

---
## Test Results

**Unit Tests (10):** Addition with positive and negative numbers, subtraction with positive result and negative result, multiplication with positive numbers and with zero, division with positive numbers and with decimals, division by zero exception, multiplication with large numbers.

**Integration Tests (2):** Full addition workflow with state verification, clear reset after calculation


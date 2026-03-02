# Quick-Calc 🧮

A simple, clean command-line calculator application built with **C++17**. Quick-Calc supports four basic arithmetic operations — addition, subtraction, multiplication, and division — along with a clear function to reset the calculator state. The project was developed as part of the **Advanced Software Engineering** course to demonstrate professional software testing practices, version control workflows, and documentation skills.

---

## Setup Instructions

### Prerequisites

- **C++17** compatible compiler (g++ 7+ or MSVC 2017+)

### Build & Run

1. Clone the repository:
   ```bash
   git clone https://github.com/eren-pekdemir/swe-testing-assignment
   cd swe-testing-assignment/QuickCalc
   ```

2. Build and run the application:
   ```bash
   g++ -std=c++17 QuickCalc.cpp -o quick_calc.exe
   ./quick_calc.exe
   ```

---

## How to Run Tests

```bash
g++ -std=c++17 QuickCalc.cpp test.cpp -o run_tests.exe
./run_tests.exe
```

---

## Testing Framework Research: Google Test vs Catch2

**Google Test** is the most popular C++ testing framework. It uses macros like `TEST`, `EXPECT_EQ`, and supports fixtures and parameterized tests. It integrates well with CMake but requires compilation as a dependency.

**Catch2** is a lighter alternative with a more readable syntax (`REQUIRE(x == 5)`). The v2 version is header-only, making setup trivial for small projects. However, it lacks some advanced features like death tests.

For this project, we used a **custom lightweight test runner** since the scope is small (14 tests) and no external dependency is needed. For a larger project, Google Test would be the better choice due to its richer feature set and industry adoption.

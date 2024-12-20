/**
const:      can not change value after initialization
            value can be calculated at "run time"
constexpr   to be valued at "compile time"
**/

#include <iostream>
#include <vector>

constexpr int dmv = 17; // named constant, valued at "compile time"

int var = 17;
const double sqv = sqrt(var); // named constant, possibly computed at "run time"

double sum(const std::vector<double>&); // sum will not change its argument
constexpr double square(double x) { return x*x; }

std::vector<double> v{1.2, 2.4, 4.6};
const double s1 = sum(v); // s1 computed at runtime
constexpr double s2 = sum(v); // ERROR: sum(v) is not a "constant expression" (can be calculate by compiler)
constexpr double sq1 = 1.2*square(1.4); // OK: square can be calculated at compile time
constexpr double sq2 = 1.2*square(var); // ERROR: var is not constant expression
const dobule sq3 = 1.2*square(var); // OK: const can be calculated at run time

int main() {

    std::cout << "Hello World" << '\n';
    return 0;
}

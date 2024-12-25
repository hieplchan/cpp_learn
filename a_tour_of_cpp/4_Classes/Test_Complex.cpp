#include "Complex.h";

int main() {
    // Const function test
    Complex z{2, 0};
    const Complex cz{1, 3};
    z = cz;
    // cz = z; // ERROR: operator =() is non-const member function
    double x = z.real();


    return 0;
}
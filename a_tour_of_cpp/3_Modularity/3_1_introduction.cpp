#include <iostream>
#include <cmath>

#include "Vector.h"

using namespace std;

double sqrt_sum(Vector v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += sqrt(v[i]);
    }
    return sum;
}

void test_range_exception(Vector& v) {
    // test exception
    try {
        v[v.size()] = 1;
    } 
    catch (out_of_range& err) {
        cerr << err.what() << '\n';
    }
}

void test_constructor_exception() {
    try {
        Vector(-27);
    }
    catch (length_error& err) {
        cerr << err.what() << '\n';
        throw; // rethrow
    }
    catch (bad_alloc& err) {
        // handle memory exhausion
        cerr << err.what() << '\n';
        terminate();
    }
}

int MyMain() {
// int main() {
    Vector v(10);
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }
    cout << "Result: " << sqrt_sum(v) << '\n';

    test_range_exception(v);
    test_constructor_exception();

    return 0;
}
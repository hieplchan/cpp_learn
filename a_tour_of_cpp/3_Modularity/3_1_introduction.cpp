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

int main() {
    Vector v(10);
    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }

    cout << "Result: " << sqrt_sum(v);
}
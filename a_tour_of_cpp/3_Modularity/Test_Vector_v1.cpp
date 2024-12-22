// cl /I \. .\Test_Vector_v1.cpp .\Vector_v1.cpp

#include <iostream>
#include "Vector_v1.h"

int main() {
    Vector v(3);

    for (int i = 0; i < v.size(); i++) {
        v[i] = i;
    }

    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    std::cout << "Sum: " << sum << '\n';

    return 0;
}
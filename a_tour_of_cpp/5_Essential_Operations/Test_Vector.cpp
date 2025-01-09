// cl /I \. .\Test_Vector.cpp .\Vector.cpp

#include <iostream>
#include <istream>

#include "Vector.h"

void print_vector(Vector& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }
    std::cout << std::endl;
}

void test_copy_constructor_assignment() {
    // if we dont have copy constructor/assignment
    // same output will be print and destroyed maybe error
    Vector v1 {0, 1, 2};
    Vector v2 {v1}; // copy contructor
    Vector v3(v1.size());

    v3 = v1; // copy assignment
    v2[0] = 9;
    v3[0] = 8;

    print_vector(v1);
    print_vector(v2);
    print_vector(v3);
}

int main() {
    test_copy_constructor_assignment();
    return 0;
}
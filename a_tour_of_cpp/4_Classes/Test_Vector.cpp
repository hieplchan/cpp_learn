// cl /I \. .\Test_Vector.cpp .\Vector.cpp .\Vector_container.cpp

#include <iostream>
#include <istream>

#include "Vector.h"
#include "Container.h"
#include "Vector_container.h"

void test_exception(Vector&v) {
    try { // exception here handled by the handler define below
        v[6] = 7;
    } catch (std::out_of_range& err) { // error handler
        std::cout << err.what() << '\n';
    }
}

void test_invarion_constructor() {
    try {
        Vector v(-27);
    } catch (std::length_error& err) {
        std::cerr << "test failed: length error\n";
    } catch (std::bad_alloc& err) { // this program not designed to handle memory exhaustion
        std::terminate();
    }
}

void test_destructor() {
    Vector v1(3);
    if (true) {
        Vector v2(2);
    } // v2 is destroyed here
} // v1 is destroyed here

void test_list_init() {
    Vector v1{1, 2, 3, 4, 5};
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << '\n';
}

// this func use Container interface in complete ignorance of implementation details
void test_container(Container& c) {
    const int sz = c.size();
    for (int i = 0; i < sz; i++) {
        std::cout << c[i];
    }
}

// Vector read_vector(std::istream& is) {
//     Vector v; // still not implement default constructor yet
//     for (double d; is>>d;) {
//         v.push_back(d);
//     }
//     return v;
// }

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

    test_exception(v);

    test_invarion_constructor();

    test_destructor();

    test_list_init();

    // Vector v = read_vector(std::cin); // move Constructor

    Vector_container v2(10);
    test_container(v2);

    return 0;
}
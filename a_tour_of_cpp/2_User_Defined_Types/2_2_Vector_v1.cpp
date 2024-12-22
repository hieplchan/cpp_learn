#include <iostream>

struct Vector {
    int size;
    double* element;
};

void Vector_init(Vector& v, int size) {
    v.size = size;
    v.element = new double[size];
}

int main() {
    Vector v;
    Vector_init(v, 3);

    for (int i = 0; i < v.size; i++) {
        v.element[i] = i;
    }

    double sum = 0;
    for (int i = 0; i < v.size; i++) {
        sum += v.element[i];
    }

    std::cout << "Sum: " << sum << '\n';

    return 0;
}
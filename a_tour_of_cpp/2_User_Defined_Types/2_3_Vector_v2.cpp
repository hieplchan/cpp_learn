#include <iostream>

/*
Pg.24 - Object is handle cointain pointer to element & number of element
Number of element can be differ between objects, but "Vector" objects always same size
This is the basic technique for handling varying amounts of information in C++: 
a fixed-size handle referring to a variable amount of data ‘‘elsewhere’’
 */
class Vector {
public:
    Vector(int size) : elem {new double[size]}, sz {size} { };
    double& operator[](int index) { return elem[index]; }
    int size() { return sz; }
private:
    int sz;
    double* elem;
};

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
#include <stdexcept>
#include "Vector.h"

Vector::Vector(int size)
{
    if (size < 0)
        throw std::length_error{"Vector constructor: Negative size"};
    sz = size;
    elem = new double[size];
}

// Version 2: add initializer-list constructor
Vector::Vector(std::initializer_list<double> lst)
:elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    std::copy(lst.begin(), lst.end(), elem);
}

// Version 2: add destructor
Vector::~Vector() {
    delete[] elem; // delete array
}

double& Vector::operator[](int index) 
{
    if (index < 0 || size() < index)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[index];
}

int Vector::size() const
{
    return sz;
}

// Version 2
void Vector::push_back(double value) {

}

///////////////// Version 1

// double& Vector::operator[](int index) 
// {
//     return elem[index];
// }

// double& Vector::operator[](int index) 
// {
//     if (index < 0 || size() < index)
//         throw std::out_of_range{"Vector::operator[]"};
//     return elem[index];
// }
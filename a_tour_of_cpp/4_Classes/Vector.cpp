#include <stdexcept>
#include "Vector.h"

Vector::Vector(int size)
{
    if (size < 0)
        throw std::length_error{"Vector constructor: Negative size"};
    sz = size;
    elem = new double[size];
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

int Vector::size()
{
    return sz;
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
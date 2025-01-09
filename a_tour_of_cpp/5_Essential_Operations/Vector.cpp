#include <stdexcept>
#include <iostream>
#include "Vector.h"

Vector::Vector(int size)
{
    if (size < 0)
        throw std::length_error{"Vector constructor: Negative size"};
    std::cout << "Created!" << std::endl; 
    sz = size;
    elem = new double[size];
}

Vector::Vector(std::initializer_list<double> lst)
:elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    std::cout << "Created! list" << std::endl; 
    std::copy(lst.begin(), lst.end(), elem);
}

Vector::~Vector() {
    std::cout << "Destroyed!" << std::endl; 
    delete[] elem;
}

// 5.2 Add copy constructor
Vector::Vector(const Vector& other) 
    :elem{new double[other.size()]}, sz{other.size()}
{
    std::cout << "Copied constructor!" << std::endl;
    std::memcpy(elem, other.elem, sz *sizeof(double));
}

// 5.2 Add copy assignment
Vector& Vector::operator=(const Vector& other) {
    std::cout << "Copied assignment!" << std::endl;
    sz = other.size();
    delete[] elem;
    elem = new double[sz];
    std::memcpy(elem, other.elem, sz * sizeof(double));
    return *this;
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

void Vector::push_back(double value) {

}
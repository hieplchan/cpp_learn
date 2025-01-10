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

// 5.2 Add move constructor
Vector::Vector(Vector&& other)
    : elem{other.elem}, // steal other's elem
    sz{other.size()}
{
    std::cout << "Moved constructor!" << std::endl;
    other.elem = nullptr; // now has no elem
    other.sz = 0;
}

// 5.2 Add move assignment
Vector& Vector::operator=(Vector&& other) {
    std::cout << "Moved assignment!" << std::endl;

    if (this != &other) {
        delete[] elem;

        elem = other.elem;
        sz = other.size();

        other.elem = nullptr;
        other.sz = 0;
    }

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

// 5.2 Move containers
Vector operator+(Vector& a, Vector& b) {
    if (a.size() != b.size())
        throw std::length_error{"Vector_size_mismatch"};

    Vector res(a.size());
    for (int i = 0; i < a.size(); i++) {
        res[i] = a[i] + b[i];
    }

    return res;
}
#include "Vector.h"
#include <stdexcept>

template<typename T>
Vector<T>::Vector(int size) 
{
    if (size < 0)
    {
        throw std::length_error{"Vector constructor: Negative size"};
    }
    sz = size;
    elem = new T[sz];
}

template<typename T>
Vector<T>::~Vector() 
{
    delete[] elem;
    sz = 0;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index > sz)
    {
        throw std::out_of_range{"Vector::operator[]"};
    }
    return elem[index];
}

template<typename T>
int Vector<T>::size() const
{
    return sz;
}
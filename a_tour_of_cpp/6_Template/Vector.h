#pragma once
#include <stdexcept>

template<typename T>
class Vector
{
public:
    Vector(int size);

    ~Vector();

    T& operator[](int index);
    int size() const;

private:
    T* elem;
    int sz;
};

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

template<typename T>
T* begin(Vector<T>& x)
{
    return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x)
{
    return x.size() ? &x[0] + x.size() : nullptr;
}
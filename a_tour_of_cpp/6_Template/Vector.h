#pragma once
#include <stdexcept>

template<typename T>
class Vector
{
public:
    Vector(int size);
    Vector(std::initializer_list<T> list);

    Vector(const Vector& other);
    Vector& operator=(const Vector other);    

    Vector(Vector&& other);
    Vector& operator=(Vector&& other);

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
Vector<T>::Vector(std::initializer_list<T> list)
    : elem{new T[list.size()]}, sz{static_cast<int>(list.size())}
{
    std::copy(list.begin(), list.end(), elem);
}

template<typename T>
Vector<T>::Vector(const Vector& other)
    : elem{new T[other.size()]}, sz{other.size()}
{
    memcpy(elem, other.elem, other.size() * sizeof(T));
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
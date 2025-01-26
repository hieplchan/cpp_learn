#pragma once

template<typename T>
class Vector
{
public:
    Vector(int size);

    T& operator[](int index);
    int size() const;

    ~Vector();
private:
    T* elem;
    int sz;
};
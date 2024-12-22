#include "Vector_v1.h"

Vector::Vector(int size) :
    elem {new double[size]}, 
    sz {size}
{
}

double& Vector::operator[](int index) 
{
    return elem[index];
}

int Vector::size()
{
    return sz;
}
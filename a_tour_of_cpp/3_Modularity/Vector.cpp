#include <stdexcept>
#include "Vector.h"

using namespace std;

Vector::Vector(int s)
{
    if (s < 0)
        throw length_error("Vector::Vector negative size");
    sz = s;
    elem = new double[s];
}

double& Vector::operator[](int i) {
    if (i < 0 || size() <= i)
        throw out_of_range{"Vector::operator[] out_of_range"};
    return elem[i];
}

int Vector::size() {
    return sz;
}
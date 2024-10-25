#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

class Vector_1
{
public:
    Vector_1(int s) : element{new double[s]}, sz{s} {} //constructor
    double& operator[](int i) { return element[i]; } //element access: subcripting
    int size() { return sz; }
private:
    int sz;
    double* element;
};

#endif
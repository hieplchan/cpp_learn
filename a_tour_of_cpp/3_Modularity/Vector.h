#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

class Vector {
public:
    Vector(int size);
    double& operator[](int index);
    int size();
private:
    double* elem;
    int sz;
};

#endif
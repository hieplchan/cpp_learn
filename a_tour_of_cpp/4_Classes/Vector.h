#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
public:
    Vector(int size);

    ~Vector();

    double& operator[](int index);
    int size();
private:
    int sz;
    double* elem;
};

#endif
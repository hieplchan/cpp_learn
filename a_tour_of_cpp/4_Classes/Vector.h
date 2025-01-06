#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
public:
    Vector(int size);
    Vector(std::initializer_list<double> list);

    ~Vector();

    double& operator[](int index);
    int size() const;
    void push_back(double value);
private:
    int sz;
    double* elem;
};

#endif
#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
public:
    Vector(int size);
    Vector(std::initializer_list<double> list);

    ~Vector();

    // 5.2 Add deep copy to prevent destructor 
    // "delete" same memory multiple times
    Vector(const Vector& other); // copy constructor
    Vector& operator=(const Vector& other); //copy assignment

    // 5.2 Move container: prevent copy large object
    // && = rvalue reference, rvalue = value nobody can assign to
    Vector(Vector&& other); // move constructor
    Vector& operator=(Vector&& other); // copy constructor

    double& operator[](int index);
    int size() const;
    void push_back(double value);
private:
    int sz;
    double* elem;
};

// 5.2 Move containers
Vector operator+(Vector& a, Vector& b);

#endif
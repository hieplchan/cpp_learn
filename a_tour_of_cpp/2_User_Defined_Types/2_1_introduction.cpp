#include <iostream>

using namespace std;

struct Vector
{
    int sz;
    double* element;
};

void vector_init(Vector& v, int sz)
{
    v.element = new double[sz];
    v.sz = sz;
}

void test_access(Vector v, Vector& rv, Vector* pv)
{
    v.sz; // access through name
    rv.sz; // access through reference
    pv->sz; // access through pointer
}

int main()
{
    Vector v;
    vector_init(v, 3);

    cout << "Enter number: ";
    for (int i = 0; i < v.sz; i++)
    {
        cin >> v.element[i];
    }

    double sum = 0;
    for (int i = 0; i < v.sz; i++)
    {
        sum += v.element[i];
    }
    cout << "Sum of vector: " << sum;

    return 0;
}
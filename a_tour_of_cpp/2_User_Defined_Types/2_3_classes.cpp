#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(int s) : element{new double[s]}, sz{s} {} //constructor
    double& operator[](int i) { return element[i]; } //element access: subcripting
    int size() { return sz; }
private:
    int sz;
    double* element;
};

int main()
{
    Vector v(3);

    cout << "Enter number: ";
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << "Sum of vector: " << sum;
}
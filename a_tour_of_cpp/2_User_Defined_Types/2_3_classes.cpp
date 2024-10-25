#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector_1 v(3);

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
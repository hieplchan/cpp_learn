// cl /I \. .\Test_Vector.cpp .\Vector.cpp

#include <iostream>
#include "Vector.h"

template<typename T>
void printVector(Vector<T>& v) 
{
    for (int i = 0; i < v.size(); i++) 
    {
        std::cout << v[i];
    }
    std::cout << std::endl;
}

void testSimpleVector()
{
    Vector<int> v1(2);
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    printVector(v1);
}

int main() 
{
    testSimpleVector();
}
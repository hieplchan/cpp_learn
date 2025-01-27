// cl /I \. .\Test_Vector.cpp .\Vector.cpp

#include <iostream>
#include <string>

#include "Vector.h"

template<typename T>
void printVector(Vector<T>& v) 
{
    for (auto& a : v)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void testSimpleVector()
{
    Vector<T> v1(2);
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    printVector(v1);
}

int main() 
{
    testSimpleVector<int>();
    testSimpleVector<double>();
    testSimpleVector<std::string>();
}
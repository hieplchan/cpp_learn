// cl /std:c++17 /I \. .\Test_Vector.cpp

#include <iostream>
#include <string>

#include "Vector.h"

using namespace std::literals::string_literals;

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
    Vector<T> v1(3);
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    printVector(v1);
}

void testTemplateDuduction()
{
    Vector v1 {1, 2, 3};
    Vector v2 = v1;
    Vector v3 {"Aaa", "bbb"};
    Vector v4 {"Aaa"s, "bbb"s};

    std::cout << typeid(v1[0]).name() << std::endl;
    std::cout << typeid(v2[0]).name() << std::endl;
    std::cout << typeid(v3[0]).name() << std::endl;
    std::cout << typeid(v4[0]).name() << std::endl;
}

int main() 
{
    testSimpleVector<int>();
    testSimpleVector<double>();
    testSimpleVector<std::string>();

    testTemplateDuduction();
}
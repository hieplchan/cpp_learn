// cl /I \. .\Test_Buffer.cpp

#include <iostream>

#include "Buffer.h"

Buffer<double, 1024> g_Buffer;

int main()
{
    std::cout << g_Buffer.size() << std::endl;

    g_Buffer[10] = 10;
    std::cout << g_Buffer[10] << std::endl;
}
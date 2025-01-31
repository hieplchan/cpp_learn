// cl /std:c++17 /I \. .\Function_Template.cpp

#include <string>
#include <iostream>
#include <list>
#include <vector>

#include "Vector.h"

#define LOG(x) std::cout << x << std::endl

using namespace std::literals::string_literals;

template<typename C, typename P>
int count(const C& c, P pred)
{
    int count = 0;
    for (const auto& x : c)
        if (pred(x))
            count++;
    return count;
}


// [&](int a){ return a < x; }
// generate function object using lamda expression notation
// [&]: capture list, all local names using in lamda body is access through refernce
// canbe: [&x] only x, [=x] copy x, [] no capture, [=] all access through value (copy)
void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
    std::cout << "num of value less than " << x << ": " 
                << count(vec, [&](int a){ return a < x; })
                << '\n';
    std::cout << "num of value less than " << s << ": " 
                << count(lst, [&](const std::string& a){ return a < s; }) 
                << '\n';
}

int main()
{
    
}
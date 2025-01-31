// cl /std:c++17 /I \. .\Function_Template.cpp

#include <string>
#include <iostream>
#include <list>

#include "Vector.h"

#define LOG(x) std::cout << x << std::endl

using namespace std::literals::string_literals;

template<typename T>
class Less_than 
{
    const T val;
public:
    Less_than(const T& v) : val{v} {}
    bool operator()(const T& v) const { return v < val; }
};

// Function object, can be used as "predicate"
// They can carry value to be compare with them, no need for global value
// Easy to inline than function call
Less_than lti {42}; // compare i to 42
Less_than lts {"Backup"s}; // compare s to "Backup"
Less_than<std::string> lts2 {"naur"}; // naur is C-string, need <string> to get right

void testLessThan()
{
    bool b1 = lti(10);
    bool b2 = lts("abcd"s);
    bool b3 = lts2("1234");

    LOG(b1);
    LOG(b2);
    LOG(b3);
}

template<typename C, typename P>
int count(const C& c, P pred)
{
    int count = 0;
    for (const auto& x : c)
        if (pred(x))
            count++;
    return count;
}

void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
    std::cout << "num of value less than " << x << ": " << count(vec, Less_than {x}) << '\n';
    std::cout << "num of value less than " << s << ": " << count(lst, Less_than {s}) << '\n';
}

int main()
{
    testLessThan();
}
// cl /std:c++17 /I \. .\Function_Template.cpp

#include <list>
#include <vector>
#include <complex>

#include "Vector.h"


template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{
    for (auto x : s)
        v += x;
    return v;
}

void user(Vector<int>& vi, std::list<double>& ld, std::vector<std::complex<double>>& vc)
{
    int x = sum(vi, 0);
    double d = sum(vi, 0.0);
    double dd = sum(ld, 0.0);
    auto z = sum(vc, std::complex{0.0, 0.0});
}

int main()
{
}
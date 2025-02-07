// cl /std:c++17 /I \. .\Templates_Abstraction.cpp

#include <vector>
#include <list>
#include <iostream>

#define LOG(x) std::cout << x << std::endl

using std::vector, std::list;

/*
    Why vector?
    Why int?
    Why start at 0?
    Why return double?
    Why add?
*/
double sum(const vector<int>& v)
{
    double res = 0;
    for (auto x : v)
        res += x;
    return res;
}

template<typename Iter, typename Val>
Val accummulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p != last; ++p)
        res += *p;
    return res;
}

void useAccumulate(const vector<int>& vec, const list<double> lst)
{
    auto sum = accummulate(begin(vec), end(vec), 0.0);
    auto sum2 = accummulate(begin(lst), end(lst), sum);
    LOG(sum2);
}

int main()
{
    vector<int> vec {1, 2, 3};
    list<double> lst {4, 5, 6, 7};
    useAccumulate(vec, lst);
}
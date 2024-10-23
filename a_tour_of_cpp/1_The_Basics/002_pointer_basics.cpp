#include <iostream>
#include <vector>

using namespace std;

int v[] {1, 2, 3, 4, 5};

void const_references(const vector<double>& value)
{
    cout << "Dont want to modify argument, but still dont want cost of copying";
}

// p assume zero terminated array of char
int count_x(const char* p, char x)
{
    if (p == nullptr) return 0;

    int count = 0;
    while (*p)
    {
        if (*p == x) ++count;
        ++p;
    }

    return count;
}

void print()
{
    // using reference, dont need to copy first
    for (auto& x : v)
    {
        ++x;
        cout << x << " ";
    }

    cout << "\n";
    // copy v to x first
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n";
    string temp = "hello";
    cout << count_x(temp.c_str(), 'l');
}

int main()
{
    print();

    return 0;
}
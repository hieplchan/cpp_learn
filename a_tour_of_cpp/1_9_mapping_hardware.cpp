#include <iostream>

using namespace std;

void test_pointer()
{
    int x = 2;
    int y = 3;
    int *p1 = &x;
    int *p2 = &y;

    p1 = p2;
    cout << "x: " << x << " y: " << y << "\n";
}

void test_reference()
{
    int x = 2;
    int y = 3;
    int& r1 = x;
    int& r2 = y;

    // reference and pointer are both memory adrress
    // but the using is different
    r1 = r2;
    cout << "x: " << x << " y: " << y << "\n";
}

int main()
{
    test_pointer();
    test_reference();
}
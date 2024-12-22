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
    // Assignment to a reference does not change what the reference refers to
    // but assigns to the referenced object
    r1 = r2; // // read through r2, write through r: x becomes 3
    cout << "x: " << x << " y: " << y << "\n";
}

int main()
{
    // x: 2 y: 3
    test_pointer();
    // x: 3 y: 3
    test_reference();
}
#include <iostream>

using namespace std;

int square(int x)
{
    return x*x;
}

void print_square(int x)
{
    cout << "Square(x) = " << square(x) << " \n";
}

int main()
{
    print_square(10);
    return 0;
}
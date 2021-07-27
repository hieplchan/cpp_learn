#include <iostream>

using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// Type alias declare
// typedef int arrType[5];
using arrType = int[5];
arrType* arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}

// Normal declaration
// int (*arrPtr(int i))[5] {
//     return (i % 2) ? &odd : &even;
// }

// Trailing return type declaration: easier to understand
// auto arrPtr(int i) -> int (*)[5] {
//     return (i % 2) ? &odd : &even;
// }

// decltype declaration: return pointer to what ever odd is
// decltype(odd) *arrPtr(int i) {
//     return (i % 2) ? &odd : &even;
// }

int main(int argc, char **argv) {
    cout << "Function return pointer of array example: " << argv[0] << endl;

    int (*result_odd)[5] = arrPtr(1);
    for (auto beg = begin(*result_odd); beg != end(*result_odd); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;

    int (*result_even)[5] = arrPtr(2);
    for (auto beg = begin(*result_even); beg != end(*result_even); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;

    return 0;
}
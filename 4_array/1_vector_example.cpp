#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Start array example\n" << endl;

    unsigned scores[11] = {};
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade/10];
        }
    }

    for (auto i : scores) {
        cout << i << " ";
    }
    cout << endl;

    // Another way to write array
    unsigned *pBegin = std::begin(scores);
    unsigned *pEnd = std::end(scores);
    while (pBegin != pEnd) {
        cout << *pBegin << " ";
        ++pBegin;
    }
    cout << endl;

    return 0;
}
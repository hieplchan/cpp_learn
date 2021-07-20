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

    return 0;
}
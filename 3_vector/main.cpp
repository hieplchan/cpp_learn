#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    cout << "Start vector example\n" << endl;

    vector<unsigned> scores(11, 0);
    unsigned grade;

    while (cin >> grade) {
        if (grade <= 100) {
            ++scores[grade/10];
        }
    }

    for (decltype(scores.size()) index = 0; index <scores.size(); index++) {
        cout << scores[index] << " ";
    }

    cout << endl;
}